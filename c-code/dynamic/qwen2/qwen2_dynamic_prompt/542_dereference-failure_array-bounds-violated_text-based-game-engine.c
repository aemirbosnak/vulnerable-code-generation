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
    FILE *file = fopen("levels.dat", "r");
    if (!file) {
        printf("Failed to open levels file.\n");
        return;
    }

    for (int i = 0; i < MAX_LEVELS; i++) {
        levels[i].level = i + 1;
        levels[i].description = NULL;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        int level_number;
        sscanf(buffer, "%d %s", &level_number, buffer);
        if (level_number > 0 && level_number <= MAX_LEVELS) {
            levels[level_number - 1].description = strdup(buffer);
        }
    }

    fclose(file);
}

void print_level_description(int level) {
    if (level >= 1 && level <= MAX_LEVELS) {
        printf("Level %d: %s\n", level, levels[level - 1].description);
    } else {
        printf("Invalid level number.\n");
    }
}

int main() {
    load_levels();

    int choice;
    while (1) {
        printf("\nChoose a level (1-%d) or 0 to exit: ", MAX_LEVELS);
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        print_level_description(choice);
    }

    // Free allocated memory
    for (int i = 0; i < MAX_LEVELS; i++) {
        free(levels[i].description);
    }

    return 0;
}
