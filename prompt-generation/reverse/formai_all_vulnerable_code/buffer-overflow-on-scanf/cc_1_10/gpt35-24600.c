//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 1000

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if(num_medicines >= MAX_MEDICINES) {
        printf("Error: Maximum number of medicines reached.\n");
        return;
    }
    Medicine medicine;
    printf("Enter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &medicine.price);
    medicines[num_medicines++] = medicine;
    printf("Added medicine successfully.\n");
}

void remove_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    int found = 0;
    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            found = 1;
            medicines[i] = medicines[num_medicines - 1];
            num_medicines--;
            printf("Removed medicine successfully.\n");
            break;
        }
    }
    if(!found) {
        printf("Error: Medicine not found.\n");
    }
}

void search_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    int found = 0;
    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            found = 1;
            printf("Medicine found:\n");
            printf("- Name: %s\n", medicines[i].name);
            printf("- Quantity: %d\n", medicines[i].quantity);
            printf("- Price: $%.2f\n", medicines[i].price);
            break;
        }
    }
    if(!found) {
        printf("Error: Medicine not found.\n");
    }
}

void list_medicines() {
    printf("List of medicines:\n");
    for(int i = 0; i < num_medicines; i++) {
        printf("%d. %s, %d units, $%.2f each\n", i+1, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void buy_medicine() {
    char name[50];
    int quantity;
    printf("Enter medicine name: ");
    scanf("%s", name);
    int found = 0;
    int index = -1;
    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }
    if(!found) {
        printf("Error: Medicine not found.\n");
        return;
    }
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    if(medicines[index].quantity < quantity) {
        printf("Error: Not enough medicine available.\n");
        return;
    }
    float total_price = quantity * medicines[index].price;
    printf("Total price: $%.2f\n", total_price);
    medicines[index].quantity -= quantity;
    printf("Bought medicine successfully.\n");
}

int main() {
    while(1) {
        printf("\n");
        printf("Welcome to Medical Store Management!\n");
        printf("1. Add new medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Search medicine\n");
        printf("4. List all medicines\n");
        printf("5. Buy medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                list_medicines();
                break;
            case 5:
                buy_medicine();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }
    return 0;
}