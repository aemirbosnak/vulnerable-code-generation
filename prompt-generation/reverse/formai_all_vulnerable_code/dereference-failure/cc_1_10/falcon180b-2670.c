//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_DATA 1000

typedef struct {
    char *data[MAX_DATA];
    int row;
    int col;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp;
    CSV *csv;
    char line[MAX_ROW];
    char *token;

    csv = (CSV*)malloc(sizeof(CSV));
    if (csv == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        exit(1);
    }

    csv->row = 0;
    csv->col = 0;

    while (fgets(line, MAX_ROW, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            csv->data[csv->row * MAX_COL + csv->col++] = strdup(token);
            if (csv->col == MAX_COL) {
                csv->col = 0;
                csv->row++;
            }
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i * MAX_COL + j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            free(csv->data[i * MAX_COL + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv;
    int choice;

    csv = csv_open("example.csv");
    csv_print(csv);

    do {
        printf("1. Print CSV\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                csv_print(csv);
                break;
            case 2:
                csv_close(csv);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}