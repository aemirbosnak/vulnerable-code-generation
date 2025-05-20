//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int health = 100;
    int score = 0;
    char name[20];
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\n%s, you wake up in a dark and mysterious forest.\n", name);
    while (1) {
        system("clear");
        printf("\n%s, you have %d health points and %d score points.\n", name, health, score);
        printf("What would you like to do?\n");
        printf("1. Explore the forest\n");
        printf("2. Rest and recover health\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nYou start walking deeper into the forest.\n");
                int encounter = rand() % 3;
                switch (encounter) {
                    case 0:
                        printf("\nYou stumble upon a hidden treasure! You gain 10 score points.\n");
                        score += 10;
                        break;
                    case 1:
                        printf("\nYou encounter a dangerous wild animal! You lose 20 health points.\n");
                        health -= 20;
                        break;
                    case 2:
                        printf("\nYou find a magical healing spring! You recover 30 health points.\n");
                        health += 30;
                        break;
                }
                break;
            case 2:
                printf("\nYou take a nap and recover some health.\n");
                health += 10;
                break;
            case 3:
                printf("\n%s, thank you for playing!\n", name);
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}