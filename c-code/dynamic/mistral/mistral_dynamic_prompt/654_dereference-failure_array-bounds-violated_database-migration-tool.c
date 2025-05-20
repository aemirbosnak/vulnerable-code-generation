#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_LENGTH 255

void readData(char data[MAX_COLUMNS][MAX_LENGTH]);
void processData(char data[][MAX_LENGTH]);

int main() {
    char data[MAX_COLUMNS][MAX_LENGTH];

    readData(data);
    processData(data);

    return 0;
}

void readData(char data[MAX_COLUMNS][MAX_LENGTH]) {
    FILE *file;
    char line[MAX_LENGTH];
    int row = 0;

    file = fopen("data.txt", "r");
    while (fgets(line, sizeof(line), file)) {
        strcpy(data[row], line);
        row++;
    }
    fclose(file);
}

void processData(char data[][MAX_LENGTH]) {
    int column = 0;
    for (int i = 0; i < 10; i++) {
        printf("%s\n", data[i]);
        printf("Column %d: %c\n", column, data[i][column]); // Violates array bounds
        column++;
    }
}
