//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct Bill
{
    char item[20];
    int quantity;
    float price;
};

void display_menu(void);
void place_order(struct Bill *order, int *size);
void calculate_bill(struct Bill order[], int size);

int main()
{
    struct Bill order[MAX];
    int size = 0;

    printf("Welcome to the C Cafe!\n");

    while(1)
    {
        display_menu();

        if(size >= MAX)
        {
            printf("Your order is full. Please pay the bill.\n");
            break;
        }
        else
        {
            place_order(order, &size);
        }
    }

    calculate_bill(order, size);

    return 0;
}

void display_menu(void)
{
    printf("\nMenu:\n");
    printf("1. Coffee\n2. Tea\n3. Sandwich\n4. Pizza\n5. Burger\n");
}

void place_order(struct Bill *order, int *size)
{
    char choice;
    printf("\nEnter your choice: ");
    scanf("%c", &choice);

    switch(choice)
    {
        case '1':
            strcpy(order[*size].item, "Coffee");
            printf("Enter quantity: ");
            scanf("%d", &order[*size].quantity);
            printf("Enter price per unit: ");
            scanf("%f", &order[*size].price);
            break;

        case '2':
            strcpy(order[*size].item, "Tea");
            printf("Enter quantity: ");
            scanf("%d", &order[*size].quantity);
            printf("Enter price per unit: ");
            scanf("%f", &order[*size].price);
            break;

        case '3':
            strcpy(order[*size].item, "Sandwich");
            printf("Enter quantity: ");
            scanf("%d", &order[*size].quantity);
            printf("Enter price per unit: ");
            scanf("%f", &order[*size].price);
            break;

        case '4':
            strcpy(order[*size].item, "Pizza");
            printf("Enter quantity: ");
            scanf("%d", &order[*size].quantity);
            printf("Enter price per unit: ");
            scanf("%f", &order[*size].price);
            break;

        case '5':
            strcpy(order[*size].item, "Burger");
            printf("Enter quantity: ");
            scanf("%d", &order[*size].quantity);
            printf("Enter price per unit: ");
            scanf("%f", &order[*size].price);
            break;

        default:
            printf("Invalid choice. Order cancelled.\n");
            (*size)--;
            break;
    }
}

void calculate_bill(struct Bill order[], int size)
{
    float total = 0;

    printf("\nYour order:\n");

    for(int i=0; i<size; i++)
    {
        printf("%s - %d units - $%.2f\n", order[i].item, order[i].quantity, order[i].price*order[i].quantity);
        total += order[i].price*order[i].quantity;
    }

    printf("\nTotal bill: $%.2f\n", total);
}