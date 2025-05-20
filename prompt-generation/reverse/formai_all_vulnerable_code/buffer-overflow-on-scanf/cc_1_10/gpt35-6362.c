//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Define structure to hold database records
#define MAX_RECORDS 100
typedef struct
{
    int id;
    char name[50];
    int age;
    char address[100];
} Record;

//Define structure to hold database
typedef struct
{
    Record records[MAX_RECORDS];
    int numRecords;
} Database;

//Function to add a record to the database
void addRecord(Database *db)
{
    //Check if database is full
    if (db->numRecords >= MAX_RECORDS)
    {
        printf("Database is full, cannot add record.\n");
        return;
    }

    //Get input values for record
    int id, age;
    char name[50], address[100];
    printf("Enter record id: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter address: ");
    scanf("%s", address);

    //Create new record and add to database
    Record newRecord = {id, name, age, address};
    db->records[db->numRecords++] = newRecord;
    printf("Record added to database.\n");
}

//Function to print all records in the database
void printRecords(Database *db)
{
    if (db->numRecords == 0)
    {
        printf("Database is empty.\n");
        return;
    }

    //Print header row
    printf("| %-3s | %-20s | %-3s | %-50s |\n", "ID", "Name", "Age", "Address");
    printf("+-----+----------------------+-----+----------------------------------------------------+\n");

    //Print each record in the database
    for (int i = 0; i < db->numRecords; i++)
    {
        printf("| %-3d | %-20s | %-3d | %-50s |\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].address);
    }
}

//Function to search for a record by ID
void searchRecord(Database *db)
{
    int id;
    printf("Enter record id to search for: ");
    scanf("%d", &id);

    //Search for record with matching ID
    bool found = false;
    for (int i = 0; i < db->numRecords; i++)
    {
        if (db->records[i].id == id)
        {
            printf("| %-3s | %-20s | %-3s | %-50s |\n", "ID", "Name", "Age", "Address");
            printf("+-----+----------------------+-----+----------------------------------------------------+\n");
            printf("| %-3d | %-20s | %-3d | %-50s |\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].address);
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Record not found.\n");
    }
}

int main()
{
    Database db = {0};

    while (true)
    {
        printf("\n---------- DATABASE MENU ----------\n");
        printf("1. Add record\n");
        printf("2. Print all records\n");
        printf("3. Search for record by ID\n");
        printf("4. Exit program\n");

        int choice;
        printf("\nEnter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addRecord(&db);
            break;
        case 2:
            printRecords(&db);
            break;
        case 3:
            searchRecord(&db);
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}