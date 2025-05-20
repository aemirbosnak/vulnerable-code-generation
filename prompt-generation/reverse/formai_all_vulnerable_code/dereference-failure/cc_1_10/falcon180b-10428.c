//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1024
#define WATERMARK_SIZE 64
#define WATERMARK_VALUE 42

void write_watermark(char* data, int size, int watermark) {
    int i;
    for (i = 0; i < size; i++) {
        if (i % WATERMARK_SIZE == 0) {
            data[i] = (char) watermark;
        } else {
            data[i] = data[i] ^ watermark;
        }
    }
}

int read_watermark(char* data, int size) {
    int i, watermark = 0;
    for (i = 0; i < size; i++) {
        if (i % WATERMARK_SIZE == 0) {
            if (data[i]!= (char) watermark) {
                return 0;
            }
        } else {
            watermark ^= data[i];
        }
    }
    return 1;
}

int main() {
    char* data = (char*) malloc(MAX_SIZE);
    int size = 0;

    printf("Enter data to be watermarked: ");
    fgets(data, MAX_SIZE, stdin);
    size = strlen(data);

    write_watermark(data, size, WATERMARK_VALUE);

    printf("Watermarked data: %s\n", data);

    if (read_watermark(data, size)) {
        printf("Watermark found!\n");
    } else {
        printf("Watermark not found.\n");
    }

    free(data);
    return 0;
}