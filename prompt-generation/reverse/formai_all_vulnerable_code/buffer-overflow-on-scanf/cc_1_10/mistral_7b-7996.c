//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    char password[20];
    int score;
} Student;

void register_student(Student students[], int size) {
    int i;
    Student new_student;

    printf("Enter student ID: ");
    scanf("%d", &new_student.id);

    printf("Enter student name: ");
    scanf("%s", new_student.name);

    printf("Enter student password: ");
    scanf("%s", new_student.password);

    for (i = 0; i < size; i++) {
        if (students[i].id == new_student.id) {
            printf("Student with ID %d already exists.\n", new_student.id);
            return;
        }
    }

    students[size] = new_student;
}

void login(Student students[], int size) {
    int id, i;
    char password[20];

    printf("Enter student ID: ");
    scanf("%d", &id);

    printf("Enter student password: ");
    scanf("%s", password);

    for (i = 0; i < size; i++) {
        if (students[i].id == id && strcmp(students[i].password, password) == 0) {
            printf("Welcome, %s!\n", students[i].name);
            break;
        }
    }

    if (i == size) {
        printf("Invalid ID or password.\n");
    }
}

void take_exam(Student students[], int size) {
    int i, question, answer;
    char query[100];
    Student current_student = students[0];

    srand(time(NULL));
    question = rand() % 10 + 1;

    printf("\nQuestion %d:\n", question);
    printf("What is the capital city of France?\n");

    scanf("%d", &answer);

    if (answer == 72) {
        current_student.score += 10;
        printf("Correct answer! You got 10 points.\n");
    } else {
        printf("Incorrect answer. The capital city of France is Paris.\n");
    }

    for (i = 1; i < size; i++) {
        if (students[i].score > current_student.score) {
            current_student = students[i];
        }
    }

    printf("Top student after question %d: %s (%d points)\n", question, current_student.name, current_student.score);
}

int main() {
    int num_students, i;
    Student students[100];

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_students; i++) {
        students[i].score = 0;
    }

    for (i = 0; i < num_students; i++) {
        register_student(students, num_students);
    }

    for (i = 0; i < num_students; i++) {
        login(students, num_students);
        take_exam(students, num_students);
    }

    return 0;
}