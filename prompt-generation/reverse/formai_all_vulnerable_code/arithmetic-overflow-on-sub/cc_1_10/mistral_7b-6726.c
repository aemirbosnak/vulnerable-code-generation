//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll_number;
    char name[50];
    float marks;
} Student;

void readStudentData(Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter roll number of student %d: ", i + 1);
        scanf("%d", &(students[i].roll_number));
        fflush(stdin);
        printf("Enter name of student %d: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &(students[i].marks));
    }
}

void displayStudentData(Student* students, int size) {
    printf("\n%-10s %-20s %-10s %-10s\n", "Roll Number", "Name", "Marks", "Status");
    for (int i = 0; i < size; i++) {
        printf("%-10d %-20s %-10.2f %s\n", students[i].roll_number, students[i].name, students[i].marks, (students[i].marks >= 50) ? "Pass" : "Fail");
    }
}

void sortStudents(Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    Student* students = malloc(n * sizeof(Student));
    readStudentData(students, n);
    sortStudents(students, n);
    displayStudentData(students, n);
    free(students);
    return 0;
}