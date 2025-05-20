//FormAI DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#define MAX_REC 100

// Defining the structure of each record in the database
struct Record {
    int id;
    char name[20];
    char email[30];
};

// Function to add a new record to the database
void add_record(struct Record* db, int* len) {
    if (*len >= MAX_REC) {
        printf("The database is full. Please delete some records first.\n");
        return;
    }
    printf("Enter ID, name and email of the new record separated by spaces:\n");
    scanf("%d %s %s", &db[*len].id, db[*len].name, db[*len].email);
    (*len)++;
}
 
// Function to delete an existing record from the database
void delete_record(struct Record* db, int* len) {
    if (*len <= 0) {
        printf("The database is empty. Please add some records first.\n");
        return;
    }
    printf("Enter the ID of the record to be deleted:\n");
    int id, i;
    scanf("%d", &id);
    for (i=0; i<*len; i++) {
        if (db[i].id == id) {
            for (int j=i; j<*len-1; j++) {
                db[j] = db[j+1]; // shift all the records after the deleted record by one position to the left
            }
            (*len)--;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to display all the records in the database
void display_records(struct Record* db, int* len) {
    if (*len <= 0) {
        printf("The database is empty. Please add some records first.\n");
        return;
    }
    printf("ID\tName\tEmail\n");
    for (int i=0; i<*len; i++) {
        printf("%d\t%s\t%s\n", db[i].id, db[i].name, db[i].email);
    }
}

int main() {
    struct Record db[MAX_REC]; // array of records to store the database
    int len = 0; // number of records in the database
    int choice;
    
    while(1) {
        printf("\nChoose an option:\n1. Add a new record\n2. Delete an existing record\n3. Display all the records\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record(db, &len);
                break;
            case 2:
                delete_record(db, &len);
                break;
            case 3:
                display_records(db, &len);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }
    }
    return 0;
}