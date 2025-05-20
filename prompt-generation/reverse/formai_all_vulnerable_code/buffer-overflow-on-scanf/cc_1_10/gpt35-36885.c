//FormAI DATASET v1.0 Category: Database simulation ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    int id;
    char name[20];
    float marks;
} * db;

int size = 0;

void add_student() {
    printf("Enter student id: ");
    scanf("%d", &db[size].id);
    printf("Enter student name: ");
    scanf("%s", db[size].name);
    printf("Enter student marks: ");
    scanf("%f", &db[size].marks);
    size++;
}

void display_student(int index) {
    printf("ID: %d | Name: %s | Marks:%.2f\n", db[index].id, db[index].name, db[index].marks);
}

void display_all_students() {
    for(int i=0; i<size; i++) {
        display_student(i);
    }
}

void search_student() {
    int id;
    printf("Enter the id of the student: ");
    scanf("%d", &id);
    for(int i=0; i<size; i++) {
        if(db[i].id == id) {
            display_student(i);
            return;
        }
    }
    printf("Student with id %d not found!\n", id);
}

void menu() {
    int choice;
    printf("\n\n*************** Student Database ***************\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_student();
            break;
        case 2:
            display_all_students();
            break;
        case 3:
            search_student();
            break;
        case 4:
            printf("Bye!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    db = (struct student*) malloc(sizeof(struct student)*100);
    while(1) {
        menu();
    }
    free(db);
    return 0;
}