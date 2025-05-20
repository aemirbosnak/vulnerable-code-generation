//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the menu items and prices from a file
void readMenuItems(float *prices, char **items) {
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) {
        printf("Error: could not open menu.txt file\n");
        exit(1);
    }
    char line[100], buf[10];
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        int len = strlen(line);
        line[len - 1] = '\0'; // remove newline character at end of line
        int j = 0;
        while (line[j] != ',') {
            buf[j] = line[j];
            j++;
        }
        buf[j] = '\0';
        prices[i] = atof(buf);
        items[i] = malloc(sizeof(char) * (len - j));
        strcpy(items[i], line + j + 1);
        i++;
    }
    fclose(file);
}

// Function to display the menu
void displayMenu(float *prices, char **items) {
    printf("Menu:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i], prices[i]);
    }
}

// Function to calculate total cost of order
float calculateTotal(int *quantities, float *prices) {
    float total = 0.0;
    for (int i = 0; i < 10; i++) {
        total += quantities[i] * prices[i];
    }
    return total;
}

// Function to display the invoice
void displayInvoice(int *quantities, float *prices, char **items) {
    printf("Invoice:\n");
    for (int i = 0; i < 10; i++) {
        if (quantities[i] > 0) {
            printf("%d x %s - $%.2f\n", quantities[i], items[i], prices[i] * quantities[i]);
        }
    }
    printf("Total: $%.2f\n", calculateTotal(quantities, prices));
}

int main() {
    float prices[10];
    char *items[10];
    readMenuItems(prices, items); // read menu items and prices from file
    int quantities[10] = {0}; // initialize all quantities to 0
    int choice, quantity;
    do {
        displayMenu(prices, items);
        printf("Enter choice (0 to exit): ");
        scanf("%d", &choice);
        if (choice != 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            quantities[choice - 1] += quantity;
        }
    } while (choice != 0);
    displayInvoice(quantities, prices, items);
    return 0;
}