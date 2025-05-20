//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_STUDENTS 50

struct question {
    char question_text[100];
    int correct_answer;
    char options[MAX_OPTIONS][100];
};

struct student {
    char name[50];
    int score;
};

void generate_question(struct question *q) {
    int i;
    srand(time(NULL));
    q->correct_answer = rand() % MAX_OPTIONS;
    for (i = 0; i < MAX_OPTIONS; i++) {
        if (i == q->correct_answer) {
            sprintf(q->options[i], "%d. %s (Correct)", i+1, q->options[i]);
        } else {
            sprintf(q->options[i], "%d. %s", i+1, q->options[i]);
        }
    }
}

int main() {
    int i, j, num_students;
    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    printf("\nEnter the questions:\n");
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d:\n", i+1);
        scanf("%s", questions[i].question_text);
        generate_question(&questions[i]);
    }

    printf("\n\nOnline Examination System\n");
    for (i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i+1);
        scanf("%s", students[i].name);
        for (j = 0; j < MAX_QUESTIONS; j++) {
            printf("%s\n", questions[j].question_text);
            int choice;
            scanf("%d", &choice);
            if (choice == questions[j].correct_answer) {
                students[i].score++;
                printf("%d. %s (Correct)\n", choice, questions[j].options[choice-1]);
            } else {
                printf("%d. %s (Incorrect)\n", choice, questions[j].options[choice-1]);
            }
        }
        printf("\n%s's score: %d\n\n", students[i].name, students[i].score);
    }

    return 0;
}