//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024
#define WATERMARK "SURPRISE"

void embed_watermark(char* filename) {
    FILE* fp;
    char buffer[SIZE], c;
    int i, count, watermark_index = 0;

    fp = fopen(filename, "r+");

    if (fp == NULL) {
        printf("Unable to open file!");
        exit(1);
    }

    i = 0;
    count = 0;

    while ((c = fgetc(fp)) != EOF && count < SIZE) {
        buffer[i++] = c;

        if (c == WATERMARK[watermark_index]) {
            watermark_index++;

            if (watermark_index == strlen(WATERMARK)) {
                // Embed the watermark in the file
                fprintf(fp, "%s", WATERMARK);
                break;
            }
        } else {
            watermark_index = 0;
        }

        if (i == SIZE) {
            // Reset the buffer
            for (int j = 0; j < SIZE; j++) {
                buffer[j] = 0;
            }
            i = 0;
        }

        count++;
    }

    fclose(fp);

    if (watermark_index == strlen(WATERMARK)) {
        printf("Watermark embedded successfully!\n");
    } else {
        printf("Unable to embed watermark!\n");
    }
}

void extract_watermark(char* filename) {
    FILE* fp;
    char buffer[SIZE], c;
    int i, count, watermark_index = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file!");
        exit(1);
    }

    i = 0;
    count = 0;

    while ((c = fgetc(fp)) != EOF && count < SIZE) {
        buffer[i++] = c;

        if (c == WATERMARK[watermark_index]) {
            watermark_index++;

            if (watermark_index == strlen(WATERMARK)) {
                // Watermark found!
                printf("Watermark found in file: %s\n", filename);
                break;
            }
        } else {
            watermark_index = 0;
        }

        if (i == SIZE) {
            // Reset the buffer
            for (int j = 0; j < SIZE; j++) {
                buffer[j] = 0;
            }
            i = 0;
        }

        count++;
    }

    fclose(fp);

    if (watermark_index != strlen(WATERMARK)) {
        printf("Watermark not found in file: %s\n", filename);
    }
}

int main() {
    char filename[100];

    printf("Enter the name of the file to embed watermark: ");
    scanf("%s", filename);

    embed_watermark(filename);

    printf("Enter the name of the file to extract watermark: ");
    scanf("%s", filename);

    extract_watermark(filename);

    return 0;
}