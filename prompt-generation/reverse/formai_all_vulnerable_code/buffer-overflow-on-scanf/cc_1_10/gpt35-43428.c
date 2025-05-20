//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[20];
    int quantity;
    float price;
};

void addMedicine(struct medicine m[], int *n) {
    printf("Enter name: ");
    scanf("%s", m[*n].name);

    printf("Enter quantity: ");
    scanf("%d", &m[*n].quantity);

    printf("Enter price: ");
    scanf("%f", &m[*n].price);

    (*n)++;
}

void removeMedicine(struct medicine m[], int *n) {
    char name[20];
    int i, found = 0;

    printf("Enter name: ");
    scanf("%s", name);

    for (i = 0; i < *n; i++) {
        if (strcmp(m[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < (*n - 1); i++) {
            m[i] = m[i + 1];
        }
        (*n)--;
        printf("Medicine removed successfully.\n");
    } else {
        printf("Medicine not found.\n");
    }
}

void searchMedicine(struct medicine m[], int n) {
    char name[20];
    int i, found = 0;

    printf("Enter name: ");
    scanf("%s", name);

    for (i = 0; i < n; i++) {
        if (strcmp(m[i].name, name) == 0) {
            found = 1;
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", m[i].name, m[i].quantity, m[i].price);
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

void displayMedicine(struct medicine m[], int n) {
    int i;

    printf("Name\tQuantity\tPrice\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%d\t\t%.2f\n", m[i].name, m[i].quantity, m[i].price);
    }
}

int main() {
    struct medicine m[50];
    int n = 0, choice;

    do {
        printf("\n-------------------\n");
        printf("Medical Store Menu\n");
        printf("-------------------\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Search medicine\n");
        printf("4. Display medicine\n");
        printf("5. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(m, &n);
                break;
            case 2:
                removeMedicine(m, &n);
                break;
            case 3:
                searchMedicine(m, n);
                break;
            case 4:
                displayMedicine(m, n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}