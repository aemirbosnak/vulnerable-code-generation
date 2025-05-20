//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100 // Maximum number of records allowed

// Structure to hold a record in the database
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Record;

// Global variables
Record records[MAX_RECORDS];
int num_records = 0;

// Function to add a new record to the database
void add_record() {
    Record new_record;
    printf("Enter id: ");
    scanf("%d", &new_record.id);
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    printf("Enter salary: ");
    scanf("%f", &new_record.salary);
    records[num_records++] = new_record;
}

// Function to display all records in the database
void display_records() {
    printf("%-5s %-20s %-5s %-10s\n", "ID", "NAME", "AGE", "SALARY");
    for(int i = 0; i < num_records; i++) {
        printf("%-5d %-20s %-5d %-10.2f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
    }
}

// Function to search for a record by id
void search_record(int id) {
    for(int i = 0; i < num_records; i++) {
        if(records[i].id == id) {
            printf("%-5s %-20s %-5s %-10s\n", "ID", "NAME", "AGE", "SALARY");
            printf("%-5d %-20s %-5d %-10.2f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
            return;
        }
    }
    printf("Record not found!\n");
}

// Function to delete a record by id
void delete_record(int id) {
    for(int i = 0; i < num_records; i++) {
        if(records[i].id == id) {
            for(int j = i; j < num_records - 1; j++) {
                records[j] = records[j+1];
            }
            num_records--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

int main() {
    int choice, id;
    while(1) {
        printf("\n1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Enter id to search: ");
                scanf("%d", &id);
                search_record(id);
                break;
            case 4:
                printf("Enter id to delete: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}