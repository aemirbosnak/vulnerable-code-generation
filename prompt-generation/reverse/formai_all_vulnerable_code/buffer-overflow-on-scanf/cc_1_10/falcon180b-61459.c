//Falcon-180B DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define NUM_ITEMS 10

typedef struct {
    char name[20];
    int value;
} item;

void generate_items(item items[]) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sprintf(items[i].name, "Item %d", i + 1);
        items[i].value = rand() % 100;
    }
}

void print_items(item items[]) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%s - $%d\n", items[i].name, items[i].value);
    }
}

int main() {
    srand(time(0));

    item items[NUM_ITEMS];
    generate_items(items);

    int player_pos = 0;
    int num_items_collected = 0;

    while (num_items_collected < NUM_ITEMS) {
        system("clear");
        printf("You are in a room with %d items.\n", NUM_ITEMS);

        int choice;
        printf("What would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Collect item\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (player_pos < SIZE - 1) {
                player_pos++;
            } else {
                printf("You can't go any further.\n");
            }
            break;
        case 2:
            if (player_pos > 0) {
                player_pos--;
            } else {
                printf("You can't go any further.\n");
            }
            break;
        case 3:
            if (items[player_pos].value > 0) {
                printf("You collected %s - $%d\n", items[player_pos].name, items[player_pos].value);
                items[player_pos].value = 0;
                num_items_collected++;
            } else {
                printf("There is nothing to collect here.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
        }

        print_items(items);
    }

    printf("Congratulations! You collected all the items.\n");

    return 0;
}