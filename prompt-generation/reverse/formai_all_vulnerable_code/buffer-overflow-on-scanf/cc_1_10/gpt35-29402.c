//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void addMedicine();
void searchMedicine();
void deleteMedicine();
void viewMedicine();
void displayMenu();

// global variables
struct medicine {
    char name[50];
    int quantity;
    float price;
} m[100];

int n;

int main() {
    int choice;

    do {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                searchMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                viewMedicine();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n");
    printf("***********************************\n");
    printf("* C MEDICAL STORE MANAGEMENT MENU *\n");
    printf("***********************************\n");
    printf("* 1. Add Medicine                  *\n");
    printf("* 2. Search Medicine               *\n");
    printf("* 3. Delete Medicine               *\n");
    printf("* 4. View Medicine Inventory       *\n");
    printf("* 5. Exit Program                  *\n");
    printf("***********************************\n");
}

void addMedicine() {
    printf("\n");
    printf("***************\n");
    printf("* ADD MEDICINE *\n");
    printf("***************\n");

    printf("Enter name of medicine: ");
    scanf("%s", m[n].name);

    printf("Enter quantity of medicine: ");
    scanf("%d", &m[n].quantity);

    printf("Enter price of medicine: ");
    scanf("%f", &m[n].price);

    n++; // increment the number of medicines in the inventory

    printf("Medicine added successfully.\n");
}

void searchMedicine() {
    char name[50];
    int i, flag = 0;

    printf("\n");
    printf("*****************\n");
    printf("* SEARCH MEDICINE *\n");
    printf("*****************\n");

    printf("Enter name of medicine to search for: ");
    scanf("%s", name);

    for (i = 0; i < n; i++) {
        if (strcmp(name, m[i].name) == 0) {
            printf("Medicine found.\n");
            printf("Name: %s \n", m[i].name);
            printf("Quantity: %d \n", m[i].quantity);
            printf("Price: $%.2f \n", m[i].price);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Medicine not found.\n");
    }
}

void deleteMedicine() {
    char name[50];
    int i, j, flag = 0;

    printf("\n");
    printf("*****************\n");
    printf("* DELETE MEDICINE *\n");
    printf("*****************\n");

    printf("Enter name of medicine to delete: ");
    scanf("%s", name);

    for (i = 0; i < n; i++) {
        if (strcmp(name, m[i].name) == 0) {
            for (j = i; j < n - 1; j++) {
                strcpy(m[j].name, m[j + 1].name);
                m[j].quantity = m[j + 1].quantity;
                m[j].price = m[j + 1].price;
            }
            n--; // decrement the number of medicines in the inventory
            printf("Medicine deleted successfully.\n");
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Medicine not found.\n");
    }
}

void viewMedicine() {
    int i;

    printf("\n");
    printf("***************************\n");
    printf("* VIEW MEDICINE INVENTORY *\n");
    printf("***************************\n");

    if (n == 0) {
        printf("No medicine in inventory.\n");
    } else {
        printf("Medicine Name      Quantity      Price\n");
        for (i = 0; i < n; i++) {
            printf("%-20s %-14d $%0.2f\n", m[i].name, m[i].quantity, m[i].price);
        }
    }
}