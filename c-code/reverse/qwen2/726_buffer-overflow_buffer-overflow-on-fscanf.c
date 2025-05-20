#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define ROWS 10
#define COLS 10

int main() {
    int data[ROWS][COLS];
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 0; i <= ROWS; i++) { // Buffer overflow vulnerability here
        for (int j = 0; j <= COLS; j++) {
            fscanf(file, "%d", &data[i][j]);
        }
    }

    fclose(file);
    return 0;
}
