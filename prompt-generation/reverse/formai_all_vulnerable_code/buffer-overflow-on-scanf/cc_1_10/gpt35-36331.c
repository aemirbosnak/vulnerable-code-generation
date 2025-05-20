//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, ans, user_ans;
    int score = 0;
    char cont = 'Y';

    printf("Welcome to the Math Exercise program!\n");
    printf("Are you ready to test your math skills? Let's begin!\n");

    while (cont == 'Y') {
        // Generate two random numbers
        srand(time(NULL));
        num1 = rand() % 100;
        num2 = rand() % 100;

        // Prompt user for answer
        printf("\nWhat is %d + %d?\n", num1, num2);
        scanf("%d", &user_ans);

        // Calculate correct answer
        ans = num1 + num2;

        // Check if user's answer is correct
        if (user_ans == ans) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect. The correct answer is %d.\n", ans);
        }

        // Prompt user to continue or quit
        printf("\nDo you want to continue? (Y/N)\n");
        scanf(" %c", &cont);

        // Make sure input is either Y or N (case insensitive)
        while (cont != 'Y' && cont != 'N' && cont != 'y' && cont != 'n') {
            printf("Invalid input. Please enter Y or N.\n");
            scanf(" %c", &cont);
        }
    }

    // Print final score
    printf("Your score is %d out of 100!\n", score);

    return 0;
}