//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    float price;
    int quantity;
    char expiry[20];
};

void addMedicine(struct medicine [], int *);
void viewMedicine(struct medicine [], int);
void searchMedicine(struct medicine [], int);
void updateMedicine(struct medicine [], int);
void deleteMedicine(struct medicine [], int *);

int main() {
    struct medicine med[100];
    int numMeds = 0;
    int choice = 0;

    while (choice != 6) {
        printf("\n\nMEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("--------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. View All Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMedicine(med, &numMeds); break;
            case 2: viewMedicine(med, numMeds); break;
            case 3: searchMedicine(med, numMeds); break;
            case 4: updateMedicine(med, numMeds); break;
            case 5: deleteMedicine(med, &numMeds); break;
            case 6: exit(0); break;
            default: printf("\nInvalid Choice! Please Try Again.\n");
        }
    }

    return 0;
}

/* Adds medicine to the inventory */
void addMedicine(struct medicine med[], int *numMeds) {
    printf("\n\nADD MEDICINE\n");
    printf("-------------\n");
    printf("Enter Name: ");
    fflush(stdin);
    gets(med[*numMeds].name);

    printf("Enter Price: ");
    scanf("%f", &med[*numMeds].price);

    printf("Enter Quantity: ");
    scanf("%d", &med[*numMeds].quantity);

    printf("Enter Expiry Date: ");
    fflush(stdin);
    gets(med[*numMeds].expiry);

    (*numMeds)++;

    printf("\nMedicine Added Successfully!\n");
}

/* Displays all medicine in the inventory */
void viewMedicine(struct medicine med[], int numMeds) {
    printf("\n\nVIEW ALL MEDICINE\n");
    printf("------------------\n");

    if (numMeds == 0) {
        printf("\nNo Medicine Found!\n");
        return;
    }

    printf("%-20s%-20s%-20s%s\n", "Name", "Price", "Quantity", "Expiry");

    for (int i = 0; i < numMeds; i++) {
        printf("%-20s%-20.2f%-20d%s\n", med[i].name, med[i].price, med[i].quantity, med[i].expiry);
    }
}

/* Searches for medicine in the inventory */
void searchMedicine(struct medicine med[], int numMeds) {
    printf("\n\nSEARCH MEDICINE\n");
    printf("-----------------\n");

    if (numMeds == 0) {
        printf("\nNo Medicine Found!\n");
        return;
    }

    char searchName[50];
    int found = 0;

    printf("Enter Name to Search: ");
    fflush(stdin);
    gets(searchName);

    for (int i = 0; i < numMeds; i++) {
        if (strcmp(med[i].name, searchName) == 0) {
            printf("%-20s%-20s%-20s%s\n", "Name", "Price", "Quantity", "Expiry");
            printf("%-20s%-20.2f%-20d%s\n", med[i].name, med[i].price, med[i].quantity, med[i].expiry);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine Not Found!\n");
    }
}

/* Updates medicine in the inventory */
void updateMedicine(struct medicine med[], int numMeds) {
    printf("\n\nUPDATE MEDICINE\n");
    printf("-----------------\n");

    if (numMeds == 0) {
        printf("\nNo Medicine Found!\n");
        return;
    }

    char searchName[50];
    int found = 0;

    printf("Enter Name to Update: ");
    fflush(stdin);
    gets(searchName);

    for (int i = 0; i < numMeds; i++) {
        if (strcmp(med[i].name, searchName) == 0) {
            printf("Enter New Price: ");
            scanf("%f", &med[i].price);

            printf("Enter New Quantity: ");
            scanf("%d", &med[i].quantity);

            printf("Enter New Expiry Date: ");
            fflush(stdin);
            gets(med[i].expiry);

            printf("\nMedicine Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine Not Found!\n");
    }
}

/* Deletes medicine from the inventory */
void deleteMedicine(struct medicine med[], int *numMeds) {
    printf("\n\nDELETE MEDICINE\n");
    printf("-----------------\n");

    if (*numMeds == 0) {
        printf("\nNo Medicine Found!\n");
        return;
    }

    char searchName[50];
    int found = 0;

    printf("Enter Name to Delete: ");
    fflush(stdin);
    gets(searchName);

    for (int i = 0; i < *numMeds; i++) {
        if (strcmp(med[i].name, searchName) == 0) {
            for (int j = i; j < *numMeds - 1; j++) {
                strcpy(med[j].name, med[j + 1].name);
                med[j].price = med[j + 1].price;
                med[j].quantity = med[j + 1].quantity;
                strcpy(med[j].expiry, med[j + 1].expiry);
            }

            (*numMeds)--;
            printf("\nMedicine Deleted Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine Not Found!\n");
    }
}