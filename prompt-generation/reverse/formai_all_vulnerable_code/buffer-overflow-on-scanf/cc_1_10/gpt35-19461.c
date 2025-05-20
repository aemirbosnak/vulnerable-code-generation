//FormAI DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, c, d, e, f, correct_ans, option, user_ans, count = 0;

    srand(time(0)); // Seed the random number generator with current time

    printf("Welcome to the Math Exercise Program!\n");

    while (count < 5) // Ask 5 questions
    {
        a = rand() % 10 + 1; // Generate two random numbers between 1-10
        b = rand() % 10 + 1;

        printf("\n%d + %d = ?", a, b); // Display the question

        correct_ans = a + b; // Store the correct answer

        printf("\n1. %d\t2. %d\t3. %d\n", correct_ans, correct_ans + 1, correct_ans - 1);
        // Display three answer options (one correct and two incorrect)

        printf("Choose the correct answer option (1-3): ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            user_ans = correct_ans;
            break;
        case 2:
            user_ans = correct_ans + 1;
            break;
        case 3:
            user_ans = correct_ans - 1;
            break;
        default:
            printf("Invalid option selected. Try again.\n");
            continue;
        }

        if (user_ans == correct_ans)
        {
            printf("Correct answer!\n");
            count++; // Increase question count only if answer is correct
        }
        else
        {
            printf("Incorrect answer. The correct answer is %d.\n", correct_ans);
        }
    }

    printf("\nCongratulations! You have completed all the questions.\n");

    return 0;
}