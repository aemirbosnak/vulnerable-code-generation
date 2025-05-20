//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define WATERMARK_LENGTH 64
#define WATERMARK_VALUE "This is a watermark"

void generate_watermark(char* watermark) {
    char* value = WATERMARK_VALUE;
    int value_length = strlen(value);
    int watermark_length = strlen(watermark);
    int i, j;

    for (i = 0; i < watermark_length; i++) {
        if (watermark[i] == 'w') {
            for (j = 0; j < value_length; j++) {
                watermark[i+j] = value[j];
            }
        }
    }
}

int main(int argc, char** argv) {
    char* watermark = malloc(WATERMARK_LENGTH);
    char* image = malloc(100000);

    srand(time(NULL));
    int i;
    for (i = 0; i < WATERMARK_LENGTH; i++) {
        watermark[i] = rand() % 26 + 'a';
    }
    generate_watermark(watermark);

    printf("Watermark: %s\n", watermark);

    printf("Enter image file name: ");
    scanf("%s", image);

    FILE* fp = fopen(image, "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* file_content = malloc(file_size);
    fread(file_content, file_size, 1, fp);
    fclose(fp);

    int watermark_index = 0;
    int image_index = 0;

    while (image_index < file_size) {
        if (file_content[image_index] == watermark[watermark_index]) {
            image_index++;
            watermark_index++;
        } else if (watermark_index > 0) {
            watermark_index = 0;
        } else {
            image_index++;
        }
    }

    printf("Watermark found at position %d.\n", image_index - WATERMARK_LENGTH);

    free(watermark);
    free(image);
    free(file_content);

    return 0;
}