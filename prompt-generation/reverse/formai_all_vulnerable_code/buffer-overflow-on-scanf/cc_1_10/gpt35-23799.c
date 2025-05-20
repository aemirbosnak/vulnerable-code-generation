//FormAI DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_ANSWERS 4
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[MAX_NAME_LENGTH];
    char answers[MAX_ANSWERS][MAX_NAME_LENGTH];
    int correct_answer;
} Question;

void display_question(Question q) {
    printf("%s\n", q.question);
    for(int i=0; i<MAX_ANSWERS; i++) {
        printf("%d) %s\n", i+1, q.answers[i]);
    }
}

int validate_answer(int answer) {
    if(answer >= 1 && answer <= 4) {
        return 1;
    } else {
        printf("Invalid answer! Please enter between 1-4\n");
        return 0;
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions;
    printf("Enter number of questions (max %d): ", MAX_QUESTIONS);
    scanf("%d", &num_questions);
    getchar(); // remove newline from buffer

    for(int i=0; i<num_questions; i++) {
        printf("Enter Question %d: ", i+1);
        fgets(questions[i].question, MAX_NAME_LENGTH, stdin);
        questions[i].question[strlen(questions[i].question) - 1] = '\0'; // remove newline
        for(int j=0; j<MAX_ANSWERS; j++) {
            printf("Enter answer %d for Question %d: ", j+1, i+1);
            fgets(questions[i].answers[j], MAX_NAME_LENGTH, stdin);
            questions[i].answers[j][strlen(questions[i].answers[j]) - 1] = '\0'; // remove newline
        }
        printf("Enter correct answer for Question %d (1-4): ", i+1);
        scanf("%d", &questions[i].correct_answer);
        getchar(); // remove newline from buffer
        while(!validate_answer(questions[i].correct_answer)) {
            printf("Enter correct answer for Question %d (1-4): ", i+1);
            scanf("%d", &questions[i].correct_answer);
            getchar(); // remove newline from buffer
        }
    }

    printf("Starting Exam!\n");
    int score = 0;
    for(int i=0; i<num_questions; i++) {
        display_question(questions[i]);
        printf("Enter your answer (1-4): ");
        int answer;
        scanf("%d", &answer);
        getchar(); // remove newline from buffer
        if(validate_answer(answer)){
            if(answer == questions[i].correct_answer) {
                score++;
                printf("Correct!\n");
            } else {
                printf("Incorrect!\n");
            }
        } else {
            i--;
        }
    }

    printf("\n\n");
    printf("Your Score: %d/%d\n", score, num_questions);
    return 0;
}