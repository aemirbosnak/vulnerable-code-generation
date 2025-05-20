//FormAI DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>  
#define MAX_SIZE 100  
  
int main()  
{
  //Declare variables
    int choice, n = 0;  
    int code[MAX_SIZE], stock[MAX_SIZE], i;  
    float price[MAX_SIZE];  
    char name[MAX_SIZE][30], category[MAX_SIZE][20];
  
    printf("\n===== PRODUCT INVENTORY SYSTEM =====\n");
    do {
        //Display menu
        printf("\n1. Add a new product\n");
        printf("2. Update stock of a product\n");
        printf("3. Search a product by code\n");
        printf("4. Display all products by category\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");
      
        //Get user input for choice 
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {  
            case 1:
                printf("\nEnter product code: ");
                scanf("%d", &code[n]);

                printf("Enter product name: ");
                scanf("%s",name[n]);

                printf("Enter product category: ");
                scanf("%s",category[n]);

                printf("Enter product stock: ");
                scanf("%d", &stock[n]);

                printf("Enter product price: ");
                scanf("%f", &price[n]);
              
                printf("\nProduct successfully added!\n");
              
                n++;
                break;

            case 2:
                printf("\nEnter product code: ");
                scanf("%d", &choice);
              
                for (i = 0; i < n; i++) {
                    if (choice == code[i]) {
                        printf("Enter new stock: ");
                        scanf("%d", &stock[i]);
                        printf("\nStock updated successfully!\n");
                    }
                }
              
                if (i == n) {
                    printf("\nProduct not found!\n");
                }
              
                break;

            case 3:          
                printf("\nEnter product code: ");
                scanf("%d", &choice);
              
                for (i = 0; i < n; i++) {
                    if (choice == code[i]) {
                        printf("\nCode: %d\n", code[i]);
                        printf("Name: %s\n", name[i]);
                        printf("Category: %s\n", category[i]);
                        printf("Stock: %d\n", stock[i]);
                        printf("Price: %.2f\n", price[i]);
                        break;                     
                    }
                }
              
                if (i == n) {
                    printf("\nProduct not found!\n");
                }
              
                break;

            case 4:
                printf("\nEnter category to search: ");
                scanf("%s", category[0]);

                for (i = 0; i < n; i++) {
                    if (strcmp(category[0], category[i]) == 0) {
                        printf("\nCode: %d\n", code[i]);
                        printf("Name: %s\n", name[i]);
                        printf("Category: %s\n", category[i]);
                        printf("Stock: %d\n", stock[i]);
                        printf("Price: %.2f\n", price[i]);
                        printf("--------------------\n");
                    }   
                }

                break;

            case 5:
                printf("\nPRODUCT LIST\n");
                printf("--------------------------\n");
                printf("Code  Name              Category  Stock  Price\n");
                printf("--------------------------\n");
                for (i = 0; i < n; i++) {
                  printf("%-5d %-15s %-10s %-5d  $ %-6.2f\n", code[i], name[i], category[i], stock[i], price[i]);
                }
                printf("--------------------------\n");
              
                break;

            default:
                printf("Invalid choice!\n");
        }
      
    } while (choice != 6); 
  
    printf("\nThank you for using the Product Inventory System!\n\n");
  
    return 0;  
}