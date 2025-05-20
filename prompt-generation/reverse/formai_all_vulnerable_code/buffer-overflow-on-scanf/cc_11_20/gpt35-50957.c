//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    float price;
    int quantity;
};

int main() {
    int choice, i, n, found = 0;
    char search[50];
    struct medicine *meds;

    printf("Enter the number of medicines: ");
    scanf("%d", &n);

    meds = (struct medicine*) malloc(n * sizeof(struct medicine)); // Dynamic allocation of memory

    for(i = 0; i < n; i++) {
        printf("\nEnter details of medicine %d:", i+1);

        // Input details of each medicine
        printf("\nName: ");
        scanf("%s", (meds+i)->name);

        printf("Price: ");
        scanf("%f", &(meds+i)->price);

        printf("Quantity: ");
        scanf("%d", &(meds+i)->quantity);
    }

    do {
        printf("\n*** MEDICAL STORE MANAGEMENT SYSTEM MENU ***\n");
        printf("1. Display medicines\n");
        printf("2. Add new medicine\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine\n");
        printf("5. Delete medicine\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Display all medicines
                printf("\nMEDICINES:\n");
                printf("---------------------------------------------------------------------------------\n");
                printf("Name\t\tPrice\t\tQuantity\n");
                printf("---------------------------------------------------------------------------------\n");
                for(i = 0; i < n; i++) {
                    printf("%s\t\t%.2f\t\t%d\n", (meds+i)->name, (meds+i)->price, (meds+i)->quantity);
                }
                printf("---------------------------------------------------------------------------------\n");
                break;

            case 2: // Add new medicine
                n++;
                meds = (struct medicine*) realloc(meds, n * sizeof(struct medicine)); // Reallocate memory to accommodate new medicine
                printf("\nEnter details of new medicine %d:", n);
                printf("\nName: ");
                scanf("%s", (meds+n-1)->name);

                printf("Price: ");
                scanf("%f", &(meds+n-1)->price);

                printf("Quantity: ");
                scanf("%d", &(meds+n-1)->quantity);
                break;

            case 3: // Search for a medicine
                printf("\nEnter name of the medicine you want to search: ");
                scanf("%s", search);
                found = 0; // Reset found flag
                for(i = 0; i < n; i++) {
                    if(strcmp((meds+i)->name, search) == 0) { // Match found
                        printf("\nName\t\tPrice\t\tQuantity\n");
                        printf("------------------------------------------------\n");
                        printf("%s\t\t%.2f\t\t%d\n", (meds+i)->name, (meds+i)->price, (meds+i)->quantity);
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("\n%s not found!\n", search);
                }
                break;

            case 4: // Update a medicine
                printf("\nEnter name of the medicine you want to update: ");
                scanf("%s", search);
                found = 0; // Reset found flag
                for(i = 0; i < n; i++) {
                    if(strcmp((meds+i)->name, search) == 0) { // Match found
                        printf("\nEnter new details of medicine %d:", i+1);

                        printf("\nName: ");
                        scanf("%s", (meds+i)->name);

                        printf("Price: ");
                        scanf("%f", &(meds+i)->price);

                        printf("Quantity: ");
                        scanf("%d", &(meds+i)->quantity);
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("\n%s not found!\n", search);
                }
                break;

            case 5: // Delete a medicine
                printf("\nEnter name of the medicine you want to delete: ");
                scanf("%s", search);
                found = 0; // Reset found flag
                for(i = 0; i < n; i++) {
                    if(strcmp((meds+i)->name, search) == 0) { // Match found
                        for(int j = i; j < n-1; j++) {
                            *(meds+j) = *(meds+j+1); // Shift all medicines one position left from found medicine
                        }
                        n--; // Reduce number of medicines
                        meds = (struct medicine*) realloc(meds, n * sizeof(struct medicine)); // Reallocate memory to remove deleted medicine
                        printf("\n%s deleted successfully!\n", search);
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("\n%s not found!\n", search);
                }
                break;

            case 6: // Exit program
                printf("\nExiting program...");
                break;

            default: // Invalid choice
                printf("\nInvalid choice! Please enter a valid choice from the menu.\n");
                break;
        }

    }while(choice != 6);

    free(meds); // Release the dynamically allocated memory

    return 0;
}