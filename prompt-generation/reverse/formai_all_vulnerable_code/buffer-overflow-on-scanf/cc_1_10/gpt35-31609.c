//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[30];
    char brand[30];
    float price;
    int quantity;
};

void addMedicine(struct medicine med[], int *numMeds);
void updateMedicine(struct medicine med[], int numMeds);
void deleteMedicine(struct medicine med[], int *numMeds);
void searchMedicine(struct medicine med[], int numMeds);
void displayMedicine(struct medicine med[], int numMeds);

int main() {
    struct medicine med[100];
    int numMeds = 0;
    int choice;
    
    do {
        printf("\n\n---------MEDICAL STORE MANAGEMENT SYSTEM---------\n");
        printf("\n\n1. Add new medicine\n");
        printf("2. Update medicine information\n");
        printf("3. Delete medicine\n");
        printf("4. Search medicine\n");
        printf("5. Display all medicines\n");
        printf("6. Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMedicine(med, &numMeds);
                break;
            case 2:
                updateMedicine(med, numMeds);
                break;
            case 3:
                deleteMedicine(med, &numMeds);
                break;
            case 4:
                searchMedicine(med, numMeds);
                break;
            case 5:
                displayMedicine(med, numMeds);
                break;
            case 6:
                printf("\nExiting Medical Store Management System...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while(1);
    return 0;
}

void addMedicine(struct medicine med[], int *numMeds) {
    printf("\n-------ADD NEW MEDICINE-------");
    printf("\nName: ");
    scanf("%s", med[*numMeds].name);
    printf("Brand: ");
    scanf("%s", med[*numMeds].brand);
    printf("Price: ");
    scanf("%f", &med[*numMeds].price);
    printf("Quantity: ");
    scanf("%d", &med[*numMeds].quantity);
    (*numMeds)++;
    printf("\nMedicine added successfully!");
}

void updateMedicine(struct medicine med[], int numMeds) {
    char name[30];
    int found = 0;
    printf("\n----------UPDATE MEDICINE INFORMATION----------");
    printf("\nEnter name of medicine to update: ");
    scanf("%s", name);
    for(int i = 0; i < numMeds; i++) {
        if(strcmp(name, med[i].name) == 0) {
            printf("\nName: %s", med[i].name);
            printf("\nBrand: %s", med[i].brand);
            printf("\nPrice: %f", med[i].price);
            printf("\nQuantity: %d", med[i].quantity);
            printf("\nEnter new details of medicine: \n");
            printf("Name: ");
            scanf("%s", med[i].name);
            printf("Brand: ");
            scanf("%s", med[i].brand);
            printf("Price: ");
            scanf("%f", &med[i].price);
            printf("Quantity: ");
            scanf("%d", &med[i].quantity);
            found = 1;
            printf("\nMedicine information updated successfully!");
            break;
        }
    }
    if(found == 0)
        printf("\nMedicine not found!");
}

void deleteMedicine(struct medicine med[], int *numMeds) {
    char name[30];
    int i, j;
    printf("\n-----------DELETE MEDICINE-----------");
    printf("\nEnter name of medicine to delete: ");
    scanf("%s", name);
    for(i = 0; i < (*numMeds); i++) {
        if(strcmp(name, med[i].name) == 0) {
            for(j = i; j < (*numMeds) - 1; j++) {
                med[j] = med[j + 1];
            }
            (*numMeds)--;
            printf("\nMedicine deleted successfully!");
            break;
        }
    }
    if(i == (*numMeds))
        printf("\nMedicine not found!");
}

void searchMedicine(struct medicine med[], int numMeds) {
    char name[30];
    int found = 0;
    printf("\n------------SEARCH MEDICINE------------");
    printf("\nEnter name of medicine to search: ");
    scanf("%s", name);
    for(int i = 0; i < numMeds; i++) {
        if(strcmp(name, med[i].name) == 0) {
            printf("\nName: %s", med[i].name);
            printf("\nBrand: %s", med[i].brand);
            printf("\nPrice: %f", med[i].price);
            printf("\nQuantity: %d", med[i].quantity);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("\nMedicine not found!");
}

void displayMedicine(struct medicine med[], int numMeds) {
    printf("\n---------------------ALL MEDICINES---------------------\n");
    printf("Name\t\tBrand\t\tPrice\t\tQuantity\n");
    for(int i = 0; i < numMeds; i++) {
        printf("%s\t\t%s\t\t%f\t\t%d\n", med[i].name, med[i].brand, med[i].price, med[i].quantity);
    }
}