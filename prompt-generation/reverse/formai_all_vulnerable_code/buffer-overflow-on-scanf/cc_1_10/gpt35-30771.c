//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, answer, user_answer;
    int correct_count = 0, incorrect_count = 0;
    char response[10];

    // Using the time function to seed the rand function for random number generation
    srand(time(NULL));

    printf("Welcome to the Math Exercise Program!\n");
    printf("Answer the following multiplication questions.\n");

    // Loop to generate 10 random multiplication questions
    for (int i = 0; i < 10; i++)
    {
        num1 = rand() % 11; // Generating a random number between 0 and 10
        num2 = rand() % 11;

        answer = num1 * num2;

        printf("\nQuestion #%d:\n", i + 1);
        printf("%d x %d = ", num1, num2);
        scanf("%d", &user_answer);

        // Checking if the user's answer matches the correct answer
        if (user_answer == answer)
        {
            printf("Congratulations! Your answer is correct!\n");
            correct_count++;
        }
        else
        {
            printf("Oops! Your answer is incorrect! The correct answer is %d.\n", answer);
            incorrect_count++;
        }

        // Delay of 1 second between questions
        sleep(1);
    }

    // Displaying the results of the exercise
    printf("\nExercise complete! Here are your results:\n");
    printf("Number of questions answered correctly: %d\n", correct_count);
    printf("Number of questions answered incorrectly: %d\n", incorrect_count);

    // Asking the user if they'd like to try again
    printf("\nWould you like to try again? (yes/no)\n");
    scanf("%s", response);

    // If user enters "yes," program will restart. Otherwise, program will exit.
    if (strcmp(response, "yes") == 0)
    {
        main();
    }
    else
    {
        printf("\nThank you for using the Math Exercise Program! Goodbye!\n");
        exit(0);
    }

    return 0;
}