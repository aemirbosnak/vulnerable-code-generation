//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 100

typedef struct {
    char name[50];
    int id;
} bidder;

typedef struct {
    char name[50];
    int id;
    int price;
} item;

int main() {
    bidder bidders[MAX_BIDDERS];
    item items[MAX_ITEMS];
    int num_bidders = 0, num_items = 0;
    char choice;

    do {
        printf("\nWelcome to the Digital Auction System!\n");
        printf("Please choose an option:\n");
        printf("1. Register as a bidder\n");
        printf("2. Register an item for auction\n");
        printf("3. View registered bidders\n");
        printf("4. View registered items\n");
        printf("5. Start auction\n");
        printf("6. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_bidders >= MAX_BIDDERS) {
                    printf("Sorry, maximum number of bidders reached.\n");
                } else {
                    printf("Enter your name: ");
                    scanf("%s", bidders[num_bidders].name);
                    printf("Enter your ID: ");
                    scanf("%d", &bidders[num_bidders].id);
                    num_bidders++;
                }
                break;
            case '2':
                if (num_items >= MAX_ITEMS) {
                    printf("Sorry, maximum number of items reached.\n");
                } else {
                    printf("Enter the name of the item: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter your ID: ");
                    scanf("%d", &items[num_items].id);
                    printf("Enter the starting price: ");
                    scanf("%d", &items[num_items].price);
                    num_items++;
                }
                break;
            case '3':
                printf("Registered bidders:\n");
                for (int i = 0; i < num_bidders; i++) {
                    printf("%d. %s (%d)\n", i+1, bidders[i].name, bidders[i].id);
                }
                break;
            case '4':
                printf("Registered items:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%d. %s (%d)\n", i+1, items[i].name, items[i].id);
                }
                break;
            case '5':
                // Start auction code here
                break;
            case '6':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '6');

    return 0;
}