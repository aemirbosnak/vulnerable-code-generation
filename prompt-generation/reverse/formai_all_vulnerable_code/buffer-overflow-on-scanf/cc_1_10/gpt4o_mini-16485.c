//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    double salary;
} Employee;

void clearScreen() {
    printf("\033[H\033[J"); // Escape sequence to clear the screen
}

void saveToFile(Employee* employees, int count) {
    FILE* file = fopen("employees.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
    fclose(file);
}

void loadFromFile(Employee* employees, int* count) {
    FILE* file = fopen("employees.txt", "r");
    if (file == NULL) {
        perror("No data file found. Initializing with empty records.");
        return;
    }

    while (fscanf(file, "%[^,],%d,%lf\n", employees[*count].name, &employees[*count].age, &employees[*count].salary) != EOF) {
        (*count)++;
        if (*count >= MAX_RECORDS) break; 
    }
    fclose(file);
}

void displayEmployees(Employee* employees, int count) {
    clearScreen();
    printf("Employee Records:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | Age: %d | Salary: $%.2f\n", 
               i + 1, employees[i].name, employees[i].age, employees[i].salary);
    }
    printf("---------------------------------------------------\n");
}

void addEmployee(Employee* employees, int* count) {
    if (*count >= MAX_RECORDS) {
        printf("Maximum record limit reached!\n");
        return;
    }

    printf("Enter employee name: ");
    scanf("%s", employees[*count].name);
    
    printf("Enter employee age: ");
    scanf("%d", &employees[*count].age);
    
    printf("Enter employee salary: ");
    scanf("%lf", &employees[*count].salary);
    
    (*count)++;
    printf("Employee added successfully.\n");
}

void searchEmployee(Employee* employees, int count) {
    char searchName[MAX_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    
    printf("Search Results:\n");
    printf("---------------------------------------------------\n");
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].name, searchName) == 0) {
            printf("Name: %s | Age: %d | Salary: $%.2f\n", 
                   employees[i].name, employees[i].age, employees[i].salary);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No record found for \"%s\".\n", searchName);
    }
    printf("---------------------------------------------------\n");
}

void displayMenu() {
    clearScreen();
    printf("********* Employee Data Mining System *********\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Search Employee\n");
    printf("4. Save to File\n");
    printf("5. Load from File\n");
    printf("6. Exit\n");
    printf("************************************************\n");
    printf("Select an option: ");
}

int main() {
    Employee employees[MAX_RECORDS];
    int count = 0;
    char choice;

    loadFromFile(employees, &count);
    
    while (1) {
        displayMenu();
        choice = getchar();
        getchar(); // clear newline from input buffer

        switch (choice) {
            case '1':
                addEmployee(employees, &count);
                break;
            case '2':
                displayEmployees(employees, count);
                break;
            case '3':
                searchEmployee(employees, count);
                break;
            case '4':
                saveToFile(employees, count);
                printf("Data saved successfully.\n");
                break;
            case '5':
                loadFromFile(employees, &count);
                printf("Data loaded successfully.\n");
                break;
            case '6':
                printf("Exiting... Are you sure you want to leave? (yes/no): ");
                char exitConfirm[MAX_LENGTH];
                scanf("%s", exitConfirm);
                if (strcmp(exitConfirm, "yes") == 0) {
                    printf("Goodbye! Remember, they may be watching...\n");
                    exit(EXIT_SUCCESS);
                }
                break;
            default:
                printf("Invalid option. They might be watching you... Try again.\n");
                break;
        }
    }
    return 0;
}