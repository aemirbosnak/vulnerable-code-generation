//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int temperature;
} room;

int main() {
    room rooms[5] = {
        {"Living Room", 75},
        {"Kitchen", 70},
        {"Bedroom", 68},
        {"Bathroom", 80},
        {"Garage", 65}
    };
    int room_count = 5;
    int room_index = 0;

    printf("Welcome to the Smart Home Automation System!\n");
    printf("Choose a room to control: ");
    for (int i = 0; i < room_count; i++) {
        if (i == room_index) {
            printf("%s\n", rooms[i].name);
        }
    }
    int choice;
    printf("Enter the number of the room you want to control: ");
    scanf("%d", &choice);
    if (choice >= 0 && choice < room_count) {
        room chosen_room = rooms[choice];
        int desired_temp = 0;
        printf("Enter the desired temperature for the room: ");
        scanf("%d", &desired_temp);
        if (desired_temp > 80 || desired_temp < 60) {
            printf("Invalid temperature!\n");
            return 0;
        }
        chosen_room.temperature = desired_temp;
        printf("Temperature set to %d\n", chosen_room.temperature);
    } else {
        printf("Invalid room choice!\n");
        return 0;
    }

    printf("Do you want to control another room? (y/n) ");
    char input;
    scanf(" %c", &input);
    if (input!= 'y') {
        printf("Exiting program...\n");
        return 0;
    }
    room_index++;
    room_count--;
}