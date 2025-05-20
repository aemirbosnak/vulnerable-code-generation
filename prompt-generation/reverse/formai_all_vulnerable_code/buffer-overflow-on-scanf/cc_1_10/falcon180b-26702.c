//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int roll_no;
} student;

student students[MAX_SIZE];
int num_students = 0;

void add_student(char name[], int roll_no) {
    if (num_students >= MAX_SIZE) {
        printf("Error: Maximum number of students reached!\n");
        return;
    }
    strcpy(students[num_students].name, name);
    students[num_students].roll_no = roll_no;
    num_students++;
}

void search_student(char name[], int roll_no) {
    int i;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0 && students[i].roll_no == roll_no) {
            printf("Student found: %s\n", students[i].name);
            return;
        }
    }
    printf("Student not found!\n");
}

int main() {
    char name[50];
    int roll_no, choice;
    
    do {
        printf("Enter 1 to add a student\n");
        printf("Enter 2 to search for a student\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name of student: ");
                scanf("%[^\n]", name);
                printf("Enter roll number of student: ");
                scanf("%d", &roll_no);
                add_student(name, roll_no);
                break;
                
            case 2:
                printf("Enter name of student to search: ");
                scanf("%[^\n]", name);
                printf("Enter roll number of student to search: ");
                scanf("%d", &roll_no);
                search_student(name, roll_no);
                break;
                
            case 0:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 0);
    
    return 0;
}