//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum number of records */
#define MAX_RECORDS 100

/* Define structure for a record */
typedef struct record {
    int id;
    char name[20];
    char address[50];
} record_t;

/* Declare variables for database */
record_t database[MAX_RECORDS];
int num_records = 0;

/* Display menu and get user choice */
int menu()
{
    int choice;

    printf("\nDATABASE SIMULATION\n");
    printf("--------------------\n");
    printf("1. Add record\n");
    printf("2. Delete record\n");
    printf("3. Search record\n");
    printf("4. List all records\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 5);

    return choice;
}

/* Add a record to the database */
void add_record()
{
    int id;
    char name[20];
    char address[50];

    /* Get data from user */
    printf("\nEnter record ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter address: ");
    scanf("%s", address);

    /* Check if ID already in use */
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            printf("\nError: ID already in use\n");
            return;
        }
    }

    /* Add record to database */
    database[num_records].id = id;
    strcpy(database[num_records].name, name);
    strcpy(database[num_records].address, address);
    num_records++;

    printf("\nRecord added successfully\n");
}

/* Delete a record from the database */
void delete_record()
{
    int id;

    /* Get ID to delete */
    printf("\nEnter ID of record to delete: ");
    scanf("%d", &id);

    /* Find index of record to delete */
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    /* Delete record if found */
    if (index != -1) {
        for (int i = index; i < num_records - 1; i++) {
            database[i] = database[i + 1];
        }
        num_records--;
        printf("\nRecord deleted successfully\n");
    } else {
        printf("\nError: Record not found\n");
    }
}

/* Search for a record in the database */
void search_record()
{
    int id;

    /* Get ID to search for */
    printf("\nEnter ID to search for: ");
    scanf("%d", &id);

    /* Find index of record */
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    /* Display record if found */
    if (index != -1) {
        printf("\nRecord found:\n");
        printf("ID: %d\n", database[index].id);
        printf("Name: %s\n", database[index].name);
        printf("Address: %s\n", database[index].address);
    } else {
        printf("\nError: Record not found\n");
    }
}

/* List all records in the database */
void list_records()
{
    /* Display header */
    printf("\nID\tName\tAddress\n");
    printf("----------------------------------------\n");

    /* Display records */
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%s\n", database[i].id, database[i].name, database[i].address);
    }

    /* Display footer */
    printf("----------------------------------------\n");
    printf("Total records: %d\n", num_records);
}

/* Main function */
int main()
{
    int choice;

    /* Loop until user chooses to exit */
    do {
        choice = menu();

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                search_record();
                break;
            case 4:
                list_records();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}