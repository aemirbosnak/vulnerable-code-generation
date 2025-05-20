//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
// CSV Reader Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_COL_LEN 64

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSVData;

CSVData read_csv(const char *file_name) {
    CSVData data = {0};
    char line[MAX_LINE_LEN];
    char *token;
    int row = 0;
    int col = 0;
    int num_cols = 0;

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file_name);
        return data;
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        if (row == 0) {
            num_cols = 0;
            token = strtok(line, ",");
            while (token != NULL) {
                num_cols++;
                token = strtok(NULL, ",");
            }
            data.num_cols = num_cols;
            data.num_rows = 1;
            data.data = malloc(num_cols * sizeof(char *));
            for (int i = 0; i < num_cols; i++) {
                data.data[i] = malloc(MAX_COL_LEN * sizeof(char));
            }
        }
        row++;
        col = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            strcpy(data.data[col], token);
            col++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return data;
}

void print_csv(CSVData data) {
    for (int row = 0; row < data.num_rows; row++) {
        for (int col = 0; col < data.num_cols; col++) {
            printf("%s,", data.data[col][row]);
        }
        printf("\n");
    }
}

int main() {
    CSVData data = read_csv("data.csv");
    print_csv(data);
    return 0;
}