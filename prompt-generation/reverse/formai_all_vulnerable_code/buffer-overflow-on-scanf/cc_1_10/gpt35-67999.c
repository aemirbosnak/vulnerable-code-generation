//FormAI DATASET v1.0 Category: Online Examination System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_QUESTIONS 20
#define MAX_OPTIONS 4

typedef struct {
    char question[1000];
    char options[MAX_OPTIONS][100];
    int correctOption;
}Question;

int main() {
    int option, totalQuestions, attemptedQuestions = 0, correctAnswers = 0, remainingQuestions[MAX_QUESTIONS];
    char name[50];
    Question questions[MAX_QUESTIONS];

    srand(time(NULL));

    printf("Welcome to the Online Examination System!\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    FILE *file;
    char *filename = "questions.txt";
    file = fopen(filename, "r");

    if(file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    totalQuestions = 0;

    while(!feof(file) && totalQuestions < MAX_QUESTIONS) {
        Question q;
        char buffer[1000];
        char *token;
        fgets(buffer, 1000, file);
        strcpy(q.question, buffer);
        for(int i=0; i<MAX_OPTIONS; i++) {
            fgets(buffer, 1000, file);
            strcpy(q.options[i], buffer);
        }
        fgets(buffer, 1000, file);
        token = strtok(buffer, "\n");
        q.correctOption = atoi(token);
        questions[totalQuestions++] = q;
    }

    fclose(file);

    printf("\nHello, %s. Let's start the exam!\n", name);

    for(int i=0; i<totalQuestions; i++)
        remainingQuestions[i] = i;

    while(attemptedQuestions < totalQuestions) {
        int randIndex = rand() % (totalQuestions - attemptedQuestions);
        int qIndex = remainingQuestions[randIndex];
        Question q = questions[qIndex];

        printf("\nQuestion %d: %s", attemptedQuestions+1, q.question);
        for(int i=0; i<MAX_OPTIONS; i++)
            printf("%d. %s", i+1, q.options[i]);

        printf("Enter your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &option);

        if(option == q.correctOption) {
            printf("Congratulations! That is the correct answer.\n");
            correctAnswers++;
        }
        else
            printf("Sorry, that is incorrect. The correct answer is option %d.\n", q.correctOption);

        for(int i=randIndex; i<totalQuestions-1; i++)
            remainingQuestions[i] = remainingQuestions[i+1];

        attemptedQuestions++;
    }

    printf("\nCongratulations, %s! You have completed the exam.\n", name);
    printf("You answered %d out of %d questions correctly.\n", correctAnswers, totalQuestions);

    return 0;
}