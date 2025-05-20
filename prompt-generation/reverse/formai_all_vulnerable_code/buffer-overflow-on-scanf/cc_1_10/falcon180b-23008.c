//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char name[MAX];
    int roll;
} student;

student arr[MAX];
int n;

void addStudent() {
    printf("\nEnter name of student: ");
    scanf("%[^\n]", arr[n].name);
    printf("Enter roll number of student: ");
    scanf("%d", &arr[n].roll);
    n++;
}

void viewStudents() {
    printf("\nList of students:\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s - Roll: %d\n", i+1, arr[i].name, arr[i].roll);
    }
}

int main() {
    printf("\nWelcome to Student Management System\n");
    printf("---------------------------------\n");
    int ch;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Add student\n");
        printf("2. View students\n");
        printf("3. Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(ch!=3);
    return 0;
}