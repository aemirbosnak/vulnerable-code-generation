//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

struct Question {
    char text[100];
    char options[MAX_OPTIONS][50];
    int answer;
};

int main() {
    struct Question questions[MAX_QUESTIONS];

    printf("Welcome to the Online Examination System\n");

    // Retrieve questions and options
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nEnter question %d:\n", i+1);
        fgets(questions[i].text, 100, stdin);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter option %d: ", j+1);
            fgets(questions[i].options[j], 50, stdin);
        }
        printf("Enter the correct answer (1-4): ");
        scanf("%d", &questions[i].answer);
        fflush(stdin); // clear input buffer
    }

    // Display questions and options
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\n%d. %s\n", i+1, questions[i].text);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d) %s", j+1, questions[i].options[j]);
        }
    }

    // Take the exam
    int score = 0;
    printf("\n\nBegin the exam:\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\n%d. %s\n", i+1, questions[i].text);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d) %s", j+1, questions[i].options[j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        fflush(stdin); // clear input buffer
        if (answer == questions[i].answer) {
            score++;
        }
    }

    // Display exam results
    printf("\n\nYour score: %d / %d\n", score, MAX_QUESTIONS);
    if (score >= (MAX_QUESTIONS * 0.6)) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }

    return 0;
}