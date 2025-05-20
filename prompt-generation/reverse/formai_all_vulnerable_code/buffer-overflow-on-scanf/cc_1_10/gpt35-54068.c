//FormAI DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define record structure
typedef struct{
    int key;
    char name[20];
    char address[20];
}Record;

//function to display menu options
void displayMenu(){
    printf("1. Insert a record\n");
    printf("2. Search for a record\n");
    printf("3. Delete a record\n");
    printf("4. Display all records\n");
    printf("5. Exit\n");
}

//function to insert record
void insertRecord(Record *database, int *size){
    printf("Enter key: ");
    scanf("%d", &database[*size].key);
    printf("Enter name: ");
    scanf("%s", database[*size].name);
    printf("Enter address: ");
    scanf("%s", database[*size].address);
    *size += 1;
    printf("Record added successfully.\n");
}

//function to search record
void searchRecord(Record *database, int size){
    int key;
    printf("Enter key to search for: ");
    scanf("%d", &key);
    for(int i=0; i<size; i++){
        if(database[i].key == key){
            printf("Record found:\n");
            printf("Key: %d\n", database[i].key);
            printf("Name: %s\n", database[i].name);
            printf("Address: %s\n", database[i].address);
            return;
        }
    }
    printf("Record not found.\n");
}

//function to delete record
void deleteRecord(Record *database, int *size){
    int key;
    printf("Enter key to delete: ");
    scanf("%d", &key);
    for(int i=0; i<*size; i++){
        if(database[i].key == key){
            for(int j=i; j<*size-1; j++){
                database[j] = database[j+1];
            }
            *size -= 1;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

//function to display all records
void displayRecords(Record *database, int size){
    if(size == 0){
        printf("No records found.\n");
        return;
    }
    printf("Records found:\n");
    for(int i=0; i<size; i++){
        printf("Key: %d\n", database[i].key);
        printf("Name: %s\n", database[i].name);
        printf("Address: %s\n", database[i].address);
    }
}

int main(){
    Record database[100];
    int size = 0;
    int choice;

    while(1){
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                insertRecord(database, &size);
                break;
            case 2:
                searchRecord(database, size);
                break;
            case 3:
                deleteRecord(database, &size);
                break;
            case 4:
                displayRecords(database, size);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}