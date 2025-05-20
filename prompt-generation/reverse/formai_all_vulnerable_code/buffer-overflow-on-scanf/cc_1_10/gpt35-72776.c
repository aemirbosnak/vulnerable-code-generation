//FormAI DATASET v1.0 Category: Database querying ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function declarations */
void addRecord(void);
void searchRecord(void);
void deleteRecord(void);
void displayAllRecords(void);

/* Structure for storing database records */
typedef struct
{
    int id;
    char name[50];
    char address[100];
    char email[50];
    char phone[20];
} Record;

/* Array to store database records */
Record records[100];

/* Global variables */
int numRecords = 0;
int nextRecordId = 1;

int main()
{
    char choice;
    do
    {
        /* Display menu options */
        printf("\nMenu:\n");
        printf("1. Add a record\n");
        printf("2. Search for a record\n");
        printf("3. Delete a record\n");
        printf("4. Display all records\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        
        /* Read user choice */
        scanf(" %c", &choice);
        
        /* Process user choice */
        switch(choice)
        {
            case '1':
                addRecord();
                break;
            case '2':
                searchRecord();
                break;
            case '3':
                deleteRecord();
                break;
            case '4':
                displayAllRecords();
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != '5');
    
    return 0;
}

void addRecord(void)
{
    /* Check if we have reached the maximum number of records */
    if(numRecords == 100)
    {
        printf("Error: database is full.\n");
        return;
    }
    
    /* Add record */
    Record newRecord;
    newRecord.id = nextRecordId;
    printf("Please enter the name: ");
    scanf(" %[^\n]", newRecord.name);
    printf("Please enter the address: ");
    scanf(" %[^\n]", newRecord.address);
    printf("Please enter the email: ");
    scanf(" %[^\n]", newRecord.email);
    printf("Please enter the phone number: ");
    scanf(" %[^\n]", newRecord.phone);
    records[numRecords] = newRecord;
    numRecords++;
    nextRecordId++;
    printf("Record added successfully.\n");
}

void searchRecord(void)
{
    /* Check if there are any records to search */
    if(numRecords == 0)
    {
        printf("There are no records in the database.\n");
        return;
    }
    
    /* Ask user for search criteria */
    char name[50];
    printf("Please enter the name to search for: ");
    scanf(" %[^\n]", name);
    
    /* Search for matching records */
    int numMatches = 0;
    for(int i = 0; i < numRecords; i++)
    {
        if(strcmp(records[i].name, name) == 0)
        {
            printf("Record found:\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Email: %s\n", records[i].email);
            printf("Phone: %s\n", records[i].phone);
            numMatches++;
        }
    }
    
    /* Check if any matches were found */
    if(numMatches == 0)
    {
        printf("No records found.\n");
    }
}

void deleteRecord(void)
{
    /* Check if there are any records to delete */
    if(numRecords == 0)
    {
        printf("There are no records in the database.\n");
        return;
    }
    
    /* Ask user for record ID to delete */
    int id;
    printf("Please enter the ID of the record to delete: ");
    scanf("%d", &id);
    
    /* Search for record with matching ID */
    int indexToDelete = -1;
    for(int i = 0; i < numRecords; i++)
    {
        if(records[i].id == id)
        {
            indexToDelete = i;
            break;
        }
    }
    
    /* Check if record was found */
    if(indexToDelete == -1)
    {
        printf("No record found with ID %d.\n", id);
        return;
    }
    
    /* Shift remaining records over and decrement numRecords */
    for(int i = indexToDelete + 1; i < numRecords; i++)
    {
        records[i - 1] = records[i];
    }
    numRecords--;
    
    printf("Record with ID %d deleted successfully.\n", id);
}

void displayAllRecords(void)
{
    /* Check if there are any records to display */
    if(numRecords == 0)
    {
        printf("There are no records in the database.\n");
        return;
    }
    
    /* Display header */
    printf("%-5s%-20s%-50s%-30s%-15s\n", "ID", "Name", "Address", "Email", "Phone");
    
    /* Display each record */
    for(int i = 0; i < numRecords; i++)
    {
        printf("%-5d%-20s%-50s%-30s%-15s\n", records[i].id, records[i].name, records[i].address, records[i].email, records[i].phone);
    }
}