//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    int i;
    for (i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_read(CSV *csv, FILE *fp) {
    char line[MAX_LINE_SIZE];
    char *token;
    int i = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        if (i == 0) {
            csv->num_cols = 0;
            while (token!= NULL) {
                csv->num_cols++;
                token = strtok(NULL, ",");
            }
            csv->data = (char **) malloc(csv->num_cols * sizeof(char *));
        } else {
            csv->data[i - 1] = (char *) malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csv->data[i - 1], token);
        }
        i++;
    }
    csv->num_rows = i - 1;
    return 0;
}

int csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i * csv->num_cols + j]);
        }
        printf("\n");
    }
    return 0;
}

int main(int argc, char **argv) {
    FILE *fp;
    CSV *csv;
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    csv = csv_create();
    csv_read(csv, fp);
    fclose(fp);
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}