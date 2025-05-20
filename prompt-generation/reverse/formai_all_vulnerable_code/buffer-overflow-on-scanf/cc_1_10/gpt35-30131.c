//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee{
    int emp_id;
    char emp_name[30];
    float emp_salary;
    char emp_address[50];
} Employee;

// Function to insert employee data into the database
void insertEmployeeData(Employee *emp, FILE *database) {
    fwrite(emp, sizeof(Employee), 1, database);
    printf("Employee Data Successfully Inserted into the Database!\n");
}

// Function to fetch employee data from the database by employee id
void fetchEmployeeData(int emp_id, FILE *database) {
    Employee emp;
    int flag = 0;
    fseek(database, 0, SEEK_SET);
    while (fread(&emp, sizeof(Employee), 1, database)) {
        if (emp.emp_id == emp_id) {
            printf("\nEmployee Details:\nEmployee ID: %d\nEmployee Name: %s\nEmployee Salary: %.2f\nEmployee Address: %s\n", emp.emp_id, emp.emp_name, emp.emp_salary, emp.emp_address);
            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("\nNo Employee Found with ID: %d\n", emp_id);
    }
}

// Function to display all the employee data present in the database
void displayAllData(FILE *database) {
    Employee emp;
    printf("\nAll Employee Data Present in the Database:\n");
    fseek(database, 0, SEEK_SET);
    while (fread(&emp, sizeof(Employee), 1, database)) {
        printf("Employee ID: %d\nEmployee Name: %s\nEmployee Salary: %.2f\nEmployee Address: %s\n", emp.emp_id, emp.emp_name, emp.emp_salary, emp.emp_address);
    }
}

// Function to update employee data in the database by employee id
void updateEmployeeData(int emp_id, FILE *database) {
    Employee emp;
    int flag = 0;
    fseek(database, 0, SEEK_SET);
    while (fread(&emp, sizeof(Employee), 1, database)) {
        if (emp.emp_id == emp_id) {
            printf("\nEnter New Employee Name for ID %d: ", emp_id);
            scanf("%s", emp.emp_name);
            printf("Enter New Employee Salary for ID %d: ", emp_id);
            scanf("%f", &emp.emp_salary);
            printf("Enter New Employee Address for ID %d: ", emp_id);
            scanf("%s", emp.emp_address);
            flag = 1;
            fseek(database, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, database);
            printf("\nEmployee Data for ID %d Successfully Updated in the Database!\n", emp_id);
            break;
        }
    }
    if (!flag) {
        printf("\nNo Employee Found with ID: %d\n", emp_id);
    }
}

// Function to delete employee data from the database by employee id
void deleteEmployeeData(int emp_id, FILE *database) {
    Employee emp;
    FILE *temp = fopen("temp.dat", "wb+");
    int flag = 0;
    fseek(database, 0, SEEK_SET);
    while (fread(&emp, sizeof(Employee), 1, database)) {
        if (emp.emp_id != emp_id) {
            fwrite(&emp, sizeof(Employee), 1, temp);
        } else {
            flag = 1;
        }
    }
    fclose(database);
    fclose(temp);
    remove("my_db.dat");
    rename("temp.dat", "my_db.dat");
    if (flag) {
        printf("\nEmployee Data for ID %d Successfully Deleted from the Database!\n", emp_id);
    } else {
        printf("\nNo Employee Found with ID: %d\n", emp_id);
    }
}

int main() {
    FILE *database = fopen("my_db.dat", "ab+");
    int choice = 0, emp_id;
    Employee emp;
    while (1) {
        printf("\n");
        printf("1. Insert Employee Data into the Database\n");
        printf("2. Fetch Employee Data from the Database by ID\n");
        printf("3. Display All Employee Data from the Database\n");
        printf("4. Update Employee Data in the Database by ID\n");
        printf("5. Delete Employee Data from the Database by ID\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp.emp_id);
                printf("Enter Employee Name: ");
                scanf("%s", emp.emp_name);
                printf("Enter Employee Salary: ");
                scanf("%f", &emp.emp_salary);
                printf("Enter Employee Address: ");
                scanf("%s", emp.emp_address);
                insertEmployeeData(&emp, database);
                break;
            case 2:
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp_id);
                fetchEmployeeData(emp_id, database);
                break;
            case 3:
                displayAllData(database);
                break;
            case 4:
                printf("\nEnter Employee ID to Update Employee Data: ");
                scanf("%d", &emp_id);
                updateEmployeeData(emp_id, database);
                break;
            case 5:
                printf("\nEnter Employee ID to Delete Employee Data: ");
                scanf("%d", &emp_id);
                deleteEmployeeData(emp_id, database);
                break;
            case 6:
                fclose(database);
                return 0;
            default:
                printf("\nInvalid Choice! Please Enter a Valid Choice.\n");
                break;
        }
    }
    return 0;
}