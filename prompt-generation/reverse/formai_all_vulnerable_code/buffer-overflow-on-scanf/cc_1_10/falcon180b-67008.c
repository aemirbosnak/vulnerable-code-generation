//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct customer {
    char name[20];
    int age;
    char order[50];
    float bill;
};

void menu() {
    printf("\n");
    printf("Welcome to the C Cafe!\n");
    printf("Our menu includes:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Cake\n");
    printf("4. Cookies\n");
    printf("5. Sandwich\n");
    printf("6. Pizza\n");
    printf("7. Burger\n");
    printf("8. Fries\n");
    printf("9. Salad\n");
    printf("10. Water\n");
    printf("\n");
}

void order(struct customer *c) {
    int choice;
    printf("What would you like to order?\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            strcpy(c->order, "Coffee");
            c->bill += 50;
            break;
        case 2:
            strcpy(c->order, "Tea");
            c->bill += 30;
            break;
        case 3:
            strcpy(c->order, "Cake");
            c->bill += 100;
            break;
        case 4:
            strcpy(c->order, "Cookies");
            c->bill += 20;
            break;
        case 5:
            strcpy(c->order, "Sandwich");
            c->bill += 80;
            break;
        case 6:
            strcpy(c->order, "Pizza");
            c->bill += 200;
            break;
        case 7:
            strcpy(c->order, "Burger");
            c->bill += 150;
            break;
        case 8:
            strcpy(c->order, "Fries");
            c->bill += 40;
            break;
        case 9:
            strcpy(c->order, "Salad");
            c->bill += 120;
            break;
        case 10:
            strcpy(c->order, "Water");
            c->bill += 10;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void payment(struct customer *c) {
    printf("Your bill is %.2f\n", c->bill);
    printf("Thank you for visiting the C Cafe!\n");
}

int main() {
    int i, n;
    struct customer c[MAX];
    printf("How many customers? ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Customer %d:\n", i+1);
        printf("Name: ");
        scanf("%s", c[i].name);
        printf("Age: ");
        scanf("%d", &c[i].age);
        menu();
        order(&c[i]);
        payment(&c[i]);
    }
    return 0;
}