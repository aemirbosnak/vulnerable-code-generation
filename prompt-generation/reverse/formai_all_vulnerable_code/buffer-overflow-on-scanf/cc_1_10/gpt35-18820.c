//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    char choice;
    int health = 100;
    int score = 0;
 
    printf("Welcome to the adventure game!\n");
    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s! You have 100 health points and your current score is 0.\n", name);
 
    while (health > 0) {
        printf("You enter a dark room. There are three doors. Which one do you choose? (A, B, C) ");
        scanf(" %c", &choice);
 
        switch (choice) {
            case 'A':
                printf("You entered Door A. You find a key and a note.\n");
                printf("The note says: 'The treasure lies in the room with the dragon'.\n");
                score += 10;
                break;
            case 'B':
                printf("You entered Door B. There is a monster in this room!\n");
                printf("The monster attacks you and you lose 20 health points.\n");
                health -= 20;
                break;
            case 'C':
                printf("You entered Door C. This room is empty. You search around and find nothing.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                continue; // start loop again
        }
 
        if (health <= 0) {
            printf("Sorry, you have died.\n");
            break; // end loop
        }
 
        printf("Your current score is %d\n", score);
        printf("Your current health is %d\n", health);
        printf("Do you want to continue? (Y/N) ");
 
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n') {
            printf("Thanks for playing, %s! Your final score is %d.", name, score);
            exit(0); // end the program
        }
    }
 
    return 0;
}