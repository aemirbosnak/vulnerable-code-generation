//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char name[MAX];
    int age;
    int roll;
} student;

void addStudent(student *s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter age: ");
    scanf("%d", &s->age);
    printf("Enter roll number: ");
    scanf("%d", &s->roll);
}

void displayStudent(student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Roll number: %d\n", s.roll);
}

int main() {
    student s[MAX];
    int i = 0, choice;
    
    do {
        printf("\n\nWelcome to Student Management System\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by name\n");
        printf("4. Search student by roll number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(i < MAX) {
                    addStudent(&s[i]);
                    i++;
                } else {
                    printf("Sorry, maximum number of students reached.\n");
                }
                break;
            case 2:
                for(int j=0; j<i; j++) {
                    displayStudent(s[j]);
                }
                break;
            case 3:
                printf("Enter name to search: ");
                char name[MAX];
                scanf("%s", name);
                for(int j=0; j<i; j++) {
                    if(strcmp(s[j].name, name) == 0) {
                        displayStudent(s[j]);
                    }
                }
                break;
            case 4:
                printf("Enter roll number to search: ");
                int roll;
                scanf("%d", &roll);
                for(int j=0; j<i; j++) {
                    if(s[j].roll == roll) {
                        displayStudent(s[j]);
                    }
                }
                break;
            case 5:
                printf("Thank you for using Student Management System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 5);
    
    return 0;
}