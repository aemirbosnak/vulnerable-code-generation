//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct Student{
    int id;
    char name[30];
    int age;
    char gender;
};

void addStudent(struct Student *students, int *numStudents){
    int id;
    char name[30];
    int age;
    char gender;
 
    printf("\nEnter student id: ");
    scanf("%d",&id);
    printf("Enter student name: ");
    scanf("%s", &name);
    printf("Enter student age: ");
    scanf("%d",&age);
    printf("Enter student gender (M/F): ");
    scanf(" %c",&gender);
 
    students[*numStudents].id = id;
    strcpy(students[*numStudents].name, name);
    students[*numStudents].age = age;
    students[*numStudents].gender = gender;
 
    *numStudents = *numStudents + 1;
}

void displayStudents(struct Student *students, int numStudents){
    int i;
 
    printf("\nID\tName\t\tAge\tGender\n");
    printf("--\t----\t\t---\t------\n");
    for(i=0;i<numStudents;i++){
        printf("%d\t%s\t\t%d\t%c\n",students[i].id,students[i].name, students[i].age, students[i].gender);
    }
}

int main(){
    struct Student students[100];
    int numStudents = 0;
    int choice;
 
    do{
        printf("\n\nDatabase\n");
        printf("---------\n");
        printf("1. Add new student\n");
        printf("2. Display all students\n");
        printf("3. Exit\n");
 
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
 
        switch(choice){
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                printf("\nExiting program\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice!=3);
 
    return 0;
}