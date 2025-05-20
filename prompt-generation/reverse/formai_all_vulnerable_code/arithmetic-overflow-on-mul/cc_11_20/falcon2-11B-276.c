//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ROOM 100
#define MAX_ROOM_SIZE 20
#define MAX_ROOM_NAME 20
#define MAX_ITEM 10
#define MAX_ITEM_NAME 20
#define MAX_ITEM_WEIGHT 5
#define MAX_ITEM_VALUE 100

typedef struct {
    char room_name[MAX_ROOM_NAME];
    int room_size[MAX_ROOM_SIZE];
    int item_count;
    char item_name[MAX_ITEM_NAME][MAX_ITEM_NAME];
    int item_weight[MAX_ITEM_WEIGHT];
    int item_value[MAX_ITEM_VALUE];
} Room;

int main() {
    srand(time(NULL));

    Room rooms[MAX_ROOM];
    int num_rooms = 0;

    printf("Welcome to the Rogue-like Game with Procedural Generation!\n");
    printf("How many rooms would you like to generate?\n");
    scanf("%d", &num_rooms);

    for (int i = 0; i < num_rooms; i++) {
        int room_size = rand() % 20 + 1;
        strcpy(rooms[i].room_name, "Room ");
        strcat(rooms[i].room_name, (char *)malloc(3 * sizeof(char)));
        int j;
        for (j = 0; j < room_size; j++) {
            int item_count = rand() % 5 + 1;
            strcpy(rooms[i].item_name[j], "Item ");
            strcat(rooms[i].item_name[j], (char *)malloc(item_count * sizeof(char)));
            rooms[i].item_count += item_count;
            rooms[i].item_weight[j] = rand() % 5 + 1;
            rooms[i].item_value[j] = rand() % 100 + 1;
        }
        rooms[i].room_size[0] = room_size;
    }

    int num_items = 0;
    int num_items_chosen = 0;
    int item_index = 0;

    while (num_items_chosen < num_rooms * 3) {
        printf("You are in Room %d.\n", item_index + 1);
        printf("What would you like to do?\n");
        printf("1. Look around\n");
        printf("2. Take an item\n");
        printf("3. Go to another room\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You see the following items:\n");
                for (int j = 0; j < rooms[item_index].item_count; j++) {
                    printf("%s (%d weight, %d value)\n", rooms[item_index].item_name[j], rooms[item_index].item_weight[j], rooms[item_index].item_value[j]);
                }
                break;
            case 2:
                printf("Which item would you like to take?\n");
                for (int j = 0; j < rooms[item_index].item_count; j++) {
                    printf("%s (%d weight, %d value)\n", rooms[item_index].item_name[j], rooms[item_index].item_weight[j], rooms[item_index].item_value[j]);
                }
                printf("Enter your choice: ");
                int item_index_chosen;
                scanf("%d", &item_index_chosen);
                if (item_index_chosen >= 0 && item_index_chosen < rooms[item_index].item_count) {
                    rooms[item_index].item_weight[item_index_chosen] -= 1;
                    rooms[item_index].item_value[item_index_chosen] += 1;
                    num_items_chosen += 1;
                    num_items -= 1;
                }
                break;
            case 3:
                printf("Which room would you like to go to?\n");
                for (int j = 0; j < num_rooms; j++) {
                    printf("%d. %s\n", j + 1, rooms[j].room_name);
                }
                printf("Enter your choice: ");
                int room_index_chosen;
                scanf("%d", &room_index_chosen);
                if (room_index_chosen >= 0 && room_index_chosen < num_rooms) {
                    item_index = room_index_chosen;
                    num_items_chosen += 1;
                    num_items -= 1;
                }
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    printf("You have collected %d items.\n", num_items);
    printf("You have chosen %d items.\n", num_items_chosen);
    printf("You have %d items left to choose.\n", num_rooms * 3 - num_items_chosen);

    return 0;
}