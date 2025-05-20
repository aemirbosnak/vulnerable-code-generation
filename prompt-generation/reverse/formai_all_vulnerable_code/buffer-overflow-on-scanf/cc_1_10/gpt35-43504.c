//FormAI DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu();
void startExam();
void saveResults(int score);

int main() {
    char username[20];
    int choice;

    printf("Welcome to the most amazing online examination system!\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    printf("Hello %s, let's get started!\n", username);
    printf("Please choose an option from the menu below:\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startExam();
                break;
            case 2:
                printf("Sorry, this feature is not available yet.\n");
                break;
            case 3:
                printf("Goodbye %s! Thanks for using our system!\n", username);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("1. Start Exam\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void startExam() {
    char answer[10], guess[10];
    int score = 0;

    printf("Get ready for the most difficult exam of your life!\n");
    printf("Answer the following questions with 'true' or 'false':\n");

    printf("1. The capital of Canada is Toronto.\n");
    scanf("%s", guess);
    strcpy(answer, "false");
    if (strcmp(guess, answer) == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect!\n");
    }

    printf("2. The earth is flat.\n");
    scanf("%s", guess);
    strcpy(answer, "false");
    if (strcmp(guess, answer) == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect!\n");
    }

    printf("3. The square root of 16 is 4.\n");
    scanf("%s", guess);
    strcpy(answer, "true");
    if (strcmp(guess, answer) == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect!\n");
    }

    printf("4. The sun revolves around the earth.\n");
    scanf("%s", guess);
    strcpy(answer, "false");
    if (strcmp(guess, answer) == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect!\n");
    }

    printf("5. Cows can fly.\n");
    scanf("%s", guess);
    strcpy(answer, "false");
    if (strcmp(guess, answer) == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect!\n");
    }

    printf("Congratulations! You have completed the exam.\n");
    printf("Your score is %d out of 5.\n", score);

    saveResults(score);
}

void saveResults(int score) {
    FILE *fp = fopen("results.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%d\n", score);
    printf("Your results have been saved.\n");

    fclose(fp);
}