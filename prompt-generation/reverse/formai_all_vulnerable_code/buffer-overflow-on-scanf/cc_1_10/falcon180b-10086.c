//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *rooms[] = {
    "You are in a small room with a door to the east.",
    "You are in a large room with doors to the north and south.",
    "You are in a dark room with a door to the west.",
    "You are in a bright room with a door to the east."
};

int num_rooms() {
    return sizeof(rooms) / sizeof(char *);
}

void describe_room(int room_num) {
    printf("%s\n", rooms[room_num]);
}

int main() {
    srand(time(NULL));
    int room_num;
    int choice;

    room_num = rand() % num_rooms();
    describe_room(room_num);

    while(1) {
        printf("What do you want to do? ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(room_num == 0) {
                    printf("There is no door to the east.\n");
                } else {
                    room_num = (room_num + 1) % num_rooms();
                    describe_room(room_num);
                }
                break;
            case 2:
                if(room_num == 1 || room_num == 2) {
                    printf("There is no door to the west.\n");
                } else {
                    room_num = (room_num - 1 + num_rooms()) % num_rooms();
                    describe_room(room_num);
                }
                break;
            case 3:
                if(room_num == 0) {
                    printf("There is no door to the south.\n");
                } else if(room_num == 2) {
                    printf("There is no door to the north.\n");
                } else {
                    int dir;
                    dir = rand() % 2;
                    if(dir == 0) {
                        room_num = (room_num + 1) % num_rooms();
                    } else {
                        room_num = (room_num - 1 + num_rooms()) % num_rooms();
                    }
                    describe_room(room_num);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}