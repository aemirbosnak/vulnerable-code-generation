//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WATERMARK_SIZE 100
#define MAX_FILE_SIZE 1000000

int main() {
    char file_name[100];
    char watermark[MAX_WATERMARK_SIZE];
    FILE *fp;
    char data[MAX_FILE_SIZE];
    int watermark_pos, file_pos, watermark_len, file_len;
    int i, j;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fread(data, 1, MAX_FILE_SIZE, fp);
    fclose(fp);

    file_len = strlen(data);

    printf("Enter the watermark: ");
    fgets(watermark, MAX_WATERMARK_SIZE, stdin);
    watermark_len = strlen(watermark);

    watermark_pos = 0;

    while (watermark_pos < file_len) {
        for (i = 0; i < watermark_len; i++) {
            if (tolower(data[watermark_pos + i]) == tolower(watermark[i])) {
                file_pos = watermark_pos + i;
                break;
            }
        }

        if (i == watermark_len) {
            printf("Error: Watermark not found in file.\n");
            return 1;
        }

        for (j = 0; j < watermark_len; j++) {
            data[file_pos + j] = watermark[j];
        }

        watermark_pos += watermark_len;
    }

    printf("Watermark successfully embedded.\n");

    return 0;
}