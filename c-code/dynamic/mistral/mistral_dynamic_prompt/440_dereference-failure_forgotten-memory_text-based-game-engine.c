#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void game() {
    char *map = malloc(sizeof(char) * 10);
    char input[10];

    strcpy(map, "Start,Wall,Wall,Treasure,Wall,Wall,Wall,Wall,Wall,End");

    int x = 0;
    while (1) {
        printf("You are at position %d. Your map: %s\n", x, map);
        printf("Enter direction: right, left, up, down\n");
        scanf("%s", input);

        if (strcmp(input, "right") == 0 && map[x + 1] != '\0') {
            x++;
        } else if (strcmp(input, "left") == 0 && x > 0) {
            x--;
        } else if (strcmp(input, "up") == 0 && x > 0) {
            char temp[10];
            strcpy(temp, map);
            strcpy(map, &temp[sizeof(char) * (x - 1)]);
            x--;
        } else if (strcmp(input, "down") == 0 && x < 9) {
            char temp[10];
            strcpy(temp, map);
            strcpy(&map[sizeof(char) * (x + 1)], temp + sizeof(char) * x);
            x++;
        } else {
            printf("Invalid input. Try again.\n");
        }

        if (map[x] == 'T') {
            printf("Congratulations! You found the treasure.\n");
            break;
        }
    }
}

int main() {
    game();
    return 0;
}
