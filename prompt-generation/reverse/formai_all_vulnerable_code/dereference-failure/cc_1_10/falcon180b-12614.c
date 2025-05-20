//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 256
#define DATA_SIZE 1024

typedef struct {
    int size;
    int *data;
} Watermark;

typedef struct {
    int size;
    int *data;
} Data;

void generate_watermark(Watermark *watermark) {
    watermark->size = WATERMARK_SIZE;
    watermark->data = malloc(WATERMARK_SIZE * sizeof(int));
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark->data[i] = rand() % 256;
    }
}

void generate_data(Data *data) {
    data->size = DATA_SIZE;
    data->data = malloc(DATA_SIZE * sizeof(int));
    for (int i = 0; i < DATA_SIZE; i++) {
        data->data[i] = rand() % 256;
    }
}

void embed_watermark(Watermark *watermark, Data *data) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        data->data[i] ^= watermark->data[i];
    }
}

void extract_watermark(Watermark *watermark, Data *data) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark->data[i] = data->data[i] ^ watermark->data[i];
    }
}

int main() {
    Watermark watermark;
    Data data;

    generate_watermark(&watermark);
    generate_data(&data);

    printf("Original data:\n");
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%d ", data.data[i]);
    }

    embed_watermark(&watermark, &data);

    printf("\nWatermarked data:\n");
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%d ", data.data[i]);
    }

    extract_watermark(&watermark, &data);

    printf("\nExtracted watermark:\n");
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        printf("%d ", watermark.data[i]);
    }

    return 0;
}