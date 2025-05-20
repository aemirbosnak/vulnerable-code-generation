//FormAI DATASET v1.0 Category: Database simulation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct student{
    int id;
    char name[30];
    float marks;
}Student;

int n = 0; // number of students in the database

// function to add student to the database
void add_student(Student db[], int id, char name[], float marks){
    db[n].id = id;
    strcpy(db[n].name, name);
    db[n].marks = marks;
    n++;
}

// function to display all the students in the database
void display_students(Student db[]){
    if(n == 0){
        printf("No students in database!\n");
        return;
    }
    printf("List of students in database:\n");
    for(int i=0; i<n; i++){
        printf("ID: %d\nName: %s\nMarks: %.2f\n", db[i].id, db[i].name, db[i].marks);
    }
}

// function to search for a student by id
void search_by_id(Student db[], int id){
    for(int i=0; i<n; i++){
        if(db[i].id == id){
            printf("Student found!\nID: %d\nName: %s\nMarks: %.2f\n", db[i].id, db[i].name, db[i].marks);
            return;
        }
    }
    printf("Student not found!\n");
}

// function to delete a student by id
void delete_by_id(Student db[], int id){
    int flag = 0;
    for(int i=0; i<n; i++){
        if(db[i].id == id){
            flag = 1;
            for(int j=i; j<n-1; j++){
                db[j] = db[j+1];
            }
            n--;
            printf("Student deleted!\n");
            break;
        }
    }
    if(flag == 0){
        printf("Student not found!\n");
    }
}

int main(){
    Student db[MAX];
    int choice, id;
    char name[30];
    float marks;

    do{
        printf("\nDatabase Operations\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search by ID\n");
        printf("4. Delete by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter details of student:\n");
                printf("ID: ");
                scanf("%d", &id);
                printf("Name: ");
                scanf("%s", name);
                printf("Marks: ");
                scanf("%f", &marks);
                add_student(db, id, name, marks);
                break;

            case 2:
                display_students(db);
                break;

            case 3:
                printf("\nEnter ID to search for: ");
                scanf("%d", &id);
                search_by_id(db, id);
                break;

            case 4:
                printf("\nEnter ID to delete: ");
                scanf("%d", &id);
                delete_by_id(db, id);
                break;

            case 5:
                printf("\nExiting program!\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }

    }while(choice != 5);

    return 0;
}