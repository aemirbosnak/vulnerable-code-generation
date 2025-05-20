//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_LINES 100

typedef struct CSVReader {
    char data[MAX_LINES][MAX_COLS][100];
    int nrows;
    int ncols;
} CSVReader;

CSVReader* read_csv(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file\n");
        return NULL;
    }

    CSVReader* reader = (CSVReader*) malloc(sizeof(CSVReader));

    char line[1000];
    int col_count = 0;
    int row_count = 0;

    while (fgets(line, 1000, fp)) {
        char* token = strtok(line, ",");
        while (token) {
            strcpy(reader->data[row_count][col_count++], token);
            token = strtok(NULL, ",");
        }
        row_count++;
        col_count = 0;
    }

    reader->nrows = row_count;
    reader->ncols = col_count;

    fclose(fp);

    return reader;
}

int main() {
    printf("Enter filename: ");
    char filename[100];
    scanf("%s", filename);

    CSVReader* reader = read_csv(filename);
    if (!reader) {
        return 1;
    }

    printf("Data:\n");
    for (int i = 0; i < reader->nrows; i++) {
        for (int j = 0; j < reader->ncols; j++) {
            printf("%s\t", reader->data[i][j]);
        }
        printf("\n");
    }

    free(reader);

    return 0;
}