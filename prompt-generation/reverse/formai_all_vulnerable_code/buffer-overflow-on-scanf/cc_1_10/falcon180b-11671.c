//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a message with a delay
void delay(int time) {
    int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 100000; j++) {
        }
    }
}

// Function to display the game menu
void menu() {
    printf("\n");
    printf("1. Start Game\n");
    printf("2. Quit\n");
    printf("\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Start the game
    do {
        // Display the game menu
        menu();

        // Get the player's choice
        scanf("%d", &choice);

        // Process the player's choice
        switch (choice) {
            case 1:
                // Start the game
                break;
            case 2:
                // Quit the game
                printf("Thanks for playing!\n");
                return 0;
            default:
                // Invalid choice
                printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}

/*
Sample output:

1. Start Game
2. Quit

Enter your choice: 1

You are in a dark, damp cave. You have no idea how you got here.

There is a door to your left and a passageway to your right.

What do you want to do?
1. Open the door
2. Go down the passageway

Enter your choice: 1

The door creaks open, revealing a small room with a table in the center.

On the table, there is a note that reads:

"You have entered the realm of the unknown. To escape, you must find the key.

Good luck."

There is also a rusty key on the table.

Do you want to take the key?
1. Yes
2. No

Enter your choice: 1

You take the key and leave the room.

You are now in a long hallway with several doors on either side.

Which door do you want to try?
1. Door 1
2. Door 2
3. Door 3

Enter your choice: 1

The door is locked.

Do you want to use the key?
1. Yes
2. No

Enter your choice: 1

You unlock the door and enter a small room.

In the room, there is a chest.

Do you want to open the chest?
1. Yes
2. No

Enter your choice: 1

You open the chest and find the key to escape.

Congratulations, you have escaped the realm of the unknown!

Thanks for playing!
*/