//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

struct Med {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    int price;
};

struct MedStore {
    struct Med inventory[MAX_MEDS];
    int numMeds;
};

void addMed(struct MedStore *store) {
    if(store->numMeds == MAX_MEDS) {
        printf("Error: Maximum number of medications reached\n");
        return;
    }
    struct Med *newMed = &store->inventory[store->numMeds];
    printf("\nEnter medication name: ");
    fflush(stdout);
    scanf("%s", newMed->name);
    printf("Enter medication description: ");
    fflush(stdout);
    scanf("%s", newMed->description);
    printf("Enter medication quantity: ");
    fflush(stdout);
    scanf("%d", &newMed->quantity);
    printf("Enter medication price: ");
    fflush(stdout);
    scanf("%d", &newMed->price);
    store->numMeds++;
    printf("\nNew medication successfully added!\n");
}

void removeMed(struct MedStore *store) {
    char medName[MAX_NAME_LENGTH];
    printf("\nEnter medication name: ");
    fflush(stdout);
    scanf("%s", medName);
    for(int i=0; i<store->numMeds; i++) {
        if(strcmp(store->inventory[i].name, medName) == 0) {
            printf("Removing %s from inventory", medName);
            for(int j=i; j<store->numMeds-1; j++) {
                store->inventory[j] = store->inventory[j+1];
            }
            store->numMeds--;
            printf("\n%s successfully removed from inventory\n", medName);
            return;
        }
    }
    printf("Error: Medication not found in inventory\n");
}

void displayInventory(struct MedStore *store) {
    printf("\nCurrent Medication inventory:\n");
    for(int i=0; i<store->numMeds; i++) {
        struct Med *med = &store->inventory[i];
        printf("Name: %s\nDescription: %s\nQuantity: %d\nPrice: %d\n\n", med->name, med->description, med->quantity, med->price);
    }
}

int main() {
    struct MedStore store = {0};
    while(1) {
        printf("\n\n1. Add new medication to inventory\n");
        printf("2. Remove a medication from inventory\n");
        printf("3. Display current inventory\n");
        printf("4. Exit program\n\n");
        printf("Enter your choice: ");
        fflush(stdout);
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMed(&store);
                break;
            case 2:
                removeMed(&store);
                break;
            case 3:
                displayInventory(&store);
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please select an option 1-4\n");
        }
    }
    return 0;
}