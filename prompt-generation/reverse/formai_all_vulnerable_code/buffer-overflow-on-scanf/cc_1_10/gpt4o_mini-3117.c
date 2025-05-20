//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_WATERMARK_LEN 50

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function prototypes
Image* load_pgm(const char *filename);
void save_pgm(const char *filename, Image *img);
void embed_watermark(Image *img, const char *watermark);
void retrieve_watermark(Image *img, char *watermark_out);

// Main function driving the program
int main() {
    char input_filename[MAX_FILENAME_LEN], output_filename[MAX_FILENAME_LEN];
    char watermark[MAX_WATERMARK_LEN] = "Watermark!";
    
    // Prompt for input file
    printf("Enter input PGM file name: ");
    scanf("%s", input_filename);

    // Load the image
    Image *img = load_pgm(input_filename);
    if (!img) {
        fprintf(stderr, "Error: Could not load image.\n");
        return 1;
    }
    
    // Embed watermark
    embed_watermark(img, watermark);
    
    // File name for saving the modified image
    printf("Enter output PGM file name: ");
    scanf("%s", output_filename);
    
    // Save the modified image
    save_pgm(output_filename, img);
    printf("Watermark embedded and image saved as '%s'.\n", output_filename);
    
    // Prepare to retrieve watermark
    char retrieved_watermark[MAX_WATERMARK_LEN];
    retrieve_watermark(img, retrieved_watermark);
    printf("Retrieved watermark: '%s'\n", retrieved_watermark);
    
    // Cleanup
    free(img->data);
    free(img);
    
    return 0;
}

// Load PGM file
Image* load_pgm(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    // Read the header
    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Invalid PGM file");
        return NULL;
    }
    if (buffer[0] != 'P' || buffer[1] != '5') {
        fprintf(stderr, "Not a binary PGM file\n");
        return NULL;
    }
    
    // Allocate memory for image structure
    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    
    int max_value;
    fscanf(file, "%d", &max_value);
    fgetc(file); // Read the newline character

    // Allocate memory for image data
    img->data = (unsigned char *)malloc(img->width * img->height);
    fread(img->data, img->width * img->height, 1, file);
    fclose(file);

    return img;
}

// Save PGM file
void save_pgm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }
    
    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, img->width * img->height, 1, file);
    fclose(file);
}

// Embed a watermark into the image
void embed_watermark(Image *img, const char *watermark) {
    size_t wm_len = strlen(watermark);
    for (size_t i = 0; i < wm_len; i++) {
        int position = (img->width * img->height - wm_len + i) % (img->width * img->height);
        img->data[position] = (img->data[position] & 0xFE) | (watermark[i] & 0x01);
    }
}

// Retrieve the watermark from the image
void retrieve_watermark(Image *img, char *watermark_out) {
    size_t wm_len = strlen("Watermark!");
    for (size_t i = 0; i < wm_len; i++) {
        int position = (img->width * img->height - wm_len + i) % (img->width * img->height);
        watermark_out[i] = (img->data[position] & 0x01) + '0'; // Convert back to character
    }
    watermark_out[wm_len] = '\0'; // Null terminate the string
}