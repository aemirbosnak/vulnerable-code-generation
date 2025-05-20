//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sleep(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main() {
    printf("\n\nWelcome to the curious adventure game!\n\n");
    sleep(1500);

    printf("You woke up in a deserted room. You can't remember how you got here. The only things you see are a door and a window.\n");
    sleep(4000);

    printf("What do you do?\n\n");

    char choice;
    printf("a) Open the door.\n");
    printf("b) Look through the window.\n");
    scanf(" %c", &choice);

    if(choice == 'a') {
        printf("\nYou open the door, but it's locked from the other side. You need to find another way out.");
        sleep(3000);
    } else if(choice == 'b') {
        printf("\nYou look through the window and see that you're high up in a tower. There seems to be a way down through the window, but it's risky.");
        sleep(4000);
        printf("\nWhat do you do?\n\n");

        char choice2;
        printf("a) Try to climb down through the window.\n");
        printf("b) Keep looking for another way out.\n");
        scanf(" %c", &choice2);

        if(choice2 == 'a') {
            srand(time(NULL));
            int roll = rand() % 100 + 1;

            if(roll >= 50) {
                printf("\nYou successfully climb down the tower and escape!");
            } else {
                printf("\nYou fall and die. Game over.");
            }
        } else if(choice2 == 'b') {
            printf("\nYou keep looking around the room and find a loose brick in the wall. You remove it and find a hidden passage.");
            sleep(4000);
            printf("\nDo you explore the passage or go back to the window?\n\n");

            char choice3;
            printf("a) Explore the passage.\n");
            printf("b) Go back to the window.\n");
            scanf(" %c", &choice3);

            if(choice3 == 'a') {
                printf("\nYou follow the passage and find a way out of the tower. You successfully escape!");
            } else if(choice3 == 'b') {
                srand(time(NULL));
                int roll = rand() % 100 + 1;

                if(roll >= 75) {
                    printf("\nYou successfully climb down the tower and escape!");
                } else {
                    printf("\nYou fall and die. Game over.");
                }
            }
        }
    }

    printf("\n\nThanks for playing!");
    return 0;
}