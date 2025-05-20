//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 100
#define MAX_ITEM 100
#define MAX_NAME 100
#define MAX_STRING 1000

typedef struct {
    char name[MAX_NAME];
    int item;
    int x, y;
} Room;

typedef struct {
    char name[MAX_NAME];
    int room;
} Item;

typedef struct {
    char name[MAX_NAME];
    char description[MAX_STRING];
    char direction[MAX_NAME];
} RoomDescription;

int main() {
    Room rooms[MAX_ROOM];
    RoomDescription descriptions[MAX_ROOM];
    int num_rooms = 0;

    int num_items = 0;
    Item items[MAX_ITEM];

    char* name = "Your Name";
    int x, y, dx, dy;

    while (1) {
        printf("What do you want to do? (1) Go, (2) Look, (3) Take, (4) Drop, (5) Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Where do you want to go?\n");
                scanf("%d %d", &x, &y);
                dx = x - rooms[num_rooms - 1].x;
                dy = y - rooms[num_rooms - 1].y;
                if (dx!= 0 || dy!= 0) {
                    int index = 0;
                    for (int i = 0; i < num_rooms; i++) {
                        if (rooms[i].x == x && rooms[i].y == y) {
                            index = i;
                            break;
                        }
                    }
                    if (index >= 0) {
                        for (int i = index; i > 0; i--) {
                            num_rooms++;
                            rooms[num_rooms - 1] = rooms[i];
                        }
                        if (num_rooms > 0) {
                            printf("You move to the next room.\n");
                        } else {
                            printf("You cannot go in this direction.\n");
                        }
                    } else {
                        printf("You cannot go in this direction.\n");
                    }
                } else {
                    printf("You cannot go in this direction.\n");
                }
                break;
            case 2:
                printf("What do you want to look at?\n");
                scanf("%d", &num_rooms);
                if (num_rooms >= 0 && num_rooms < num_rooms) {
                    printf("You look at the %s.\n", descriptions[num_rooms].name);
                } else {
                    printf("You cannot look at this.\n");
                }
                break;
            case 3:
                printf("What do you want to take?\n");
                scanf("%d", &num_rooms);
                if (num_rooms >= 0 && num_rooms < num_rooms) {
                    printf("You take the %s.\n", items[num_rooms].name);
                } else {
                    printf("You cannot take this.\n");
                }
                break;
            case 4:
                printf("What do you want to drop?\n");
                scanf("%d", &num_rooms);
                if (num_rooms >= 0 && num_rooms < num_rooms) {
                    printf("You drop the %s.\n", items[num_rooms].name);
                } else {
                    printf("You cannot drop this.\n");
                }
                break;
            case 5:
                printf("Bye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}