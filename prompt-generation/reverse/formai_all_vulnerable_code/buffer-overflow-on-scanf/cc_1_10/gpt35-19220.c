//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between two values
int randNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    int choice, count = 0;
    
    printf("Welcome to the Haunted House Simulator! You are about to embark on a spooky journey through a haunted house.\n");
    
    while (count < 5) {
        printf("You are standing in the entrance hall. There are three doors in front of you. Which one would you like to choose? (1-3)\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("You open the door and walk into a dark room. Suddenly, the door slams shut behind you!\n");
                printf("You feel a chill run down your spine as you hear a ghostly voice whispering in your ear...\n");
                printf("There is no escape from this room. You are trapped forever!\n");
                break;
            case 2:
                printf("You open the door and find yourself in a room filled with cobwebs and old furniture.\n");
                printf("As you look around, you notice a piece of paper lying on the ground. It reads:\n");
                printf("\"Beware of the ghost that haunts this house. It preys on those who dare to enter.\"\n");
                break;
            case 3:
                printf("You enter the room and notice a chest in the corner. You approach it slowly and open it...\n");
                printf("Inside the chest, you find a key! You wonder what it could unlock...\n");
                printf("As you leave the room, you notice a narrow staircase leading upwards. Do you want to investigate? (1- Yes, 2- No)\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You climb the staircase and find yourself in a dusty attic.\n");
                    printf("In the distance, you see a figure shrouded in mist. It beckons you forward...\n");
                    printf("But as you approach, the figure disappears! You are alone in the attic.\n");
                }
                break;
            default:
                printf("Invalid choice. Please choose a number between 1-3.\n");
        }
        
        count++; // Increment count to keep track of number of choices made
    }
    
    printf("Congratulations, you made it through the haunted house! Thanks for playing!\n");
    
    return 0;
}