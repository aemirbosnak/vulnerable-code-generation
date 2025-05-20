//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 100
#define MAX_WALL 100
#define MAX_ITEM 50

#define TRUE 1
#define FALSE 0

typedef struct {
    char name[20];
    int x, y, z;
    int width, height, depth;
    int isOpen;
    int isLight;
    int isDoor;
    int isStair;
} room;

typedef struct {
    char name[20];
    int x, y, z;
    int width, height, depth;
} wall;

typedef struct {
    char name[20];
    int x, y, z;
} item;

room rooms[MAX_ROOM];
wall walls[MAX_WALL];
item items[MAX_ITEM];

int main() {
    int i, j, k, choice;
    char input[100];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please choose an option:\n");
    printf("1. Add a room\n");
    printf("2. Add a wall\n");
    printf("3. Add an item\n");
    printf("4. Remove a room\n");
    printf("5. Remove a wall\n");
    printf("6. Remove an item\n");
    printf("7. List all rooms\n");
    printf("8. List all walls\n");
    printf("9. List all items\n");
    printf("10. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Add a room:\n");
                printf("Enter room name: ");
                scanf("%s", input);
                for (i = 0; i < MAX_ROOM; i++) {
                    if (strcmp(input, rooms[i].name) == 0) {
                        printf("Room %s already exists!\n", input);
                        break;
                    }
                }
                if (i == MAX_ROOM) {
                    strcpy(rooms[i].name, input);
                    printf("Room %s added!\n", input);
                }
                break;
            case 2:
                printf("Add a wall:\n");
                printf("Enter wall name: ");
                scanf("%s", input);
                for (i = 0; i < MAX_WALL; i++) {
                    if (strcmp(input, walls[i].name) == 0) {
                        printf("Wall %s already exists!\n", input);
                        break;
                    }
                }
                if (i == MAX_WALL) {
                    strcpy(walls[i].name, input);
                    printf("Wall %s added!\n", input);
                }
                break;
            case 3:
                printf("Add an item:\n");
                printf("Enter item name: ");
                scanf("%s", input);
                for (i = 0; i < MAX_ITEM; i++) {
                    if (strcmp(input, items[i].name) == 0) {
                        printf("Item %s already exists!\n", input);
                        break;
                    }
                }
                if (i == MAX_ITEM) {
                    strcpy(items[i].name, input);
                    printf("Item %s added!\n", input);
                }
                break;
            case 4:
                printf("Remove a room:\n");
                printf("Enter room name: ");
                scanf("%s", input);
                for (i = 0; i < MAX_ROOM; i++) {
                    if (strcmp(input, rooms[i].name) == 0) {
                        for (j = i; j < MAX_ROOM - 1; j++) {
                            strcpy(rooms[j].name, rooms[j + 1].name);
                        }
                        strcpy(rooms[MAX_ROOM - 1].name, "");
                        printf("Room %s removed!\n", input);
                        break;
                    }
                }
                break;
            case 5:
                printf("Remove a wall:\n");
                printf("Enter wall name: ");
                scanf("%s", input);
                for (i = 0; i < MAX_WALL; i++) {
                    if (strcmp(input, walls[i].name) == 0) {
                        for (j = i; j < MAX_WALL - 1; j++) {
                            strcpy(walls[j].name, walls[j + 1].name);
                        }
                        strcpy(walls[MAX_WALL - 1].name, "");
                        printf("Wall %s removed!\n", input);
                        break;
                    }
                }
                break;
            case 6:
                printf("Remove an item:\n");
                printf("Enter item name: ");
                scanf("%s", input);
                for (i = 0; i < MAX_ITEM; i++) {
                    if (strcmp(input, items[i].name) == 0) {
                        for (j = i; j < MAX_ITEM - 1; j++) {
                            strcpy(items[j].name, items[j + 1].name);
                        }
                        strcpy(items[MAX_ITEM - 1].name, "");
                        printf("Item %s removed!\n", input);
                        break;
                    }
                }
                break;
            case 7:
                printf("List all rooms:\n");
                for (i = 0; i < MAX_ROOM; i++) {
                    printf("Room %s:\n", rooms[i].name);
                    printf("x = %d, y = %d, z = %d\n", rooms[i].x, rooms[i].y, rooms[i].z);
                    printf("width = %d, height = %d, depth = %d\n", rooms[i].width, rooms[i].height, rooms[i].depth);
                    printf("isOpen = %d, isLight = %d, isDoor = %d, isStair = %d\n", rooms[i].isOpen, rooms[i].isLight, rooms[i].isDoor, rooms[i].isStair);
                    printf("\n");
                }
                break;
            case 8:
                printf("List all walls:\n");
                for (i = 0; i < MAX_WALL; i++) {
                    printf("Wall %s:\n", walls[i].name);
                    printf("x = %d, y = %d, z = %d\n", walls[i].x, walls[i].y, walls[i].z);
                    printf("width = %d, height = %d, depth = %d\n", walls[i].width, walls[i].height, walls[i].depth);
                    printf("\n");
                }
                break;
            case 9:
                printf("List all items:\n");
                for (i = 0; i < MAX_ITEM; i++) {
                    printf("Item %s:\n", items[i].name);
                    printf("x = %d, y = %d, z = %d\n", items[i].x, items[i].y, items[i].z);
                    printf("\n");
                }
                break;
            case 10:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (choice!= 10);

    return 0;
}