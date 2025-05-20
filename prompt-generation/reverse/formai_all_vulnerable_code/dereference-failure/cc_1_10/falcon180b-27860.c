//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL_LEN 100

typedef struct {
    char **values;
    int rows;
    int cols;
} csv_data;

csv_data* read_csv(FILE *file) {
    csv_data *data = malloc(sizeof(csv_data));
    data->values = malloc(MAX_ROWS * sizeof(char*));
    data->rows = 0;
    data->cols = 0;

    char line[MAX_VAL_LEN];
    while (fgets(line, MAX_VAL_LEN, file)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            data->values[data->rows] = malloc(strlen(token) + 1);
            strcpy(data->values[data->rows], token);
            data->rows++;
            cols++;
            token = strtok(NULL, ",");
        }
        data->cols = cols;
    }

    return data;
}

void print_csv(csv_data *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            printf("%s ", data->values[i]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    csv_data *data = read_csv(file);
    if (data == NULL) {
        printf("Error reading CSV data\n");
        return 1;
    }

    print_csv(data);

    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            free(data->values[i]);
        }
        free(data->values[i]);
    }
    free(data->values);
    free(data);

    fclose(file);
    return 0;
}