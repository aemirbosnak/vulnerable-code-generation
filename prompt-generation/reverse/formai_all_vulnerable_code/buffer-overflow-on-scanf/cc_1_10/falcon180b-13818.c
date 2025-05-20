//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void start() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark room. What do you want to do?\n");
}

void move(char direction) {
    if(direction == 'n') {
        printf("You move north and find a door.\n");
    } else if(direction =='s') {
        printf("You move south and find a wall.\n");
    } else if(direction == 'e') {
        printf("You move east and find a window.\n");
    } else if(direction == 'w') {
        printf("You move west and find a table.\n");
    } else {
        printf("Invalid direction.\n");
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char input[10];

    start();

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter direction: ");
                scanf("%s", input);
                move(input[0]);
                break;
            case 2:
                printf("You find a key on the table.\n");
                break;
            case 3:
                printf("You use the key to open the door.\n");
                break;
            case 4:
                printf("You exit the room and win the game!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}