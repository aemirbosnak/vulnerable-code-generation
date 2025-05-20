//FormAI DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct Student {
    int roll_no;
    char name[30];
    int marks;
};

// Function prototypes
void add_student(struct Student *students, int *size);
void modify_student(struct Student *students, int *size);
void delete_student(struct Student *students, int *size);
void display_student(struct Student *students, int size);
void search_student(struct Student *students, int size);

int main() {
    struct Student students[MAX];
    int size = 0;
    int choice;

    // Menu driven program
    do {
        printf("\n1. Add Student\n");
        printf("2. Modify Student Details\n");
        printf("3. Delete Student\n");
        printf("4. Display All Students\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_student(students, &size);
                break;
            case 2:
                modify_student(students, &size);
                break;
            case 3:
                delete_student(students, &size);
                break;
            case 4:
                display_student(students, size);
                break;
            case 5:
                search_student(students, size);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (1);
    return 0;
}

void add_student(struct Student *students, int *size) {
    if (*size >= MAX) {
        printf("Cannot add more students.\n");
        return;
    }

    struct Student new_student;
    printf("Enter roll number: ");
    scanf("%d", &new_student.roll_no);
    printf("Enter name: ");
    scanf("%s", new_student.name);
    printf("Enter marks: ");
    scanf("%d", &new_student.marks);

    students[*size] = new_student;
    (*size)++;
}

void modify_student(struct Student *students, int *size) {
    int roll_no;
    printf("Enter roll number of student to modify: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < *size; i++) {
        if (students[i].roll_no == roll_no) {
            printf("New name: ");
            scanf("%s", students[i].name);
            printf("New marks: ");
            scanf("%d", &students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

void delete_student(struct Student *students, int *size) {
    int roll_no;
    printf("Enter roll number of student to delete: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < *size; i++) {
        if (students[i].roll_no == roll_no) {
            // Removing student by shifting all elements to left
            for (int j = i; j < *size - 1; j++) {
                students[j] = students[j+1];
            }
            (*size)--;
            return;
        }
    }
    printf("Student not found.\n");
}

void display_student(struct Student *students, int size) {
    if (size == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nRoll No\t\tName\t\tMarks\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t\t%s\t\t%d\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

void search_student(struct Student *students, int size) {
    if (size == 0) {
        printf("No students to search.\n");
        return;
    }

    int roll_no;
    printf("Enter roll number of student to search: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < size; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %d\n", students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}