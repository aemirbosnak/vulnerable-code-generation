//FormAI DATASET v1.0 Category: Database querying ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int id;
    char name[50];
    int age;
    double gpa;
};

void printMenu(){
    printf("\n-- STUDENT DATABASE MANAGEMENT --\n");
    printf("1. Add a new student\n");
    printf("2. Display all students\n");
    printf("3. Search for a student by ID\n");
    printf("4. Update a student's information\n");
    printf("5. Delete a student\n");
    printf("6. Exit the program\n");
}

void addStudent(struct student* s, int* n){
    printf("\nEnter the following information to add a new student:\n");
    printf("ID: ");
    scanf("%d", &s[*n].id);
    printf("Name: ");
    scanf("%s", s[*n].name);
    printf("Age: ");
    scanf("%d", &s[*n].age);
    printf("GPA: ");
    scanf("%lf", &s[*n].gpa);
    (*n)++;
    printf("\nStudent added successfully!\n");
}

void displayAllStudents(struct student* s, int n){
    if(n == 0){
        printf("\nThere are no students in the database.\n");
        return;
    }
    printf("\nID\tName\tAge\tGPA\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%s\t%d\t%.2lf\n", s[i].id, s[i].name, s[i].age, s[i].gpa);
    }
}

void searchByID(struct student* s, int n){
    int id;
    printf("\nEnter the ID of the student you want to search for: ");
    scanf("%d", &id);
    for(int i = 0; i < n; i++){
        if(s[i].id == id){
            printf("\nID\tName\tAge\tGPA\n");
            printf("%d\t%s\t%d\t%.2lf\n", s[i].id, s[i].name, s[i].age, s[i].gpa);
            return;
        }
    }
    printf("\nStudent with ID %d not found in the database.\n", id);
}

void updateStudent(struct student* s, int n){
    int id;
    printf("\nEnter the ID of the student you want to update: ");
    scanf("%d", &id);
    for(int i = 0; i < n; i++){
        if(s[i].id == id){
            printf("\nEnter the updated information for the student:\n");
            printf("Name: ");
            scanf("%s", s[i].name);
            printf("Age: ");
            scanf("%d", &s[i].age);
            printf("GPA: ");
            scanf("%lf", &s[i].gpa);
            printf("\nStudent information updated successfully!\n");
            return;
        }
    }
    printf("\nStudent with ID %d not found in the database.\n", id);
}

void deleteStudent(struct student* s, int* n){
    int id;
    printf("\nEnter the ID of the student you want to delete: ");
    scanf("%d", &id);
    int flag = 0;
    for(int i = 0; i < *n; i++){
        if(s[i].id == id){
            for(int j = i; j < *n-1; j++){
                s[j] = s[j+1];
            }
            (*n)--;
            printf("\nStudent with ID %d deleted successfully!\n", id);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("\nStudent with ID %d not found in the database.\n", id);
    }
}

int main(){
    int option, numStudents = 0;
    struct student students[100];
    do{
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1: addStudent(students, &numStudents); break;
            case 2: displayAllStudents(students, numStudents); break;
            case 3: searchByID(students, numStudents); break;
            case 4: updateStudent(students, numStudents); break;
            case 5: deleteStudent(students, &numStudents); break;
            case 6: printf("\nExiting the program...\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    }while(option != 6);
    return 0;
}