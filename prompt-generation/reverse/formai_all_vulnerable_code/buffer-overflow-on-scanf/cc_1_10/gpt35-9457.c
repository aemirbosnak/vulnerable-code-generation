//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include<stdio.h>
#include<string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

int main() {

    // creating an array of employees
    Employee employees[10];

    int num_employees = 0;
    char choice = 'y';

    // opening the file for writing
    FILE *fptr = fopen("employee_data.txt", "w");

    // checking if file was opened successfully
    if (fptr == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // getting employee details and writing to file
    while (choice == 'y' || choice == 'Y') {
        printf("Enter name: ");
        scanf("%s", employees[num_employees].name);
        printf("Enter age: ");
        scanf("%d", &employees[num_employees].age);
        printf("Enter salary: ");
        scanf("%f", &employees[num_employees].salary);

        // writing employee details to file
        fprintf(fptr, "%s %d %.2f\n", employees[num_employees].name, employees[num_employees].age, employees[num_employees].salary);

        num_employees++;
        printf("Do you want to add another employee? (y/n): ");
        scanf(" %c", &choice);
    }

    // closing file
    fclose(fptr);

    // opening file for reading
    fptr = fopen("employee_data.txt", "r");

    // checking if file was opened successfully
    if (fptr == NULL) {
        printf("Error opening file!");
        return 1;
    }

    printf("\nEmployees\n");
    printf("---------\n");

    int i = 0;
    // reading employee details from file and displaying them
    while(fscanf(fptr, "%s %d %f", employees[i].name, &employees[i].age, &employees[i].salary) == 3) {
        printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", employees[i].name, employees[i].age, employees[i].salary);
        i++;
    }

    // closing file
    fclose(fptr);

    return 0;
}