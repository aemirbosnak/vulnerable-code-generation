//FormAI DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Item {
    char name[20];
    int quantity;
    double price;
};

void displayItem(struct Item item) {
    printf("Name: %s\n", item.name);
    printf("Quantity: %d\n", item.quantity);
    printf("Price: $%.2f\n", item.price);
}

int main() {
    int choice;
    int numItems = 0, i;

    struct Item *items = NULL;

    printf("Welcome to the post-apocalyptic store!\n");

    while(1) {
        printf("\n-----------------------------------------\n");
        printf("Enter 1 to add item.\n");
        printf("Enter 2 to display all items.\n");
        printf("Enter 3 to search item by name.\n");
        printf("Enter 4 to exit.\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                numItems++;
                items = (struct Item*) realloc(items, numItems * sizeof(struct Item));

                printf("Enter item name: ");
                scanf("%s", items[numItems-1].name);

                printf("Enter quantity: ");
                scanf("%d", &items[numItems-1].quantity);

                printf("Enter price: ");
                scanf("%lf", &items[numItems-1].price);

                printf("Item added successfully!\n");
                break;
            }
            case 2: {
                if(numItems == 0)
                    printf("No items to display!\n");
                else {
                    printf("Items:\n");
                    printf("=========================================\n");
                    for(i=0; i<numItems; i++) {
                        displayItem(items[i]);
                        printf("-----------------------------------------\n");
                    }
                }
                break;
            }
            case 3: {
                if(numItems == 0)
                    printf("No items to search for!\n");
                else {
                    char name[20];
                    int found = 0;

                    printf("Enter item name to search: ");
                    scanf("%s", name);

                    for(i=0; i<numItems; i++) {
                        if(strcmp(name, items[i].name) == 0) {
                            printf("=========================================\n");
                            displayItem(items[i]);
                            found = 1;
                            break;
                        }
                    }

                    if(!found)
                        printf("Item not found!\n");
                }
                break;
            }
            case 4: {
                printf("Thank you for shopping with us! Goodbye!\n");
                exit(0);
                break;
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    }

    return 0;
}