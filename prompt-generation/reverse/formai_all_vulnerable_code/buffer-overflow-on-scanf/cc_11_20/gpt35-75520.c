//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Medical Store Management System

struct Medicine {
    char name[50];
    int cost;
    int quantity;
};

int main() {
    struct Medicine stock[100];
    int num_of_meds = 0;
    int choice = 0, med_index = -1, med_cost = 0, total_sales = 0, sales_quantity = 0;
    char med_name[50];
    printf("Welcome to the Medical Store Management System. What would you like to do?\n");

    while (choice != 5) {
        printf("1. Add medicine to stock\n2. Sell medicine\n3. View stock\n4. View sales report\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nEnter name of medicine: ");
                scanf("%s", stock[num_of_meds].name);
                printf("Enter cost of medicine: ");
                scanf("%d", &stock[num_of_meds].cost);
                printf("Enter quantity of medicine: ");
                scanf("%d", &stock[num_of_meds].quantity);
                printf("\nMedicine added to stock.\n");
                num_of_meds++;
                break;
            case 2:
                printf("\nEnter name of medicine: ");
                scanf("%s", med_name);

                for (int i = 0; i < num_of_meds; i++) {
                    if (strcmp(med_name, stock[i].name) == 0) {
                        med_index = i;
                        break;
                    }
                }

                if (med_index == -1) {
                    printf("Medicine not found in stock.\n");
                }
                else {
                    printf("Enter quantity of medicine to sell: ");
                    scanf("%d", &sales_quantity);
                    if (sales_quantity > stock[med_index].quantity) {
                        printf("Required quantity not available in stock.\n");
                    }
                    else {
                        med_cost = stock[med_index].cost * sales_quantity;
                        stock[med_index].quantity -= sales_quantity;
                        total_sales += med_cost;
                        printf("Sold %d units of %s for Rs. %d.\n", sales_quantity, med_name, med_cost);
                    }
                }
                break;
            case 3:
                printf("\n%-30s%-15s%-15s\n", "Name", "Cost", "Quantity");
                for (int i = 0; i < num_of_meds; i++) {
                    printf("%-30s%-15d%-15d\n", stock[i].name, stock[i].cost, stock[i].quantity);
                }
                break;
            case 4:
                printf("\n%-30s%-15s\n", "Name", "Cost");
                for (int i = 0; i < num_of_meds; i++) {
                    printf("%-30s%-15d\n", stock[i].name, stock[i].cost);
                }
                printf("\nTotal sales: Rs. %d\n", total_sales);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}