//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for maintaining the medical records
struct medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

void addMedicine(struct medicine *med_list, int *size) {
    // Function to add new medicine to the list
    printf("Enter the name of the medicine: ");
    scanf("%s", med_list[*size].name);
    printf("Enter the manufacturer of the medicine: ");
    scanf("%s", med_list[*size].manufacturer);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &med_list[*size].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &med_list[*size].price);

    // Increase size of medicine list
    (*size)++;
}

void viewMedicine(struct medicine *med_list, int size) {
    // Function to view the medicine list
    printf("\nName\t\t\tManufacturer\t\tQuantity\tPrice\n");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0; i<size; i++) {
        printf("%-20s\t%-20s\t%-10d\t%.2f\n", med_list[i].name, med_list[i].manufacturer,
               med_list[i].quantity, med_list[i].price);
    }
}

void searchMedicine(struct medicine *med_list, int size) {
    // Function to search medicine in the list
    char query[50];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", query);

    printf("\nName\t\t\tManufacturer\t\tQuantity\tPrice\n");
    printf("--------------------------------------------------------------------------------\n");
    int found=0;
    for(int i=0; i<size; i++) {
        if(strcmp(query, med_list[i].name) == 0) {
            printf("%-20s\t%-20s\t%-10d\t%.2f\n", med_list[i].name, med_list[i].manufacturer,
               med_list[i].quantity, med_list[i].price);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Medicine not found!\n");
    }
}

int main() {
    printf("\n*********Welcome to Medical Store Management System*********\n");

    int size = 0; // Initialize size of medicine list
    struct medicine *med_list = malloc(10 * sizeof(struct medicine)); // Allocate memory for medicine list

    while(1) {
        printf("\n\nPlease select an option:\n");
        printf("1. Add medicine to the list\n");
        printf("2. View medicine list\n");
        printf("3. Search for medicine in the list\n");
        printf("4. Exit\n");

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                addMedicine(med_list, &size);
                break;
            case 2:
                viewMedicine(med_list, size);
                break;
            case 3:
                searchMedicine(med_list, size);
                break;
            case 4:
                printf("\nThank you for using Medical Store Management System!\n");
                free(med_list); // Free allocated memory
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }

    return 0;
}