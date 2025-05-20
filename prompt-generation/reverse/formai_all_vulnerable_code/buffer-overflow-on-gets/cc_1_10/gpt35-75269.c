//FormAI DATASET v1.0 Category: Database simulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Database structure and related functions
typedef struct{
    int id;
    char name[50];
    float salary;
} Employee;

Employee* create_database(int size){
    Employee* emp_db = malloc(size * sizeof(Employee));
    return emp_db;
}

void insert_employee(Employee* emp_db, int index, int id, char* name, float salary){
    emp_db[index].id = id;
    strcpy(emp_db[index].name, name);
    emp_db[index].salary = salary;
}

void update_employee(Employee* emp_db, int index, char* name, float salary){
    strcpy(emp_db[index].name, name);
    emp_db[index].salary = salary;
}

void delete_employee(Employee* emp_db, int index){
    emp_db[index].id = 0;
    strcpy(emp_db[index].name, "");
    emp_db[index].salary = 0;
}

void print_database(Employee* emp_db, int size){
    printf("\nID\tName\tSalary\n");
    for(int i=0;i<size;i++){
        if(emp_db[i].id != 0){
            printf("%d\t%s\t%.2f\n", emp_db[i].id, emp_db[i].name, emp_db[i].salary);
        }
    }
}

//Main function
int main(){
    int size = 5;
    Employee* emp_db = create_database(size);
    int choice = 0;
    int index = 0;
    int id;
    char name[50];
    float salary;

    do{
        printf("\n1. Insert employee\n2. Update employee\n3. Delete employee\n4. Print database\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(index >= size){
                    printf("\nDatabase is full\n");
                }
                else{
                    printf("\nEnter employee ID: ");
                    scanf("%d", &id);
                    printf("Enter employee name: ");
                    fflush(stdin);
                    gets(name);
                    printf("Enter employee salary: ");
                    scanf("%f", &salary);
                    insert_employee(emp_db, index, id, name, salary);
                    index++;
                    printf("\nEmployee inserted successfully\n");
                }
                break;

            case 2:
                printf("\nEnter the ID of employee to be updated: ");
                scanf("%d", &id);

                for(int i=0;i<size;i++){
                    if(emp_db[i].id == id){
                        printf("Enter new name for employee: ");
                        fflush(stdin);
                        gets(name);
                        printf("Enter new salary for employee: ");
                        scanf("%f", &salary);
                        update_employee(emp_db, i, name, salary);
                        printf("\nEmployee updated successfully\n");
                        break;
                    }
                    else if(i == size-1){
                        printf("\nEmployee with ID %d not found\n", id);
                    }
                }
                break;

            case 3:
                printf("\nEnter the ID of employee to be deleted: ");
                scanf("%d", &id);

                for(int i=0;i<size;i++){
                    if(emp_db[i].id == id){
                        delete_employee(emp_db, i);
                        index--;
                        printf("\nEmployee deleted successfully\n");
                        break;
                    }
                    else if(i == size-1){
                        printf("\nEmployee with ID %d not found\n", id);
                    }
                }
                break;

            case 4:
                print_database(emp_db, size);
                break;

            case 5:
                printf("\nExiting program\n");
                break;

            default:
                printf("\nInvalid choice\n");
                break;
        }

    }while(choice != 5);

    free(emp_db);
    return 0;
}