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
        if (levels[level - 1].description) {
            printf("Level %d: %s\n", level, levels[level - 1].description);
        } else {
            printf("No description available for level %d.\n", level);
        }
    } else {
        printf("Invalid level number.\n");
    }
}

int main() {
    load_levels();

    int choice;
    while (1) {
        printf("\nText-Based Game Engine\n");
        printf("1. Load Levels\n");
        printf("2. Print Level Description\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                load_levels();
                break;
            case 2:
                printf("Enter level number: ");
                int level;
                scanf("%d", &level);
                print_level_description(level);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
