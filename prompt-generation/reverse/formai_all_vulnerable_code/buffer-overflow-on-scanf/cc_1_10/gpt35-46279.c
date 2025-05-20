//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

struct medicine {
    char name[50];
    float price;
    int quantity;
    char expiry[20];
};

void addMedicine(struct medicine list[], int *size) {
    struct medicine temp;
    printf("\nEnter medicine name: ");
    scanf("%s", temp.name);
    printf("Enter price: ");
    scanf("%f", &temp.price);
    printf("Enter quantity: ");
    scanf("%d", &temp.quantity);
    printf("Enter expiry date: ");
    scanf("%s", temp.expiry);
    list[*size] = temp;
    (*size)++;
}

void searchMedicine(struct medicine list[], int size) {
    char name[50];
    printf("\nEnter name to search: ");
    scanf("%s", name);
    for(int i=0; i<size; i++) {
        if(strcmp(list[i].name, name) == 0) {
            printf("\nMedicine Found!\n");
            printf("\nName: %s\nPrice: Rs. %0.2f\nQuantity: %d\nExpiry Date: %s\n", list[i].name, list[i].price, list[i].quantity, list[i].expiry);
            return;
        }
    }
    printf("\nMedicine not found.\n");
}

void sellMedicine(struct medicine list[], int size) {
    char name[50];
    printf("\nEnter name to sell: ");
    scanf("%s", name);
    for(int i=0; i<size; i++) {
        if(strcmp(list[i].name, name) == 0) {
            int quantity;
            printf("\nMedicine Found!\n");
            printf("\nName: %s\nPrice: Rs. %0.2f\nQuantity: %d\nExpiry Date: %s\n", list[i].name, list[i].price, list[i].quantity, list[i].expiry);
            printf("\nEnter quantity to sell: ");
            scanf("%d", &quantity);
            if(quantity > list[i].quantity) {
                printf("\nNot enough stock.\n");
                return;
            }
            list[i].quantity -= quantity;
            printf("\nSold %d %s. Total amount: Rs. %0.2f\n", quantity, list[i].name, quantity*list[i].price);
            return;
        }
    }
    printf("\nMedicine not found.\n");
}

void printInventory(struct medicine list[], int size) {
    printf("\n");
    printf("| %-20s | %-10s | %-8s | %-15s |\n", "PRODUCT NAME", "PRICE", "QUANTITY", "EXPIRY DATE");
    for(int i=0; i<size; i++) {
        printf("| %-20s | %6.2f   | %-8d | %-15s |\n", list[i].name, list[i].price, list[i].quantity, list[i].expiry);
    }
}

int main() {
    struct medicine list[100];
    int size=0;
    int choice;
    while(1) {
        printf("\n------ Medical Store Management System ------\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Sell Medicine\n");
        printf("4. Print Inventory\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(list, &size);
                break;
            case 2:
                searchMedicine(list, size);
                break;
            case 3:
                sellMedicine(list, size);
                break;
            case 4:
                printInventory(list, size);
                break;
            case 5:
                printf("\nThank you for using our system!\n");
                return 0;
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}