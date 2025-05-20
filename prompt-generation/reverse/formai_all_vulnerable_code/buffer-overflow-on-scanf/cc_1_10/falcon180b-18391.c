//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int score = 0;
    char name[50];

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));
    printf("\n%s, you find yourself in a dark forest.\n", name);
    printf("You can go north, east, south, or west.\n");

    while(1) {
        system("clear");
        printf("\n%s, you are in a dark forest.\n", name);
        printf("You have %d health points and %d score points.\n", health, score);

        printf("\nWhat would you like to do?\n");
        printf("1. Go north\n");
        printf("2. Go east\n");
        printf("3. Go south\n");
        printf("4. Go west\n");
        printf("5. Check inventory\n");
        printf("6. Save game\n");
        printf("7. Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou go north.\n");
                health -= 10;
                score += 5;
                break;
            case 2:
                printf("\nYou go east.\n");
                health -= 10;
                score += 5;
                break;
            case 3:
                printf("\nYou go south.\n");
                health -= 10;
                score += 5;
                break;
            case 4:
                printf("\nYou go west.\n");
                health -= 10;
                score += 5;
                break;
            case 5:
                printf("\nYou check your inventory.\n");
                break;
            case 6:
                printf("\nYou save your game.\n");
                break;
            case 7:
                printf("\nThanks for playing, %s!\n", name);
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}