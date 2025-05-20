//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char* rooms[] = {"Living Room", "Kitchen", "Bedroom", "Bathroom"};
    int room_index = rand() % 4;
    char* current_room = rooms[room_index];

    printf("You find yourself in a dimly lit room. There is a door to your left and right.\n");
    printf("Which direction do you go? (left/right) ");
    char choice;
    scanf("%c", &choice);

    switch (choice) {
        case 'l':
            room_index = (room_index == 0)? 3 : 0;
            current_room = rooms[room_index];
            break;
        case 'r':
            room_index = (room_index == 3)? 0 : 3;
            current_room = rooms[room_index];
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("You are now in the %s.\n", current_room);
    printf("There is a chest in the room. Do you want to open it? (y/n) ");
    char open_chest;
    scanf("%c", &open_chest);

    switch (open_chest) {
        case 'y':
            printf("You open the chest and find a key. You can now unlock the door.\n");
            printf("Do you want to go through the door? (y/n) ");
            char go_door;
            scanf("%c", &go_door);
            break;
        case 'n':
            printf("You leave the chest closed and continue exploring the room.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("You unlock the door and go through it.\n");
    printf("You find yourself in a dark hallway. Do you want to turn on the light? (y/n) ");
    char turn_light;
    scanf("%c", &turn_light);

    switch (turn_light) {
        case 'y':
            printf("You turn on the light and see a switch on the wall. Do you want to turn it on? (y/n) ");
            char turn_switch;
            scanf("%c", &turn_switch);
            break;
        case 'n':
            printf("You leave the light off and continue exploring the hallway.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("You turn on the switch and see a hidden door. Do you want to open it? (y/n) ");
    char open_hidden_door;
    scanf("%c", &open_hidden_door);

    switch (open_hidden_door) {
        case 'y':
            printf("You open the hidden door and find a treasure chest. Do you want to open it? (y/n) ");
            char open_treasure_chest;
            scanf("%c", &open_treasure_chest);
            break;
        case 'n':
            printf("You leave the hidden door closed and continue exploring the hallway.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("You open the treasure chest and find a valuable item. Congratulations!\n");
    printf("Do you want to go back to the starting room? (y/n) ");
    char go_back;
    scanf("%c", &go_back);

    switch (go_back) {
        case 'y':
            room_index = (room_index == 3)? 0 : 3;
            current_room = rooms[room_index];
            break;
        case 'n':
            printf("You decide to continue exploring the hallway.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("You find yourself back in the %s.\n", current_room);
    printf("You can now leave the room and return to the starting room.\n");
    printf("Do you want to leave? (y/n) ");
    char leave;
    scanf("%c", &leave);

    switch (leave) {
        case 'y':
            printf("You leave the room and return to the starting room.\n");
            break;
        case 'n':
            printf("You decide to continue exploring the room.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("You find yourself back in the %s.\n", current_room);
    printf("You can now leave the room and return to the starting room.\n");
    printf("Do you want to leave? (y/n) ");
    char leave_final;
    scanf("%c", &leave_final);

    switch (leave_final) {
        case 'y':
            printf("You leave the room and return to the starting room.\n");
            break;
        case 'n':
            printf("You decide to continue exploring the room.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}