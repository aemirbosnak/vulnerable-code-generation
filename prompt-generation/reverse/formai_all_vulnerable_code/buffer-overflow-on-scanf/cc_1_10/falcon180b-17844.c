//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_ANSWER_CHOICES 5
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
    char choices[MAX_ANSWER_CHOICES][MAX_ANSWER_LENGTH];
    int num_choices;
    int correct_choice;
} Question;

void read_questions(Question* questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i].question);

        printf("Enter answer: ");
        scanf("%s", questions[i].answer);

        printf("Enter number of choices: ");
        scanf("%d", &questions[i].num_choices);

        printf("Enter choices:\n");
        for (int j = 0; j < questions[i].num_choices; j++) {
            scanf("%s", questions[i].choices[j]);
        }

        printf("Enter correct choice: ");
        scanf("%d", &questions[i].correct_choice);
    }
}

void take_exam(Question* questions, int num_questions) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n%s\n", i + 1, questions[i].question);

        for (int j = 0; j < questions[i].num_choices; j++) {
            printf("%d. %s\n", j + 1, questions[i].choices[j]);
        }

        int choice;
        scanf("%d", &choice);

        if (choice == questions[i].correct_choice) {
            score++;
        }
    }

    printf("\nYour final score is: %d/%d\n", score, num_questions);
}

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions;

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    if (num_questions > MAX_QUESTIONS) {
        printf("Error: Too many questions.\n");
        return 1;
    }

    read_questions(questions, num_questions);
    take_exam(questions, num_questions);

    return 0;
}