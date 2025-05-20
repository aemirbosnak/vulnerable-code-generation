#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVELS 10

typedef struct {
    int level;
    char *description;
} Level;

Level levels[MAX_LEVELS];

void load_levels() {
    FILE *file = fopen("levels.txt", "r");
    if (!file) {
        perror("Failed to open levels file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_LEVELS; i++) {
        levels[i].level = i + 1;
        levels[i].description = NULL;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        int level;
        sscanf(buffer, "%d %s", &level, buffer);
        if (level > 0 && level <= MAX_LEVELS) {
            levels[level - 1].description = strdup(buffer);
        }
    }

    fclose(file);
}

void print_level_description(int level) {
    if (level > 0 && level <= MAX_LEVELS) {
        printf("Level %d: %s\n", level, levels[level - 1].description);
    } else {
        printf("Invalid level number\n");
    }
}

int main() {
    load_levels();

    int choice;
    while (1) {
        printf("Enter level number (1-%d) or 0 to quit: ", MAX_LEVELS);
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        print_level_description(choice);
    }

    for (int i = 0; i < MAX_LEVELS; i++) {
        free(levels[i].description);
    }

    return 0;
}
