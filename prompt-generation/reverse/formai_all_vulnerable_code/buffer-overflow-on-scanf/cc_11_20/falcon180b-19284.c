//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
} Item;

int main() {
    int numItems = 0;
    Item items[MAX_ITEMS];
    char input[100];
    int i;

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    for (i = 0; i < numItems; i++) {
        printf("Enter name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter price of item %s: ", items[i].name);
        scanf("%d", &items[i].price);
    }

    while (1) {
        printf("Menu:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Edit item\n");
        printf("4. Print bill\n");
        printf("5. Exit\n");
        scanf("%s", input);

        switch (tolower(input[0])) {
            case '1':
                printf("Enter name of new item: ");
                scanf("%s", items[numItems].name);
                printf("Enter price of new item: ");
                scanf("%d", &items[numItems].price);
                numItems++;
                printf("Item added successfully.\n");
                break;

            case '2':
                printf("Enter name of item to remove: ");
                scanf("%s", input);
                for (i = 0; i < numItems; i++) {
                    if (strcmp(items[i].name, input) == 0) {
                        printf("Item removed successfully.\n");
                        numItems--;
                        break;
                    }
                }
                break;

            case '3':
                printf("Enter name of item to edit: ");
                scanf("%s", input);
                for (i = 0; i < numItems; i++) {
                    if (strcmp(items[i].name, input) == 0) {
                        printf("Enter new name of item: ");
                        scanf("%s", items[i].name);
                        printf("Enter new price of item: ");
                        scanf("%d", &items[i].price);
                        printf("Item edited successfully.\n");
                        break;
                    }
                }
                break;

            case '4':
                printf("Bill:\n");
                for (i = 0; i < numItems; i++) {
                    printf("%s - $%d\n", items[i].name, items[i].price);
                }
                break;

            case '5':
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}