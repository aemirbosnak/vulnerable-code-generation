#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void loadGame(char* filename) {
    char buffer[100];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Loading game from %s...\n", filename);
    fscanf(file, "%99s", buffer); // Vulnerable line: no check for buffer size
    fclose(file);
    printf("Loaded game: %s\n", buffer);
}

int main() {
    char filename[256];
    printf("Enter the game file to load: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character
    loadGame(filename);
    return 0;
}
