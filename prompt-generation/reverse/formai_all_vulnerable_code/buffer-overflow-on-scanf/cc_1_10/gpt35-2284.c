//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_SIZE 10

typedef struct{
    char name[20];
    int age;
    char address[50];
    float salary;
} Employee;

void displayMenu();
void addEmployee(Employee *database, int *numEmployees);
void viewEmployee(Employee *database, int numEmployees);
void deleteEmployee(Employee *database, int *numEmployees);
void searchEmployee(Employee *database, int numEmployees);
void saveDatabase(Employee *database, int numEmployees);

int main(){
    Employee database[MAX_DATABASE_SIZE];
    int numEmployees = 0;
    char choice;

    while(1){
        displayMenu();
        scanf("%c", &choice);
        getchar();

        switch(choice){
            case '1':
                addEmployee(database, &numEmployees);
                break;
            case '2':
                viewEmployee(database, numEmployees);
                break;
            case '3':
                deleteEmployee(database, &numEmployees);
                break;
            case '4':
                searchEmployee(database, numEmployees);
                break;
            case '5':
                saveDatabase(database, numEmployees);
                break;
            case '6':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}

void displayMenu(){
    printf("\nEmployee Database\n");
    printf("1. Add employee\n");
    printf("2. View employee details\n");
    printf("3. Delete employee\n");
    printf("4. Search for employee\n");
    printf("5. Save database\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addEmployee(Employee *database, int *numEmployees){
    if(*numEmployees == MAX_DATABASE_SIZE){
        printf("Database is full. No more employees can be added.\n");
        return;
    }

    Employee e;

    printf("Enter employee name: ");
    fgets(e.name, 20, stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter employee age: ");
    scanf("%d", &e.age);
    getchar();

    printf("Enter employee address: ");
    fgets(e.address, 50, stdin);
    e.address[strcspn(e.address, "\n")] = '\0';

    printf("Enter employee salary: ");
    scanf("%f", &e.salary);
    getchar();

    database[*numEmployees] = e;
    (*numEmployees)++;
    printf("Employee added successfully!\n");
}

void viewEmployee(Employee *database, int numEmployees){
    if(numEmployees == 0){
        printf("Database is empty. No employee details to view.\n");
        return;
    }

    printf("Enter employee index number (1-%d): ", numEmployees);
    int index;
    scanf("%d", &index);
    getchar();

    if(index < 1 || index > numEmployees){
        printf("Invalid index number. Try again.\n");
        return;
    }

    Employee e = database[index - 1];

    printf("\nName    : %s\n", e.name);
    printf("Age     : %d\n", e.age);
    printf("Address : %s\n", e.address);
    printf("Salary  : %.2f\n", e.salary);
}

void deleteEmployee(Employee *database, int *numEmployees){
    if(*numEmployees == 0){
        printf("Database is empty. No employees to delete.\n");
        return;
    }

    printf("Enter employee index number (1-%d) to delete: ", *numEmployees);
    int index;
    scanf("%d", &index);
    getchar();

    if(index < 1 || index > *numEmployees){
        printf("Invalid index number. Try again.\n");
        return;
    }

    for(int i=index-1; i<*numEmployees-1; i++){
        database[i] = database[i+1];
    }

    (*numEmployees)--;
    printf("Employee deleted successfully!\n");
}

void searchEmployee(Employee *database, int numEmployees){
    if(numEmployees == 0){
        printf("Database is empty. No employees to search for.\n");
        return;
    }

    printf("Enter search string: ");
    char search[20];
    fgets(search, 20, stdin);
    search[strcspn(search, "\n")] = '\0';

    int found = 0;

    for(int i=0; i<numEmployees; i++){
        if(strstr(database[i].name, search) != NULL ||
           strstr(database[i].address, search) != NULL){
            printf("\nName    : %s\n", database[i].name);
            printf("Age     : %d\n", database[i].age);
            printf("Address : %s\n", database[i].address);
            printf("Salary  : %.2f\n", database[i].salary);
            found = 1;
        }
    }

    if(!found){
        printf("No matching records found.\n");
    }
}

void saveDatabase(Employee *database, int numEmployees){
    if(numEmployees == 0){
        printf("Database is empty. Cannot save empty database.\n");
        return;
    }

    FILE *fp = fopen("database.txt", "w");
    if(fp == NULL){
        printf("Unable to save database. File cannot be created.\n");
        return;
    }

    for(int i=0; i<numEmployees; i++){
        fprintf(fp, "%s,%d,%s,%.2f\n", database[i].name, database[i].age,
                database[i].address, database[i].salary);
    }

    fclose(fp);

    printf("Database saved successfully!\n");
}