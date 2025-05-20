//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Room {
    char *description;
    int north;
    int south;
    int east;
    int west;
};

void print_room(struct Room room) {
    printf("%s\n", room.description);
}

int main() {
    srand(time(NULL));

    struct Room entrance = {"You are standing at the entrance of a haunted house. The door creaks open slowly.", 1, 0, 0, 0};
    struct Room hallway = {"You find yourself in a long, dark hallway. The walls are covered in peeling wallpaper and cobwebs.", 0, 1, 1, 0};
    struct Room bedroom = {"This must have been the master bedroom. A large, four-poster bed dominates the room, its curtains tattered and torn.", 0, 0, 1, 1};
    struct Room kitchen = {"The kitchen is a mess. Dirty dishes pile up in the sink, and the refrigerator hums ominously.", 1, 0, 0, 1};
    struct Room basement = {"A rickety staircase leads down to the basement. It's dark and damp, with an earthy smell that makes your skin crawl.", 0, 0, 0, 1};

    int current_room = 0;
    while(current_room!= 5) {
        switch(current_room) {
            case 0:
                print_room(entrance);
                printf("Which way would you like to go? (1=North, 2=South, 3=East, 4=West)\n");
                scanf("%d", &current_room);
                break;
            case 1:
                print_room(hallway);
                printf("Which way would you like to go? (1=North, 2=South, 3=East, 4=West)\n");
                scanf("%d", &current_room);
                break;
            case 2:
                print_room(bedroom);
                printf("Which way would you like to go? (1=North, 2=South, 3=East, 4=West)\n");
                scanf("%d", &current_room);
                break;
            case 3:
                print_room(kitchen);
                printf("Which way would you like to go? (1=North, 2=South, 3=East, 4=West)\n");
                scanf("%d", &current_room);
                break;
            case 4:
                print_room(basement);
                printf("Which way would you like to go? (1=North, 2=South, 3=East, 4=West)\n");
                scanf("%d", &current_room);
                break;
            default:
                printf("Invalid room number.\n");
        }
    }

    return 0;
}