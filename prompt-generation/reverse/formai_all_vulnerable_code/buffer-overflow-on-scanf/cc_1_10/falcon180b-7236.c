//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_QTY_LEN 10

struct item {
    char name[MAX_NAME_LEN];
    char description[MAX_NAME_LEN];
    float price;
    int quantity;
};

void add_item(struct item *menu, int *num_items) {
    printf("Enter item name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", menu[*num_items].name);

    printf("Enter item description (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", menu[*num_items].description);

    printf("Enter item price: ");
    scanf("%f", &menu[*num_items].price);

    printf("Enter item quantity: ");
    scanf("%d", &menu[*num_items].quantity);

    (*num_items)++;
}

void display_menu(struct item menu[], int num_items) {
    printf("\nMenu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %s - $%.2f - %d\n", i+1, menu[i].name, menu[i].description, menu[i].price, menu[i].quantity);
    }
}

void place_order(struct item menu[], int num_items) {
    int choice;
    float total = 0.0;

    do {
        display_menu(menu, num_items);
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= num_items) {
            printf("\nYou chose %s\n", menu[choice-1].name);
            printf("Enter quantity: ");
            scanf("%d", &menu[choice-1].quantity);
            total += menu[choice-1].price * menu[choice-1].quantity;
        } else {
            printf("\nInvalid choice.\n");
        }

        printf("\nDo you want to order more? (y/n): ");
        char ans;
        scanf(" %c", &ans);
        if (tolower(ans) == 'n')
            break;

    } while (1);

    printf("\nTotal amount: $%.2f\n", total);
}

int main() {
    struct item menu[MAX_ITEMS];
    int num_items = 0;

    add_item(menu, &num_items);
    add_item(menu, &num_items);

    place_order(menu, num_items);

    return 0;
}