#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void loadLevel(int levelData[], int size) {
    int i;
    for (i = 0; i <= size; i++) { // Dereference failure here: out-of-bounds access
        levelData[i] = i * 10;
    }
}

int main() {
    int levelSize = 5;
    int levelData[5];

    printf("Loading level...\n");
    loadLevel(levelData, levelSize);

    printf("Level data:\n");
    for (int i = 0; i <= levelSize; i++) { // Dereference failure here: out-of-bounds access
        printf("%d ", levelData[i]);
    }

    return 0;
}
