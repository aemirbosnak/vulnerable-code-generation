//FormAI DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//define structure for the database row
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

//define structure for the index row
typedef struct {
    int id;
    int offset;
} IndexRow;

//function to add employee to the database and update index
void addEmployee(Employee emp, FILE* fptr, FILE* indexFptr) {
    //move file pointer to end of file
    fseek(fptr, 0, SEEK_END);

    //write employee record to database
    fwrite(&emp, sizeof(Employee), 1, fptr);

    //get current position of file pointer
    long int currentOffset = ftell(fptr);

    //create index row for employee
    IndexRow indexRow;
    indexRow.id = emp.id;
    indexRow.offset = currentOffset - sizeof(Employee);

    //write index row to index file
    fwrite(&indexRow, sizeof(IndexRow), 1, indexFptr);
}

//function to search employee by id using index
void searchEmployeeById(int id, FILE* fptr, FILE* indexFptr) {
    //calculate size of index row and number of rows in index file
    int indexRowSize = sizeof(IndexRow);
    fseek(indexFptr, 0, SEEK_END);
    int numRows = ftell(indexFptr) / indexRowSize;
    fseek(indexFptr, 0, SEEK_SET);

    //initialize variables for binary search
    int start = 0;
    int end = numRows - 1;
    int mid = (start + end) / 2;
    IndexRow indexRow;

    //perform binary search on index file
    while (start <= end) {
        //move file pointer to middle of current range
        fseek(indexFptr, mid * indexRowSize, SEEK_SET);

        //read index row at middle position
        fread(&indexRow, sizeof(IndexRow), 1, indexFptr);

        //check if id matches
        if (indexRow.id == id) {
            //move file pointer to data position in database file
            fseek(fptr, indexRow.offset, SEEK_SET);

            //read employee record
            Employee emp;
            fread(&emp, sizeof(Employee), 1, fptr);

            //print employee details
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Age: %d\n", emp.age);
            printf("Salary: %.2f\n", emp.salary);

            return;
        } else if (indexRow.id < id) {
            //update start of range
            start = mid + 1;
        } else {
            //update end of range
            end = mid - 1;
        }

        //update middle of range
        mid = (start + end) / 2;
    }

    //if employee not found
    printf("Employee with ID %d not found.\n", id);
}

//main function
int main() {
    //open database file
    FILE* fptr = fopen("employee_db.bin", "a+");

    //open index file
    FILE* indexFptr = fopen("employee_db_index.bin", "a+");

    //get choice from user
    int choice;
    printf("1. Add Employee\n2. Search Employee by ID\n3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    //perform operation based on user choice
    switch (choice) {
        case 1: {
            //get employee details from user
            Employee emp;
            printf("Enter Employee ID: ");
            scanf("%d", &emp.id);
            printf("Enter Employee Name: ");
            scanf("%s", emp.name);
            printf("Enter Employee Age: ");
            scanf("%d", &emp.age);
            printf("Enter Employee Salary: ");
            scanf("%f", &emp.salary);

            //add employee to database and update index
            addEmployee(emp, fptr, indexFptr);

            printf("Employee Added Successfully.\n");

            break;
        }
        case 2: {
            //get id from user
            int id;
            printf("Enter Employee ID: ");
            scanf("%d", &id);

            //search employee by id using index
            searchEmployeeById(id, fptr, indexFptr);

            break;
        }
        case 3: {
            //close files and exit
            fclose(fptr);
            fclose(indexFptr);
            exit(0);
        }
        default: {
            //invalid choice
            printf("Invalid Choice.\n");
            break;
        }
    }

    //recursively call main function to allow user to perform another operation
    main();

    return 0;
}