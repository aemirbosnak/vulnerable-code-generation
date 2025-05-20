//Gemma-7B DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10

typedef struct student {
    char name[20];
    int roll_no;
    float marks;
} student;

student students[MAX_STUDENTS];

void add_student() {
    student new_student;

    printf("Enter student name: ");
    scanf("%s", new_student.name);

    printf("Enter student roll no: ");
    scanf("%d", &new_student.roll_no);

    printf("Enter student marks: ");
    scanf("%f", &new_student.marks);

    students[MAX_STUDENTS - 1] = new_student;
}

void view_students() {
    int i;

    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

void search_student() {
    char search_name[20];

    printf("Enter student name: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (strcmp(search_name, students[i].name) == 0) {
            printf("Name: %s\n", students[i].name);
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int choice;

    printf("Enter 1 to add a student, 2 to view students, 3 to search for a student: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_student();
            break;
        case 2:
            view_students();
            break;
        case 3:
            search_student();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}