//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Cryptic
#include <stdio.h>
#include <string.h>

#define MAX_MEDICINES 100

struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Medicine stock[MAX_MEDICINES];
int count = 0;

void addMedicine() {
    struct Medicine newMedicine;
    printf("Enter medicine id: ");
    scanf("%d", &newMedicine.id);
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);
    stock[count++] = newMedicine;
    printf("%s added successfully!\n", newMedicine.name);
}

void displayMedicine(struct Medicine m) {
    printf("%d\t%s\t%.2f\t%d\n", m.id, m.name, m.price, m.quantity);
}

void viewMedicines() {
    printf("ID\tNAME\tPRICE\tQUANTITY\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) {
        displayMedicine(stock[i]);
    }
}

void searchMedicine() {
    int id;
    printf("Enter medicine id to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (stock[i].id == id) {
            displayMedicine(stock[i]);
            return;
        }
    }
    printf("Medicine with id %d not found!\n", id);
}

void updateMedicine() {
    int id;
    printf("Enter medicine id to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (stock[i].id == id) {
            printf("Enter new details:\n");
            printf("Enter medicine name: ");
            scanf("%s", stock[i].name);
            printf("Enter medicine price: ");
            scanf("%f", &stock[i].price);
            printf("Enter medicine quantity: ");
            scanf("%d", &stock[i].quantity);
            printf("%s updated successfully!\n", stock[i].name);
            return;
        }
    }
    printf("Medicine with id %d not found!\n", id);
}

void sellMedicine() {
    int id, quantity;
    printf("Enter medicine id to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    for (int i = 0; i < count; i++) {
        if (stock[i].id == id) {
            if (stock[i].quantity >= quantity) {
                stock[i].quantity -= quantity;
                printf("%d %ss sold for %.2f!\n", quantity, stock[i].name, stock[i].price * quantity);
            } else {
                printf("Only %d %ss available!\n", stock[i].quantity, stock[i].name);
            }
            return;
        }
    }
    printf("Medicine with id %d not found!\n", id);
}

int main() {
    printf("======C Medical Store Management System======\n");
    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Add medicine\n2. View medicines\n3. Search medicine\n4. Update medicine\n5. Sell medicine\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                sellMedicine();
                break;
            case 6:
                printf("Thank you for using C Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);
    return 0;
}