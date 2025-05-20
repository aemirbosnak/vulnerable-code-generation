//Falcon-180B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_GRADES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int grades[MAX_GRADES];
    int num_grades;
} student_t;

student_t students[MAX_STUDENTS];
int num_students = 0;

void add_student() {
    char name[MAX_NAME_LENGTH];
    printf("Enter student name: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student already exists.\n");
            return;
        }
    }

    strcpy(students[num_students].name, name);
    students[num_students].num_grades = 0;
    num_students++;

    printf("Student added.\n");
}

void add_grade() {
    int i;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, students[num_students - 1].name) == 0) {
            break;
        }
    }

    if (i == num_students - 1) {
        printf("Student not found.\n");
        return;
    }

    int grade;
    printf("Enter grade: ");
    scanf("%d", &grade);

    students[i].grades[students[i].num_grades] = grade;
    students[i].num_grades++;

    printf("Grade added.\n");
}

void print_grades() {
    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].num_grades == 0) {
            continue;
        }

        printf("Student: %s\n", students[i].name);
        printf("Grades:\n");

        int j;
        for (j = 0; j < students[i].num_grades; j++) {
            printf("%d\n", students[i].grades[j]);
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add student\n");
        printf("2. Add grade\n");
        printf("3. Print grades\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                add_grade();
                break;
            case 3:
                print_grades();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}