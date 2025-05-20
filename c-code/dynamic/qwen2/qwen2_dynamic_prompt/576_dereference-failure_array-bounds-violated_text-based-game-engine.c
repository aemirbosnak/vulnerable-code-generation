#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void loadLevel(int levelData[], int size) {
    FILE *file = fopen("level.dat", "r");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }

    for (int i = 0; i <= size; i++) { // Dereference failure here
        fscanf(file, "%d", &levelData[i]);
    }

    fclose(file);
}

int main() {
    const int MAX_LEVEL_SIZE = 100;
    int level[MAX_LEVEL_SIZE];

    loadLevel(level, MAX_LEVEL_SIZE);

    for (int i = 0; i < MAX_LEVEL_SIZE; i++) {
        printf("%d ", level[i]);
    }
    printf("\n");

    return 0;
}
