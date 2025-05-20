#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void saveGame(char *filename, char *data, int size) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s", data);
        fclose(file);
    }
}

void loadGame(char *filename, char *data, int size) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fgets(data, size, file);
        fclose(file);
    }
}

void playGame() {
    char data[1];
    char *filename = "save.txt";

    loadGame(filename, data, sizeof(data));

    printf("Welcome back, warrior!\n");
    printf("You have %s on you.\n", data);

    // Game logic

    saveGame(filename, data, sizeof(data));
}

int main() {
    playGame();

    // Additional game functionality

    return 0;
}
