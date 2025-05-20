//FormAI DATASET v1.0 Category: File handling ; Style: real-life
#include<stdio.h>

struct record{
    int id; // ID of the record
    char name[20]; // Name of the person in the record
    int age; // Age of the person in the record
};

// Function to add new records to file
void addRecord(FILE* file){
    struct record r;
    printf("Enter ID: ");
    scanf("%d", &r.id);
    printf("Enter Name: ");
    scanf("%s", &r.name);
    printf("Enter Age: ");
    scanf("%d", &r.age);
    fwrite(&r, sizeof(struct record), 1, file);
    printf("Record added successfully!\n\n");
}

// Function to search for a specific record
void searchRecord(FILE* file){
    int searchId, found = 0;
    struct record r;
    printf("Enter ID to search for: ");
    scanf("%d", &searchId);
    while(fread(&r, sizeof(struct record), 1, file)){
        if(r.id == searchId){
            printf("Record found:\n");
            printf("ID: %d\n", r.id);
            printf("Name: %s\n", r.name);
            printf("Age: %d\n\n", r.age);
            found = 1;
            break;
        }
    }
    if(!found) printf("Record with ID %d not found.\n\n", searchId);
}

// Function to display all records in file
void displayRecords(FILE* file){
    struct record r;
    printf("All records:\n");
    while(fread(&r, sizeof(struct record), 1, file)){
        printf("ID: %d\n", r.id);
        printf("Name: %s\n", r.name);
        printf("Age: %d\n\n", r.age);
    }
}

int main(){
    FILE* file;
    file = fopen("records.bin", "ab+"); // Opening in append+binary mode
    int choice;
    do{
        printf("MENU\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addRecord(file);
                break;
            case 2:
                searchRecord(file);
                break;
            case 3:
                displayRecords(file);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 4);
    fclose(file); // Closing file
    return 0;
}