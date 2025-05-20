//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_IMAGE_SIZE 1000
#define MAX_DATA_SIZE 250

#define SET_BIT(value, bit) (value |= (1 << bit))
#define GET_BIT(value, bit) ((value >> bit) & 1)

int main() {
    char image[MAX_IMAGE_SIZE];
    char data[MAX_DATA_SIZE];
    bool message_end = false;

    FILE *fp_image = fopen("example_image.bmp", "rb");
    FILE *fp_output = fopen("output_image.bmp", "wb");
    FILE *fp_data = fopen("data.txt", "r");
    
    if (fp_image == NULL || fp_output == NULL || fp_data == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    int start_offset = 54; // skip BMP header
    fseek(fp_image, start_offset, SEEK_SET);
    fread(image, MAX_IMAGE_SIZE, 1, fp_image);

    int data_len = 0;
    char c;
    while ((c = fgetc(fp_data)) != EOF && data_len < MAX_DATA_SIZE) {
        data[data_len] = c;
        data_len++;
    }

    int image_len = MAX_IMAGE_SIZE;
    for (int i = 0; i < data_len; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = GET_BIT(data[i], j);
            if (data[i] == '\0' && j == 0) {
                message_end = true;
                break;
            }
            SET_BIT(image[start_offset], 0);
            image[start_offset] |= (bit << 0);
            start_offset++;
            if (start_offset >= image_len) {
                printf("Not enough space in the image.\n");
                exit(2);
            }
        }
        if (message_end) {
            break;
        }
    }

    fseek(fp_output, 0, SEEK_SET);
    fwrite(image, MAX_IMAGE_SIZE, 1, fp_output);

    printf("Data successfully hidden in the image.\n");

    fclose(fp_image);
    fclose(fp_output);
    fclose(fp_data);
    
    return 0;
}