//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_CSV_SIZE 1000000

struct CSV_Data {
    char **data;
    int rows;
    int cols;
};

void read_csv(char *filename, struct CSV_Data *csv_data) {
    FILE *fp;
    char line[MAX_CSV_SIZE];
    char delimiter;
    int row = 0;
    int col = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    fgets(line, MAX_CSV_SIZE, fp);
    sscanf(line, "%c", &delimiter);

    csv_data->data = malloc(MAX_ROW * sizeof(char *));
    csv_data->rows = 0;
    csv_data->cols = 0;

    while (fgets(line, MAX_CSV_SIZE, fp)!= NULL) {
        row++;
        csv_data->rows++;

        char *token = strtok(line, ",");
        while (token!= NULL) {
            col++;
            csv_data->cols = col > csv_data->cols? col : csv_data->cols;

            csv_data->data[row] = realloc(csv_data->data[row], csv_data->cols * sizeof(char *));
            csv_data->data[row][col - 1] = strdup(token);

            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
}

void print_csv(struct CSV_Data *csv_data) {
    int i, j;

    for (i = 0; i < csv_data->rows; i++) {
        for (j = 0; j < csv_data->cols; j++) {
            printf("%s\t", csv_data->data[i][j]);
        }
        printf("\n");
    }
}

void free_csv(struct CSV_Data *csv_data) {
    int i, j;

    for (i = 0; i < csv_data->rows; i++) {
        for (j = 0; j < csv_data->cols; j++) {
            free(csv_data->data[i][j]);
        }
        free(csv_data->data[i]);
    }
    free(csv_data->data);
}

int main() {
    char filename[100];
    printf("Enter the CSV file name: ");
    scanf("%s", filename);

    struct CSV_Data csv_data;
    read_csv(filename, &csv_data);
    print_csv(&csv_data);
    free_csv(&csv_data);

    return 0;
}