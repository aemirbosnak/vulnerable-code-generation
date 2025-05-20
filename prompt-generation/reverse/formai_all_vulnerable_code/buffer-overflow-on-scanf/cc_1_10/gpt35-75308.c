//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[20];
    int quantity;
};

void check_stock(struct medicine *med, int size, char *name) {
    int i;
    for (i=0; i<size; i++) {
        if (strcmp(med[i].name, name)==0) {
            printf("Stock for %s: %d\n", name, med[i].quantity);
            return;
        }
    }
    printf("%s not found in stock.\n", name);
}

void restock(struct medicine *med, int size, char *name, int amount) {
    int i;
    for (i=0; i<size; i++) {
        if (strcmp(med[i].name, name)==0) {
            med[i].quantity += amount;
            printf("%d %s added to stock.\n", amount, name);
            return;
        }
    }
    printf("%s not found in stock.\n", name);
}

void sell(struct medicine *med, int size, char *name, int amount) {
    int i;
    for (i=0; i<size; i++) {
        if (strcmp(med[i].name, name)==0) {
            if (med[i].quantity >= amount) {
                med[i].quantity -= amount;
                printf("%d %s sold.\n", amount, name);
                return;
            } else {
                printf("Not enough %s in stock.\n", name);
                return;
            }
        }
    }
    printf("%s not found in stock.\n", name);
}

int main() {
    struct medicine med[5] = {{"Aspirin", 50}, {"Penicillin", 20}, {"Morphine", 10},
                         {"Epinephrine", 15}, {"Insulin", 30}};
    int choice, amount;
    char name[20];

    printf("Welcome to the Medical Store Management System.\n");
    printf("How can I assist you today?\n");

    while (1) {
        printf("1. Check stock\n");
        printf("2. Restock medicine\n");
        printf("3. Sell medicine\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                check_stock(med, 5, name);
                break;

            case 2:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                printf("Enter amount to add to stock: ");
                scanf("%d", &amount);
                restock(med, 5, name, amount);
                break;

            case 3:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                printf("Enter amount to sell: ");
                scanf("%d", &amount);
                sell(med, 5, name, amount);
                break;

            case 4:
                printf("Thank you for visiting our store. Goodbye.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}