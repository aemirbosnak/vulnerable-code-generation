//FormAI DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Structure to hold employee details
struct employee {
    int id;
    char name[20];
    int age;
    long salary;
};

int main() {
    int choice, emp_id, emp_found = 0, i, num_emp = 0;
    struct employee emp;
    FILE *file_ptr;
    
    // Creating file pointer and opening file in binary mode
    file_ptr = fopen("employees.bin", "rb+");
    
    // Checking if file exists
    if (file_ptr == NULL) {
        printf("File not found!\nCreating new file...\n");
        // Creating new file in binary mode
        file_ptr = fopen("employees.bin", "wb+");
        if (file_ptr == NULL) {
            printf("Error creating file!");
            exit(1);
        }
    }
    
    // Finding number of employees in file
    fseek(file_ptr, 0, SEEK_END);
    num_emp = ftell(file_ptr) / sizeof(struct employee);
    rewind(file_ptr);
    
    do {
        // Displaying menu
        printf("\n1. Add new employee\n");
        printf("2. Display all employees\n");
        printf("3. Update employee\n");
        printf("4. Delete employee\n");
        printf("5. Find employee by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Adding new employee
                printf("\nEnter employee ID: ");
                scanf("%d", &emp.id);
                printf("Enter employee name: ");
                scanf("%s", emp.name);
                printf("Enter employee age: ");
                scanf("%d", &emp.age);
                printf("Enter employee salary: ");
                scanf("%ld", &emp.salary);
                fseek(file_ptr, 0, SEEK_END); // Moving file pointer to end of file
                fwrite(&emp, sizeof(struct employee), 1, file_ptr); // Writing to file
                num_emp++; // Incrementing number of employees
                printf("Employee added successfully!\n");
                break;
            
            case 2: // Displaying all employees
                printf("\nID\t NAME\t AGE\t SALARY\n");
                printf("===================================\n");
                for (i = 0; i < num_emp; i++) {
                    fread(&emp, sizeof(struct employee), 1, file_ptr); // Reading employee from file
                    printf("%d\t %s\t %d\t %ld\n", emp.id, emp.name, emp.age, emp.salary);
                }
                rewind(file_ptr); // Moving file pointer back to start of file
                break;
            
            case 3: // Updating employee
                printf("\nEnter employee ID of employee to update: ");
                scanf("%d", &emp_id);
                fseek(file_ptr, 0, SEEK_SET); // Moving file pointer to start of file
                emp_found = 0;
                for (i = 0; i < num_emp; i++) {
                    fread(&emp, sizeof(struct employee), 1, file_ptr); // Reading employee from file
                    if (emp.id == emp_id) { // Employee found
                        emp_found = 1;
                        printf("Enter new name (or leave blank to retain old name): ");
                        scanf("%s", emp.name);
                        printf("Enter new age (or leave blank to retain old age): ");
                        scanf("%d", &emp.age);
                        printf("Enter new salary (or leave blank to retain old salary): ");
                        scanf("%ld", &emp.salary);
                        fseek(file_ptr, -sizeof(struct employee), SEEK_CUR); // Moving file pointer to start of this employee record
                        fwrite(&emp, sizeof(struct employee), 1, file_ptr); // Writing updated employee to file
                        printf("Employee updated successfully!\n");
                        break;
                    }
                }
                if (!emp_found) {
                    printf("Employee not found!\n");
                }
                rewind(file_ptr); // Moving file pointer back to start of file
                break;
            
            case 4: // Deleting employee
                printf("\nEnter employee ID of employee to delete: ");
                scanf("%d", &emp_id);
                fseek(file_ptr, 0, SEEK_SET); // Moving file pointer to start of file
                emp_found = 0;
                for (i = 0; i < num_emp; i++) {
                    fread(&emp, sizeof(struct employee), 1, file_ptr); // Reading employee from file
                    if (emp.id == emp_id) { // Employee found
                        emp_found = 1;
                        fseek(file_ptr, -sizeof(struct employee), SEEK_CUR); // Moving file pointer to start of this employee record
                        fwrite(&emp, 0, sizeof(struct employee), file_ptr); // Writing 0 bytes to this employee record to delete it
                        num_emp--; // Decrementing number of employees
                        printf("Employee deleted successfully!\n");
                        break;
                    }
                }
                if (!emp_found) {
                    printf("Employee not found!\n");
                }
                rewind(file_ptr); // Moving file pointer back to start of file
                break;
            
            case 5: // Finding employee by ID
                printf("\nEnter employee ID to find: ");
                scanf("%d", &emp_id);
                fseek(file_ptr, 0, SEEK_SET); // Moving file pointer to start of file
                emp_found = 0;
                for (i = 0; i < num_emp; i++) {
                    fread(&emp, sizeof(struct employee), 1, file_ptr); // Reading employee from file
                    if (emp.id == emp_id) { // Employee found
                        emp_found = 1;
                        printf("\nID\t NAME\t AGE\t SALARY\n");
                        printf("===================================\n");
                        printf("%d\t %s\t %d\t %ld\n", emp.id, emp.name, emp.age, emp.salary);
                        break;
                    }
                }
                if (!emp_found) {
                    printf("Employee not found!\n");
                }
                rewind(file_ptr); // Moving file pointer back to start of file
                break;
            
            case 6: // Exiting application
                break;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 6);
    
    // Closing file pointer
    fclose(file_ptr);
    
    return 0;
}