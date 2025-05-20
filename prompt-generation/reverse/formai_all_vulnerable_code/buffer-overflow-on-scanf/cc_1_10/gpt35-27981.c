//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    // Welcome message
    printf("Welcome to the Text-Based Adventure Game!\n\n");

    // Get user's name
    printf("What is your name? ");
    char name[50];
    scanf("%s", name);

    // Introduction
    printf("\nHello, %s! You have just woken up in a mysterious forest.\nYou have no idea how you got here or what happened.\n", name);

    // Ask user if they want to explore
    printf("\nDo you want to start exploring? (y/n) ");
    char answer[2];
    scanf("%s", answer);

    // Check user's answer
    if (strcmp(answer, "y") == 0) {
        printf("\nYou start walking and soon come across a river.\n");
        printf("The water is crystal clear and you can see fish swimming around.\n");
        printf("Do you want to cross the river? (y/n) ");
        scanf("%s", answer);

        // Check user's answer
        if (strcmp(answer, "y") == 0) {
            printf("\nYou jump into the water and start swimming.\n");
            printf("Suddenly, you feel something grab your leg and pull you down.\n");
            printf("You realize too late that you were swimming towards a underwater cave.\n");
            printf("You drowned.\n\nGAME OVER.\n");
        } else {
            printf("\nYou decide not to take the risk and keep exploring the forest.\n");
            printf("You eventually come across a small cabin.\n");
            printf("Do you want to enter the cabin? (y/n) ");
            scanf("%s", answer);

            // Check user's answer
            if (strcmp(answer, "y") == 0) {
                printf("\nYou enter the cabin and find a note on the table that says:\n");
                printf("Welcome, %s! You have been chosen to participate in a game.\n", name);
                printf("Your mission is to find the seven hidden gems in this forest.\n");
                printf("Good luck!\n");
                printf("You feel a chill down your spine and suddenly realize that you are not alone.\n");
                printf("You turn around and see a hooded figure staring at you.\n");
                printf("Do you want to talk to the figure? (y/n) ");
                scanf("%s", answer);

                // Check user's answer
                if (strcmp(answer, "y") == 0) {
                    printf("\nThe figure introduces themselves as the game master.\n");
                    printf("They explain to you that you have to find the seven hidden gems in the forest.\n");
                    printf("They warn you that the gems are well guarded and finding them will not be easy.\n");
                    printf("Do you accept the challenge? (y/n) ");
                    scanf("%s", answer);

                    // Check user's answer
                    if (strcmp(answer, "y") == 0) {
                        printf("\nThe game master hands you a map of the forest and wishes you good luck.\n");
                        printf("You exit the cabin and start your quest to find the seven hidden gems.\n");
                        // The game goes on
                        // ...
                    } else {
                        printf("\nThe game master disappears and you are left alone in the cabin.\n");
                        printf("You feel a sense of regret and frustration, but decide to keep exploring the forest.\n");
                        // The game goes on
                        // ...
                    }
                } else {
                    printf("\nYou decide not to talk to the figure and exit the cabin.\n");
                    printf("You continue your journey through the forest, wondering what other secrets it holds.\n");
                    // The game goes on
                    // ...
                }
            } else {
                printf("\nYou decide not to enter the cabin and keep exploring the forest.\n");
                printf("You eventually come across a clearing and see a group of people gathered around a campfire.\n");
                printf("Do you want to join them? (y/n) ");
                scanf("%s", answer);

                // Check user's answer
                if (strcmp(answer, "y") == 0) {
                    printf("\nYou approach the campfire and introduce yourself to the group.\n");
                    printf("They tell you that they are on a journey to find the seven hidden gems in the forest.\n");
                    printf("They invite you to join their search and you accept eagerly.\n");
                    // The game goes on
                    // ...
                } else {
                    printf("\nYou decide not to join the group and keep exploring the forest on your own.\n");
                    printf("You wander for hours, but to no avail.\n");
                    printf("Tired and hungry, you decide to rest under the shade of a tree and think about your next move.\n");
                    // The game goes on
                    // ...
                }
            }
        }
    } else {
        printf("\nYou decide to stay put and wait for someone to find you.\n");
        printf("Hours turn into days and days turn into weeks.\n");
        printf("You become weak and hungry, but still nobody has found you.\n");
        printf("You realize too late that nobody is coming.\n");
        printf("You died due to starvation.\n\nGAME OVER.\n");
    }

    return 0;
}