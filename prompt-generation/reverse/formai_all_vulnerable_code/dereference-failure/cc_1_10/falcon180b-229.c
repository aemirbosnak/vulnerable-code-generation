//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = NULL;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int num_tokens = 0;

        while (token!= NULL) {
            num_tokens++;
            token = strtok(NULL, ",");
        }

        if (csv->num_rows == 0) {
            csv->num_cols = num_tokens;
            csv->data = malloc(sizeof(char *) * csv->num_cols);
            for (int i = 0; i < csv->num_cols; i++) {
                csv->data[i] = malloc(MAX_LINE_SIZE);
            }
        } else if (num_tokens!= csv->num_cols) {
            printf("Error: inconsistent number of columns\n");
            exit(1);
        }

        for (int i = 0; i < num_tokens; i++) {
            strcpy(csv->data[i], token);
        }

        csv->num_rows++;
    }

    fclose(fp);

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        exit(1);
    }

    CSV *csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);

    return 0;
}