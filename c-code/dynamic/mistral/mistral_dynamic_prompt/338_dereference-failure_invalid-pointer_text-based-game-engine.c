#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void loadLevel(char** levelData, int* levelSize) {
    char* fileName = "level_data.txt";
    FILE* file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return;
    }

    fscanf(file, "%d", levelSize);
    *levelData = (char*) malloc(*levelSize * sizeof(char));

    fgets(*levelData, *levelSize, file);
    fclose(file);
}

void gameLoop() {
    int levelSize;
    char* levelData;
    loadLevel(&levelData, &levelSize);

    // Game logic here, using levelData and levelSize
    // ...

    // Invalid pointer dereference example
    printf("Player position: %c\n", levelData[levelSize]);
}

int main() {
    gameLoop();
    return 0;
}
