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
} Room;

Room levels[MAX_LEVELS];

void load_levels() {
    levels[0].level = 1;
    levels[0].description = "You are in the entrance hall.";
    levels[1].level = 2;
    levels[1].description = "You are in the library.";
    levels[2].level = 3;
    levels[2].description = "You are in the kitchen.";
    levels[3].level = 4;
    levels[3].description = "You are in the garden.";
    levels[4].level = 5;
    levels[4].description = "You are in the basement.";
    levels[5].level = 6;
    levels[5].description = "You are in the attic.";
    levels[6].level = 7;
    levels[6].description = "You are in the garage.";
    levels[7].level = 8;
    levels[7].description = "You are in the cellar.";
    levels[8].level = 9;
    levels[8].description = "You are in the study.";
    levels[9].level = 10;
    levels[9].description = "You are in the vault.";
}

void print_level_description(int current_level) {
    if (current_level >= 0 && current_level < MAX_LEVELS) {
        printf("Level %d: %s\n", levels[current_level].level, levels[current_level].description);
    } else {
        printf("Error: Invalid level number.\n");
    }
}

int main() {
    load_levels();
    int current_level = 5;
    print_level_description(current_level);

    // Intentional dereference failure
    int next_level = 10;
    print_level_description(next_level); // This will cause an array bounds violation

    return 0;
}
