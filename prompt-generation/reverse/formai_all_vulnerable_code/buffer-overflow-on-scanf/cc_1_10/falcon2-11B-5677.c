//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 10

typedef struct {
    char name[100];
    int age;
    float salary;
} bidder;

typedef struct {
    char name[100];
    int price;
    int quantity;
} item;

int main() {
    int numBidders = 0, numItems = 0;
    bidder bidders[MAX_BIDDERS];
    item items[MAX_ITEMS];

    // Read number of bidders and items
    printf("Enter number of bidders: ");
    scanf("%d", &numBidders);
    printf("Enter number of items: ");
    scanf("%d", &numItems);

    // Read bidder details
    for (int i = 0; i < numBidders; i++) {
        printf("Enter bidder %d's name: ", i + 1);
        scanf("%s", bidders[i].name);
        printf("Enter bidder %d's age: ", i + 1);
        scanf("%d", &bidders[i].age);
        printf("Enter bidder %d's salary: ", i + 1);
        scanf("%f", &bidders[i].salary);
    }

    // Read item details
    for (int i = 0; i < numItems; i++) {
        printf("Enter item %d's name: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter item %d's price: ", i + 1);
        scanf("%d", &items[i].price);
        printf("Enter item %d's quantity: ", i + 1);
        scanf("%d", &items[i].quantity);
    }

    // Display bidder details
    printf("Bidder Details:\n");
    for (int i = 0; i < numBidders; i++) {
        printf("Name: %s\nAge: %d\nSalary: %.2f\n", bidders[i].name, bidders[i].age, bidders[i].salary);
    }

    // Display item details
    printf("Item Details:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Name: %s\nPrice: %d\nQuantity: %d\n", items[i].name, items[i].price, items[i].quantity);
    }

    return 0;
}