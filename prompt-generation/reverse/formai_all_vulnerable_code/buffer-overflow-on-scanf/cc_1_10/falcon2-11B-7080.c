//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>

// Function to add a record to the database
void add_record(int *db, int index, int value) {
    db[index] = value;
}

// Function to retrieve a record from the database
int get_record(int *db, int index) {
    return db[index];
}

// Function to delete a record from the database
void delete_record(int *db, int index) {
    db[index] = 0;
}

// Function to print the entire database
void print_database(int *db, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", db[i]);
    }
    printf("\n");
}

// Function to search for a record in the database
int search_record(int *db, int index, int value) {
    for (int i = 0; i < index; i++) {
        if (db[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int db[10];
    int index = 0;

    printf("Welcome to the Simple Database Simulator!\n");
    printf("Please enter a number to add a record to the database:\n");
    scanf("%d", &db[index]);
    index++;

    printf("Record added!\n");

    while (1) {
        printf("Enter 1 to add a record to the database:\n");
        printf("Enter 2 to retrieve a record from the database:\n");
        printf("Enter 3 to delete a record from the database:\n");
        printf("Enter 4 to print the entire database:\n");
        printf("Enter 5 to search for a record in the database:\n");
        printf("Enter 6 to exit the program:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please enter a number to add a record to the database:\n");
                scanf("%d", &db[index]);
                index++;
                break;
            case 2:
                printf("Please enter an index to retrieve a record from the database:\n");
                int index_to_retrieve;
                scanf("%d", &index_to_retrieve);
                printf("The value at index %d is %d\n", index_to_retrieve, db[index_to_retrieve]);
                break;
            case 3:
                printf("Please enter an index to delete a record from the database:\n");
                int index_to_delete;
                scanf("%d", &index_to_delete);
                delete_record(db, index_to_delete);
                break;
            case 4:
                printf("The database:\n");
                print_database(db, index);
                break;
            case 5:
                printf("Please enter an index to search for a record in the database:\n");
                int index_to_search;
                scanf("%d", &index_to_search);
                int value_to_search;
                printf("Please enter a value to search for:\n");
                scanf("%d", &value_to_search);
                printf("%s\n", search_record(db, index_to_search, value_to_search)? "Found!\n" : "Not found.\n");
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}