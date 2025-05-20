//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    // Initialize the variables
    char name[50], question[100], option1[50], option2[50], option3[50], option4[50], answer[50];
    int score = 0, correct = 0, total = 0;

    // Welcome message
    printf("Welcome to the Online Examination System!\n");

    // Ask for the student's name
    printf("Please enter your name: ");
    scanf("%s", name);

    // Display the rules
    printf("Rules:\n");
    printf("1. You have 60 minutes to complete the exam.\n");
    printf("2. Each question has 4 options, and only one option is correct.\n");
    printf("3. You will earn 1 point for each correct answer and 0 points for each incorrect answer.\n");
    printf("4. At the end of the exam, your score will be displayed.\n\n");

    // Start the exam
    printf("Exam started at %s.\n", name);
    printf("Question 1:\n");
    printf("%s.\n", question);
    printf("A. %s\n", option1);
    printf("B. %s\n", option2);
    printf("C. %s\n", option3);
    printf("D. %s\n", option4);
    printf("Answer: ");
    scanf("%s", answer);
    if (strcmp(answer, option1) == 0) {
        printf("Correct!\n");
        correct++;
        total++;
    } else if (strcmp(answer, option2) == 0) {
        printf("Correct!\n");
        correct++;
        total++;
    } else if (strcmp(answer, option3) == 0) {
        printf("Correct!\n");
        correct++;
        total++;
    } else if (strcmp(answer, option4) == 0) {
        printf("Correct!\n");
        correct++;
        total++;
    } else {
        printf("Incorrect!\n");
    }

    printf("Question 2:\n");
    printf("%s.\n", question);
    printf("A. %s\n", option1);
    printf("B. %s\n", option2);
    printf("C. %s\n", option3);
    printf("D. %s\n", option4);
    printf("Answer: ");
    scanf("%s", answer);
    if (strcmp(answer, option1) == 0) {
        printf("Correct!\n");
        correct++;
        total++;
    } else if (strcmp(answer, option2) == 0) {
        printf("Correct!\n");
        correct++;
        total++;
    } else if (strcmp(answer, option3) == 0) {
        printf("Correct!\n");
        correct++;
        total++;
    } else if (strcmp(answer, option4) == 0) {
        printf("Correct!\n");
        correct++;
        total++;
    } else {
        printf("Incorrect!\n");
    }

    // Display the score
    printf("Exam completed at %s.\n", name);
    printf("Your score is: %d/%d\n", correct, total);

    return 0;
}