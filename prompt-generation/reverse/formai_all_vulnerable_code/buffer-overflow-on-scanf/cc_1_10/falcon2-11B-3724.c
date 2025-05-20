//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_ITEMS 100
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10
#define MAX_QUANTITY_LENGTH 5
#define MAX_RECEIPT_LENGTH 100
#define MAX_CUSTOMER_NAME_LENGTH 50

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    double price;
    int quantity;
} Product;

typedef struct {
    char name[MAX_CUSTOMER_NAME_LENGTH];
    double total;
} Customer;

typedef struct {
    Product product;
    Customer customer;
} Receipt;

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    double price;
    int quantity;
} ProductData;

typedef struct {
    char name[MAX_CUSTOMER_NAME_LENGTH];
    double total;
} CustomerData;

typedef struct {
    char name[MAX_RECEIPT_LENGTH];
    ProductData productData[MAX_ITEMS];
    CustomerData customerData;
} ReceiptData;

int main() {
    ReceiptData receiptData;
    int numItems;
    printf("Enter the number of items in the receipt: ");
    scanf("%d", &numItems);
    
    for (int i = 0; i < numItems; i++) {
        printf("Enter the name of product %d: ", i + 1);
        fgets(receiptData.productData[i].name, MAX_PRODUCT_NAME_LENGTH, stdin);
        receiptData.productData[i].name[strcspn(receiptData.productData[i].name, "\n")] = '\0';
        
        printf("Enter the price of product %d: ", i + 1);
        scanf("%lf", &receiptData.productData[i].price);
        
        printf("Enter the quantity of product %d: ", i + 1);
        scanf("%d", &receiptData.productData[i].quantity);
    }
    
    printf("Enter the name of customer: ");
    fgets(receiptData.customerData.name, MAX_CUSTOMER_NAME_LENGTH, stdin);
    receiptData.customerData.name[strcspn(receiptData.customerData.name, "\n")] = '\0';
    
    printf("Enter the total amount of purchase: ");
    scanf("%lf", &receiptData.customerData.total);
    
    printf("Receipt:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Name: %s\nPrice: %.2lf\nQuantity: %d\n", receiptData.productData[i].name, receiptData.productData[i].price, receiptData.productData[i].quantity);
    }
    
    printf("Customer: %s\nTotal: %.2lf\n", receiptData.customerData.name, receiptData.customerData.total);
    
    return 0;
}