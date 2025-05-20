//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int score = 0;
    int room = 1;

    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You find yourself in a dark room with a single door.\n");

    while(1) {
        system("clear");
        printf("\n");
        printf("You are in room %d.\n", room);
        printf("Your health is at %d.\n", health);
        printf("Your score is %d.\n", score);

        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Open the door\n");
        printf("2. Check your inventory\n");
        printf("3. Rest\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(room == 1) {
                    printf("\n");
                    printf("You open the door and step into the next room.\n");
                    room++;
                } else if(room == 2) {
                    printf("\n");
                    printf("You open the door and find yourself face to face with a monster!\n");
                    printf("Do you want to fight or run away?\n");
                    printf("1. Fight\n");
                    printf("2. Run away\n");
                    scanf("%d", &choice);

                    if(choice == 1) {
                        health -= 20;
                        printf("\n");
                        printf("You engage in a fierce battle with the monster.\n");
                        printf("After a few minutes, you emerge victorious!\n");
                        score += 10;
                    } else if(choice == 2) {
                        printf("\n");
                        printf("You turn tail and run away as fast as you can.\n");
                    }
                } else {
                    printf("\n");
                    printf("You open the door and find nothing but darkness.\n");
                }
                break;

            case 2:
                printf("\n");
                printf("You check your inventory and find:\n");
                printf("- A sword\n");
                printf("- A shield\n");
                printf("- A potion\n");
                break;

            case 3:
                printf("\n");
                printf("You take a moment to rest and regain your strength.\n");
                health += 10;
                break;

            case 4:
                printf("\n");
                printf("Thank you for playing the Text-Based Adventure Game!\n");
                return 0;

            default:
                printf("\n");
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}