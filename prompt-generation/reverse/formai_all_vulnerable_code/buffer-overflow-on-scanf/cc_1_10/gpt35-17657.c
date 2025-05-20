//FormAI DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold information about kingdoms
typedef struct {
    int kingdomId;
    char kingdomName[50];
    char rulerName[50];
    int armySize;
} Kingdom;

// Function to retrieve a specific kingdom record by ID
Kingdom findKingdomById(int id) {
    FILE *fp = fopen("kingdoms.txt", "r");
    Kingdom kingdom;
    while(fscanf(fp, "%d %s %s %d", &kingdom.kingdomId, kingdom.kingdomName, kingdom.rulerName, &kingdom.armySize) != EOF) {
        if (kingdom.kingdomId == id) {
            fclose(fp);
            return kingdom;
        }
    }
    fclose(fp);
    // If kingdom is not found, return an empty struct
    Kingdom emptyKingdom = {0, "", "", 0};
    return emptyKingdom;
}

// Function to print all kingdoms in the file
void printAllKingdoms() {
    FILE *fp = fopen("kingdoms.txt", "r");
    Kingdom kingdom;
    while(fscanf(fp, "%d %s %s %d", &kingdom.kingdomId, kingdom.kingdomName, kingdom.rulerName, &kingdom.armySize) != EOF) {
        printf("Kingdom ID: %d | Kingdom Name: %s | Ruler Name: %s | Army Size: %d\n", kingdom.kingdomId, kingdom.kingdomName, kingdom.rulerName, kingdom.armySize);
    }
    fclose(fp);
}

int main() {
    int choice, id;
    Kingdom kingdom;
    printf("Welcome to the Kingdom Database Querying Program.\n");
    printf("Please select an option:\n");
    printf("1. Find kingdom by ID.\n");
    printf("2. Print all kingdoms.\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter kingdom ID: ");
            scanf("%d", &id);
            kingdom = findKingdomById(id);
            if (kingdom.kingdomId == 0) {
                printf("Kingdom not found.\n");
            } else {
                printf("Kingdom ID: %d | Kingdom Name: %s | Ruler Name: %s | Army Size: %d\n", kingdom.kingdomId, kingdom.kingdomName, kingdom.rulerName, kingdom.armySize);
            }
            break;
        case 2:
            printAllKingdoms();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}