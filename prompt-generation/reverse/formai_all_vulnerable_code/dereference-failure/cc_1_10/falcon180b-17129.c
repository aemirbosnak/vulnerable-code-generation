//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char delimiter;
    char quote;
    char eol;
    int header;
} csv_config;

typedef struct {
    int row;
    int col;
    char **data;
} csv_table;

csv_table *csv_read(FILE *fp) {
    csv_table *table = malloc(sizeof(csv_table));
    table->row = 0;
    table->col = 0;
    table->data = malloc(sizeof(char *));
    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            table->col++;
            table->data = realloc(table->data, sizeof(char *) * table->col);
            table->data[table->col - 1] = malloc(strlen(token) + 1);
            strcpy(table->data[table->col - 1], token);
            table->row++;
            token = strtok(NULL, ",");
        }
    }
    return table;
}

void csv_print(csv_table *table) {
    for (int i = 0; i < table->row; i++) {
        for (int j = 0; j < table->col; j++) {
            printf("%s\t", table->data[j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[1024];
    printf("Enter the CSV file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    csv_table *table = csv_read(fp);
    csv_print(table);
    fclose(fp);
    return 0;
}