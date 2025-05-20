//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {

    char player_name[20];
    int player_age;
    char choice[10];
    int score = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);
    printf("Please enter your age: ");
    scanf("%d", &player_age);
  
    printf("Hello %s, you are now lost in a dense forest.\n", player_name);
    printf("You have a map, but you don't know which way to go.\n");
    printf("Enter 'L' to go left, 'R' to go right, 'F' to go forward\n");

    while (score >= 0 && score <= 10) {

        printf("\nYour current score is: %d\n", score);
        printf("Enter your choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "L") == 0) {
            printf("You encountered a grizzly bear!\n");
            printf("You quickly ran back to the starting point.\n");
            score -= 1;

        } else if (strcmp(choice, "R") == 0) {
            printf("You found a river, and crossed it safely.\n");
            score += 2;

        } else if (strcmp(choice, "F") == 0) {
            printf("You stumbled upon a hidden treasure!\n");
            printf("You gained 5 points and found your way out of the forest.\n");
            score += 5;
            break;

        } else {
            printf("Invalid input, please try again.\n");
        }
    }

    if (score >= 0 && score <= 10) {
        printf("\nCongratulations %s, you have successfully completed the game!\n", player_name);
        printf("Your final score is %d.\n", score);
    } else {
        printf("\nUnfortunately, %s, your score is below 0 and you have failed the game.\n", player_name);
        printf("Better luck next time!\n");
    }

    return 0;
}