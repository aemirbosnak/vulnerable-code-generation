#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define ROWS 10
#define COLS 784

int main() {
    int data[ROWS][COLS];
    FILE *file = fopen("dataset.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%d", &data[i][j]);
        }
    }
    
    fclose(file);
    return 0;
}
