//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5

struct Student{
    char name[50];
    int age;
    char address[100];
    int id;
};
typedef struct Student student;

int num_students = 0;

void insert_student(student *students){
    if(num_students == MAX_SIZE){
        printf("Database is full, cannot insert new student\n");
        return;
    }
    printf("Enter student name: ");
    scanf("%s",students[num_students].name);
    printf("Enter student age: ");
    scanf("%d",&students[num_students].age);
    printf("Enter student address: ");
    scanf("%s",students[num_students].address);
    printf("Enter student id: ");
    scanf("%d",&students[num_students].id);
    printf("Student added successfully\n");
    num_students++;
}

void delete_student(student *students, int id){
    int index = -1;
    for(int i=0;i<num_students;i++){
        if(students[i].id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("No such student found with id %d\n",id);
        return;
    }
    for(int i=index;i<num_students-1;i++){
        students[i] = students[i+1];
    }
    printf("Student with id %d deleted successfully\n",id);
    num_students--;
}

void search_student(student *students, int id){
    for(int i=0;i<num_students;i++){
        if(students[i].id == id){
            printf("Name: %s\nAge: %d\nAddress: %s\nID: %d\n",students[i].name,students[i].age,students[i].address,students[i].id);
            return;
        }
    }
    printf("No such student found with id %d\n",id);
}

void display_all(student *students){
    printf("Total number of students: %d\n",num_students);
    for(int i=0;i<num_students;i++){
        printf("Name: %s\nAge: %d\nAddress: %s\nID: %d\n",students[i].name,students[i].age,students[i].address,students[i].id);
    }
}

int main(){
    student students[MAX_SIZE];
    int choice, id;
    while(1){
        printf("Enter 1 to insert new student, 2 to delete a student, 3 to search a student, 4 to display all students, 0 to exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting program...\n");
                exit(0);
                break;
            case 1:
                insert_student(students);
                break;
            case 2:
                printf("Enter id of student to delete: ");
                scanf("%d",&id);
                delete_student(students,id);
                break;
            case 3:
                printf("Enter id of student to search: ");
                scanf("%d",&id);
                search_student(students,id);
                break;
            case 4:
                display_all(students);
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}