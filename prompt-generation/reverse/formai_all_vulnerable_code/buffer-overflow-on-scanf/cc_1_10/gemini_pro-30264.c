//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

void add_medicine(medicine *m, int *n) {
    printf("Enter the name of the medicine: ");
    scanf("%s", m[*n].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &m[*n].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &m[*n].price);
    (*n)++;
}

void delete_medicine(medicine *m, int *n) {
    char name[50];
    printf("Enter the name of the medicine to be deleted: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(m[i].name, name) == 0) {
            break;
        }
    }
    if (i == *n) {
        printf("Medicine not found.\n");
    } else {
        for (int j = i; j < *n - 1; j++) {
            m[j] = m[j + 1];
        }
        (*n)--;
    }
}

void search_medicine(medicine *m, int n) {
    char name[50];
    printf("Enter the name of the medicine to be searched: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(m[i].name, name) == 0) {
            break;
        }
    }
    if (i == n) {
        printf("Medicine not found.\n");
    } else {
        printf("Medicine found:\n");
        printf("Name: %s\n", m[i].name);
        printf("Quantity: %d\n", m[i].quantity);
        printf("Price: %f\n", m[i].price);
    }
}

void display_medicines(medicine *m, int n) {
    printf("Medicines in the store:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %f\n", m[i].name, m[i].quantity, m[i].price);
    }
}

int main() {
    medicine m[100];
    int n = 0;
    int choice;
    do {
        printf("1. Add medicine\n2. Delete medicine\n3. Search medicine\n4. Display medicines\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine(m, &n);
                break;
            case 2:
                delete_medicine(m, &n);
                break;
            case 3:
                search_medicine(m, n);
                break;
            case 4:
                display_medicines(m, n);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}