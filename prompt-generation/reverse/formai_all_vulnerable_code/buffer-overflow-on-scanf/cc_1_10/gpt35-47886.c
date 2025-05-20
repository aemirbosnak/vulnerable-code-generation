//FormAI DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent the record
struct Record {
    int key;
    char name[30];
    int age;
};

// Function to insert a record into the database
void insertRecord(struct Record *database, int size) {
    int key, age;
    char name[30];

    printf("\nEnter the key: ");
    scanf("%d", &key);
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the age: ");
    scanf("%d", &age);

    // Inserting the record into the database
    database[size].key = key;
    strcpy(database[size].name, name);
    database[size].age = age;
}

// Function to display all the records in the database
void displayRecord(struct Record *database, int size) {
    printf("\n\nKey\tName\tAge\n");
    for(int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\n", database[i].key, database[i].name, database[i].age);
    }
}

// Function to perform binary search to find a record based on key
int binarySearch(struct Record *database, int key, int left, int right) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(database[mid].key == key) {
            return mid;
        }
        else if(database[mid].key > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int size = 0;
    int choice = 0;
    int key, index;

    // Allocating memory to store the database
    struct Record *database = (struct Record*)malloc(sizeof(struct Record)*100);

    do {
        printf("\n\n1. Insert a record into the database");
        printf("\n2. Display all the records in the database");
        printf("\n3. Search for a record based on key");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertRecord(database, size);
                size++;
                break;

            case 2:
                displayRecord(database, size);
                break;

            case 3:
                printf("\nEnter the key to search for: ");
                scanf("%d", &key);
                index = binarySearch(database, key, 0, size-1);
                if(index == -1) {
                    printf("\nRecord not found!");
                }
                else {
                    printf("\nRecord found at index: %d", index);
                }
                break;

            case 4:
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid choice!");
                break;
        }

    } while(choice != 4);

    free(database);
    return 0;
}