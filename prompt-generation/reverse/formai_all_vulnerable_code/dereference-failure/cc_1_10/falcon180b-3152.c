//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1024
#define WATERMARK_SIZE 64
#define WATERMARK_VALUE 0.5

typedef struct {
    int size;
    double *data;
} Signal;

typedef struct {
    int size;
    double *data;
} Watermark;

Signal *read_signal_from_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    Signal *signal = malloc(sizeof(Signal));
    signal->size = size;
    signal->data = malloc(size * sizeof(double));

    fread(signal->data, sizeof(double), size, file);

    fclose(file);

    return signal;
}

Watermark *create_watermark(int size) {
    Watermark *watermark = malloc(sizeof(Watermark));
    watermark->size = size;
    watermark->data = malloc(size * sizeof(double));

    for (int i = 0; i < size; i++) {
        watermark->data[i] = WATERMARK_VALUE;
    }

    return watermark;
}

void embed_watermark(Signal *signal, Watermark *watermark) {
    int signal_size = signal->size;
    int watermark_size = watermark->size;

    if (watermark_size > signal_size) {
        printf("Watermark size is larger than signal size\n");
        exit(1);
    }

    double alpha = WATERMARK_VALUE / watermark_size;

    for (int i = 0; i < watermark_size; i++) {
        signal->data[i] += alpha * watermark->data[i];
    }
}

void save_watermarked_signal_to_file(Signal *signal, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fwrite(signal->data, sizeof(double), signal->size, file);

    fclose(file);
}

int main() {
    Signal *signal = read_signal_from_file("signal.dat");
    Watermark *watermark = create_watermark(WATERMARK_SIZE);

    embed_watermark(signal, watermark);

    save_watermarked_signal_to_file(signal, "watermarked_signal.dat");

    free(signal->data);
    free(signal);

    free(watermark->data);
    free(watermark);

    return 0;
}