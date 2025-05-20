//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    int id;
    char name[30];
    float marks;
}Student;

void addStudent(Student** database, int* size);
void printDatabase(Student** database, int size);
void deleteStudent(Student** database, int* size);
void updateStudent(Student** database, int size);

int main(){
    Student** database = NULL;
    int size = 0;
    int choice = 0;
    do{
        printf("\nMENU\n");
        printf("1. Add Student\n2. Print Database\n3. Delete Student\n4. Update Student\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addStudent(database, &size);
                    break;
            case 2: printDatabase(database, size);
                    break;
            case 3: deleteStudent(database, &size);
                    break;
            case 4: updateStudent(database, size);
                    break;
            case 5: printf("Terminating program...");
                    break;
            default: printf("Invalid choice. Try again.");
                     break;
        }
    }while(choice != 5);
    return 0;
}

void addStudent(Student** database, int* size){
    Student* temp = (Student*)malloc(sizeof(Student));
    printf("Enter Student ID: ");
    scanf("%d", &temp->id);
    printf("Enter Student Name: ");
    scanf("%s", temp->name);
    printf("Enter Student Marks: ");
    scanf("%f", &temp->marks);
    *size += 1;
    database = realloc(database, (*size)*sizeof(Student*));
    database[*size-1] = temp;
    printf("\nStudent added successfully!\n");
}

void printDatabase(Student** database, int size){
    printf("\nDatabase:\n\n");
    printf("ID\tNAME\tMARKS\n");
    for(int i=0; i<size; i++){
        printf("%d\t%s\t%.2f\n", database[i]->id, database[i]->name, database[i]->marks);
    }
}

void deleteStudent(Student** database, int* size){
    printf("Enter ID of the student to be deleted: ");
    int id;
    int index = -1;
    scanf("%d", &id);
    for(int i=0; i<*size; i++){
        if(database[i]->id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("Student with ID %d not found.\n", id);
        return;
    }
    for(int i=index; i<*size-1; i++){
        database[i] = database[i+1];
    }
    *size -= 1;
    database = realloc(database, (*size)*sizeof(Student*));
    printf("Student with ID %d deleted successfully.\n", id);
}

void updateStudent(Student** database, int size){
    printf("Enter ID of the student to be updated: ");
    int id;
    int index = -1;
    scanf("%d", &id);
    for(int i=0; i<size; i++){
        if(database[i]->id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("Student with ID %d not found.\n", id);
        return;
    }
    printf("Enter updated name: ");
    scanf("%s", database[index]->name);
    printf("Enter updated marks: ");
    scanf("%f", &database[index]->marks);
    printf("Student with ID %d updated successfully.\n", id);
}