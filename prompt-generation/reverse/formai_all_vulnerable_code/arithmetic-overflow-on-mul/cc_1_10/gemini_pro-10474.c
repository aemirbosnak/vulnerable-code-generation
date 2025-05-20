//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned char *data;
	int width, height, channels;
} Image;

Image *new_image(int width, int height, int channels) {
	Image *image = malloc(sizeof(Image));
	image->data = malloc(width * height * channels);
	image->width = width;
	image->height = height;
	image->channels = channels;
	return image;
}

void free_image(Image *image) {
	free(image->data);
	free(image);
}

Image *load_image(const char *filename) {
	FILE *file = fopen(filename, "rb");
	if (!file) {
		fprintf(stderr, "Error: could not open file %s\n", filename);
		return NULL;
	}

	// Read the header
	unsigned char header[54];
	fread(header, sizeof(header), 1, file);

	// Check if the file is a BMP file
	if (header[0] != 'B' || header[1] != 'M') {
		fprintf(stderr, "Error: not a BMP file\n");
		fclose(file);
		return NULL;
	}

	// Read the image dimensions
	int width = *(int *)&header[18];
	int height = *(int *)&header[22];

	// Read the number of channels
	int channels = *(int *)&header[28];

	// Create an image object
	Image *image = new_image(width, height, channels);

	// Read the image data
	fread(image->data, width * height * channels, 1, file);

	// Close the file
	fclose(file);

	return image;
}

void save_image(Image *image, const char *filename) {
	FILE *file = fopen(filename, "wb");
	if (!file) {
		fprintf(stderr, "Error: could not open file %s\n", filename);
		return;
	}

	// Write the header
	unsigned char header[54];
	header[0] = 'B';
	header[1] = 'M';
	*(int *)&header[2] = sizeof(header) + image->width * image->height * image->channels;
	*(int *)&header[10] = sizeof(header);
	*(int *)&header[14] = 40;
	*(int *)&header[18] = image->width;
	*(int *)&header[22] = image->height;
	*(int *)&header[26] = 1;
	*(int *)&header[28] = image->channels * 8;
	*(int *)&header[34] = 0;
	*(int *)&header[38] = 0;
	*(int *)&header[42] = 0;
	*(int *)&header[46] = 0;
	fwrite(header, sizeof(header), 1, file);

	// Write the image data
	fwrite(image->data, image->width * image->height * image->channels, 1, file);

	// Close the file
	fclose(file);
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
		return 1;
	}

	// Load the input image
	Image *input_image = load_image(argv[1]);
	if (!input_image) {
		fprintf(stderr, "Error: could not load input image\n");
		return 1;
	}

	// Convert the image to grayscale
	for (int i = 0; i < input_image->width * input_image->height; i++) {
		unsigned char grayscale = (input_image->data[i * input_image->channels + 0] + input_image->data[i * input_image->channels + 1] + input_image->data[i * input_image->channels + 2]) / 3;
		input_image->data[i * input_image->channels + 0] = grayscale;
		input_image->data[i * input_image->channels + 1] = grayscale;
		input_image->data[i * input_image->channels + 2] = grayscale;
	}

	// Apply a Gaussian blur to the image
	float kernel[3][3] = {
		{ 1/16.0, 2/16.0, 1/16.0 },
		{ 2/16.0, 4/16.0, 2/16.0 },
		{ 1/16.0, 2/16.0, 1/16.0 }
	};

	for (int i = 1; i < input_image->width - 1; i++) {
		for (int j = 1; j < input_image->height - 1; j++) {
			float sum = 0.0;
			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					sum += input_image->data[(i + k) * input_image->channels + (j + l)] * kernel[k + 1][l + 1];
				}
			}
			input_image->data[i * input_image->channels + j] = (unsigned char)sum;
		}
	}

	// Save the output image
	save_image(input_image, argv[2]);

	// Free the input image
	free_image(input_image);

	return 0;
}