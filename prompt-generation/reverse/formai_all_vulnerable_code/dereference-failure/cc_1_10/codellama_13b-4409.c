//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
/*
 * CSV Reader
 *
 * A simple CSV reader program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_COL_LEN 100

typedef struct {
    char **data;
    int num_cols;
    int num_rows;
} csv_data_t;

int read_csv(const char *file_name, csv_data_t *data) {
    FILE *fp = fopen(file_name, "r");
    if (!fp) {
        printf("Error: Unable to open file %s\n", file_name);
        return 1;
    }

    char line[MAX_LINE_LEN];
    int num_cols = 0;
    int num_rows = 0;

    while (fgets(line, MAX_LINE_LEN, fp)) {
        char *token = strtok(line, ",");
        while (token) {
            data->data[num_cols][num_rows] = token;
            token = strtok(NULL, ",");
            num_cols++;
        }
        num_rows++;
    }

    data->num_cols = num_cols;
    data->num_rows = num_rows;

    fclose(fp);
    return 0;
}

int main(void) {
    const char *file_name = "data.csv";
    csv_data_t data;
    data.data = malloc(MAX_COL_LEN * sizeof(char *));
    for (int i = 0; i < MAX_COL_LEN; i++) {
        data.data[i] = malloc(MAX_LINE_LEN * sizeof(char));
    }

    read_csv(file_name, &data);

    for (int i = 0; i < data.num_rows; i++) {
        for (int j = 0; j < data.num_cols; j++) {
            printf("%s ", data.data[j][i]);
        }
        printf("\n");
    }

    for (int i = 0; i < MAX_COL_LEN; i++) {
        free(data.data[i]);
    }
    free(data.data);

    return 0;
}