//Code Llama-13B DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

void add_watermark(char *data, char *watermark) {
    int i, j;
    for (i = 0; i < strlen(data); i++) {
        data[i] += watermark[i % strlen(watermark)];
    }
}

void remove_watermark(char *data, char *watermark) {
    int i, j;
    for (i = 0; i < strlen(data); i++) {
        data[i] -= watermark[i % strlen(watermark)];
    }
}

int main() {
    char data[MAX_LENGTH];
    char watermark[MAX_LENGTH];
    int choice;

    printf("Enter the data to be watermarked: ");
    fgets(data, MAX_LENGTH, stdin);
    printf("Enter the watermark: ");
    fgets(watermark, MAX_LENGTH, stdin);

    printf("1. Add watermark\n");
    printf("2. Remove watermark\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_watermark(data, watermark);
            break;
        case 2:
            remove_watermark(data, watermark);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("Modified data: %s\n", data);

    return 0;
}