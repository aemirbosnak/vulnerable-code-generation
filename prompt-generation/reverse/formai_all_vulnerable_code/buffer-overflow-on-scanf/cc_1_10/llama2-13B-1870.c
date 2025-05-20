//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 1024
#define MAX_ITEMS 10

typedef struct {
    char name[50];
    char desc[100];
    int weight;
    int value;
} item_t;

typedef struct {
    char name[50];
    char desc[100];
    int weight;
    int value;
} ship_part_t;

 ship_part_t ship_parts[MAX_ITEMS];
 item_t items[MAX_ITEMS];
 int current_item;
 int current_ship_part;
 int repair_progress;
 int escape_progress;

 void init_game() {
    current_item = 0;
    current_ship_part = 0;
    repair_progress = 0;
    escape_progress = 0;
 }

 void print_game_state() {
    printf("You are on the alien planet of %s\n", items[current_item].name);
    printf("Your current ship part is %s\n", ship_parts[current_ship_part].name);
    printf("Repair progress: %d/%d\n", repair_progress, items[current_item].weight);
    printf("Escape progress: %d/%d\n", escape_progress, ship_parts[current_ship_part].weight);
 }

 void pick_item() {
    int chosen_item = -1;
    printf("Available items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].weight > 0) {
            printf(" %s (%d lbs)", items[i].name, items[i].weight);
            if (chosen_item == -1) {
                chosen_item = i;
            }
        }
    }
    printf("\nChoose an item: ");
    scanf("%d", &chosen_item);
    current_item = chosen_item;
 }

 void pick_ship_part() {
    int chosen_ship_part = -1;
    printf("Available ship parts:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (ship_parts[i].weight > 0) {
            printf(" %s (%d lbs)", ship_parts[i].name, ship_parts[i].weight);
            if (chosen_ship_part == -1) {
                chosen_ship_part = i;
            }
        }
    }
    printf("\nChoose a ship part: ");
    scanf("%d", &chosen_ship_part);
    current_ship_part = chosen_ship_part;
 }

 void repair_ship() {
    int progress = 0;
    while (progress < repair_progress) {
        printf("You are repairing the ship...\n");
        progress++;
    }
    repair_progress = 0;
 }

 void escape_planet() {
    int progress = 0;
    while (progress < escape_progress) {
        printf("You are escaping the planet...\n");
        progress++;
    }
    escape_progress = 0;
 }

 int main() {
    init_game();

    while (1) {
        print_game_state();

        char command[MAX_INPUT];
        printf("Enter a command (p for pick item, s for pick ship part, r for repair ship, e for escape planet): ");
        scanf("%s", command);

        if (strcmp(command, "p") == 0) {
            pick_item();
        } else if (strcmp(command, "s") == 0) {
            pick_ship_part();
        } else if (strcmp(command, "r") == 0) {
            repair_ship();
        } else if (strcmp(command, "e") == 0) {
            escape_planet();
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
 }