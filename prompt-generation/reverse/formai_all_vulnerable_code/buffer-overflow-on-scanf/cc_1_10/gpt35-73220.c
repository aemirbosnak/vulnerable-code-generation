//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing medicine details
typedef struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
}Medicine;

// Function to print menu
void printMenu() {
    printf("1. Add Medicine\n");
    printf("2. Remove Medicine\n");
    printf("3. Display Stock\n");
    printf("4. Sell Medicine\n");
    printf("5. Exit\n");
}

int main() {
    // Array to store medicine details
    Medicine stock[50];
    int count = 0;
    int choice;

    do {
        // Print menu and get choice from user
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch(choice) {
            case 1:
                printf("Enter medicine id: ");
                scanf("%d", &stock[count].id);
                printf("Enter medicine name: ");
                getchar();
                fgets(stock[count].name, 50, stdin);
                printf("Enter medicine price: ");
                scanf("%f", &stock[count].price);
                printf("Enter medicine quantity: ");
                scanf("%d", &stock[count].quantity);
                count++;
                printf("Medicine added to stock.\n");
                break;
            case 2:
                printf("Enter medicine id to remove: ");
                int idToRemove;
                scanf("%d", &idToRemove);
                int found = 0;
                for(int i=0; i<count; i++) {
                    if(stock[i].id == idToRemove) {
                        for(int j=i; j<count-1; j++) {
                            stock[j] = stock[j+1];
                        }
                        count--;
                        found = 1;
                        break;
                    }
                }
                if(found) {
                    printf("Medicine removed from stock.\n");
                } else {
                    printf("Medicine not found.\n");
                }
                break;
            case 3:
                printf("Medicine ID \t Medicine Name \t Price \t Quantity\n");
                for(int i=0; i<count; i++) {
                    printf("%d \t\t %s \t %.2f \t %d\n", stock[i].id, stock[i].name, stock[i].price, stock[i].quantity);
                }
                break;
            case 4:
                printf("Enter medicine id to sell: ");
                int idToSell;
                scanf("%d", &idToSell);
                found = 0;
                for(int i=0; i<count; i++) {
                    if(stock[i].id == idToSell) {
                        int numSold;
                        printf("Enter quantity sold: ");
                        scanf("%d", &numSold);
                        if(numSold > stock[i].quantity) {
                            printf("Insufficient stock.\n");
                        } else {
                            stock[i].quantity -= numSold;
                            printf("Total sale amount: %.2f\n", numSold * stock[i].price);
                        }
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Medicine not found.\n");
                }
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}