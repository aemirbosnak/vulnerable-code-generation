//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item {
    char name[50];
    int qty;
    float price;
    struct item *next; // linked list pointer
};

typedef struct item Item;

Item* head = NULL;

float totalBill = 0;

int main() {
    while(1) {
        printf("\nWelcome to C Cafe Billing System\n\n");
        printf("1. Add item\n");
        printf("2. View bill\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                Item *newItem = (Item*)malloc(sizeof(Item));
                printf("\nEnter item name: ");
                scanf("%s", newItem->name);
                printf("Enter quantity: ");
                scanf("%d", &newItem->qty);
                printf("Enter price: ");
                scanf("%f", &newItem->price);

                newItem->next = NULL;

                if(head == NULL) {
                    head = newItem;
                } else {
                    Item *tmp = head;

                    while(tmp->next != NULL) {
                        tmp = tmp->next;
                    }

                    tmp->next = newItem;
                }

                printf("\nItem added successfully!\n\n");
                break;
            }

            case 2: {
                printf("\n\n----------------BILL----------------\n");

                int i = 1;
                Item *tmp = head;

                while(tmp != NULL) {
                    printf("%d.%20s%10d%10.2f\n", i++, tmp->name, tmp->qty, tmp->price);
                    totalBill += tmp->qty * tmp->price;
                    tmp = tmp->next;
                }

                printf("\n\nTotal bill: %10.2f\n\n", totalBill);
                break;
            }

            case 3: {
                printf("\n\nThank you for using C Cafe Billing System\n\n");
                exit(0);
            }

            default: {
                printf("\n\nInvalid choice! Try again\n\n");
                break;
            }
        }
    }
    return 0;
}