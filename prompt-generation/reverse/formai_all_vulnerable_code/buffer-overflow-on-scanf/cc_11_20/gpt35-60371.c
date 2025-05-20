//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include<stdio.h>

int main() {
    int capacity[5][2], qty[5][2], ch, prod_id, wh_id, temp_qty;
    char prod_name[20][20], wh_name[5][20];
    int i, j;
    printf("Enter the names of the 5 warehouses: ");
    for(i=0; i<5; i++) {
        scanf("%s", wh_name[i]);
    }
    printf("\nEnter the capacity and current quantity of each warehouse for each product (in pairs): ");
    for(i=0; i<5; i++) {
        printf("\nEnter the details for Warehouse %d", i+1);
        for(j=0; j<2; j++) {
            printf("\nProduct %d:", j+1);
            scanf("%d %d", &capacity[i][j], &qty[i][j]);
            printf("Enter the product name: ");
            scanf("%s", prod_name[j]);
        }
    }
    while(1) {
        printf("\nWhat would you like to do?");
        printf("\n1. Check stock");
        printf("\n2. Add stock");
        printf("\n3. Remove stock");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        if(ch==1) {
            printf("\nEnter the warehouse ID and product ID: ");
            scanf("%d %d", &wh_id, &prod_id);
            printf("The current stock of %s in Warehouse %s is %d\n", prod_name[prod_id-1], wh_name[wh_id-1], qty[wh_id-1][prod_id-1]);
        }
        else if(ch==2) {
            printf("\nEnter the warehouse ID and product ID: ");
            scanf("%d %d", &wh_id, &prod_id);
            printf("Enter the amount to add: ");
            scanf("%d", &temp_qty);
            if(qty[wh_id-1][prod_id-1] + temp_qty > capacity[wh_id-1][prod_id-1]) {
                printf("Overflow! Cannot add more than the warehouse capacity.");
            }
            else {
                qty[wh_id-1][prod_id-1] += temp_qty;
                printf("%d %s added successfully to Warehouse %s.\n", temp_qty, prod_name[prod_id-1], wh_name[wh_id-1]);
                printf("The current stock of %s in Warehouse %s is %d\n", prod_name[prod_id-1], wh_name[wh_id-1], qty[wh_id-1][prod_id-1]);
            }
        }
        else if(ch==3) {
            printf("\nEnter the warehouse ID and product ID: ");
            scanf("%d %d", &wh_id, &prod_id);
            printf("Enter the amount to remove: ");
            scanf("%d", &temp_qty);
            if(qty[wh_id-1][prod_id-1] - temp_qty < 0) {
                printf("Underflow! Cannot remove more than what is available in the warehouse.");
            }
            else {
                qty[wh_id-1][prod_id-1] -= temp_qty;
                printf("%d %s removed successfully from Warehouse %s.\n", temp_qty, prod_name[prod_id-1], wh_name[wh_id-1]);
                printf("The current stock of %s in Warehouse %s is %d\n", prod_name[prod_id-1], wh_name[wh_id-1], qty[wh_id-1][prod_id-1]);
            }
        }
        else if(ch==4) {
            printf("\nExiting the program...");
            break;
        }
        else {
            printf("\nInvalid choice! Please enter a valid choice.");
        }
    }
    return 0;
}