//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

struct Student students[100];
int numStudents = 0;

void addStudent() {
    printf("Enter student name: ");
    scanf("%s", students[numStudents].name);
    printf("Enter student roll: ");
    scanf("%d", &students[numStudents].roll);
    printf("Enter student marks: ");
    scanf("%d", &students[numStudents].marks);
    numStudents++;
}

void displayStudents() {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll: %d\n", students[i].roll);
        printf("Marks: %d\n", students[i].marks);
        printf("\n");
    }
}

void searchStudent() {
    int roll;
    printf("Enter student roll: ");
    scanf("%d", &roll);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].roll == roll) {
            printf("Student found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll: %d\n", students[i].roll);
            printf("Marks: %d\n", students[i].marks);
            printf("\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void deleteStudent() {
    int roll;
    printf("Enter student roll: ");
    scanf("%d", &roll);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].roll == roll) {
            for (int j = i + 1; j < numStudents; j++) {
                students[j - 1] = students[j];
            }
            numStudents--;
            printf("Student deleted!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void updateStudent() {
    int roll;
    printf("Enter student roll: ");
    scanf("%d", &roll);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].roll == roll) {
            printf("Enter new student name: ");
            scanf("%s", students[i].name);
            printf("Enter new student marks: ");
            scanf("%d", &students[i].marks);
            printf("Student updated!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int main() {
    int choice;
    do {
        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Search student\n");
        printf("4. Delete student\n");
        printf("5. Update student\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                updateStudent();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}