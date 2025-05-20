//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
    int product_id;
    char product_name[25];
    float product_price;
};
  
struct warehouse{
    char warehouse_name[25];
    struct product products[25];
    int product_count;
};

int main(){
    struct warehouse warehouses[5];
    int warehouse_count = 0;
    int choice;
    char temp[25];
    int flag = 0;
    int warehouse_index;
    int product_index;

    while(1){
        printf("\n\n==== WAREHOUSE MANAGEMENT SYSTEM ====\n");
        printf("1. Add warehouse\n");
        printf("2. Add product to warehouse\n");
        printf("3. Show all warehouses\n");
        printf("4. Search a warehouse\n");
        printf("5. Search a product in a warehouse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nWarehouse Name: ");
                fflush(stdin);
                fgets(temp, 25, stdin);
                temp[strlen(temp) - 1] = '\0';

                for(int i=0; i<warehouse_count; i++){
                    if(strcmp(temp, warehouses[i].warehouse_name) == 0){
                        printf("\nWarehouse already exists!\n");
                        flag = 1;
                        break;
                    }
                }

                if(flag){
                    flag = 0;
                    break;
                }
              
                strcpy(warehouses[warehouse_count].warehouse_name, temp);
                warehouses[warehouse_count].product_count = 0;

                printf("\nWarehouse added successfully!\n");
                warehouse_count++;
                break;

            case 2:
                printf("\nWarehouse Name: ");
                fflush(stdin);
                fgets(temp, 25, stdin);
                temp[strlen(temp) - 1] = '\0';

                for(int i=0; i<warehouse_count; i++){
                    if(strcmp(temp, warehouses[i].warehouse_name) == 0){
                        warehouse_index = i;
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    printf("\nWarehouse not found!\n");
                    break;
                }

                struct product prod;
                printf("\nEnter Product ID: ");
                scanf("%d", &prod.product_id);
                printf("\nEnter Product Name: ");
                fflush(stdin);
                fgets(prod.product_name, 25, stdin);
                prod.product_name[strlen(prod.product_name) - 1] = '\0';
                printf("\nEnter Product Price: ");
                scanf("%f", &prod.product_price);

                warehouses[warehouse_index].product_count++;
                product_index = warehouses[warehouse_index].product_count;
                warehouses[warehouse_index].products[product_index] = prod;

                printf("\nProduct added successfully to warehouse %s!\n", temp);
                break;

            case 3:
                printf("\n\n==== Warehouse Details ====\n");
                for(int i=0; i<warehouse_count; i++){
                    printf("\nWarehouse Name: %s\n", warehouses[i].warehouse_name);
                    printf("Number of Products: %d\n", warehouses[i].product_count);

                    if(warehouses[i].product_count == 0){
                        printf("No products found in this warehouse.\n");
                    }
                    else{
                        printf("\tProduct ID\tProduct Name\tProduct Price\n");
                        for(int j=1; j<=warehouses[i].product_count; j++){
                            printf("\t%d\t\t%s\t%.2f\n", warehouses[i].products[j].product_id, warehouses[i].products[j].product_name, warehouses[i].products[j].product_price);
                        }
                    }
              }
              break;

            case 4:
                printf("\nEnter Warehouse Name: ");
                fflush(stdin);
                fgets(temp, 25, stdin);
                temp[strlen(temp) - 1] = '\0';

                for(int i=0; i<warehouse_count; i++){
                    if(strcmp(temp, warehouses[i].warehouse_name) == 0){
                        printf("\nWarehouse Name: %s\n", warehouses[i].warehouse_name);
                        printf("Number of Products: %d\n", warehouses[i].product_count);

                        if(warehouses[i].product_count == 0){
                            printf("No products found in this warehouse.\n");
                        }
                        else{
                            printf("\tProduct ID\tProduct Name\tProduct Price\n");
                            for(int j=1; j<=warehouses[i].product_count; j++){
                                printf("\t%d\t\t%s\t%.2f\n", warehouses[i].products[j].product_id, warehouses[i].products[j].product_name, warehouses[i].products[j].product_price);
                            }
                        }
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    printf("\nWarehouse not found!\n");
                    break;
                }
                break;

            case 5:
                printf("\nEnter Warehouse Name: ");
                fflush(stdin);
                fgets(temp, 25, stdin);
                temp[strlen(temp) - 1] = '\0';

                for(int i=0; i<warehouse_count; i++){
                    if(strcmp(temp, warehouses[i].warehouse_name) == 0){
                        printf("\nEnter Product ID: ");
                        int p_id;
                        scanf("%d", &p_id);

                        for(int j=1; j<=warehouses[i].product_count; j++){
                            if(p_id == warehouses[i].products[j].product_id){
                                printf("\tProduct ID\tProduct Name\tProduct Price\n");
                                printf("\t%d\t\t%s\t%.2f\n", warehouses[i].products[j].product_id, warehouses[i].products[j].product_name, warehouses[i].products[j].product_price);
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 0){
                            printf("\nProduct not found in this warehouse!\n");
                        }
                        flag = 0;
                        break;
                    }
                }

                if(flag == 0){
                    printf("\nWarehouse not found!\n");
                    break;
                }
                break;

            case 6:
                printf("\nExiting Warehouse Management System...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid Choice. Please Try Again!\n");
                break;
        }
    }
    return 0;
}