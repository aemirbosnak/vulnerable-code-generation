//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char pass[20];
    printf("Enter password to access the Medical Store Management System: ");
    scanf("%s", pass);

    if(strcmp(pass, "password123") == 0){
        printf("Access granted!\n");
        printf("Welcome to the Medical Store Management System\n");
        printf("--------------------------------------------\n");

        printf("Enter the number of medicines you would like to add in the inventory: ");
        int num;
        scanf("%d", &num);

        char *med_name[num];
        int med_qty[num], med_price[num], total_profit = 0;

        for(int i=0; i<num; i++){
            char temp_name[20];
            int temp_qty, temp_price;
            printf("\nEnter details for medicine %d:\n", i+1);
            printf("Name: ");
            scanf("%s", temp_name);
            printf("Quantity: ");
            scanf("%d", &temp_qty);
            printf("Price: ");
            scanf("%d", &temp_price);

            if(temp_price < 0){
                printf("Error: Price cannot be negative. Try again.\n");
                i--; //Decrement i to enter details for this item again
                continue;
            }

            med_name[i] = (char *) malloc(sizeof(char) * strlen(temp_name));
            strcpy(med_name[i], temp_name);
            med_qty[i] = temp_qty;
            med_price[i] = temp_price;
        }

        //Displaying inventory
        printf("\nInventory:\n");
        printf("Name\tQuantity\tPrice\n");
        printf("--------------------------------\n");
        for(int i=0; i<num; i++){
            printf("%s\t%d\t%d\n", med_name[i], med_qty[i], med_price[i]);
        }

        printf("\n");

        //Order management
        printf("Enter the number of orders you would like to add: ");
        int num_orders;
        scanf("%d", &num_orders);

        int *order_qty[num_orders], total_income = 0;
        char *order_med[num_orders];

        for(int i=0; i<num_orders; i++){
            char temp_med[20];
            int temp_qty;
            printf("\nEnter details for order %d:\n", i+1);
            printf("Medicine Name: ");
            scanf("%s", temp_med);
            printf("Quantity: ");
            scanf("%d", &temp_qty);

            //Checking if medicine exists in inventory
            int found = 0;
            for(int j=0; j<num; j++){
                if(strcmp(med_name[j], temp_med) == 0){
                    found = 1;
                    if(temp_qty > med_qty[j]){
                        printf("Error: Insufficient quantity. Try again.\n");
                        i--; //Decrement i to enter details for this order again
                        break;
                    }
                    else{
                        order_med[i] = (char *) malloc(sizeof(char) * strlen(temp_med));
                        strcpy(order_med[i], temp_med);
                        med_qty[j] -= temp_qty;
                        order_qty[i] = (int *) malloc(sizeof(int));
                        *order_qty[i] = temp_qty;
                        total_income += temp_qty * med_price[j];
                        break;
                    }
                }
            }   

            if(!found){
                printf("Error: Medicine not found. Try again.\n");
                i--; //Decrement i to enter details for this order again
            }       
        }   

        //Displaying orders
        printf("\nOrders:\n");
        printf("Name\tQuantity\tIncome\n");
        printf("-------------------------\n");
        for(int i=0; i<num_orders; i++){
            printf("%s\t%d\t%d\n", order_med[i], *order_qty[i], *order_qty[i] * med_price[i]);
        }

        printf("\n");

        //Displaying total profit
        printf("Total income: %d\n", total_income);

        //Freeing memory
        for(int i=0; i<num; i++){
            free(med_name[i]);
        }
        for(int i=0; i<num_orders; i++){
            free(order_med[i]);
            free(order_qty[i]);
        }
    }

    else{
        printf("Error: Incorrect password. Access denied.\n");
    }   

    return 0;
}