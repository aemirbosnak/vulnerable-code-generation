//FormAI DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct bankRecord {
    char name[50];
    int accountNumber;
    float balance;
};

int main() {
    printf("Welcome to the dreamscape banking record system!\n");

    struct bankRecord customers[100];
    int option, customerCount = 0;

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a new customer\n");
        printf("2. View customer information\n");
        printf("3. Edit customer information\n");
        printf("4. Delete customer information\n");
        printf("5. Exit dreamscape banking record system\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                // surreal input prompt
                printf("\nWhat is the customer's dream name?\n");
                scanf("%s", customers[customerCount].name);

                printf("\nWhat is the customer's dream account number?\n");
                scanf("%d", &customers[customerCount].accountNumber);

                printf("\nWhat is the customer's dream balance?\n");
                scanf("%f", &customers[customerCount].balance);

                // confirmation message
                printf("\nCongratulations! A new customer has been added to the dreamscape banking record system.\n");

                customerCount++;
                break;

            case 2:
                // surreal output message
                printf("\nWhose dreamscape would you like to view?\n");

                char viewName[50];
                scanf("%s", viewName);

                // surreal search process
                int i;
                for (i = 0; i < customerCount; i++) {
                    if (strcmp(customers[i].name, viewName) == 0) {
                        printf("\nHere are the dream details of %s:\n", customers[i].name);
                        printf("Dream account number: %d\n", customers[i].accountNumber);
                        printf("Dream balance: %.2f\n", customers[i].balance);
                        break;
                    }
                }

                if (i == customerCount) {
                    // surreal error message
                    printf("\nWe're sorry, but that dream is not currently in our banking records.\n");
                }
                break;

            case 3:
                // surreal input prompt
                printf("\nWhose dream details would you like to edit?\n");

                char editName[50];
                scanf("%s", editName);

                // surreal search process
                int j;
                for (j = 0; j < customerCount; j++) {
                    if (strcmp(customers[j].name, editName) == 0) {
                        printf("\nWhat is the dream account number?\n");
                        scanf("%d", &customers[j].accountNumber);

                        printf("\nWhat is the dream balance?\n");
                        scanf("%f", &customers[j].balance);

                        // confirmation message
                        printf("\nCongratulations! The dream details of %s have been updated.\n", customers[j].name);
                        break;
                    }
                }

                if (j == customerCount) {
                    // surreal error message
                    printf("\nWe're sorry, but that dream is not currently in our banking records.\n");
                }
                break;

            case 4:
                // surreal input prompt
                printf("\nWhose dream details would you like to delete?\n");

                char deleteName[50];
                scanf("%s", deleteName);

                // surreal search process
                int k;
                for (k = 0; k < customerCount; k++) {
                    if (strcmp(customers[k].name, deleteName) == 0) {
                        int l;
                        for (l = k; l < customerCount - 1; l++) {
                            customers[l] = customers[l+1];
                        }

                        // confirmation message
                        printf("\nCongratulations! The dream details of %s have been deleted.\n", deleteName);

                        customerCount--;
                        break;
                    }
                }

                if (k == customerCount) {
                    // surreal error message
                    printf("\nWe're sorry, but that dream is not currently in our banking records.\n");
                }
                break;

            case 5:
                // surreal exit message
                printf("\nThank you for visiting the dreamscape banking record system. Sweet dreams!\n");
                break;

            default:
                // surreal error message
                printf("\nWe're sorry, but that is not a valid option. Please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}