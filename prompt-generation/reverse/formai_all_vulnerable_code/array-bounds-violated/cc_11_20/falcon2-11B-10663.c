//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 10
#define MAX_COMMAND 10

typedef struct {
    char name[20];
    char description[100];
} room;

int main() {
    int room_num;
    int command_num;
    char command[MAX_COMMAND];

    room rooms[MAX_ROOM] = {
        {"Room 1", "You are in a dark room. There are four doors."},
        {"Room 2", "You are in a kitchen. There is a table with a knife on it."},
        {"Room 3", "You are in a bedroom. There is a bed and a lamp."},
        {"Room 4", "You are in a bathroom. There is a toilet and a sink."},
        {"Room 5", "You are in a living room. There is a TV and a sofa."}
    };

    char* command_list[] = {
        "go north", "go south", "go east", "go west", "look around", "take knife", "take lamp", "take toilet", "take TV"
    };

    while (1) {
        printf("Where would you like to go? (n/s/e/w)\n");
        fgets(command, MAX_COMMAND, stdin);
        command_num = 0;

        while (command[command_num]!= '\n') {
            if (command[command_num] == 'n' || command[command_num] =='s' || command[command_num] == 'e' || command[command_num] == 'w') {
                room_num = command[command_num] - 'n';
                if (room_num < 0 || room_num > 3) {
                    printf("You cannot go that way.\n");
                } else {
                    printf("You go %c and enter %s.\n", command[command_num], rooms[room_num].name);
                }
                command_num++;
            } else if (command[command_num] == 'l') {
                printf("You look around and see %s.\n", rooms[room_num].description);
                command_num++;
            } else if (command[command_num] == 't') {
                if (command[command_num + 1] == 'k') {
                    printf("You take the knife and enter %s.\n", rooms[room_num].name);
                } else if (command[command_num + 1] == 'l') {
                    printf("You take the lamp and enter %s.\n", rooms[room_num].name);
                } else if (command[command_num + 1] == 't') {
                    printf("You take the toilet and enter %s.\n", rooms[room_num].name);
                } else if (command[command_num + 1] == 'V') {
                    printf("You take the TV and enter %s.\n", rooms[room_num].name);
                } else {
                    printf("You cannot take that.\n");
                }
                command_num += 2;
            } else {
                printf("You cannot do that.\n");
            }
        }
    }
}