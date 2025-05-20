//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include<stdio.h>
#include<string.h>

struct item{
    char name[20];
    int quantity;
    float price;
};

void showMenu(){
    printf("\n\nWelcome to the Warehouse Management System\n");
    printf("1. Add new item\n");
    printf("2. View all items\n");
    printf("3. Edit item\n");
    printf("4. Delete item\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main(){
    int choice, i, n=0;
    struct item items[100];

    do{
        showMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                //Add new item
                printf("\nEnter name: ");
                scanf("%s", items[n].name);
                printf("Enter quantity: ");
                scanf("%d", &items[n].quantity);
                printf("Enter price: ");
                scanf("%f", &items[n].price);

                printf("\nItem added successfully!\n");
                n++;
                break;

            case 2:
                //View all items
                if(n==0){
                    printf("\nNo items found!\n");
                }
                else{
                    printf("\nName\tQuantity\tPrice\n");
                    for(i=0;i<n;i++){
                        printf("%s\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
                    }
                }
                break;

            case 3:
                //Edit item
                if(n==0){
                    printf("\nNo items found!\n");
                    break;
                }
                printf("\nEnter name of item to edit: ");
                char itemName[20];
                scanf("%s", itemName);
                for(i=0;i<n;i++){
                    if(strcmp(itemName, items[i].name)==0){
                        printf("\nName\tQuantity\tPrice\n");
                        printf("%s\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
                        printf("\nEnter new details:\n");
                        printf("Name: ");
                        scanf("%s", items[i].name);
                        printf("Quantity: ");
                        scanf("%d", &items[i].quantity);
                        printf("Price: ");
                        scanf("%f", &items[i].price);
                        printf("\nItem edited successfully!\n");
                        break;
                    }
                }
                if(i==n){
                    printf("\nItem not found!\n");
                }

                break;

            case 4:
                //Delete item
                if(n==0){
                    printf("\nNo items found!\n");
                    break;
                }
                printf("\nEnter name of item to delete: ");
                char itemName2[20];
                scanf("%s", itemName2);
                for(i=0;i<n;i++){
                    if(strcmp(itemName2, items[i].name)==0){
                        break;
                    }
                }
                if(i==n){
                    printf("\nItem not found!\n");
                }
                else{
                    printf("\nName\tQuantity\tPrice\n");
                    printf("%s\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
                    if(i!=n-1){
                        items[i] = items[n-1];
                        printf("\nItem deleted successfully!\n");
                    }
                    n--;
                }
                break;

            case 5:
                //Exit
                printf("\nThank you for using our system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }

    }while(choice!=5);

    return 0;
}