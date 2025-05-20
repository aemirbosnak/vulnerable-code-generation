//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

//Structure to store student information
typedef struct Student {
    int rollNumber;
    char name[MAXSIZE];
    int age;
} Student;

//Function prototypes
void insertRecord(Student students[], int *count);
void deleteRecord(Student students[], int *count);
void displayRecords(Student students[], int count);
void searchRecord(Student students[], int count);

int main() {
    Student students[MAXSIZE]; //Array of structures to hold student records
    int count = 0; //Variable to keep track of number of records

    int choice = 0;
    while (choice != 5) { //Loop for displaying the menu until the user chooses to exit
        printf("\n***********MENU*********\n");
        printf("1. Insert Record\n");
        printf("2. Delete Record\n");
        printf("3. Display Records\n");
        printf("4. Search Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: //Insert Record
                insertRecord(students, &count);
                break;
            case 2: //Delete Record
                deleteRecord(students, &count);
                break;
            case 3: //Display Records
                displayRecords(students, count);
                break;
            case 4: //Search Record
                searchRecord(students, count);
                break;
            case 5: //Exit
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

//Function to insert a new record into the database
void insertRecord(Student students[], int *count) {
    if (*count == MAXSIZE) { //Check if maximum capacity has been reached
        printf("Database already full. Cannot insert new record.\n");
        return;
    }

    Student newStudent;
    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter Name: ");
    scanf("%s", newStudent.name);
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);

    students[*count] = newStudent; //Add the new record to the end of the array
    *count += 1; //Update the count of records
    printf("Record added successfully.\n");
}

//Function to delete a record from the database
void deleteRecord(Student students[], int *count) {
    int rollNumber;
    printf("Enter Roll Number of student to delete: ");
    scanf("%d", &rollNumber);

    int indexToDelete = -1;
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("Record not found.\n");
        return;
    }

    for (int i = indexToDelete; i < *count - 1; i++) {
        students[i] = students[i + 1]; //Shift all records after the deleted record one position left
    }

    *count -= 1; //Update the count of records
    printf("Record deleted successfully.\n");
}

//Function to display all records in the database
void displayRecords(Student students[], int count) {
    if (count == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("Roll Number\tName\t\tAge\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%d\n", students[i].rollNumber, students[i].name, students[i].age);
    }
}

//Function to search for a specific record by roll number
void searchRecord(Student students[], int count) {
    if (count == 0) {
        printf("Database is empty.\n");
        return;
    }

    int rollNumber;
    printf("Enter Roll Number of student to search: ");
    scanf("%d", &rollNumber);

    int indexToSearch = -1;
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            indexToSearch = i;
            break;
        }
    }

    if (indexToSearch == -1) {
        printf("Record not found.\n");
        return;
    }

    printf("Roll Number\tName\t\tAge\n");
    printf("%d\t\t%s\t\t%d\n", students[indexToSearch].rollNumber, students[indexToSearch].name, students[indexToSearch].age);
}