//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define COLS 5

// Structure representing a futuristic data entity
typedef struct {
    int id;
    char name[30];
    float value;
    double timestamp; // Timestamp in futuristic terms, e.g., nanoseconds since epoch
    char attributes[50]; // Extra attributes in string format
} DataEntity;

// Function prototypes
void addDataEntity(DataEntity* entities, int* count);
void displayDataEntities(const DataEntity* entities, int count);
void sortDataEntities(DataEntity* entities, int count);
int compareEntities(const void* a, const void* b);
void futuristicPause(int milliseconds);

// Main function
int main() {
    DataEntity dataEntities[MAX_SIZE];
    int count = 0;
    char choice;

    printf("=== Welcome to the Galactic Data Management System ===\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add Data Entity\n");
        printf("2. Display Data Entities\n");
        printf("3. Sort Data Entities\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addDataEntity(dataEntities, &count);
                break;
            case '2':
                displayDataEntities(dataEntities, count);
                break;
            case '3':
                sortDataEntities(dataEntities, count);
                break;
            case '0':
                printf("Exiting the Galactic Data Management System. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        futuristicPause(500); // Pause for a half-second for user experience
    }

    return 0;
}

// Function to add a Data Entity
void addDataEntity(DataEntity* entities, int* count) {
    if (*count >= MAX_SIZE) {
        printf("Cannot add more entities. Maximum size reached.\n");
        return;
    }

    DataEntity newEntity;
    newEntity.id = *count + 1; // Sequential ID generation
    printf("Enter name (up to 29 characters): ");
    scanf(" %[^\n]s", newEntity.name);
    printf("Enter value (floating point): ");
    scanf("%f", &newEntity.value);
    printf("Enter timestamp (in nanoseconds): ");
    scanf("%lf", &newEntity.timestamp);
    printf("Enter attributes (up to 49 characters): ");
    scanf(" %[^\n]s", newEntity.attributes);
    
    entities[*count] = newEntity;
    (*count)++;
    printf("Data Entity added successfully!\n");
}

// Function to display all Data Entities
void displayDataEntities(const DataEntity* entities, int count) {
    if (count == 0) {
        printf("No Data Entities to display.\n");
        return;
    }

    printf("\nDisplaying Data Entities:\n");
    printf("%-4s %-30s %-10s %-20s %-50s\n", "ID", "Name", "Value", "Timestamp", "Attributes");
    printf("------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-30s %-10.2f %-20.0lf %-50s\n", 
               entities[i].id, 
               entities[i].name, 
               entities[i].value, 
               entities[i].timestamp, 
               entities[i].attributes);
    }
}

// Function to sort Data Entities
void sortDataEntities(DataEntity* entities, int count) {
    if (count < 2) {
        printf("Not enough entities to sort.\n");
        return;
    }

    qsort(entities, count, sizeof(DataEntity), compareEntities);
    printf("Data Entities sorted by value successfully!\n");
}

// Comparison function for sorting
int compareEntities(const void* a, const void* b) {
    DataEntity* entityA = (DataEntity*) a;
    DataEntity* entityB = (DataEntity*) b;
    return (entityA->value < entityB->value) ? -1 : (entityA->value > entityB->value);
}

// Function to simulate futuristic pause
void futuristicPause(int milliseconds) {
    long pauseTime = milliseconds * 1000L; // Convert to microseconds
    usleep(pauseTime); // Use usleep for microsecond-level sleep
}