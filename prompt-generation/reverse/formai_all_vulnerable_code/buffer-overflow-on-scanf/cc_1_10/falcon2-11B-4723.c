//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_SIZE 1000

struct student {
    char name[MAX_NAME_LENGTH];
    int age;
    int roll_no;
    float grade;
    char gender;
};

struct student *create_student(char name[], int age, int roll_no, float grade, char gender) {
    struct student *student = (struct student *)malloc(sizeof(struct student));
    strcpy(student->name, name);
    student->age = age;
    student->roll_no = roll_no;
    student->grade = grade;
    student->gender = gender;
    return student;
}

void print_student(struct student *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Roll No.: %d\n", student->roll_no);
    printf("Grade: %f\n", student->grade);
    printf("Gender: %c\n", student->gender);
}

void create_database(struct student *students, int size) {
    struct student *current;
    for (int i = 0; i < size; i++) {
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter age: ");
        scanf("%d", &students[i].age);
        printf("Enter roll no.: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter grade: ");
        scanf("%f", &students[i].grade);
        printf("Enter gender: ");
        scanf(" %c", &students[i].gender);
        current = students + i;
        printf("Student %d details saved.\n", i + 1);
    }
}

void search_student(struct student *students, int size, char name[]) {
    struct student *current;
    printf("Enter student name to search: ");
    scanf("%s", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            print_student(students + i);
            break;
        }
    }
}

int main() {
    struct student *students = (struct student *)malloc(MAX_SIZE * sizeof(struct student));
    int size = 0;
    while (1) {
        printf("1. Create database\n");
        printf("2. Search student\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_database(students, MAX_SIZE);
                size = MAX_SIZE;
                break;
            case 2:
                search_student(students, size, "");
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}