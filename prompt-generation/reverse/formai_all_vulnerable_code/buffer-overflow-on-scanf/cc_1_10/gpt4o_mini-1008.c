//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3
#define CITY_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char age[AGE_LENGTH];
    char city[CITY_LENGTH];
} Record;

Record database[MAX_RECORDS];
int recordCount = 0;

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[recordCount].name);
    printf("Enter age: ");
    scanf("%s", database[recordCount].age);
    printf("Enter city: ");
    scanf("%s", database[recordCount].city);
    recordCount++;
    printf("Record added successfully!\n");
}

void viewRecords() {
    if (recordCount == 0) {
        printf("No records in the database.\n");
        return;
    }

    printf("\n--- Records ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Record %d: Name: %s, Age: %s, City: %s\n", 
            i + 1, database[i].name, database[i].age, database[i].city);
    }
    printf("----------------\n");
}

void searchRecord() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;

    for (int i = 0; i < recordCount; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Record Found: Name: %s, Age: %s, City: %s\n", 
                database[i].name, database[i].age, database[i].city);
            found = 1;
            break;
        }
    }
    if (!found) printf("No record found with the name '%s'.\n", name);
}

void deleteRecord() {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(database[i].name, name) == 0) {
            for (int j = i; j < recordCount - 1; j++) {
                database[j] = database[j + 1];
            }
            recordCount--;
            printf("Record with name '%s' deleted!\n", name);
            return;
        }
    }
    printf("No record found with the name '%s'.\n", name);
}

void saveRecords() {
    FILE *file = fopen("database.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%s,%s,%s\n", database[i].name, database[i].age, database[i].city);
    }
    fclose(file);
    printf("Records saved to 'database.txt'.\n");
}

void loadRecords() {
    FILE *file = fopen("database.txt", "r");
    if (!file) {
        printf("No existing database found, starting fresh!\n");
        return;
    }
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", 
                  database[recordCount].name, 
                  database[recordCount].age, 
                  database[recordCount].city) != EOF) {
        recordCount++;
    }
    fclose(file);
    printf("Records loaded from 'database.txt'.\n");
}

int main() {
    loadRecords();
    int option;

    while (1) {
        printf("\n=== Database Menu ===\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search for Record\n");
        printf("4. Delete Record\n");
        printf("5. Save Records\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: addRecord(); break;
            case 2: viewRecords(); break;
            case 3: searchRecord(); break;
            case 4: deleteRecord(); break;
            case 5: saveRecords(); break;
            case 6: 
                saveRecords(); 
                printf("Exiting program...\n"); 
                exit(0);
            default: printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}