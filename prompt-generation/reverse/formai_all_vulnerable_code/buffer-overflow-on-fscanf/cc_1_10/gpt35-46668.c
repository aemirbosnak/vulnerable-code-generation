//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[20];
    int age;
    int id;
} Student;

void addStudent(Student* db[], int* count){
    //create new student
    Student* newStudent = malloc(sizeof(Student));
    
    //get student details from user
    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    
    printf("Enter student age: ");
    scanf("%d", &newStudent->age);
    
    printf("Enter student ID: ");
    scanf("%d", &newStudent->id);
    
    //add student to database
    db[*count] = newStudent;
    *count += 1;
}

void displayStudents(Student* db[], int count){
    //display all students in database
    printf("Students in database:\n");
    for(int i=0; i<count; i++){
        printf("Name: %s, Age: %d, ID: %d\n", db[i]->name, db[i]->age, db[i]->id);
    }
}

void searchStudent(Student* db[], int count){
    //get student ID to search for
    int idToSearch;
    printf("Enter student ID to search for: ");
    scanf("%d", &idToSearch);
    
    //search for student in database
    for(int i=0; i<count; i++){
        if(db[i]->id == idToSearch){
            printf("Student found:\n");
            printf("Name: %s, Age: %d, ID: %d\n", db[i]->name, db[i]->age, db[i]->id);
            return;
        }
    }
    
    printf("Student with ID %d not found\n", idToSearch);
}

void deleteStudent(Student* db[], int* count){
    //get student ID to delete
    int idToDelete;
    printf("Enter student ID to delete: ");
    scanf("%d", &idToDelete);
    
    //search and delete student in database
    for(int i=0; i<*count; i++){
        if(db[i]->id == idToDelete){
            printf("Student with ID %d deleted\n", idToDelete);
            free(db[i]);    //free memory allocated to student
            //shift all students after this one down 1 index
            for(int j=i; j<*count-1; j++){
                db[j] = db[j+1];
            }
            *count -= 1;
            return;
        }
    }
    
    printf("Student with ID %d not found\n", idToDelete);
}

void saveToFile(Student* db[], int count){
    //open file in write mode
    FILE* fp = fopen("database.txt", "w");
    
    //write each student to file
    for(int i=0; i<count; i++){
        fprintf(fp, "%s %d %d\n", db[i]->name, db[i]->age, db[i]->id);
    }
    
    //close file
    fclose(fp);
    printf("Database saved to file\n");
}

void loadFromFile(Student* db[], int* count){
    //open file in read mode
    FILE* fp = fopen("database.txt", "r");
    
    //check if file exists
    if(fp == NULL){
        printf("No database file found\n");
        return;
    }
    
    //read each student from file
    while(!feof(fp)){
        Student* newStudent = malloc(sizeof(Student));
        fscanf(fp, "%s %d %d\n", newStudent->name, &newStudent->age, &newStudent->id);
        db[*count] = newStudent;
        *count += 1;
    }
    
    //close file
    fclose(fp);
    printf("Database loaded from file\n");
}

int main(){
    Student* db[100];   //array of pointers to Student structs
    int count = 0;      //number of students in database
    
    //menu loop
    while(1){
        printf("\n\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search for student\n");
        printf("4. Delete student\n");
        printf("5. Save database to file\n");
        printf("6. Load database from file\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addStudent(db, &count);
                break;
            case 2:
                displayStudents(db, count);
                break;
            case 3:
                searchStudent(db, count);
                break;
            case 4:
                deleteStudent(db, &count);
                break;
            case 5:
                saveToFile(db, count);
                break;
            case 6:
                loadFromFile(db, &count);
                break;
            case 7:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
        
    }
    return 0;
}