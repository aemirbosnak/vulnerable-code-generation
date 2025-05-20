//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int score = 0;
    char name[20];

    printf("Welcome to the Haunted House!\n");
    printf("What is your name? ");
    scanf("%s", name);

    while(1) {
        printf("\n%s, you are in a dark room.\n", name);
        printf("There are three doors in front of you.\n");
        printf("Which one do you choose?\n");
        printf("1. Left door\n");
        printf("2. Middle door\n");
        printf("3. Right door\n");
        printf("4. Go back\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou open the left door and enter a long hallway.\n");
                printf("The hallway is filled with paintings of creepy faces.\n");
                printf("Suddenly, one of the paintings comes to life!\n");
                printf("A ghostly figure jumps out and scares you.\n");
                printf("You lose 1 point for being scared.\n");
                score--;
                break;
            case 2:
                printf("\nYou open the middle door and find yourself in a library.\n");
                printf("The bookshelves are lined with old, dusty books.\n");
                printf("As you reach for a book, a skeleton hand grabs you!\n");
                printf("You scream and run out of the room.\n");
                printf("You lose 1 point for being scared.\n");
                score--;
                break;
            case 3:
                printf("\nYou open the right door and enter a dark chamber.\n");
                printf("In the center of the room, there is a glowing crystal.\n");
                printf("As you approach it, a group of bats swoops down and attacks you!\n");
                printf("You manage to fight them off, but not without losing 1 point.\n");
                score--;
                break;
            case 4:
                printf("\nYou decide to go back to the entrance.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        if(score == 0) {
            printf("\n\nGame over! You have been too scared and lost all your points.\n");
            printf("Thanks for playing!\n");
            return 0;
        }
    }

    return 0;
}