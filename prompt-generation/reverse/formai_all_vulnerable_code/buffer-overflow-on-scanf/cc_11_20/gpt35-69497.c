//FormAI DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

//define the structure of product
struct product{
    int pid;
    char pname[50];
    float price;
    int qty;
}p[100];

int main(){
    int choice, i, n, id, index;
    printf("Enter the number of products: ");
    scanf("%d", &n);

    //enter details of products
    printf("\nEnter the product details:\n");
    for(i=0;i<n;i++){
        p[i].pid = i+1;
        printf("Enter name of product %d: ", i+1);
        scanf("%s", p[i].pname);
        printf("Enter price of product %d: ", i+1);
        scanf("%f", &p[i].price);
        printf("Enter quantity of product %d: ", i+1);
        scanf("%d", &p[i].qty);
    }

    //menu driven code
    do{
        printf("\n\n===============PRODUCT INVENTORY SYSTEM===============");
        printf("\n\n1. Display all products\n2. Display a product\n3. Add a product\n4. Update a product\n5. Delete a product\n6. Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n\n\t\tALL PRODUCTS\n\n");
                printf("ID\tPRODUCT NAME\tPRICE\tQUANTITY\n");

                for(i=0;i<n;i++){
                    printf("%d\t%s\t\t%.2f\t%d\n", p[i].pid, p[i].pname, p[i].price, p[i].qty);
                }
                break;

            case 2:
                printf("\n\n\t\tDISPLAY A PRODUCT\n\n");
                printf("Enter id of product: ");
                scanf("%d", &id);

                for(i=0;i<n;i++){
                    if(p[i].pid == id){
                        index = i;
                        break;
                    }
                }

                printf("ID\tPRODUCT NAME\tPRICE\tQUANTITY\n");
                printf("%d\t%s\t\t%.2f\t%d\n", p[index].pid, p[index].pname, p[index].price, p[index].qty);
                break;

            case 3:
                printf("\n\n\t\tADD A PRODUCT\n\n");
                printf("Enter name of product: ");
                scanf("%s", p[n].pname);
                printf("Enter price of product: ");
                scanf("%f", &p[n].price);
                printf("Enter quantity of product: ");
                scanf("%d", &p[n].qty);
                p[n].pid = n+1;

                printf("\nNew Product added successfully!\n");
                n++;
                break;

            case 4:
                printf("\n\n\t\tUPDATE A PRODUCT\n\n");
                printf("Enter id of product to update: ");
                scanf("%d", &id);

                for(i=0;i<n;i++){
                    if(p[i].pid == id){
                        index = i;
                        break;
                    }
                }
                printf("Enter new details:\n");
                printf("Enter name of product: ");
                scanf("%s", p[index].pname);
                printf("Enter price of product: ");
                scanf("%f", &p[index].price);
                printf("Enter quantity of product: ");
                scanf("%d", &p[index].qty);

                printf("\nProduct updated successfully!\n");
                break;

            case 5:
                printf("\n\n\t\tDELETE A PRODUCT\n\n");
                printf("Enter id of product to delete: ");
                scanf("%d", &id);

                for(i=0;i<n;i++){
                    if(p[i].pid == id){
                        index = i;
                        break;
                    }
                }
                for(i=index;i<n-1;i++){
                    p[i] = p[i+1];
                }
                n--;
                printf("\nProduct deleted successfully!\n");
                break;

            case 6:
                printf("\n\n\t\tTHANK YOU FOR USING PRODUCT INVENTORY SYSTEM!!\n");
                break;

            default:
                printf("\n\nInvalid Option! Please enter a valid option.\n");
                break;
        }
    }while(choice!=6);
    return 0;
}