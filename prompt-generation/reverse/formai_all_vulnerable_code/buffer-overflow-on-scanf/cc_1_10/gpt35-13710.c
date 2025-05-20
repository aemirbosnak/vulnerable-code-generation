//FormAI DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>

// structure definition for student records
typedef struct {
    int roll_no;
    char name[50];
    float marks;
} student_record;

// function to add a new record to the database with indexing
void add_record(student_record* database, int* index, int max_size) {
    if (*index == max_size) {
        printf("Database is full!\n");
    } else {
        printf("Enter student details:\n");
        printf("Roll No. : ");
        scanf("%d", &database[*index].roll_no);
        printf("Name : ");
        scanf("%s", database[*index].name);
        printf("Marks : ");
        scanf("%f", &database[*index].marks);
        *index += 1;
        printf("Record added successfully!\n");
    }
}

// function to search for a student record by roll number
void search_record(student_record* database, int index) {
    int roll_no;
    printf("Enter roll number to search : ");
    scanf("%d", &roll_no);
    int found = 0;
    for (int i = 0; i < index; i++) {
        if (database[i].roll_no == roll_no) {
            printf("Student Details:\n");
            printf("Roll No. : %d\n", database[i].roll_no);
            printf("Name : %s\n", database[i].name);
            printf("Marks : %.2f\n", database[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

// function to print all student records in the database
void print_records(student_record* database, int index) {
    printf("Student Records:\n\n");
    printf("Roll No.\tName\t\tMarks\n");
    for (int i = 0; i < index; i++) {
        printf("%d\t\t%s\t\t%.2f\n", database[i].roll_no, database[i].name, database[i].marks);
    }
}

// main function
int main() {
    int max_size = 100;  // maximum number of records that can be stored
    student_record database[max_size];  // array to hold the student records
    int index = 0;  // current number of records in the database

    // menu loop
    while (1) {
        printf("\n\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Print Records\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record(database, &index, max_size);
                break;
            case 2:
                search_record(database, index);
                break;
            case 3:
                print_records(database, index);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}