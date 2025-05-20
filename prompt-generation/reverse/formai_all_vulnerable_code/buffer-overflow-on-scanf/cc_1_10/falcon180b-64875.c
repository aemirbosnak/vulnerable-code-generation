//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* rooms[] = {"You are in a small room. There is a door to the north.",
               "This is a dark room. You can't see anything.",
               "You are in a large hall. There are doors to the east and west.",
               "This room has a strange smell. It's coming from the south.",
               "You are in a garden. There are flowers everywhere."};

int num_rooms = sizeof(rooms)/sizeof(rooms[0]);

void look(int room) {
    printf("%s\n", rooms[room]);
}

void move(int* room, int dir) {
    if(dir == 0)
        *room = (*room + num_rooms - 1) % num_rooms;
    else if(dir == 1)
        *room = (*room + 1) % num_rooms;
    else if(dir == 2)
        *room = (*room - 1 + num_rooms) % num_rooms;
    else if(dir == 3)
        *room = (*room - 1) % num_rooms;
}

int main() {
    srand(time(NULL));
    int room = rand() % num_rooms;

    while(1) {
        system("clear");
        look(room);

        int choice;
        printf("What do you want to do?\n");
        printf("1. Look around\n");
        printf("2. Move north\n");
        printf("3. Move east\n");
        printf("4. Move south\n");
        printf("5. Move west\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                look(room);
                break;
            case 2:
                move(&room, 0);
                break;
            case 3:
                move(&room, 1);
                break;
            case 4:
                move(&room, 2);
                break;
            case 5:
                move(&room, 3);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}