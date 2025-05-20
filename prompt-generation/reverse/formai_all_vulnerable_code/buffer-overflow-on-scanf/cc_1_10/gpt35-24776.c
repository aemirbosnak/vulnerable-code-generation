//FormAI DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int questions[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char answers[10] = {'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b'};
    char response[10];
    int points = 0;
    int i;

    // Shuffle the questions array
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        int random_index = rand() % 10;
        int temp = questions[i];
        questions[i] = questions[random_index];
        questions[random_index] = temp;
    }

    // Administer the exam
    printf("Welcome to the C Exam Online System!\n");
    printf("You have 10 questions. Please answer with a, b, c, or d.\n\n");

    for (i = 0; i < 10; i++) {
        // Get the user's response
        printf("Question %d:\n", i+1);
        printf("What is the result of %d + %d?\n", questions[i], questions[i] * 2);
        printf("a. %d\n", questions[i] * 2 + 1);
        printf("b. %d\n", questions[i] * 2);
        printf("c. %d\n", questions[i] * 2 - 1);
        printf("d. None of the above\n");
        printf("Your answer: ");
        scanf(" %c", &response[i]);

        // Check if the response is correct
        if (response[i] == answers[i]) {
            printf("Correct!\n\n");
            points++;
        } else {
            printf("Incorrect.\n\n");
        }
    }

    // Give the user their score
    printf("Your score is %d out of 10.\n", points);

    return 0;
}