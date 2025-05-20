//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct medicine {
    char name[20];
    int quantity;
    float price;
};

typedef struct medicine med;

static med inventory[50];

int num_medicines=0, opt;

void add_medicine() {
    if(num_medicines >= 50) {
        printf("Sorry, the medical store is already full!\n");
        return;
    }
    printf("\nEnter medicine name: ");
    scanf("%s", &inventory[num_medicines].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[num_medicines].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[num_medicines].price);
    num_medicines++;
    printf("\nMedicine has been added successfully!\n\n");
}

void sell_medicine() {
    if(num_medicines <= 0) {
        printf("Sorry, the medical store is empty!\n");
        return;
    }
    int sel_med_quantity=0, sel_med_index=-1;
    char sel_med_name[20];
    printf("\nEnter medicine name: ");
    scanf("%s", &sel_med_name);
    for(int i=0; i<num_medicines; i++) {
        if(strcmp(inventory[i].name, sel_med_name)==0) {
            sel_med_index = i;
            printf("Enter medicine quantity: ");
            scanf("%d", &sel_med_quantity);
            break;
        }
    }
    if(sel_med_index==-1 || sel_med_quantity>inventory[sel_med_index].quantity) {
        printf("Sorry, medicine not found or insufficient quantity!\n");
        return;
    }
    float amt = sel_med_quantity * inventory[sel_med_index].price;
    printf("\nTransaction successful! Amount to be paid: %0.2f\n\n", amt);
    inventory[sel_med_index].quantity -= sel_med_quantity;
}

void show_inventory() {
    if(num_medicines <= 0) {
        printf("\nSorry, the medical store is empty!\n\n");
        return;
    }
    printf("\nMEDICINE INVENTORY\n");
    printf("------------------\n");
    printf("NAME\tQUANTITY\tPRICE\n");
    printf("----\t--------\t-----\n");
    for(int i=0; i<num_medicines; i++) {
        printf("%s\t%d\t\t%0.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    printf("Welcome to the Funny Medical Store Management System!\n");
    while(1) {
        printf("Enter your choice:\n1 - Add medicine\n2 - Sell medicine\n3 - Show inventory\n4 - Exit\n");
        scanf("%d", &opt);
        switch(opt) {
            case 1: add_medicine(); break;
            case 2: sell_medicine(); break;
            case 3: show_inventory(); break;
            case 4:
                printf("\nThank you for using the Funny Medical Store Management System!\n");
                exit(0);
            default: printf("\nInvalid option selected!\n\n"); break;
        }
    }
    return 0;
}