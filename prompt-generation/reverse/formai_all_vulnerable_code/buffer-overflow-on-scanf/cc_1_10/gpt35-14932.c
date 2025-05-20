//FormAI DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_FILE_LEN 200

struct Student {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
};

void addStudent(FILE* fp, struct Student student) {
    fwrite(&student, sizeof(struct Student), 1, fp);
}

void printStudents(FILE* fp) {
    printf("Name\t\tAge\t\tGPA\n");
    printf("-----------------------------------\n");
    struct Student student;
    while (fread(&student, sizeof(struct Student), 1, fp)) {
        printf("%s\t\t%d\t\t%.2f\n", student.name, student.age, student.gpa);
    }
}

int main() {
    char filename[MAX_FILE_LEN];
    printf("Welcome to our student registration system!\n");
    printf("Please enter the name of the file you wish to use: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "ab");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }
    printf("File opened successfully.\n");
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a student\n");
        printf("2. Print students\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Please enter the student's name: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);
                struct Student student;
                strncpy(student.name, name, MAX_NAME_LEN);
                printf("Please enter the student's age: ");
                scanf("%d", &student.age);
                printf("Please enter the student's GPA: ");
                scanf("%f", &student.gpa);
                addStudent(fp, student);
                printf("Student added successfully.\n");
                break;
            case 2:
                printStudents(fp);
                break;
            case 3:
                fclose(fp);
                printf("File closed.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}