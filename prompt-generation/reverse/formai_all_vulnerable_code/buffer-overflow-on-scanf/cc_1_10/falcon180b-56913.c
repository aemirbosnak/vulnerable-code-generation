//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int id;
    char name[50];
    int score;
} student;

void addStudent(student* s, int id, char* name, int score) {
    strcpy(s->name, name);
    s->id = id;
    s->score = score;
}

void displayStudents(student* s, int numStudents) {
    printf("\nName\tID\tScore\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s\t%d\t%d\n", s[i].name, s[i].id, s[i].score);
    }
}

int main() {
    student s[SIZE];
    int numStudents = 0;
    char choice;

    do {
        printf("\nOnline Examination System\n");
        printf("1. Add Student\n2. Display Students\n3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (numStudents < SIZE) {
                int id;
                char name[50];
                int score;

                printf("Enter ID: ");
                scanf("%d", &id);

                printf("Enter Name: ");
                scanf("%s", name);

                printf("Enter Score: ");
                scanf("%d", &score);

                addStudent(s, id, name, score);
                numStudents++;

                printf("\nStudent added successfully!\n");
            } else {
                printf("Maximum number of students reached.\n");
            }
            break;

        case '2':
            if (numStudents > 0) {
                displayStudents(s, numStudents);
            } else {
                printf("No students added yet.\n");
            }
            break;

        case '3':
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= '3');

    return 0;
}