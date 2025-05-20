//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
} Student;

void addStudent(Student* students, int numStudents) {
    printf("Enter student name (max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", students[numStudents].name);

    printf("Enter student age: ");
    scanf("%d", &students[numStudents].age);

    printf("Enter student GPA: ");
    scanf("%f", &students[numStudents].gpa);

    numStudents++;
}

void displayStudents(Student* students, int numStudents) {
    printf("\nStudents:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s (%d years old) - GPA: %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    addStudent(students, numStudents);

    while (numStudents < MAX_STUDENTS) {
        printf("\nDo you want to add another student? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            addStudent(students, numStudents);
        } else {
            break;
        }
    }

    displayStudents(students, numStudents);

    return 0;
}