//FormAI DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[50];
    int rollno;
    float marks;
} Student;

void add_student() {
    FILE *file;
    Student student;

    file = fopen("students.dat", "ab");

    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter student roll number: ");
    scanf("%d", &student.rollno);
    printf("Enter student marks: ");
    scanf("%f", &student.marks);

    fwrite(&student, sizeof(Student), 1, file);

    printf("\nStudent added successfully!\n\n");

    fclose(file);
}

void view_students() {
    FILE *file;
    Student student;

    file = fopen("students.dat", "rb");

    printf("All students:\n\n");

    while (fread(&student, sizeof(Student), 1, file)) {
        printf("Name: %s\n", student.name);
        printf("Roll Number: %d\n", student.rollno);
        printf("Marks: %.2f\n", student.marks);
        printf("\n");
    }

    fclose(file);
}

void search_student() {
    FILE *file;
    Student student;
    int roll_no;
    int found = 0;

    file = fopen("students.dat","rb");

    printf("Enter student roll number: ");
    scanf("%d", &roll_no);

    while (fread(&student, sizeof(Student), 1, file)) {
        
        if (student.rollno == roll_no) {
            printf("\nStudent found!\n");
            printf("Name: %s\n", student.name);
            printf("Roll Number: %d\n", student.rollno);
            printf("Marks: %.2f\n", student.marks);
            printf("\n");
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nStudent not found!\n\n");
    }

    fclose(file);
}

int main() {
    int choice;
    printf("Welcome to Student Management System\n\n");

    while(1) {
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
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
            case 4:
                printf("\nThanks for using Student Management System!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice, try again!\n\n");
        }
    }

    return 0;
}