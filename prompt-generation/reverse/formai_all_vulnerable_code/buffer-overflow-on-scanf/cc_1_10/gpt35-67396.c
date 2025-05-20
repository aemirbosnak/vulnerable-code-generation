//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct medicine {                //defining the structure of each medicine
    char name[20];
    int quantity;
    float price;
};

void add_medicine(struct medicine a[], int size) {    //function to add new medicine to the inventory
    char med_name[20];
    int qty=0;
    float prc=0.0;
    int flag=1, i;
    for(i=0; i<size; i++) {       //loop to check if the medicine already exists
        if(strcmp(a[i].name, med_name)==0) {
            printf("Medicine already exists. Updating stock...\n");
            printf("Enter quantity: ");
            scanf("%d", &qty);
            a[i].quantity += qty;
            flag=0;
            break;
        }
    }
    if(flag!=0) {
        printf("Enter price: ");
        scanf("%f", &prc);
        printf("Enter quantity: ");
        scanf("%d", &qty);
        struct medicine new_med;         //defining new medicine
        strcpy(new_med.name, med_name);
        new_med.quantity=qty;
        new_med.price=prc;
        a[size]=new_med;
        printf("Medicine added successfully!\n");
    }
}

void sell_medicine(struct medicine a[], int size) {    //function to sell medicine
    int flag=0, idx, qty;
    char med_name[20];
    printf("Enter medicine name: ");
    scanf("%s", med_name);
    for(int i=0; i<size; i++) {       //loop to search for the medicine
        if(strcmp(a[i].name, med_name)==0) {
            printf("Enter quantity: ");
            scanf("%d", &qty);
            if(qty>a[i].quantity) {     //checks if the entered quantity is more than available quantity
                printf("Oops! Not enough stock.\n");
                flag=1;
                break;
            }
            else {
                a[i].quantity -= qty;
                printf("Amount to be paid: %.2f\n", qty*a[i].price);
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        printf("Medicine not found.\n");
}

void display_inventory(struct medicine a[], int size) {     //function to display inventory
    printf("NAME\tQUANTITY\tPRICE\n");
    for(int i=0; i<size; i++) {
        printf("%s\t%d\t%.2f\n", a[i].name, a[i].quantity, a[i].price);
    }
}

void main() {
    struct medicine inventory[100];           //array of medicine structure
    int size=0, choice;
    while(1) {                            //displaying the menu and taking appropriate action on user's choice
        printf("1. Add medicine\n");
        printf("2. Sell medicine\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_medicine(inventory, size);
                    size++;
                    break;
            case 2: sell_medicine(inventory, size);
                    break;
            case 3: display_inventory(inventory, size);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}