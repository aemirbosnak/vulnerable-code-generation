//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

void display(Medicine *med, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %d - %.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

int main() {
    Medicine med[MAX];
    int n = 0;

    // Insert medicine
    while (1) {
        printf("Enter medicine name: ");
        scanf("%s", med[n].name);

        printf("Enter quantity: ");
        scanf("%d", &med[n].quantity);

        printf("Enter price: ");
        scanf("%f", &med[n].price);

        n++;

        // Check if user wants to continue
        char ans;
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &ans);

        if (ans == 'N') {
            break;
        }
    }

    // Display medicine
    display(med, n);

    return 0;
}