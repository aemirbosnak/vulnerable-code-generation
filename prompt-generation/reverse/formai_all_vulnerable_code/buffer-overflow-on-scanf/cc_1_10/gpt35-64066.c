//FormAI DATASET v1.0 Category: Database simulation ; Style: shape shifting
// C Shape Shifting Database Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for different fields in the database
struct Employee {
    int emp_id;
    char name[50];
    int age;
    float salary;
};

struct Student {
    int roll_no;
    char name[50];
    char course[50];
    float marks;
};

// Define a union to hold the data for either Employee or Student
union Data {
    struct Employee emp;
    struct Student std;
};

// Define a structure for each row in the database
struct Record {
    int id;
    char type;
    union Data data;
};

// Define a function to add a new row to the database
void addRecord(struct Record records[], int *num_records) {
    char type;
    printf("Enter the type of record (E for Employee, S for Student): ");
    scanf(" %c", &type);

    if (type == 'E') {
        // Add a new employee record
        struct Employee emp;
        printf("Enter employee ID: ");
        scanf("%d", &emp.emp_id);
        printf("Enter name: ");
        scanf(" %[^\n]", emp.name);
        printf("Enter age: ");
        scanf("%d", &emp.age);
        printf("Enter salary: ");
        scanf("%f", &emp.salary);

        struct Record new_record;
        new_record.id = *num_records;
        new_record.type = 'E';
        new_record.data.emp = emp;
        records[*num_records] = new_record;
        *num_records += 1;
    } else if (type == 'S') {
        // Add a new student record
        struct Student std;
        printf("Enter roll number: ");
        scanf("%d", &std.roll_no);
        printf("Enter name: ");
        scanf(" %[^\n]", std.name);
        printf("Enter course: ");
        scanf(" %[^\n]", std.course);
        printf("Enter marks: ");
        scanf("%f", &std.marks);

        struct Record new_record;
        new_record.id = *num_records;
        new_record.type = 'S';
        new_record.data.std = std;
        records[*num_records] = new_record;
        *num_records += 1;
    } else {
        printf("Invalid record type. Please try again.\n");
    }
}

// Define a function to display all the records in the database
void displayRecords(struct Record records[], int num_records) {
    printf("\nID\tTYPE\t\tNAME\t\t\tAGE/ROLL NO.\tSALARY/MARKS\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < num_records; i++) {
        struct Record record = records[i];
        if (record.type == 'E') {
            // Display the employee record
            printf("%d\tE\t\t%s\t\t\t%d\t\t%.2f\n", record.id, record.data.emp.name, record.data.emp.age, record.data.emp.salary);
        } else if (record.type == 'S') {
            // Display the student record
            printf("%d\tS\t\t%s\t\t\t%d\t\t%.2f\n", record.id, record.data.std.name, record.data.std.roll_no, record.data.std.marks);
        }
    }
}

int main() {
    struct Record records[100]; // Maximum of 100 records can be stored
    int num_records = 0; // Indicates the number of records currently stored
    
    printf("=====Database Simulation Program=====\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &num_records);
                break;
            case 2:
                displayRecords(records, num_records);
                break;
            case 3:
                printf("\nExiting program. Thank you for using the database simulation!");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }

    return 0;
}