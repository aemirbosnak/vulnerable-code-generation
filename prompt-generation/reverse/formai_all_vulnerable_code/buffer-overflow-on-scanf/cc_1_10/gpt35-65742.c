//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[30];
    int id;
    float price;
    int quantity;
} medicine;

void print_inventory(medicine medicineList[], int n) {
    printf("Current inventory:\n");
    printf("%-30s %-10s %-10s %-10s\n", "Name", "ID", "Price", "Quantity");
    for(int i=0;i<n;i++) {
        printf("%-30s %-10d %-10f %-10d\n", medicineList[i].name, medicineList[i].id, medicineList[i].price, medicineList[i].quantity);
    }
}

void add_medicine(medicine medicineList[], int *n) {
    char name[30];
    int id, quantity;
    float price;

    printf("Enter the name of the medicine: ");
    scanf("%s", name);

    printf("Enter the ID of the medicine: ");
    scanf("%d", &id);

    printf("Enter the price of the medicine: ");
    scanf("%f", &price);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);

    medicineList[*n].id = id;
    strcpy(medicineList[*n].name, name);
    medicineList[*n].price = price;
    medicineList[*n].quantity = quantity;

    (*n)++;

    printf("Medicine with ID '%d' added successfully.\n", id);
}

void search_medicine(medicine medicineList[], int n) {
    int id;
    printf("Enter the ID of the medicine to be searched: ");
    scanf("%d", &id);

    for(int i=0;i<n;i++) {
        if(medicineList[i].id == id) {
            printf("Medicine details:\n");
            printf("Name: %s\n", medicineList[i].name);
            printf("ID: %d\n", medicineList[i].id);
            printf("Price: %.2f\n", medicineList[i].price);
            printf("Quantity: %d\n", medicineList[i].quantity);
            return;
        }
    }

    printf("Medicine with ID '%d' not found.\n", id);
}

void sell_medicine(medicine medicineList[], int n) {
    int id, quantity;
    printf("Enter the ID of the medicine to be sold: ");
    scanf("%d", &id);

    for(int i=0;i<n;i++) {
        if(medicineList[i].id == id) {
            printf("Enter the quantity to be sold: ");
            scanf("%d", &quantity);
            if(medicineList[i].quantity >= quantity) {
                medicineList[i].quantity -= quantity;
                printf("Sold %d units of '%s' successfully.\n", quantity, medicineList[i].name);
            } else {
                printf("Requested quantity not available for '%s'. Available quantity is %d.\n", medicineList[i].name, medicineList[i].quantity);
            }
            return;
        }
    }

    printf("Medicine with ID '%d' not found.\n", id);
}

int main() {
    medicine medicineList[MAX_SIZE];
    int n = 0;
    int choice;

    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Print current inventory.\n");
        printf("2. Add medicine.\n");
        printf("3. Search medicine.\n");
        printf("4. Sell medicine.\n");
        printf("5. Exit.\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_inventory(medicineList, n);
                break;
            case 2:
                add_medicine(medicineList, &n);
                break;
            case 3:
                search_medicine(medicineList, n);
                break;
            case 4:
                sell_medicine(medicineList, n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}