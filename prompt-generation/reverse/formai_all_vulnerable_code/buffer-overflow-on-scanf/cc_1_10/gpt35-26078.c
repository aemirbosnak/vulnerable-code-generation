//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum number of records that can be stored
#define MAX_RECORDS 100

// Define the length of each field in a record
#define FIELD_LENGTH 50

// Define the size of the record in bytes
#define RECORD_SIZE (4 + (3 * FIELD_LENGTH))

// Define the structure of a record
typedef struct {
    int id;
    char name[FIELD_LENGTH];
    char category[FIELD_LENGTH];
    int quantity;
} Record;

// Define the function to add a new record
void addRecord(Record *records, int *count) {
    Record newRecord;
    printf("Enter the product name: ");
    scanf("%s", newRecord.name);
    printf("Enter the product category: ");
    scanf("%s", newRecord.category);
    printf("Enter the product quantity: ");
    scanf("%d", &newRecord.quantity);
    newRecord.id = *count;
    records[*count] = newRecord;
    *count += 1;
    printf("Product added succesfully!\n");
}

// Define the function to remove a record
void removeRecord(Record *records, int *count) {
    int id;
    printf("Enter the product ID to remove: ");
    scanf("%d", &id);
    for(int i = 0; i < *count; i++) {
        if(records[i].id == id) {
            for(int j = i; j < *count - 1; j++) {
                records[j] = records[j+1];
            }
            *count -= 1;
            printf("Product removed succesfully!\n");
            return;
        }
    }
    printf("Product ID not found.\n");
}

// Define the function to search for a record by name
void searchRecord(Record *records, int *count) {
    char name[FIELD_LENGTH];
    printf("Enter the product name to search: ");
    scanf("%s", name);
    for(int i = 0; i < *count; i++) {
        if(strcmp(records[i].name, name) == 0) {
            printf("Product ID: %d\n", records[i].id);
            printf("Product name: %s\n", records[i].name);
            printf("Product category: %s\n", records[i].category);
            printf("Product quantity: %d\n", records[i].quantity);
            return;
        }
    }
    printf("Product name not found.\n");
}

// Define the function to print all records
void printRecords(Record *records, int *count) {
    printf("Product Inventory:\n");
    for(int i = 0; i < *count; i++) {
        printf("Product ID: %d\n", records[i].id);
        printf("Product name: %s\n", records[i].name);
        printf("Product category: %s\n", records[i].category);
        printf("Product quantity: %d\n", records[i].quantity);
    }
    if(*count == 0) {
        printf("No products found.\n");
    }
}

int main() {

    // Initialize the records and count
    Record records[MAX_RECORDS];
    int count = 0;

    // Define the menu options
    int choice;
    do {
        printf("1. Add new product\n");
        printf("2. Remove product\n");
        printf("3. Search product\n");
        printf("4. Print all products\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                removeRecord(records, &count);
                break;
            case 3:
                searchRecord(records, &count);
                break;
            case 4:
                printRecords(records, &count);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 0);

    return 0;
}