//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 1000
#define ITEM_NAME_LENGTH 30

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    int quantity;
    double price;
} Transaction;

typedef struct {
    char itemName[ITEM_NAME_LENGTH];
    int totalSales;
    double totalRevenue;
} ItemSummary;

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    ItemSummary itemSummary[MAX_TRANSACTIONS];
    int transactionCount = 0;
    int summaryCount = 0;
    double totalSales = 0.0;
    
    // Simulated data input
    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open transactions file.\n");
        return 1;
    }

    while(fscanf(file, "%[^,],%d,%lf\n", transactions[transactionCount].itemName, 
                  &transactions[transactionCount].quantity, 
                  &transactions[transactionCount].price) != EOF) {
        totalSales += transactions[transactionCount].quantity * transactions[transactionCount].price;
        transactionCount++;
        if (transactionCount >= MAX_TRANSACTIONS) break;
    }
    fclose(file);

    // Summarizing the transactions
    for (int i = 0; i < transactionCount; i++) {
        int found = 0;
        for (int j = 0; j < summaryCount; j++) {
            if (strcmp(transactions[i].itemName, itemSummary[j].itemName) == 0) {
                itemSummary[j].totalSales += transactions[i].quantity;
                itemSummary[j].totalRevenue += transactions[i].quantity * transactions[i].price;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(itemSummary[summaryCount].itemName, transactions[i].itemName);
            itemSummary[summaryCount].totalSales = transactions[i].quantity;
            itemSummary[summaryCount].totalRevenue = transactions[i].quantity * transactions[i].price;
            summaryCount++;
        }
    }

    // Displaying results
    printf("Total Sales: %.2f\n", totalSales);
    printf("Average Purchase Value: %.2f\n", totalSales / transactionCount);
    printf("\nItem Summary:\n");
    printf("%-20s %-10s %-10s\n", "Item Name", "Quantity", "Revenue");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < summaryCount; i++) {
        printf("%-20s %-10d %-10.2f\n", itemSummary[i].itemName, 
                                        itemSummary[i].totalSales, 
                                        itemSummary[i].totalRevenue);
    }

    // Finding the most popular item
    ItemSummary mostPopular = itemSummary[0];
    for (int i = 1; i < summaryCount; i++) {
        if (itemSummary[i].totalSales > mostPopular.totalSales) {
            mostPopular = itemSummary[i];
        }
    }

    printf("\nMost Popular Item:\n");
    printf("%s - %d sold\n", mostPopular.itemName, mostPopular.totalSales);

    return 0;
}