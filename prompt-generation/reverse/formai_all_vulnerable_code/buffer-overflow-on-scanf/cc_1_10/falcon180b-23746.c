//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_ITEMS 5

typedef struct {
    char name[50];
    int description[100];
    int item;
} Room;

typedef struct {
    char name[50];
    int description[100];
} Item;

Room rooms[NUM_ROOMS];
Item items[NUM_ITEMS];

void generateRooms() {
    int i;
    for(i=0; i<NUM_ROOMS; i++) {
        rooms[i].item = rand() % NUM_ITEMS;
        sprintf(rooms[i].name, "Room %d", i+1);
        sprintf(rooms[i].description, "You are in room %d. It is dark and spooky.", i+1);
    }
}

void generateItems() {
    int i;
    for(i=0; i<NUM_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].description[0] = '\0';
    }
}

int main() {
    srand(time(NULL));
    generateRooms();
    generateItems();

    int choice;
    while(1) {
        printf("What would you like to do?\n");
        printf("1. Move to another room\n");
        printf("2. Search for an item\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            int roomNum;
            printf("Which room would you like to move to?\n");
            scanf("%d", &roomNum);

            if(roomNum >= 1 && roomNum <= NUM_ROOMS) {
                printf("You are now in room %d.\n", roomNum);
            } else {
                printf("Invalid room number.\n");
            }
        } else if(choice == 2) {
            int itemNum;
            printf("Which item would you like to search for?\n");
            scanf("%d", &itemNum);

            if(itemNum >= 1 && itemNum <= NUM_ITEMS) {
                if(items[itemNum-1].name[0] == '\0') {
                    printf("You found %s!\n", items[itemNum-1].name);
                    items[itemNum-1].name[0] = '\0';
                } else {
                    printf("You did not find anything.\n");
                }
            } else {
                printf("Invalid item number.\n");
            }
        } else if(choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}