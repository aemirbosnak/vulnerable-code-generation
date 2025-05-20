//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 5
#define MAX_NAME_LENGTH 50

struct question {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[10];
};

struct student {
    char name[MAX_NAME_LENGTH];
    int score;
};

void print_question(struct question q) {
    printf("\n%s\n", q.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int main() {
    srand(time(NULL));
    struct question questions[MAX_QUESTIONS];
    struct student students[10];
    int num_questions, num_students, current_question, current_student;
    int choice;

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i].question);

        printf("Enter option A for question %d: ", i + 1);
        scanf("%s", questions[i].options[0]);

        printf("Enter option B for question %d: ", i + 1);
        scanf("%s", questions[i].options[1]);

        printf("Enter option C for question %d: ", i + 1);
        scanf("%s", questions[i].options[2]);

        printf("Enter option D for question %d: ", i + 1);
        scanf("%s", questions[i].options[3]);

        printf("Enter option E for question %d: ", i + 1);
        scanf("%s", questions[i].options[4]);

        printf("Enter the answer for question %d: ", i + 1);
        scanf("%s", questions[i].answer);
    }

    for (int i = 0; i < num_students; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    for (current_question = 0; current_question < num_questions; current_question++) {
        for (current_student = 0; current_student < num_students; current_student++) {
            print_question(questions[current_question]);
            scanf("%d", &choice);

            if (strcmp(questions[current_question].answer, questions[current_question].options[choice - 1]) == 0) {
                students[current_student].score += 1;
            }
        }
    }

    printf("\nResults:\n");

    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}