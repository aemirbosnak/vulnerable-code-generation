//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 50
#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    int age;
    char gender;
    char address[100];
    char contact[20];
} Customer;

typedef struct {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

int num_customers = 0;
Customer customers[MAX_CUSTOMERS];

int num_medicines = 0;
Medicine medicines[MAX_MEDICINES];

void add_customer() {
    Customer c;
    printf("Enter customer name: ");
    scanf("%s", &c.name);
    printf("Enter customer age: ");
    scanf("%d", &c.age);
    printf("Enter customer gender (M/F): ");
    scanf(" %c", &c.gender);
    printf("Enter customer address: ");
    scanf("%s", &c.address);
    printf("Enter customer contact number: ");
    scanf("%s", &c.contact);
    customers[num_customers++] = c;
}

void view_customers() {
    printf("Customers:\n");
    for(int i=0; i<num_customers; i++) {
        printf("%d. %s (%d, %c)\n", i+1, customers[i].name, customers[i].age, customers[i].gender);
    }
}

void add_medicine() {
    Medicine m;
    printf("Enter medicine name: ");
    scanf("%s", &m.name);
    printf("Enter manufacturer: ");
    scanf("%s", &m.manufacturer);
    printf("Enter price: ");
    scanf("%f", &m.price);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);
    medicines[num_medicines++] = m;
}

void view_medicines() {
    printf("Medicines:\n");
    for(int i=0; i<num_medicines; i++) {
        printf("%d. %s (%d)\n", i+1, medicines[i].name, medicines[i].quantity);
    }
}

void place_order() {
    int customer_idx, medicine_idx, quantity;
    printf("Enter customer index: ");
    scanf("%d", &customer_idx);
    view_medicines();
    printf("Enter medicine index: ");
    scanf("%d", &medicine_idx);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    if(medicines[medicine_idx-1].quantity < quantity) {
        printf("Insufficient stock.\n");
    } else {
        medicines[medicine_idx-1].quantity -= quantity;
        printf("Order placed successfully.\n");
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Add customer\n2. View customers\n3. Add medicine\n4. View medicines\n5. Place order\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_customer();
                break;
            case 2:
                view_customers();
                break;
            case 3:
                add_medicine();
                break;
            case 4:
                view_medicines();
                break;
            case 5:
                place_order();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}