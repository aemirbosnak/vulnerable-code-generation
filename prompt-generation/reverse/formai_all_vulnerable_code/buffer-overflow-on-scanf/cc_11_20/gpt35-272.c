//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

int main()
{
    int choice, num_meds, index, i, j;
    float total_cost = 0;
    char search_name[50];
    Medicine *med_list;

    printf("Welcome to the Medical Store Management System!\n");
    printf("How many medicines do you want to manage? ");
    scanf("%d", &num_meds);

    // Allocate memory for the medicine list
    med_list = (Medicine*) malloc(sizeof(Medicine) * num_meds);

    // Get the medicine details from the user
    for(i = 0; i < num_meds; i++) {
        printf("\nMedicine %d:\n", i+1);
        printf("Name: ");
        scanf("%s", med_list[i].name);
        printf("Quantity: ");
        scanf("%d", &med_list[i].quantity);
        printf("Price: ");
        scanf("%f", &med_list[i].price);
    }

    // Main menu
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Search for a medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Add a new medicine\n");
        printf("4. Remove a medicine\n");
        printf("5. Check total cost of medicines\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Search for a medicine
                printf("\nEnter the name of the medicine: ");
                scanf("%s", search_name);

                for(i = 0; i < num_meds; i++) {
                    if(strcmp(search_name, med_list[i].name) == 0) {
                        printf("\nMedicine found!\n");
                        printf("Name: %s\n", med_list[i].name);
                        printf("Quantity: %d\n", med_list[i].quantity);
                        printf("Price: %.2f\n", med_list[i].price);
                        break;
                    }
                }

                if(i == num_meds) {
                    printf("\nMedicine not found!\n");
                }

                break;

            case 2:
                // Display all medicines
                printf("\nMedicine list:\n");

                for(i = 0; i < num_meds; i++) {
                    printf("%d. %s (%d) - %.2f\n", i+1, med_list[i].name, med_list[i].quantity, med_list[i].price);
                }

                break;

            case 3:
                // Add a new medicine
                printf("\nEnter the details of the new medicine:\n");
                printf("Name: ");
                scanf("%s", med_list[num_meds].name);
                printf("Quantity: ");
                scanf("%d", &med_list[num_meds].quantity);
                printf("Price: ");
                scanf("%f", &med_list[num_meds].price);
                num_meds++;

                break;

            case 4:
                // Remove a medicine
                printf("\nEnter the index of the medicine to remove: ");
                scanf("%d", &index);

                if(index < 1 || index > num_meds) {
                    printf("\nInvalid index!\n");
                } else {
                    for(i = index-1; i < num_meds-1; i++) {
                        med_list[i] = med_list[i+1];
                    }
                    num_meds--;
                }

                break;

            case 5:
                // Check total cost of medicines
                total_cost = 0;

                for(i = 0; i < num_meds; i++) {
                    total_cost += med_list[i].quantity * med_list[i].price;
                }

                printf("\nTotal cost of medicines: %.2f\n", total_cost);

                break;

            case 6:
                // Exit program
                printf("\nThank you for using the Medical Store Management System!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }

    } while(choice != 6);

    // Free memory for the medicine list
    free(med_list);

    return 0;
}