//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
// This is a simulation program for a simple database management system
// We will be using C language here to code the simulation program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

int num_records = 0;

// Structure for storing our database records
struct record {
    int id;
    char name[50];
    char phone[20];
    char email[50];
};

// Array to store our records
struct record records[MAX_RECORDS];

// Function to add a new record to our database
void add_record() {
    struct record new_rec;

    printf("\nEnter ID: ");
    scanf("%d", &new_rec.id);

    printf("Enter name: ");
    scanf("%s", &new_rec.name);

    printf("Enter phone: ");
    scanf("%s", &new_rec.phone);

    printf("Enter email: ");
    scanf("%s", &new_rec.email);

    records[num_records] = new_rec;
    num_records++;

    printf("\nRecord added successfully!\n\n");
}

// Function to search for a record in our database
void search_record() {
    int id;

    printf("\nEnter the ID of the record you want to search: ");
    scanf("%d", &id);

    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            printf("\nRecord found!\n\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Phone: %s\n", records[i].phone);
            printf("Email: %s\n\n", records[i].email);
            return;
        }
    }

    printf("\nRecord not found.\n\n");
}

// Function to print all records in our database
void print_records() {
    printf("\n");

    for (int i = 0; i < num_records; i++) {
        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Phone: %s\n", records[i].phone);
        printf("Email: %s\n\n", records[i].email);
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Print all records\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;

            case 2:
                search_record();
                break;

            case 3:
                print_records();
                break;

            case 4:
                printf("\nGoodbye!\n\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }
    return 0;
}