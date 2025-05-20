//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_INDEX 100

typedef struct {
    int id;
    char name[50];
    char email[50];
} Record;

typedef struct {
    int id;
    int record_index;
} IndexEntry;

Record database[MAX_RECORDS];
IndexEntry index_table[MAX_INDEX];
int record_count = 0;
int index_count = 0;

// Function to add a record to the database
void add_record(int id, const char* name, const char* email) {
    if(record_count < MAX_RECORDS) {
        database[record_count].id = id;
        strcpy(database[record_count].name, name);
        strcpy(database[record_count].email, email);
        
        // Create index entry
        index_table[index_count].id = id;
        index_table[index_count].record_index = record_count;
        index_count++;
        
        record_count++;
        printf("Record added: ID %d, Name %s, Email %s\n", id, name, email);
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

// Function to find a record by ID using the index
void find_record(int id) {
    for (int i = 0; i < index_count; i++) {
        if (index_table[i].id == id) {
            int record_index = index_table[i].record_index;
            printf("Found Record: ID %d, Name %s, Email %s\n", 
                   database[record_index].id, 
                   database[record_index].name, 
                   database[record_index].email);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

// Function to display all records
void display_records() {
    printf("\nAll Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", 
               database[i].id, 
               database[i].name, 
               database[i].email);
    }
}

// Main function to drive the program
int main() {
    int choice, id;
    char name[50], email[50];
    
    while (1) {
        printf("\n*** Database Indexing System ***\n");
        printf("1. Add Record\n");
        printf("2. Find Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                add_record(id, name, email);
                break;
            case 2:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                find_record(id);
                break;
            case 3:
                display_records();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}