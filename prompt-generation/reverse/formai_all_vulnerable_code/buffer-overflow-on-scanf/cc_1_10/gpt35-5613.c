//FormAI DATASET v1.0 Category: Data mining ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int age;
    float marks;
};

void displayMenu() {
    printf("Welcome to the Student Record Management System\n");
    printf("-----------------------------------------------\n");
    printf("1. Add a student record\n");
    printf("2. Display all student records\n");
    printf("3. Display student record with highest marks\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addStudent(struct student *s) {
    printf("Enter Name: ");
    scanf("%s", s->name);
    printf("Enter Age: ");
    scanf("%d", &s->age);
    printf("Enter Marks: ");
    scanf("%f", &s->marks);
}

void displayAllStudents(struct student *s, int n) {
    printf("Name\tAge\tMarks\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].age, s[i].marks);
    }
}

void displayStudentWithHighestMarks(struct student *s, int n) {
    float maxMarks = 0;
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(s[i].marks > maxMarks) {
            maxMarks = s[i].marks;
            index = i;
        }
    }

    printf("Name\tAge\tMarks\n");
    printf("%s\t%d\t%.2f\n", s[index].name, s[index].age, s[index].marks);
}

int main() {
    int choice, n = 0;
    struct student *s;
    s = (struct student*) malloc(sizeof(struct student));

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                n++;
                s = (struct student*) realloc(s, n * sizeof(struct student));
                addStudent(&s[n-1]);
                break;
            case 2:
                displayAllStudents(s, n);
                break;
            case 3:
                displayStudentWithHighestMarks(s, n);
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid Choice. Try Again.\n");
        }
    } while(choice != 4);

    free(s);
    return 0;
}