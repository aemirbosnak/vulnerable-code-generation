//FormAI DATASET v1.0 Category: QR code reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_CODE_SIZE 21

typedef struct {
    char name[50];
    char code[QR_CODE_SIZE];
    int quantity;
} Product;

void printProduct(Product product) {
    printf("Name: %s\n", product.name);
    printf("Code: %s\n", product.code);
    printf("Quantity: %d\n", product.quantity);
}

void scanQRCode(char *code) {
    printf("Enter QR code: ");
    scanf("%s", code);
}

bool validateQRCode(char *code) {
    if (strlen(code) != QR_CODE_SIZE - 1) {
        printf("Invalid QR code length!\n");
        return false;
    }
    for (int i = 0; i < QR_CODE_SIZE - 1; i++) {
        if (code[i] < '0' || code[i] > '9') {
            printf("Invalid QR code format!\n");
            return false;
        }
    }
    return true;
}

void addProduct(Product *products, int *numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[*numProducts].name);

    char code[QR_CODE_SIZE];
    scanQRCode(code);
    while (!validateQRCode(code)) {
        scanQRCode(code);
    }
    strcpy(products[*numProducts].code, code);

    printf("Enter quantity: ");
    scanf("%d", &products[*numProducts].quantity);
    (*numProducts)++;

    printf("Product added successfully!\n");
}

int findProduct(Product *products, int numProducts, char *code) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}

void updateProductQuantity(Product *product) {
    int quantity;
    printf("Enter new quantity: ");
    scanf("%d", &quantity);
    product->quantity = quantity;
    printf("Quantity updated successfully!\n");
}

void removeProduct(Product *products, int *numProducts, char *code) {
    int index = findProduct(products, *numProducts, code);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }
    for (int i = index; i < *numProducts - 1; i++) {
        products[i] = products[i+1];
    }
    (*numProducts)--;
    printf("Product removed successfully!\n");
}

int main(void) {
    Product products[50];
    int numProducts = 0;

    while (true) {
        printf("1. Add product\n");
        printf("2. Update product quantity\n");
        printf("3. Remove product\n");
        printf("4. Print all products\n");
        printf("5. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                {
                    char code[QR_CODE_SIZE];
                    scanQRCode(code);
                    int index = findProduct(products, numProducts, code);
                    if (index == -1) {
                        printf("Product not found!\n");
                    } else {
                        updateProductQuantity(&products[index]);
                    }
                }
                break;
            case 3:
                {
                    char code[QR_CODE_SIZE];
                    scanQRCode(code);
                    removeProduct(products, &numProducts, code);
                }
                break;
            case 4:
                for (int i = 0; i < numProducts; i++) {
                    printProduct(products[i]);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\n");
    }

    return 0;
}