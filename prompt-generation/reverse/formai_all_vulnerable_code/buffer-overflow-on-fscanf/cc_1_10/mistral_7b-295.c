//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE (1024 * 16)

typedef struct {
    int id;
    double value;
} DataPoint;

int read_file(const char *filename, DataPoint **data, size_t *num_data) {
    FILE *fp;
    size_t capacity = BUFFER_SIZE / sizeof(DataPoint);
    size_t num_read = 0;
    DataPoint *buffer;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    buffer = malloc(capacity * sizeof(DataPoint));
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return 1;
    }

    while (fscanf(fp, "%d %lf", &(buffer[num_read].id), &(buffer[num_read].value)) != EOF) {
        num_read++;
        if (num_read >= capacity) {
            capacity *= 2;
            DataPoint *new_buffer = realloc(buffer, capacity * sizeof(DataPoint));
            if (new_buffer == NULL) {
                perror("Error reallocating memory");
                free(buffer);
                fclose(fp);
                return 1;
            }
            buffer = new_buffer;
        }
    }

    fclose(fp);

    *data = buffer;
    *num_data = num_read;

    return 0;
}

void process_data(DataPoint *data, size_t num_data) {
    clock_t start, end;
    double sum = 0.0;

    start = clock();

    for (size_t i = 0; i < num_data; i++) {
        sum += data[i].value;
    }

    end = clock();

    printf("Sum of all data values: %.2f\n", sum);
    printf("Processing time: %.6fs\n", (end - start) / (double)CLOCKS_PER_SEC);
}

int main() {
    DataPoint *data;
    size_t num_data;

    int status = read_file("large_data.txt", &data, &num_data);
    if (status != 0) {
        perror("Error reading file");
        return 1;
    }

    process_data(data, num_data);

    free(data);

    return 0;
}