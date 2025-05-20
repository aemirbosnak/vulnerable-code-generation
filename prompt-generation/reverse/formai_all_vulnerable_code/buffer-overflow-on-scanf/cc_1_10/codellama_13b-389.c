//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct student {
    char name[50];
    char rollno[10];
    int age;
    float marks;
};

// Function to add student information
void addStudent(struct student* s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter roll no: ");
    scanf("%s", s->rollno);
    printf("Enter age: ");
    scanf("%d", &s->age);
    printf("Enter marks: ");
    scanf("%f", &s->marks);
}

// Function to display student information
void displayStudent(struct student* s) {
    printf("Name: %s\n", s->name);
    printf("Roll no: %s\n", s->rollno);
    printf("Age: %d\n", s->age);
    printf("Marks: %.2f\n", s->marks);
}

// Function to update student information
void updateStudent(struct student* s) {
    printf("Enter new name: ");
    scanf("%s", s->name);
    printf("Enter new roll no: ");
    scanf("%s", s->rollno);
    printf("Enter new age: ");
    scanf("%d", &s->age);
    printf("Enter new marks: ");
    scanf("%f", &s->marks);
}

// Function to delete student information
void deleteStudent(struct student* s) {
    memset(s, 0, sizeof(struct student));
}

int main() {
    struct student s;
    int choice;

    while (1) {
        printf("1. Add student\n");
        printf("2. Display student\n");
        printf("3. Update student\n");
        printf("4. Delete student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&s);
                break;
            case 2:
                displayStudent(&s);
                break;
            case 3:
                updateStudent(&s);
                break;
            case 4:
                deleteStudent(&s);
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}