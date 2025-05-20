//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char input[50];
    int rand_num = rand() % 2;

    printf("Welcome to the Romeo and Juliet Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", input);
    printf("Nice to meet you, %s.\n", input);
    printf("Would you like to play the game? (yes or no)\n");
    scanf("%s", input);

    if (strcmp(input, "yes") == 0) {
        printf("Great! Let's begin!\n\n");
        printf("You are Romeo, a young man in love with Juliet, the daughter of your family's enemy.\n");
        printf("You and Juliet plan to run away together and start a new life.\n");
        printf("You will need to make several decisions along the way that will determine your fate.\n\n");

        printf("You are in the city center. Juliet is waiting for you at the church on the other side of town.\n");
        printf("As you walk through the streets, you hear a commotion and see a group of Capulet men approaching.\n");
        printf("What do you do? (fight or run)\n");
        scanf("%s", input);

        if (strcmp(input, "fight") == 0) {
            printf("You fight bravely, but are outnumbered. You are killed in battle.\n");
            printf("Game over.\n");
        } else {
            printf("You manage to escape and make your way to the church where Juliet is waiting.\n");
            printf("However, you are pursued by the Capulet men who are now even more angry.\n\n");

            if (rand_num == 0) {
                printf("You hide behind a dumpster and wait for them to pass.\n");
                printf("They eventually leave and you continue on your way.\n");
                printf("You make it safely to the church and reunite with Juliet.\n\n");

                printf("Juliet tells you that her father has found out about your plans and is coming to stop you.\n");
                printf("You must make a decision quickly. Do you flee the city with Juliet or stay and fight?\n");
                scanf("%s", input);

                if (strcmp(input, "flee") == 0) {
                    printf("You and Juliet leave the city and start a new life together.\n");
                    printf("Congratulations! You win the game!\n");
                } else {
                    printf("You fight bravely against the Capulets, but are killed in battle.\n");
                    printf("Game over.\n");
                }
            } else {
                printf("You make a run for it, but one of the Capulet men catches you.\n");
                printf("He stabs you and you die of your wounds before making it to the church.\n");
                printf("Game over.\n");
            }
        }
    } else {
        printf("That's too bad. Maybe next time.\n");
    }

    return 0;
}