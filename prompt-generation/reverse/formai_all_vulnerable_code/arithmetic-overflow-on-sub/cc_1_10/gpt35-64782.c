//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine {
    int id;
    char name[50];
    float price;
};

struct Cart {
    int medId;
    int quantity;
};

struct Inventory {
    int medId;
    int stock;
};

struct Medicine medicines[] = {
    {1001, "Paracetamol", 1.5},
    {1002, "Aspirin", 2.0},
    {1003, "Ibuprofen", 3.5},
    {1004, "Antacid", 2.5},
    {1005, "Cough Syrup", 4.0}
};

struct Inventory inventory[] = {
    {1001, 500},
    {1002, 300},
    {1003, 200},
    {1004, 400},
    {1005, 250}
};

int itemCount = sizeof(medicines) / sizeof(medicines[0]);
int inventoryCount = sizeof(inventory) / sizeof(inventory[0]);
float discount = 0.1;

void displayMenu() {
    printf("\nWelcome to ABC Medical Store!\n\n");
    printf("Please select an option:\n");
    printf("1. View Medicine List\n");
    printf("2. Add to Cart\n");
    printf("3. View Cart\n");
    printf("4. Remove from Cart\n");
    printf("5. Checkout\n");
    printf("6. Exit\n\n");
}

void viewMedicines() {
    printf("\nMedicine List:\n\n");
    printf("ID\tName\t\tPrice\n");
    printf("---------------------------------------\n");
    for(int i=0; i<itemCount; i++) {
        printf("%d\t%s\t\t$%.2f\n", medicines[i].id, medicines[i].name, medicines[i].price);
    }
    printf("\n");
}

void addToCart(struct Cart *cart, int *cartItemCount) {
    int medId, quantity, remainingStock;
    printf("\nEnter the ID of the medicine: ");
    scanf("%d", &medId);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    for(int i=0; i<inventoryCount; i++) {
        if(inventory[i].medId == medId) {
            remainingStock = inventory[i].stock - quantity;
            if(remainingStock < 0) {
                printf("Sorry, only %d items are available in stock.\n", inventory[i].stock);
                return;
            } else {
                cart[*cartItemCount].medId = medId;
                cart[*cartItemCount].quantity = quantity;
                inventory[i].stock = remainingStock;
                printf("Added to cart.\n");
                (*cartItemCount)++;
                break;
            }
        }
        if(i == inventoryCount - 1) {
            printf("Invalid medicine ID.\n");
        }
    }
}

void viewCart(struct Cart *cart, int *cartItemCount) {
    if(*cartItemCount == 0) {
        printf("\nYour cart is empty.\n\n");
    } else {
        float total = 0;
        printf("\nYour cart:\n\n");
        printf("ID\tName\t\tPrice\t\tQuantity\tTotal\n");
        printf("------------------------------------------------------------------\n");
        for(int i=0; i<*cartItemCount; i++) {
            int j = cart[i].medId - 1001;
            float itemTotal = cart[i].quantity * medicines[j].price;
            printf("%d\t%s\t\t$%.2f\t\t%d\t\t$%.2f\n", medicines[j].id, medicines[j].name, medicines[j].price, cart[i].quantity, itemTotal);
            total += itemTotal;
        }
        printf("\nTotal (before discount): $%.2f", total);
        total -= total * discount;
        printf("\nDiscount: %d%%", (int)(discount*100));
        printf("\nTotal (after discount): $%.2f\n\n", total);
    }
}

void removeFromCart(struct Cart *cart, int *cartItemCount) {
    int medId, index = -1, quantity, remainingStock;
    printf("\nEnter the ID of the medicine: ");
    scanf("%d", &medId);
    for(int i=0; i<*cartItemCount; i++) {
        if(cart[i].medId == medId) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("The medicine is not in the cart.\n");
    } else {
        quantity = cart[index].quantity;
        for(int i=0; i<inventoryCount; i++) {
            if(inventory[i].medId == medId) {
                remainingStock = inventory[i].stock + quantity;
                cart[index] = cart[--(*cartItemCount)];
                inventory[i].stock = remainingStock;
                printf("Removed from cart.\n");
                break;
            }
        }
    }
}

void checkout(struct Cart *cart, int *cartItemCount) {
    if(*cartItemCount == 0) {
        printf("\nYour cart is empty.\n\n");
    } else {
        float totalPrice = 0;
        printf("\nThank you for shopping with us!\n\n");
        printf("Your receipt:\n\n");
        printf("ID\tName\t\tPrice\t\tQuantity\tTotal\n");
        printf("------------------------------------------------------------------\n");
        for(int i=0; i<*cartItemCount; i++) {
            int j = cart[i].medId - 1001;
            float itemTotal = cart[i].quantity * medicines[j].price;
            printf("%d\t%s\t\t$%.2f\t\t%d\t\t$%.2f\n", medicines[j].id, medicines[j].name, medicines[j].price, cart[i].quantity, itemTotal);
            totalPrice += itemTotal;
            inventory[j].stock -= cart[i].quantity;
        }
        printf("\nTotal (before discount): $%.2f", totalPrice);
        totalPrice -= totalPrice * discount;
        printf("\nDiscount: %d%%", (int)(discount*100));
        printf("\nTotal (after discount): $%.2f\n\n", totalPrice);
        *cartItemCount = 0;
    }
}

int main() {
    int option, cartItemCount = 0;
    struct Cart cart[50];
    while(1) {
        displayMenu();
        scanf("%d", &option);
        switch(option) {
            case 1:
                viewMedicines();
                break;
            case 2:
                addToCart(cart, &cartItemCount);
                break;
            case 3:
                viewCart(cart, &cartItemCount);
                break;
            case 4:
                removeFromCart(cart, &cartItemCount);
                break;
            case 5:
                checkout(cart, &cartItemCount);
                break;
            default:
                printf("Thank you for using ABC Medical Store!\n");
                exit(0);
        }
    }
    return 0;
}