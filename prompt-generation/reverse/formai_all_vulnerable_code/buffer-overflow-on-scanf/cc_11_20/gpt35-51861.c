//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char choice;
    int i, j, k, randomNum;
    srand(time(NULL)); //seed the random number generator with current time

    printf("Welcome to the Haunted Castle Simulator!\n");
    printf("Are you brave enough to enter? (y/n)\n");
    scanf("%c", &choice);

    if (choice == 'y') {
        printf("Excellent, let's get started!\n");
        printf("You are standing in front of an old castle that looks like it's about to collapse.\n");

        for (i = 0; i < 3; i++) { //loop to enter the castle three times
            printf("Enter the castle? (y/n)\n");
            scanf(" %c", &choice);

            switch(choice) {
                case 'y':
                    printf("You push open the heavy doors and enter.\n");
                    break;
                case 'n':
                    printf("Are you sure you want to give up so easily? (y/n)\n");
                    scanf(" %c", &choice);
                    if (choice == 'y') { //exits the program
                        printf("Goodbye!\n");
                        return 0;
                    }
                    else {
                        i--; //repeats the loop
                    }
                    break;
                default:
                    printf("Invalid choice, please try again.\n");
                    i--; //repeats the loop
                    break;
            }

            printf("You find yourself in a dimly lit room with several doors.\n");
            printf("Which door would you like to choose? (1, 2, 3, 4)\n");
            scanf("%d", &randomNum);
            randomNum = (rand() % 4) + 1;

            switch(randomNum) {
                case 1:
                    printf("You open the door and find a long, dark hallway.\n");
                    printf("As you walk down the hallway, you hear strange noises around you.\n");
                    printf("Suddenly, ghostly figures start to appear, floating towards you!\n");
                    printf("You panic and try to run back, but the door is locked! You're trapped!\n");
                    break;
                case 2:
                    printf("You open the door and enter a room with several coffins.\n");
                    printf("As you approach one of the coffins, the lid suddenly creaks open!\n");
                    printf("A vampire jumps out and attacks you!\n");
                    printf("You struggle to fight it off, but it's no use. You're doomed...\n");
                    break;
                case 3:
                    printf("You open the door and enter a room filled with strange artifacts.\n");
                    printf("One artifact catches your eye, a shiny crystal.\n");
                    printf("As you reach for it, the room starts to spin and your surroundings blur.\n");
                    printf("You find yourself transported to another dimension, alone and scared...\n");
                    break;
                case 4:
                    printf("You open the door and find yourself in a room with a treasure chest.\n");
                    printf("You approach the chest and open it, revealing piles of gold and jewels!\n");
                    printf("As you reach for the treasure, you hear a loud growl behind you.\n");
                    printf("You turn around to see a huge, terrifying monster ready to attack!\n");
                    printf("You gather your wits and decide to fight for your life...\n");
                    break;
            }

            printf("Do you want to leave the castle? (y/n)\n");
            scanf(" %c", &choice);

            if (choice == 'y') {
                printf("Congratulations on surviving the haunted castle! Until next time...\n");
                return 0;
            }
            else {
                printf("You continue on your journey, ready to face whatever comes your way.\n");
            }
        }
    }
    else if (choice == 'n') {
        printf("Maybe next time, then. Goodbye!\n");
        return 0;
    }
    else {
        printf("Invalid choice, please try again.\n");
        main(); //restarts the program if invalid choice is entered
    }

    return 0;
}