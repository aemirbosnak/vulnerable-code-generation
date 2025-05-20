//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
    float weight;
} Person;

typedef struct {
    Person records[MAX_RECORDS];
    int count;
} Database;

void addRecord(Database *db, const char *name, int age, float height, float weight) {
    if (db->count < MAX_RECORDS) {
        strncpy(db->records[db->count].name, name, MAX_NAME_LENGTH);
        db->records[db->count].age = age;
        db->records[db->count].height = height;
        db->records[db->count].weight = weight;
        db->count++;
        printf("Record added: %s, %d, %.2f, %.2f\n", name, age, height, weight);
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

void displayRecords(const Database *db) {
    printf("\nDatabase Records:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Name: %s, Age: %d, Height: %.2f, Weight: %.2f\n",
               db->records[i].name, db->records[i].age, db->records[i].height, db->records[i].weight);
    }
}

float computeAverageHeight(const Database *db) {
    float totalHeight = 0;
    for (int i = 0; i < db->count; i++) {
        totalHeight += db->records[i].height;
    }
    return db->count != 0 ? totalHeight / db->count : 0;
}

float computeAverageWeight(const Database *db) {
    float totalWeight = 0;
    for (int i = 0; i < db->count; i++) {
        totalWeight += db->records[i].weight;
    }
    return db->count != 0 ? totalWeight / db->count : 0;
}

int main() {
    Database db = { .count = 0 };
    char name[MAX_NAME_LENGTH];
    int age;
    float height, weight;

    while (1) {
        printf("Enter name (or 'exit' to finish): ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter height (in cm): ");
        scanf("%f", &height);
        printf("Enter weight (in kg): ");
        scanf("%f", &weight);

        addRecord(&db, name, age, height, weight);
    }

    displayRecords(&db);

    float avgHeight = computeAverageHeight(&db);
    float avgWeight = computeAverageWeight(&db);
    
    printf("\nAverage Height: %.2f cm\n", avgHeight);
    printf("Average Weight: %.2f kg\n", avgWeight);

    return 0;
}