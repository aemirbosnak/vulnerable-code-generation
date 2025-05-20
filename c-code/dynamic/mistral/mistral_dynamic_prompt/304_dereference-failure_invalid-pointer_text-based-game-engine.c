#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_level(char* level_data) {
    char* room = malloc(strlen(level_data) * sizeof(char));
    strcpy(room, level_data);

    char* cursor = room;

    while (*cursor) {
        if (*cursor == 'E') {
            printf("You found the exit!\n");
            exit(0);
        }

        if (*cursor == 'M') {
            printf("Monster attack!\n");
            // Monster AI goes here...
        }

        if (*cursor == 'I') {
            printf("You found an item!\n");
            // Item usage goes here...
        }

        cursor++;
    }
}

int main() {
    char level_data[] = "IMSMMMMEEEE";

    load_level(level_data);

    return 0;
}
