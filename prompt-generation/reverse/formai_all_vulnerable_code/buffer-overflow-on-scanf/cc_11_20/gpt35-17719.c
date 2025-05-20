//FormAI DATASET v1.0 Category: Stock market tracker ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX_STOCKS 10

typedef struct {
    char symbol[10];
    float price;
} Stock;

int main() {
    Stock stock_list[MAX_STOCKS];
    int n = 0;

    while (1) {
        printf("\nStock Tracker\n");
        printf("1. Add stock\n");
        printf("2. Delete stock\n");
        printf("3. Update prices\n");
        printf("4. View all stocks\n");
        printf("5. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("\nAdding stock...\n");
                if (n == MAX_STOCKS) {
                    printf("Max limit reached, cannot add more stocks.\n");
                    break;
                }
                printf("Enter stock symbol: ");
                scanf("%s", stock_list[n].symbol);
                printf("Enter price: ");
                scanf("%f", &stock_list[n].price);
                n++;
                printf("Stock added successfully.\n");
                break;
            }

            case 2: {
                printf("\nDeleting stock...\n");
                if (n == 0) {
                    printf("List is empty, cannot delete stock.\n");
                    break;
                }
                printf("Enter stock symbol: ");
                char symbol[10];
                scanf("%s", symbol);
                int i, j;
                for (i = 0; i < n; i++) {
                    if(strcmp(symbol, stock_list[i].symbol) == 0) {
                        for (j = i; j < n - 1; j++) {
                            stock_list[j] = stock_list[j + 1];
                        }
                        n--;
                        printf("Stock deleted successfully.\n");
                        break;
                    }
                }
                if (i == n) {
                    printf("Stock not found.\n");
                }
                break;
            }

            case 3: {
                printf("\nUpdating prices...\n");
                if (n == 0) {
                    printf("List is empty, cannot update prices.\n");
                    break;
                }
                for (int i = 0; i < n; i++) {
                    printf("Enter new price for %s: ", stock_list[i].symbol);
                    scanf("%f", &stock_list[i].price);
                }
                printf("Prices updated successfully.\n");
                break;
            }

            case 4: {
                printf("\nAll stocks:\n");
                printf("Symbol\tPrice\n");
                for (int i = 0; i < n; i++) {
                    printf("%s\t%.2f\n", stock_list[i].symbol, stock_list[i].price);
                }
                break;
            }

            case 5: {
                exit(0);
            }

            default: {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    }

    return 0;
}