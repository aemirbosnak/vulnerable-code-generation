//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *data;
    int size;
} Data;

typedef struct {
    char *header;
    int num_rows;
    int num_cols;
    Data **data;
} Table;

Table *create_table(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    char line[MAX_DATA_SIZE];
    fgets(line, MAX_DATA_SIZE, fp); // Read header line

    char *header = strdup(line);
    int num_cols = 0;
    char *token = strtok(header, ",");
    while (token!= NULL) {
        num_cols++;
        token = strtok(NULL, ",");
    }

    Table *table = (Table *)malloc(sizeof(Table));
    table->header = header;
    table->num_rows = 0;
    table->num_cols = num_cols;
    table->data = (Data **)malloc(sizeof(Data *) * num_cols);

    while (fgets(line, MAX_DATA_SIZE, fp)!= NULL) {
        table->num_rows++;
        int i = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            int size = strlen(token);
            Data *data = (Data *)malloc(sizeof(Data));
            data->data = (char *)malloc(sizeof(char) * (size + 1));
            strncpy(data->data, token, size);
            data->size = size;
            table->data[i] = data;
            i++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return table;
}

void print_table(Table *table) {
    printf("%s\n", table->header);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s\t", table->data[j]->data);
        }
        printf("\n");
    }
}

void free_table(Table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        free(table->data[i]->data);
        free(table->data[i]);
    }
    free(table->data);
    free(table->header);
    free(table);
}

int main() {
    Table *table = create_table("example.csv");
    print_table(table);
    free_table(table);

    return 0;
}