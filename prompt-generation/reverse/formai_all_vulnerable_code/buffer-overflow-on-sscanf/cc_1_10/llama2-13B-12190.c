//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10
#define MAX_LINE_LENGTH 256

void read_file(const char *file_name, double *array) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        double value;
        if (sscanf(line, "%lf", &value) == 1) {
            array[i] = value;
            i++;
        }
    }

    fclose(file);
}

void write_file(const char *file_name, double *array) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int i = 0;
    for (; i < 10; i++) {
        fprintf(file, "%.2lf ", array[i]);
    }

    fclose(file);
}

int main() {
    double array[10];
    read_file("data.txt", array);
    // do something with the array

    write_file("output.txt", array);

    return 0;
}