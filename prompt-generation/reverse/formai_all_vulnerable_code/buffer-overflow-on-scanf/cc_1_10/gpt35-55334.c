//FormAI DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Mystery Math Challenge!\n\n");
    printf("You have stumbled upon a strange laboratory and before you is a mysterious machine with blinking lights.\n");
    printf("As you approach, the machine comes to life and a voice booms from speakers.");

    printf("\n\n\"Greetings, adventurer! I am Professor X and I have created this machine to test your math skills.");
    printf("\nYou will have to solve the following math problems to unlock the secrets of this laboratory.");
    printf("\nFirst, I will give you a riddle to solve. If you succeed, the machine will begin the challenge. Are you ready?\"\n\n");

    printf("\"I am an odd number and my square is a multiple of 3. What number am I?\"\n\n");

    int answer;
    scanf("%d", &answer);

    if (answer != 9) {
        printf("\n\"I am sorry, that is incorrect. Please leave this laboratory at once and never return!\"\n\n");
        return 0;
    }

    printf("\n\"Well done, adventurer! You have solved my riddle and have proven yourself worthy to take on my math challenge.\n");
    printf("Here are your first three problems:\n\n");

    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int num3 = rand() % 10 + 1;

    int sum = num1 + num2 + num3;
    int product = num1 * num2 * num3;
    int average = sum / 3;

    printf("Problem 1: What is the sum of %d, %d, and %d?\n", num1, num2, num3);
    scanf("%d", &answer);

    if (answer != sum) {
        printf("\n\"I am sorry, that is incorrect. You have failed my challenge. Goodbye!\"\n\n");
        return 0;
    }

    printf("\n\"Correct! Onto the next problem.\"\n");

    printf("\nProblem 2: What is the product of %d, %d, and %d?\n", num1, num2, num3);
    scanf("%d", &answer);

    if (answer != product) {
        printf("\n\"I am sorry, that is incorrect. You have failed my challenge. Goodbye!\"\n\n");
        return 0;
    }

    printf("\n\"Well done once again! You are almost there.\"\n");

    printf("\nProblem 3: What is the average of %d, %d, and %d?\n", num1, num2, num3);
    scanf("%d", &answer);

    if (answer != average) {
        printf("\n\"I am sorry, that is incorrect. You have failed my challenge. Goodbye!\"\n\n");
        return 0;
    }

    printf("\n\"Congratulations, adventurer! You have completed my math challenge and unlocked the secrets of this laboratory!");
    printf("\nUse your newfound knowledge wisely and explore to your heart's content.\"");

    return 0;
}