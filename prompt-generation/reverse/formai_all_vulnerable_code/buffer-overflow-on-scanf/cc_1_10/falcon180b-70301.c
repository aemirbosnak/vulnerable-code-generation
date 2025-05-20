//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024
#define WATERMARK_SIZE 16

void embed_watermark(unsigned char *image, unsigned char *watermark) {
    int i, j, k, l, m, n, p, q, r, s;
    unsigned char *temp = (unsigned char *)malloc(MAX_SIZE);
    int watermark_size = strlen((char *)watermark);

    if (watermark_size > WATERMARK_SIZE) {
        printf("Watermark size exceeds maximum limit\n");
        exit(0);
    }

    for (i = 0; i < watermark_size; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (image[j] == watermark[i]) {
                temp[j] = image[j] - 32;
            } else {
                temp[j] = image[j];
            }
        }
        for (k = 0; k < MAX_SIZE; k++) {
            image[k] = temp[k];
        }
    }

    free(temp);
}

void extract_watermark(unsigned char *image) {
    int i, j, k, l, m, n, p, q, r, s;
    unsigned char watermark[WATERMARK_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        if (image[i] >= 32 && image[i] <= 126) {
            for (j = 0; j < WATERMARK_SIZE; j++) {
                if (image[i] == (unsigned char)(65 + j)) {
                    watermark[j] = image[i];
                    break;
                }
            }
        }
    }

    printf("Watermark: %s\n", (char *)watermark);
}

int main() {
    unsigned char image[MAX_SIZE], watermark[WATERMARK_SIZE];
    int i, choice;

    printf("Enter the image file name: ");
    scanf("%s", image);

    printf("Enter the watermark file name: ");
    scanf("%s", watermark);

    printf("Enter 1 to embed watermark or 2 to extract watermark: ");
    scanf("%d", &choice);

    if (choice == 1) {
        embed_watermark(image, watermark);
        printf("Watermark embedded successfully!\n");
    } else if (choice == 2) {
        extract_watermark(image);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}