//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to explore the universe.\n");
    printf("Choose your path:\n");
    printf("1. Explore a new planet\n");
    printf("2. Encounter an alien species\n");
    printf("3. Repair your spacecraft\n");
    printf("4. Return to Earth\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You have landed on a new planet.\n");
            printf("The atmosphere is breathable and the temperature is mild.\n");
            printf("You see strange plants and animals.\n");
            printf("Do you want to explore further? (y/n)\n");
            char explore;
            scanf(" %c", &explore);

            if (explore == 'y' || explore == 'Y') {
                printf("You discover a hidden cave.\n");
                printf("Inside the cave, you find a valuable crystal.\n");
                printf("You decide to take it with you.\n");
                printf("Congratulations! You have completed the mission.\n");
            } else {
                printf("You decide to return to your spacecraft.\n");
            }
            break;

        case 2:
            printf("You encounter an alien species.\n");
            printf("They are friendly and communicate with you telepathically.\n");
            printf("They offer to share their advanced technology with you.\n");
            printf("Do you accept their offer? (y/n)\n");
            char accept;
            scanf(" %c", &accept);

            if (accept == 'y' || accept == 'Y') {
                printf("You learn how to use their technology and it greatly enhances your mission.\n");
                printf("Congratulations! You have completed the mission.\n");
            } else {
                printf("You decline their offer and continue on your mission.\n");
            }
            break;

        case 3:
            printf("Your spacecraft has suffered minor damage.\n");
            printf("You need to repair it before continuing your mission.\n");
            printf("Do you have the necessary tools to repair your spacecraft? (y/n)\n");
            char tools;
            scanf(" %c", &tools);

            if (tools == 'y' || tools == 'Y') {
                printf("You successfully repair your spacecraft.\n");
                printf("Congratulations! You have completed the mission.\n");
            } else {
                printf("You do not have the necessary tools and must abort your mission.\n");
            }
            break;

        case 4:
            printf("You have successfully completed your mission.\n");
            printf("You return to Earth as a hero.\n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}