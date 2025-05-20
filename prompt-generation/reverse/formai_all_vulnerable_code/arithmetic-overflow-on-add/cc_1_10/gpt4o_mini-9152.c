//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    float height;
    float weight;
} DataRecord;

typedef struct {
    DataRecord records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database* db) {
    db->count = 0;
}

void addRecord(Database* db) {
    if (db->count < MAX_RECORDS) {
        printf("Enter Name: ");
        scanf("%s", db->records[db->count].name);
        
        printf("Enter Age: ");
        scanf("%d", &db->records[db->count].age);
        
        printf("Enter Height (in cm): ");
        scanf("%f", &db->records[db->count].height);
        
        printf("Enter Weight (in kg): ");
        scanf("%f", &db->records[db->count].weight);
        
        db->count++;
        printf("Record added successfully!\n\n");
    } else {
        printf("Database is full! Cannot add more records.\n\n");
    }
}

void displayRecords(Database* db) {
    if (db->count == 0) {
        printf("No records to display.\n\n");
        return;
    }

    printf("Current Records:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Record %d: Name: %s, Age: %d, Height: %.2f cm, Weight: %.2f kg\n",
                i + 1, db->records[i].name, db->records[i].age,
                db->records[i].height, db->records[i].weight);
    }
    printf("\n");
}

void findAverageAge(Database* db) {
    if (db->count == 0) {
        printf("No records to calculate average age.\n\n");
        return;
    }

    int totalAge = 0;
    for (int i = 0; i < db->count; i++) {
        totalAge += db->records[i].age;
    }
    
    float averageAge = (float)totalAge / db->count;
    printf("Average Age: %.2f\n\n", averageAge);
}

void findTallestPerson(Database* db) {
    if (db->count == 0) {
        printf("No records to find the tallest person.\n\n");
        return;
    }

    float maxHeight = db->records[0].height;
    char *tallestPerson = db->records[0].name;

    for (int i = 1; i < db->count; i++) {
        if (db->records[i].height > maxHeight) {
            maxHeight = db->records[i].height;
            tallestPerson = db->records[i].name;
        }
    }
    
    printf("The tallest person is %s with a height of %.2f cm!\n\n", tallestPerson, maxHeight);
}

void findHeaviestPerson(Database* db) {
    if (db->count == 0) {
        printf("No records to find the heaviest person.\n\n");
        return;
    }

    float maxWeight = db->records[0].weight;
    char *heaviestPerson = db->records[0].name;

    for (int i = 1; i < db->count; i++) {
        if (db->records[i].weight > maxWeight) {
            maxWeight = db->records[i].weight;
            heaviestPerson = db->records[i].name;
        }
    }
    
    printf("The heaviest person is %s with a weight of %.2f kg!\n\n", heaviestPerson, maxWeight);
}

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice;
    do {
        printf("Data Mining Application\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Find Average Age\n");
        printf("4. Find Tallest Person\n");
        printf("5. Find Heaviest Person\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                findAverageAge(&db);
                break;
            case 4:
                findTallestPerson(&db);
                break;
            case 5:
                findHeaviestPerson(&db);
                break;
            case 6:
                printf("Exiting the program. Happy Data Mining!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n\n");
                break;
        }
    } while (choice != 6);

    return 0;
}