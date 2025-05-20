//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct medicine {
    char name[50];
    int price;
    int quantity;
};

void addMedicine(struct medicine *m, int n) {
    printf("\nEnter medicine name: ");
    scanf("%s", m[n].name);
    printf("Enter medicine price: ");
    scanf("%d", &m[n].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m[n].quantity);
}

void displayMedicine(struct medicine m[], int n) {
    printf("\nMEDICINE LIST\n");
    printf("---------------------------------\n");
    printf("S.No.| Medicine Name | Price | Quantity\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s | Rs. %d | %d\n", i + 1, m[i].name, m[i].price, m[i].quantity);
    }
}

void purchaseMedicine(struct medicine m[], int n, int choice) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(m[i].name, "Paracetamol") == 0) {
            flag = 1;
            m[i].quantity--;
            printf("\n%d tablets of Paracetamol purchased.\n", choice);
        } else if (strcmp(m[i].name, "Crocin") == 0) {
            flag = 1;
            m[i].quantity--;
            printf("\n%d tablets of Crocin purchased.\n", choice);
        } else if (strcmp(m[i].name, "Dolo 650") == 0) {
            flag = 1;
            m[i].quantity--;
            printf("\n%d tablets of Dolo 650 purchased.\n", choice);
        }
    }
    if (flag == 0)
        printf("\nSorry, the medicine you want to purchase is not available.\n");
}

void main() {
    struct medicine m[MAX];
    int n, choice;

    printf("\nEnter number of medicines: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        addMedicine(m, i);
    }

    while (1) {
        system("clear");
        displayMedicine(m, n);
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            purchaseMedicine(m, n, choice);
        } else if (choice == 2) {
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }
}