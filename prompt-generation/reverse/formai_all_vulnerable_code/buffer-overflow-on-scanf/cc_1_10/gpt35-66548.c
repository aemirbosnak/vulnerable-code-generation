//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#define MAX_RECORDS 10

struct student {
    int roll_no;
    char name[20];
    float marks;
};

struct student database[MAX_RECORDS];
int num_records = 0;

// Function to add a student record to the database
void add_record(int roll_no, char *name, float marks) {
    if(num_records >= MAX_RECORDS) {
        printf("\nError: Database is full. Cannot add more records.\n");
        return;
    }
    database[num_records].roll_no = roll_no;
    strcpy(database[num_records].name, name);
    database[num_records].marks = marks;
    num_records++;
}

// Function to find a student record by roll number
int find_record(int roll_no) {
    int i;
    for(i=0; i<num_records; i++) {
        if(database[i].roll_no == roll_no) {
            return i;
        }
    }
    return -1; // Record not found
}

// Function to delete a student record by roll number
void delete_record(int roll_no) {
    int index = find_record(roll_no);
    if(index == -1) {
        printf("\nError: Record not found.\n");
        return;
    }
    int i;
    for(i=index; i<num_records-1; i++) {
        database[i] = database[i+1];
    }
    num_records--;
}

// Function to display all records in the database
void display_records() {
    int i;
    printf("\nStudent Records:\n");
    printf("=================\n");
    printf("Roll No.\tName\tMarks\n");
    for(i=0; i<num_records; i++) {
        printf("%d\t\t%s\t%.2f\n", database[i].roll_no, database[i].name, database[i].marks);
    }
}

int main() {
    int choice, roll_no;
    char name[20];
    float marks;
    do {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Find Record\n");
        printf("3. Delete Record\n");
        printf("4. Display Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter Roll No: ");
                scanf("%d", &roll_no);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                add_record(roll_no, name, marks);
                break;
            case 2:
                printf("\nEnter Roll No: ");
                scanf("%d", &roll_no);
                int index = find_record(roll_no);
                if(index == -1) {
                    printf("\nRecord not found.\n");
                } else {
                    printf("\nRecord found:\n");
                    printf("Roll No.: %d\n", database[index].roll_no);
                    printf("Name: %s\n", database[index].name);
                    printf("Marks: %.2f\n", database[index].marks);
                }
                break;
            case 3:
                printf("\nEnter Roll No: ");
                scanf("%d", &roll_no);
                delete_record(roll_no);
                break;
            case 4:
                display_records();
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}