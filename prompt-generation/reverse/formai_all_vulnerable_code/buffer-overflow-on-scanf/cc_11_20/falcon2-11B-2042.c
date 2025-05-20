//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL));
    int room_number = rand() % 100 + 1;
    int door_number = rand() % 10 + 1;
    int door_state = rand() % 2 + 1;
    int item_number = rand() % 10 + 1;
    int item_type = rand() % 5 + 1;
    int item_value = rand() % 100 + 1;
    int exit_number = rand() % 10 + 1;
    int exit_state = rand() % 2 + 1;
    
    printf("You are in Room %d.\n", room_number);
    printf("You see a door to your left and right.\n");
    printf("The left door is open %d%%.\n", door_state);
    printf("The right door is open %d%%.\n", door_state);
    printf("You see an item on the floor.\n");
    printf("The item is a %d%%.\n", item_type);
    printf("The item is worth %d points.\n", item_value);
    printf("You see an exit to your left and right.\n");
    printf("The left exit is closed %d%%.\n", exit_state);
    printf("The right exit is closed %d%%.\n", exit_state);
    
    char choice;
    printf("What would you like to do?\n");
    printf("1. Open the left door.\n");
    printf("2. Open the right door.\n");
    printf("3. Pick up the item.\n");
    printf("4. Go through the left exit.\n");
    printf("5. Go through the right exit.\n");
    printf("6. Do nothing.\n");
    printf("Enter your choice (1-6): ");
    scanf("%c", &choice);
    
    switch (choice) {
        case '1':
            if (door_state == 0) {
                printf("The door is already open.\n");
            } else {
                door_state = 1;
                printf("You open the left door.\n");
            }
            break;
        case '2':
            if (door_state == 0) {
                printf("The door is already open.\n");
            } else {
                door_state = 1;
                printf("You open the right door.\n");
            }
            break;
        case '3':
            item_value += rand() % 100 + 1;
            printf("You pick up the item.\n");
            printf("The item is now worth %d points.\n", item_value);
            break;
        case '4':
            if (exit_state == 0) {
                printf("The exit is already open.\n");
            } else {
                exit_state = 1;
                printf("You go through the left exit.\n");
            }
            break;
        case '5':
            if (exit_state == 0) {
                printf("The exit is already open.\n");
            } else {
                exit_state = 1;
                printf("You go through the right exit.\n");
            }
            break;
        case '6':
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    if (room_number == exit_number || door_number == exit_number || item_number == exit_number || door_state == 0 || exit_state == 0) {
        printf("Congratulations, you have escaped the haunted house!\n");
        return 0;
    } else {
        printf("You are still in the haunted house.\n");
    }
    
    return 0;
}