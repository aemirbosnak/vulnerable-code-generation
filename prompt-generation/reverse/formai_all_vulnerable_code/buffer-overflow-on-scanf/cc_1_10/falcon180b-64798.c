//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100

struct question {
    char question[100];
    char options[MAX_OPTIONS][50];
    int answer;
};

struct student {
    char name[50];
    int score;
};

int main() {
    int num_questions, num_students;
    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    srand(time(NULL));

    for (int i = 0; i < num_questions; i++) {
        questions[i].answer = rand() % MAX_OPTIONS;
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter option %d: ", j+1);
            scanf("%s", questions[i].options[j]);
        }
    }

    printf("Enter the names of the students: ");
    for (int i = 0; i < num_students; i++) {
        scanf("%s", students[i].name);
    }

    int correct_answers[MAX_STUDENTS] = {0};
    int total_questions = num_questions;

    for (int i = 0; i < num_students; i++) {
        printf("Student %s's score: ", students[i].name);

        for (int j = 0; j < num_questions; j++) {
            int option = 0;
            printf("%s ", questions[j].question);

            for (int k = 0; k < MAX_OPTIONS; k++) {
                printf("%d. %s\n", k+1, questions[j].options[k]);
            }

            scanf("%d", &option);

            if (option == questions[j].answer) {
                correct_answers[i]++;
            }
        }

        printf("Total score: %d/%d\n\n", correct_answers[i], total_questions);
    }

    return 0;
}