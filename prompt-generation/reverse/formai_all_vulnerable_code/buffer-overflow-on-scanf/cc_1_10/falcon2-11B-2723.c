//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void displayExam() {
    printf("Exam Details:\n");
    printf("Total Questions: 10\n");
    printf("Time Taken: 60 seconds\n");
}

void takeExam() {
    displayExam();
    int questionsAnswered = 0;
    int totalTime = 60;
    while (questionsAnswered < 10) {
        printf("Question %d:\n", questionsAnswered + 1);
        printf("A. Option 1\n");
        printf("B. Option 2\n");
        printf("C. Option 3\n");
        printf("D. Option 4\n");
        printf("Enter your answer (1-4): ");
        int optionChosen;
        scanf("%d", &optionChosen);
        if (optionChosen == 1) {
            printf("Correct!\n");
        } else if (optionChosen == 2) {
            printf("Wrong answer\n");
        } else if (optionChosen == 3) {
            printf("Correct!\n");
        } else if (optionChosen == 4) {
            printf("Wrong answer\n");
        }
        questionsAnswered++;
        printf("Time remaining: %d seconds\n", totalTime - (questionsAnswered * 15));
        printf("Do you want to continue? (y/n) ");
        char continueChoice;
        scanf(" %c", &continueChoice);
        if (continueChoice == 'n') {
            break;
        }
    }
    printf("You have completed the exam in %d seconds\n", totalTime);
}

int main() {
    displayExam();
    takeExam();
    return 0;
}