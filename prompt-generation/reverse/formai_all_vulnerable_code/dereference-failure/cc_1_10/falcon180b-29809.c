//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[20];
    int score;
} Student;

void init_students(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        students[i].id = i + 1;
        sprintf(students[i].name, "Student %d", i + 1);
        students[i].score = 0;
    }
}

void generate_question(int difficulty, char* question, char* answer) {
    switch (difficulty) {
        case 1:
            sprintf(question, "What is 2 + 2?");
            sprintf(answer, "4");
            break;
        case 2:
            sprintf(question, "What is the capital of France?");
            sprintf(answer, "Paris");
            break;
        case 3:
            sprintf(question, "What is the meaning of life?");
            sprintf(answer, "42");
            break;
        default:
            sprintf(question, "Invalid difficulty level.");
            sprintf(answer, "");
            break;
    }
}

int main() {
    srand(time(NULL));

    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student* students = (Student*)malloc(num_students * sizeof(Student));
    init_students(students, num_students);

    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        int difficulty;
        printf("Enter the difficulty level for question %d (1-3): ", i + 1);
        scanf("%d", &difficulty);

        char question[100];
        char answer[20];
        generate_question(difficulty, question, answer);

        printf("Question %d: %s\n", i + 1, question);

        for (int j = 0; j < num_students; j++) {
            printf("Student %d's answer: ", j + 1);
            scanf("%s", students[j].name);

            if (strcmp(students[j].name, answer) == 0) {
                students[j].score++;
            }
        }
    }

    printf("\nResults:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: %d/%d\n", i + 1, students[i].score, num_questions);
    }

    free(students);

    return 0;
}