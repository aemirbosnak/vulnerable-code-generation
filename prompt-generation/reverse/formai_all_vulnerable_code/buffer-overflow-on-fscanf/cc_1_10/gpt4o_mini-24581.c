//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold PPM image details.
typedef struct {
    char p[3];     // "P6"
    int width;     // Width of the image
    int height;    // Height of the image
    int max_color; // Maximum color value
    unsigned char *data; // Pixel data
} Image;

// Function to read PPM image into the Image structure.
Image *read_ppm(const char *filename) {
    Image *img = (Image *)malloc(sizeof(Image));
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Watson, we have encountered a problem! Unable to open file.\n");
        exit(1);
    }
    
    fscanf(fp, "%s", img->p); // Read the magic number
    if (strcmp(img->p, "P6") != 0) {
        fprintf(stderr, "Elementary, my dear Watson! Only P6 PPM files are supported.\n");
        fclose(fp);
        exit(1);
    }
    
    fscanf(fp, "%d %d", &img->width, &img->height); // Read dimensions
    fscanf(fp, "%d", &img->max_color); // Read max color value
    fgetc(fp); // Consume the newline
    
    img->data = (unsigned char *)malloc(img->width * img->height * 3); // Allocate memory for pixel data
    fread(img->data, 3, img->width * img->height, fp);
    fclose(fp);
    
    return img;
}

// Function to write PPM image from Image structure.
void write_ppm(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Watson, we have encountered a problem! Unable to open file for writing.\n");
        exit(1);
    }
    
    fprintf(fp, "%s\n%d %d\n%d\n", img->p, img->width, img->height, img->max_color);
    fwrite(img->data, 3, img->width * img->height, fp);
    fclose(fp);
}

// Function to hide a secret message in the PPM image using LSB.
void hide_message(Image *img, const char *message) {
    int message_len = strlen(message);
    int message_pos = 0;
    for (int i = 0; i < img->width * img->height * 3 && message_pos < message_len; i++) {
        img->data[i] = (img->data[i] & 0xFE) | ((message[message_pos] >> (i % 8)) & 1);
        if ((i % 8) == 7) {
            message_pos++;
        }
    }
    // Mark the end of the message
    for (int i = message_pos * 8; i < img->width * img->height * 3; i++) {
        img->data[i] = (img->data[i] & 0xFE); // Set all remaining bits to 0
    }
}

// Function to retrieve the secret message from the PPM image.
void retrieve_message(Image *img, char *message, int message_len) {
    memset(message, 0, message_len + 1); // Initialize message buffer
    int message_pos = 0;
    for (int i = 0; i < img->width * img->height * 3 && message_pos < message_len; i++) {
        message[message_pos] |= ((img->data[i] & 1) << (i % 8));
        if ((i % 8) == 7) {
            message_pos++;
        }
    }
}

// Main function - the scene of our investigation.
int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Watson, we need to follow our clues! Usage: %s <input.ppm> <output.ppm> <secret_message> <retrieve>\n", argv[0]);
        return 1;
    }

    Image *image = read_ppm(argv[1]);
    if (strcmp(argv[4], "hide") == 0) {
        hide_message(image, argv[3]);
        write_ppm(argv[2], image);
        printf("The secret message has been successfully concealed, Watson.\n");
    } else if (strcmp(argv[4], "retrieve") == 0) {
        char retrieved_message[256];
        retrieve_message(image, retrieved_message, sizeof(retrieved_message) - 1);
        printf("The secret message is: %s\n", retrieved_message);
    } else {
        fprintf(stderr, "Elementary, my dear Watson! The last argument should be either 'hide' or 'retrieve'.\n");
        free(image->data);
        free(image);
        return 1;
    }

    free(image->data);
    free(image);
    return 0;
}