#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void loadGame() {
    char filename[256];
    printf("Enter the game file name: ");
    fscanf(stdin, "%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    // Simulate loading game data
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main() {
    printf("Welcome to the Text-Based Game Engine!\n");
    loadGame();
    return 0;
}
