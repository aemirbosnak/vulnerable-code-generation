//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

struct customer {
    char name[MAX];
    char address[MAX];
    int contact;
};

struct order {
    char item[MAX];
    float cost;
};

void addCustomer(struct customer *c) {
    printf("\nEnter customer name: ");
    scanf("%s", c->name);

    printf("Enter customer address: ");
    scanf("%s", c->address);

    printf("Enter customer contact: ");
    scanf("%d", &c->contact);
}

void addOrder(struct customer *c, struct order *o) {
    printf("\nEnter order item: ");
    scanf("%s", o->item);

    printf("Enter order cost: ");
    scanf("%f", &o->cost);

    strcpy(o->item, c->name);
}

void displayOrder(struct order *o) {
    printf("\nOrder item: %s", o->item);
    printf("\nOrder cost: %f", o->cost);
}

int main() {
    struct customer c;
    struct order o;

    addCustomer(&c);

    int choice, i = 0;

    do {
        system("clear");
        printf("\nCafe Billing System\n");
        printf("\nCustomer name: %s", c.name);
        printf("\nCustomer address: %s", c.address);
        printf("\nCustomer contact: %d", c.contact);

        printf("\n\nMenu:\n");
        printf("1. Add order\n");
        printf("2. Display order\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                addOrder(&c, &o);
                printf("\nOrder added successfully!\n");
                break;
            }

            case 2: {
                if(i == 0) {
                    printf("\nNo orders added yet.\n");
                } else {
                    displayOrder(&o);
                }
                break;
            }

            case 3: {
                printf("\nExiting...\n");
                break;
            }

            default: {
                printf("\nInvalid choice!\n");
            }
        }

        i++;
    } while(choice!= 3);

    return 0;
}