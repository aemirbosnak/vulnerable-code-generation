//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define structures for medicine and customer
struct Medicine {
    int id;
    char name[100];
    int quantity;
    float price;
};

struct Customer {
    char name[100];
    char address[100];
    char phone[20];
    int age;
};

//function to display customer data
void display_customer(struct Customer c) {
    printf("\nCustomer Details:\n");
    printf("Name: %s\n", c.name);
    printf("Age: %d\n", c.age);
    printf("Address: %s\n", c.address);
    printf("Phone Number: %s\n", c.phone);
}

//function to display medicine data
void display_medicine(struct Medicine m) {
    printf("\nMedicine Details:\n");
    printf("ID: %d\n", m.id);
    printf("Name: %s\n", m.name);
    printf("Price: %.2f\n", m.price);
    printf("Quantity: %d\n", m.quantity);
}

//function to add new medicine
void add_medicine(struct Medicine *m, int *count) {
    printf("\nEnter Medicine ID: ");
    scanf("%d", &(m[*count].id));
    printf("Enter Medicine Name: ");
    scanf("%s", m[*count].name);
    printf("Enter Medicine Price: ");
    scanf("%f", &(m[*count].price));
    printf("Enter Quantity: ");
    scanf("%d", &(m[*count].quantity));
    (*count)++;
}

//function to search medicine by ID
void search_medicine(struct Medicine *m, int count) {
    int id, found = 0, i;
    printf("\nEnter Medicine ID to Search: ");
    scanf("%d", &id);
    for(i=0; i<count; i++) {
        if(m[i].id == id) {
            found = 1;
            display_medicine(m[i]);
            break;
        }
    }
    if(found == 0)
        printf("\nMedicine not found!\n");
}

//function to sell medicine to customer
void sell_medicine(struct Medicine *m, int count) {
    int id, quantity, i, found = 0;
    float amount = 0;
    printf("\nEnter Medicine ID: ");
    scanf("%d", &id);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    for(i=0; i<count; i++) {
        if(m[i].id == id) {
            if(m[i].quantity >= quantity) {
                found = 1;
                m[i].quantity -= quantity;
                amount = quantity * m[i].price;
                printf("\nMedicine Sold Successfully!\n");
                printf("Amount: %.2f\n", amount);
                break;
            }
            else {
                printf("\nInsufficient Quantity!\n");
                break;
            }
        }
    }
    if(found == 0)
        printf("\nMedicine not found!\n");
}

int main() {
    int choice, count = 0, i;
    struct Medicine med[100];
    struct Customer cust;
    while(1) {
        printf("\n******* Medical Store Management System *******\n");
        printf("\n1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Sell Medicine\n");
        printf("4. Customer Details\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_medicine(med, &count);
                break;
            case 2:
                search_medicine(med, count);
                break;
            case 3:
                sell_medicine(med, count);
                break;
            case 4:
                printf("\nEnter Customer Details:\n");
                printf("Name: ");
                scanf("%s", cust.name);
                printf("Age: ");
                scanf("%d", &(cust.age));
                printf("Address: ");
                scanf("%s", cust.address);
                printf("Phone Number: ");
                scanf("%s", cust.phone);
                display_customer(cust);
                printf("\nMedicine Details:\n");
                for(i=0; i<count; i++) {
                    if(med[i].quantity > 0)
                        display_medicine(med[i]);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}