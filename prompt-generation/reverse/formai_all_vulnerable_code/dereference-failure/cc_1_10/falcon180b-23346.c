//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct csv_data {
    char **rows;
    int num_rows;
    int num_cols;
};

struct csv_data read_csv(FILE *file);
void print_csv(struct csv_data data);
void free_csv_data(struct csv_data data);

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    struct csv_data data = read_csv(file);
    print_csv(data);
    free_csv_data(data);

    fclose(file);
    return 0;
}

struct csv_data read_csv(FILE *file) {
    struct csv_data data = {NULL, 0, 0};
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        int num_cols = 0;

        while (token!= NULL) {
            num_cols++;
            token = strtok(NULL, ",");
        }

        if (num_cols > data.num_cols) {
            data.num_cols = num_cols;
        }

        data.num_rows++;
        data.rows = realloc(data.rows, sizeof(char *) * data.num_rows);
        data.rows[data.num_rows - 1] = strdup(line);
    }

    return data;
}

void print_csv(struct csv_data data) {
    for (int i = 0; i < data.num_rows; i++) {
        for (int j = 0; j < data.num_cols; j++) {
            printf("%s ", data.rows[i]);
        }
        printf("\n");
    }
}

void free_csv_data(struct csv_data data) {
    for (int i = 0; i < data.num_rows; i++) {
        free(data.rows[i]);
    }
    free(data.rows);
}