//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

/* Defining a Medicine struct to store the information about each medicine */
struct Medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
};

/* Function prototypes */
void addMedicine(struct Medicine medicines[], int *count);
void removeMedicine(struct Medicine medicines[], int *count);
void displayMedicines(struct Medicine medicines[], int count);

int main() {
    struct Medicine medicines[MAX_MEDICINES];  /* Array of Medicine structs to store all the medicines */
    int count = 0;  /* Total number of medicines */

    int choice;  /* Variable to store user's choice */

    do {
        printf("\n\n********** C Medical Store Management System **********\n\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Medicines\n");
        printf("4. Exit\n\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);  /* Call addMedicine function */
                break;
            case 2:
                removeMedicine(medicines, &count);  /* Call removeMedicine function */
                break;
            case 3:
                displayMedicines(medicines, count);  /* Call displayMedicines function */
                break;
            case 4:
                printf("\nThank you for using C Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice (1-4).\n");
        }
    } while (choice != 4);

    return 0;
}

/*
 * Function to add a medicine to the array of medicines
 */
void addMedicine(struct Medicine medicines[], int *count) {
    if (*count == MAX_MEDICINES) {  /* Check if the array is already full */
        printf("\nCannot add medicine - Maximum limit exceeded!\n");
    } else {
        printf("\nEnter the details of the medicine:\n");

        fflush(stdin);
        printf("Name: ");
        fgets(medicines[*count].name, 50, stdin);  /* Read medicine name from user */

        fflush(stdin);
        printf("Manufacturer: ");
        fgets(medicines[*count].manufacturer, 50, stdin);  /* Read medicine manufacturer from user */

        printf("Price: ");
        scanf("%f", &medicines[*count].price);  /* Read medicine price from user */

        printf("Quantity: ");
        scanf("%d", &medicines[*count].quantity);  /* Read medicine quantity from user */

        (*count)++;  /* Increase the count of medicines in the array */

        printf("\nMedicine added successfully!\n");
    }
}

/*
 * Function to remove a medicine from the array of medicines
 */
void removeMedicine(struct Medicine medicines[], int *count) {
    if (*count == 0) {  /* Check if the array is already empty */
        printf("\nCannot remove medicine - No medicine available!\n");
    } else {
        char name[50];
        int index = -1;
        fflush(stdin);
        printf("\nEnter the name of the medicine you want to remove: ");
        fgets(name, 50, stdin);  /* Read medicine name from user */

        /* Loop through the array and find the index of the medicine to be removed */
        for (int i = 0; i < *count; i++) {
            if (strcmp(medicines[i].name, name) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {  /* If the medicine name was not found in the array */
            printf("\nCannot remove medicine - Medicine not found!\n");
        } else {
            /* Shift all the medicines after the removed medicine to the left by 1 index */
            for (int i = index; i < (*count)-1; i++) {
                medicines[i] = medicines[i+1];
            }

            (*count)--;  /* Decrease the count of medicines in the array */

            printf("\nMedicine removed successfully!\n");
        }
    }
}

/*
 * Function to display the details of all medicines in the array
 */
void displayMedicines(struct Medicine medicines[], int count) {
    if (count == 0) {  /* Check if the array is empty */
        printf("\nNo medicine available!\n");
    } else {
        printf("\n%-20s%-20s%-10s%-10s\n", "Name", "Manufacturer", "Price", "Quantity");
        for (int i = 0; i < count; i++) {
            printf("%-20s%-20s%-10.2f%-10d\n", medicines[i].name, medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
        }
    }
}