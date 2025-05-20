//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHELTERS 10
#define MAX_SUPPLIES 5

typedef struct {
    char name[50];
    int quantity;
} Supply;

typedef struct {
    char name[50];
    int capacity;
    Supply *supplies;
} Shelter;

void initializeShelter(Shelter *shelter, const char *name, int capacity) {
    strncpy(shelter->name, name, sizeof(shelter->name) - 1);
    shelter->name[sizeof(shelter->name) - 1] = '\0';
    shelter->capacity = capacity;
    shelter->supplies = (Supply *)malloc(MAX_SUPPLIES * sizeof(Supply));
    if (shelter->supplies == NULL) {
        perror("Failed to allocate supplies");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < MAX_SUPPLIES; i++) {
        shelter->supplies[i].quantity = 0;
    }
}

void cleanupShelter(Shelter *shelter) {
    free(shelter->supplies);
    shelter->supplies = NULL;
}

void addSupply(Shelter *shelter, const char *name, int quantity) {
    for (int i = 0; i < MAX_SUPPLIES; i++) {
        if (shelter->supplies[i].quantity == 0) {
            strncpy(shelter->supplies[i].name, name, sizeof(shelter->supplies[i].name) - 1);
            shelter->supplies[i].name[sizeof(shelter->supplies[i].name) - 1] = '\0';
            shelter->supplies[i].quantity = quantity;
            printf("Added %d of %s to shelter %s.\n", quantity, name, shelter->name);
            return;
        }
    }
    printf("No more room in shelter %s for supplies.\n", shelter->name);
}

void showSupplies(Shelter *shelter) {
    printf("Supplies in shelter %s:\n", shelter->name);
    for (int i = 0; i < MAX_SUPPLIES; i++) {
        if (shelter->supplies[i].quantity > 0) {
            printf("- %s: %d\n", shelter->supplies[i].name, shelter->supplies[i].quantity);
        }
    }
}

void manageSurvivors(int survivorCount) {
    printf("Managing %d survivors in the wasteland.\n", survivorCount);
}

int main() {
    printf("Welcome to the Post-Apocalyptic Shelter Management System.\n");
    
    Shelter *shelters[MAX_SHELTERS];
    int totalShelters = 0;

    while (totalShelters < MAX_SHELTERS) {
        shelters[totalShelters] = (Shelter *)malloc(sizeof(Shelter));
        if (shelters[totalShelters] == NULL) {
            perror("Failed to allocate shelter");
            exit(EXIT_FAILURE);
        }
        
        char name[50];
        int capacity;
        printf("Enter name for shelter %d: ", totalShelters + 1);
        scanf("%s", name);
        printf("Enter capacity for shelter %d: ", totalShelters + 1);
        scanf("%d", &capacity);
        
        initializeShelter(shelters[totalShelters], name, capacity);
        totalShelters++;

        char addMore;
        printf("Do you want to add another shelter? (y/n): ");
        scanf(" %c", &addMore);
        if (addMore != 'y') break;
    }

    for (int i = 0; i < totalShelters; i++) {
        showSupplies(shelters[i]);
        char supplyName[50];
        int supplyQuantity;

        printf("Add a supply to shelter %s. What's the name? ", shelters[i]->name);
        scanf("%s", supplyName);
        printf("How many of %s? ", supplyName);
        scanf("%d", &supplyQuantity);

        addSupply(shelters[i], supplyName, supplyQuantity);
    }

    for (int i = 0; i < totalShelters; i++) {
        showSupplies(shelters[i]);
        cleanupShelter(shelters[i]);
        free(shelters[i]);
    }

    manageSurvivors(100); // Example: managing 100 survivors.

    return 0;
}