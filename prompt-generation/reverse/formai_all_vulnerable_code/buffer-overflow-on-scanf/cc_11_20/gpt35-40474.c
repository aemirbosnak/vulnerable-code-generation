//FormAI DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
    char name[20];
    int quantity;
    float price;
};

struct product store[100];

int main(){
    int choice, count=0;

    while(1){   //Loop till user doesn't exit
        printf("\nProduct Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Delete a product\n");
        printf("3. Display all products\n");
        printf("4. Search a product\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(count==100){
                    printf("Inventory Full!");
                    break;
                }
                printf("Enter product name: ");
                scanf("%s", &store[count].name);
                printf("Enter product quantity: ");
                scanf("%d", &store[count].quantity);
                printf("Enter product price: ");
                scanf("%f", &store[count].price);
                count++;
                break;
            case 2:
                if(count==0){
                    printf("Inventory Empty!");
                    break;
                }
                char temp[20];
                printf("Enter product name: ");
                scanf("%s", &temp);
                int i, flag=0;
                for(i=0;i<count;i++){
                    if(strcmp(store[i].name, temp)==0){
                        for(int j=i;j<count-1;j++){
                            strcpy(store[j].name, store[j+1].name);
                            store[j].quantity = store[j+1].quantity;
                            store[j].price = store[j+1].price;
                        }
                        count--;
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                    printf("Product not found!");
                else
                    printf("Product deleted successfully!");
                break;
            case 3:
                printf("\nName\tQuantity\tPrice\n");
                for(i=0;i<count;i++)
                    printf("%s\t%d\t\t%.2f\n", store[i].name, store[i].quantity, store[i].price);
                break;
            case 4:
                if(count==0){
                    printf("Inventory Empty!");
                    break;
                }
                printf("Enter product name: ");
                scanf("%s", &temp);
                flag = 0;
                for(i=0;i<count;i++){
                    if(strcmp(store[i].name, temp)==0){
                        printf("\nName\tQuantity\tPrice\n");
                        printf("%s\t%d\t\t%.2f\n", store[i].name, store[i].quantity, store[i].price);
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                    printf("Product not found!");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}