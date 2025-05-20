//FormAI DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int id;
    char name[20];
    float gpa;
};

void insertStudent(struct Student *s, int size){
    int id;
    char name[20];
    float gpa;
    
    printf("Enter student ID:");
    scanf("%d", &id);
    s[size].id = id;
    
    printf("Enter student name:");
    fflush(stdin);
    gets(name);
    strcpy(s[size].name,name);
    
    printf("Enter student GPA:");
    scanf("%f", &gpa);
    s[size].gpa = gpa;
}

void deleteStudent(struct Student *s, int size){
    int id;
    int i;
    
    printf("Enter student ID to delete:");
    scanf("%d", &id);
    
    for(i = 0; i < size; i++){
        if(s[i].id == id){
            s[i].id = 0;
            strcpy(s[i].name, "");
            s[i].gpa = 0.0;
            printf("Student with ID %d has been deleted.\n", id);
            return;
        }
    }
    
    printf("Student with ID %d not found.\n", id);
}

void viewStudent(struct Student s){
    printf("%-5d%-20s%-5.2f\n", s.id, s.name, s.gpa);
}

void viewAllStudents(struct Student *s, int size){
    int i;
    printf("ID   Name                GPA\n");
    for(i = 0; i < size; i++){
        if(s[i].id != 0){
            viewStudent(s[i]);
        }
    }
}

int main(){
    int choice;
    struct Student *s;
    int size = 0;
    int i;
    
    while(1){
        printf("\n1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. View All Students\n");
        printf("0. Exit\n");
        
        printf("Enter Choice:");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                s = realloc(s, (size + 1) * sizeof(struct Student));
                insertStudent(s, size);
                size++;
                break;
            case 2:
                deleteStudent(s, size);
                break;
            case 3:
                viewAllStudents(s, size);
                break;
            case 0:
                for(i = 0; i < size; i++){
                    s[i].id = 0;
                    strcpy(s[i].name, "");
                    s[i].gpa = 0.0;
                }
                free(s);
                return 0;
                break;
            default:
                printf("Invalid Choice.");
                break;
        }
    }
    return 0;
}