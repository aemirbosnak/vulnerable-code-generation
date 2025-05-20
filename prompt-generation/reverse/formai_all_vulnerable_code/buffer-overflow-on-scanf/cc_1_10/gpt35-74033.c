//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    char name[30];
    char department[30];
} Employee;

// function to add employee to database
void add_employee(Employee **db, int *size){
    // allocate memory for new employee
    *db = realloc(*db, (*size+1)*sizeof(Employee));
    if(*db == NULL){
        printf("Error in adding employee!\n");
        return;
    }
    Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Department: ");
    scanf("%s", emp.department);
    (*db)[*size] = emp;
    *size += 1;
    printf("Employee added successfully!\n");
}

// function to display all employees in database
void display_employees(Employee *db, int size){
    if(size == 0){
        printf("No employees in database!\n");
        return;
    }
    printf("\nEmployee Database:\n");
    for(int i=0; i<size; i++){
        printf("ID: %d    Name: %s    Department: %s\n", db[i].id, db[i].name, db[i].department);
    }
}

int main(){
    int size = 0;
    Employee *db = NULL;
    int choice;
    do{
        printf("\nEnter your choice:\n1. Add employee to database\n2. Display all employees\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_employee(&db, &size);
                break;
            case 2:
                display_employees(db, size);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 3);
    free(db);
    return 0;
}