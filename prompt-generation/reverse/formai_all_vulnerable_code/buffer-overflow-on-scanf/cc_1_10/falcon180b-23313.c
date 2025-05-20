//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char element[20];
    int score = 0;
    int questionCount = 0;
    int correctAnswers = 0;
    int userAnswer;
    int randomIndex;
    int maxQuestions = 10;
    struct tm *t;
    time_t now;

    printf("Welcome to the C Periodic Table Quiz!\n");
    time(&now);
    t = localtime(&now);
    printf("Current time: %s\n", asctime(t));

    // Initialize random seed
    srand(time(NULL));

    // Loop until user answers maxQuestions correctly or reaches maxQuestions
    while (questionCount < maxQuestions && correctAnswers < maxQuestions) {
        questionCount++;

        // Generate a random element from the periodic table
        randomIndex = rand() % 118;
        strcpy(element, "?");
        element[0] = (char) (randomIndex + 65);

        // Print the question
        printf("Question %d: What is the symbol for element %c?\n", questionCount, element[0]);

        // Read user input
        scanf("%d", &userAnswer);

        // Convert user input to uppercase
        userAnswer = toupper(userAnswer);

        // Check if user answer is correct
        if (userAnswer == element[0]) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", element[0]);
        }
    }

    // Print final score
    if (correctAnswers == maxQuestions) {
        printf("You got all %d questions correct!\n", maxQuestions);
    } else {
        printf("You got %d out of %d questions correct.\n", correctAnswers, maxQuestions);
    }

    return 0;
}