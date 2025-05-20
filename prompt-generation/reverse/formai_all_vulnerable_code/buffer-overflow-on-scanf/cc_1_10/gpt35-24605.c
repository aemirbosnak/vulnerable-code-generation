//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum number of records that can be stored in database

typedef struct {
    char name[20];
    int age;
    char address[50];
    char phone_number[15];
} Record;

// Function to add a new record to the database
void add_record(int *num_records, Record database[]) {
    if (*num_records == MAX_SIZE) {
        printf("Error: Database is full!\n");
        return;
    }

    Record new_record;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter age: ");
    scanf("%d", &new_record.age);

    printf("Enter address: ");
    scanf("%s", new_record.address);

    printf("Enter phone number: ");
    scanf("%s", new_record.phone_number);

    database[*num_records] = new_record;

    (*num_records)++;

    printf("Record added to database.\n");
}

// Function to display all records in the database
void display_records(int num_records, Record database[]) {
    if (num_records == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("Name\tAge\tAddress\t\tPhone Number\n");

    for (int i = 0; i < num_records; i++) {
        printf("%s\t%d\t%s\t%s\n", database[i].name, database[i].age, database[i].address, database[i].phone_number);
    }
}

// Main function
int main() {
    int num_records = 0;
    Record database[MAX_SIZE];

    char input[10];

    while (1) {
        printf("Enter command (add, display, quit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            add_record(&num_records, database);
        } else if (strcmp(input, "display") == 0) {
            display_records(num_records, database);
        } else if (strcmp(input, "quit") == 0) {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}