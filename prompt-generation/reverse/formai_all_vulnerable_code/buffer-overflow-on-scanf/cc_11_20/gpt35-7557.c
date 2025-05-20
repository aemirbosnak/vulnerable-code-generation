//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing random number generator
    srand(time(NULL));

    printf("-Welcome to The Haunted House Simulator-\n\n");

    printf("You are standing in front of a haunted house.\n");
    printf("Do you want to enter? (yes/no): ");
    char choice[10];
    scanf("%s", &choice);
    if (strcmp(choice, "yes") != 0) {
        printf("Ok, maybe next time.\n");
        return 0;
    }

    printf("\nYou enter the house...\n");
    printf("Suddenly, the door slams shut behind you!\n");
    printf("You turn around to try to open the door, but it's locked.\n");
    printf("You are trapped inside!\n\n");

    // Initializing player status
    int health = 100;
    int sanity = 100;
    int flashlight = 1;

    while (1) {
        // Generating random events
        int event = rand() % 4 + 1;
        switch (event) {
            case 1:
                printf("You hear strange noises coming from upstairs...\n");
                break;
            case 2:
                printf("The room suddenly gets colder...\n");
                break;
            case 3:
                printf("You smell something rotten...\n");
                break;
            case 4:
                printf("Your flashlight flickers and dies...\n");
                flashlight = 0;
                break;
        }

        printf("\nWhat do you do?\n");
        if (flashlight) {
            printf("1. Investigate with flashlight\n");
        }
        printf("2. Investigate without flashlight\n");
        printf("3. Try to find a way out\n");
        printf("4. Quit game\n");
        printf("Choice (1-4): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("You investigate the area with your flashlight...\n"); 
                printf("You find nothing of interest.\n"); 
                printf("Your health decreased by 10.\n\n"); 
                health -= 10;
                break;
            case 2: 
                printf("You investigate the area without your flashlight...\n");
                printf("You find nothing of interest.\n");
                printf("Your sanity decreased by 10.\n\n"); 
                sanity -= 10; 
                break;
            case 3: 
                printf("You try to find a way out...\n");
                printf("You find a key and unlock the door!\n\n");
                printf("Congratulations, you have escaped!\n");
                return 0;
            case 4: 
                printf("Thanks for playing.\n\n"); 
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n"); 
                break;
        }

        // Checking player status
        if (health <= 0) {
            printf("You died from your injuries...\n\n");
            printf("Game over.\n");
            return 0;
        }
        if (sanity <= 0) {
            printf("You went insane...\n\n");
            printf("Game over.\n");
            return 0;
        }
    }
}