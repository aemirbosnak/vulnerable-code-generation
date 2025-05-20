//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define struct for each data entry
struct DataEntry{
    int id;
    char name[50];
    int age;
    char city[50];
};

// Define struct for Database
struct Database{
    int size;
    struct DataEntry *entries;
};

// Function to add new data entry to database
void addDataEntry(struct Database *db){
    // Increase database size by 1
    db->size++;
    db->entries = (struct DataEntry *)realloc(db->entries, sizeof(struct DataEntry)*db->size);
    
    // Prompt for user input for new data entry
    printf("\nEnter ID: ");
    scanf("%d", &(db->entries[db->size-1].id));
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", db->entries[db->size-1].name);
    printf("Enter Age: ");
    scanf("%d", &(db->entries[db->size-1].age));
    printf("Enter City: ");
    scanf(" %[^\n]%*c", db->entries[db->size-1].city);
    
    // Confirmation message
    printf("\nNew entry added to Database!\n");
}

// Function to display all data entries in database
void displayAllDataEntries(struct Database *db){
    // Check if database is empty
    if(db->size==0){
        printf("\nDatabase is Empty!\n");
        return;
    }
    
    // Loop through all data entries and print each entry
    printf("\n%-5s%-20s%-10s%-20s\n", "ID", "NAME", "AGE", "CITY");
    for(int i=0; i<db->size; i++){
        printf("%-5d", db->entries[i].id);
        printf("%-20s", db->entries[i].name);
        printf("%-10d", db->entries[i].age);
        printf("%-20s\n", db->entries[i].city);
    }
}

// Function to search for data entry by ID
void searchDataEntryByID(struct Database *db){
    // Check if database is empty
    if(db->size==0){
        printf("\nDatabase is Empty!\n");
        return;
    }
    
    // Prompt user for ID to search and loop through all data entries to find matching ID
    int id;
    printf("\nEnter ID to Search: ");
    scanf("%d", &id);
    for(int i=0; i<db->size; i++){
        if(db->entries[i].id==id){
            printf("\n%-5s%-20s%-10s%-20s\n", "ID", "NAME", "AGE", "CITY");
            printf("%-5d", db->entries[i].id);
            printf("%-20s", db->entries[i].name);
            printf("%-10d", db->entries[i].age);
            printf("%-20s\n", db->entries[i].city);
            return;
        }
    }
    // If no matching ID found
    printf("\nID not Found!\n");
}

// Function to delete data entry by ID
void deleteDataEntryByID(struct Database *db){
    // Check if database is empty
    if(db->size==0){
        printf("\nDatabase is Empty!\n");
        return;
    }
    
    // Prompt user for ID to delete and loop through all data entries to find matching ID
    int id;
    printf("\nEnter ID to Delete: ");
    scanf("%d", &id);
    for(int i=0; i<db->size; i++){
        if(db->entries[i].id==id){
            // Shift all data entries after the found ID one position to the left
            for(int j=i+1; j<db->size; j++){
                db->entries[j-1] = db->entries[j];
            }
            
            // Decrease database size by 1
            db->size--;
            db->entries = (struct DataEntry *)realloc(db->entries, sizeof(struct DataEntry)*db->size);
            
            // Confirmation message
            printf("\nID %d Deleted from Database!\n", id);
            return;
        }
    }
    // If no matching ID found
    printf("\nID not Found!\n");
}

int main(){
    // Initialize empty database
    struct Database db = {0,NULL};
    
    // Prompt user for operation choice and loop until exit choice is made
    int choice;
    do{
        printf("\n1. Add Data Entry\n");
        printf("2. Display All Data Entries\n");
        printf("3. Search Data Entry by ID\n");
        printf("4. Delete Data Entry by ID\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addDataEntry(&db);
                break;
            case 2:
                displayAllDataEntries(&db);
                break;
            case 3:
                searchDataEntryByID(&db);
                break;
            case 4:
                deleteDataEntryByID(&db);
                break;
            case 5:
                printf("\nExiting Program....\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }while(choice!=5);
    
    // Free dynamically allocated memory
    free(db.entries);
    
    return 0;
}