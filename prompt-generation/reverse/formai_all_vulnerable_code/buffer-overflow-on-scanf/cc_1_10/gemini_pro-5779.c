//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[256];
    char options[4][64];
    char answer;
};

struct Exam {
    char name[64];
    int num_questions;
    struct Question questions[10];
};

void create_exam(struct Exam *exam) {
    printf("Enter exam name: ");
    scanf("%s", exam->name);

    printf("Enter number of questions: ");
    scanf("%d", &exam->num_questions);

    for (int i = 0; i < exam->num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf(" %[^\n]s", exam->questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("Enter option %d: ", j + 1);
            scanf(" %[^\n]s", exam->questions[i].options[j]);
        }

        printf("Enter answer (A, B, C, D): ");
        scanf(" %c", &exam->questions[i].answer);
    }
}

void take_exam(struct Exam *exam) {
    int score = 0;

    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A' + j, exam->questions[i].options[j]);
        }

        char answer;
        printf("Enter your answer (A, B, C, D): ");
        scanf(" %c", &answer);

        if (answer == exam->questions[i].answer) {
            score++;
        }
    }

    printf("Your score: %d/%d\n", score, exam->num_questions);
}

int main() {
    struct Exam exam;

    int choice;
    do {
        printf("1. Create exam\n");
        printf("2. Take exam\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_exam(&exam);
                break;
            case 2:
                take_exam(&exam);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}