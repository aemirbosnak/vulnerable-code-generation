//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_load(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Couldn't open file %s\n", filename);
        return NULL;
    }

    csv_t *csv = malloc(sizeof(csv_t));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (feof(fp)) {
            break;
        }

        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        char *line = strdup(buffer);
        char *token = strtok(line, ",");
        while (token) {
            csv->cols++;
            token = strtok(NULL, ",");
        }

        csv->rows++;
        csv->data = realloc(csv->data, sizeof(char *) * csv->rows);
        csv->data[csv->rows - 1] = line;
    }

    fclose(fp);

    return csv;
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }

    free(csv->data);
    free(csv);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    csv_t *csv = csv_load(argv[1]);
    if (!csv) {
        return 1;
    }

    printf("Loaded CSV file with %d rows and %d columns\n", csv->rows, csv->cols);

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }

        printf("\n");
    }

    csv_free(csv);

    return 0;
}