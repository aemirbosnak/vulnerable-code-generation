#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Function to simulate loading a level from a file
void loadLevel(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    // Simulate reading data from the file
    int levelData[10];
    fread(levelData, sizeof(int), 10, file);

    fclose(file);

    // Dereference an invalid pointer to cause a crash
    int* invalidPtr = NULL;
    printf("Level Data: %d\n", *(invalidPtr + 5));
}

int main() {
    char* levelFilename = "nonexistent_level.txt";
    loadLevel(levelFilename);
    return 0;
}
