//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    int stock[5] = {100, 50, 75, 25, 10};
    char* medicines[5] = {"Paracetamol", "Aspirin", "Ibuprofen", "Penicillin", "Antibiotics"};
    float price[5] = {1.5, 2.0, 2.5, 5.0, 10.0};

    printf("Welcome to the Medical Store Management System!\n\n");

    do {
        int i;
        printf("Please select an option:\n");
        printf("1. Display stock and prices\n");
        printf("2. Order medicine\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nCurrent stock and prices:\n");
                printf("---------------------------------------\n");
                printf("| %-15s | %-6s | %-8s |\n", "Medicine Name", "Price", "Stock");
                printf("---------------------------------------\n");
                for (i=0; i<5; i++) {
                    printf("| %-15s | $%-4.2f | %-5d    |\n", medicines[i], price[i], stock[i]);
                }
                printf("---------------------------------------\n");
                break;
            case 2:
                printf("\nPlease select the medicine you would like to order:\n");
                for (i=0; i<5; i++) {
                    printf("%d. %s\n", i+1, medicines[i]);
                }
                scanf("%d", &choice);
                if (choice >= 1 && choice <= 5) {
                    int quantity;
                    printf("\nHow many would you like to order?\n");
                    scanf("%d", &quantity);
                    if (quantity <= stock[choice-1]) {
                        printf("\nYou have ordered %d %s.\n", quantity, medicines[choice-1]);
                        printf("Total cost: $%.2f\n\n", price[choice-1]*quantity);
                        stock[choice-1] -= quantity;
                    } else {
                        printf("\nSorry, we only have %d %s in stock.\n\n", stock[choice-1], medicines[choice-1]);
                    }
                } else {
                    printf("\nInvalid choice. Please try again.\n\n");
                }
                break;
            case 3:
                printf("\nThank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}