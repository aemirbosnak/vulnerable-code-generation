//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 1000
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

int num_medicines = 0;
Medicine medicines[MAX_MEDICINES];

void add_medicine() {
    if(num_medicines >= MAX_MEDICINES) {
        printf("Max limit reached. Cannot add more medicines.\n");
        return;
    }

    Medicine new_medicine;
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);

    medicines[num_medicines] = new_medicine;
    num_medicines++;
    printf("Medicine added successfully.\n");
}

void search_medicine() {
    char medicine_name[MAX_NAME_LENGTH];
    printf("Enter medicine name: ");
    scanf("%s", medicine_name);

    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(medicines[i].name, medicine_name) == 0) {
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            return;
        }
    }

    printf("Medicine not found.\n");
}

void list_medicines() {
    printf("List of medicines:\n");
    for(int i = 0; i < num_medicines; i++) {
        printf("%d. %s (Quantity: %d, Price: %.2f)\n", i+1, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void sell_medicine() {
    char medicine_name[MAX_NAME_LENGTH];
    printf("Enter medicine name: ");
    scanf("%s", medicine_name);

    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(medicines[i].name, medicine_name) == 0) {
            int quantity_to_sell;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity_to_sell);

            if(quantity_to_sell > medicines[i].quantity) {
                printf("Not enough stock. Cannot sell.\n");
                return;
            }

            float total_price = medicines[i].price * quantity_to_sell;
            printf("%d %s sold for %.2f\n", quantity_to_sell, medicines[i].name, total_price);

            medicines[i].quantity -= quantity_to_sell;
            return;
        }
    }

    printf("Medicine not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nWelcome to Medical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. List Medicines\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                search_medicine();
                break;
            case 3:
                list_medicines();
                break;
            case 4:
                sell_medicine();
                break;
            case 5:
                printf("Thank you for using Medical Store Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}