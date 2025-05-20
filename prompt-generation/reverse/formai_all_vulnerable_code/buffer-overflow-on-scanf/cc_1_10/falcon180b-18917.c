//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} student_t;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char choices[MAX_CHOICES][MAX_ANSWER_LENGTH];
    int answer;
} question_t;

void generate_questions(question_t questions[]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        strcpy(questions[i].question, "What is love? ");
        for (int j = 0; j < MAX_CHOICES; j++) {
            int len = rand() % MAX_ANSWER_LENGTH + 1;
            questions[i].choices[j][0] = '\0';
            for (int k = 0; k < len; k++) {
                questions[i].choices[j][k] = rand() % 26 + 'a';
            }
        }
        questions[i].answer = rand() % MAX_CHOICES;
    }
}

int main() {
    system("clear");
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    student_t students[MAX_STUDENTS];
    student_t *current_student = &students[0];
    while (strcmp(name, current_student->name)!= 0) {
        current_student++;
        if (current_student == &students[MAX_STUDENTS]) {
            printf("You are not registered for this exam. Please contact the administrator.\n");
            return 1;
        }
    }

    question_t questions[MAX_QUESTIONS];
    generate_questions(questions);

    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int choice;
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j+1, questions[i].choices[j]);
        }
        scanf("%d", &choice);
        if (choice == questions[i].answer) {
            score++;
        }
    }

    printf("\nCongratulations, %s! You have completed the exam with a score of %d out of %d.\n", name, score, MAX_QUESTIONS);

    return 0;
}