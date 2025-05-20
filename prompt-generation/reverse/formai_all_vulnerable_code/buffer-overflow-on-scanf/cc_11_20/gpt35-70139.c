//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
    char name[20];
    int quantity;
    float price;
    char expiry[10];
};

struct warehouse{
    char location[20];
    struct product p;
} w[10];

int main(){
    int option = 0, i = 0, count = 0;
    while(option != 4){
        printf("\n\tWELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM\n");
        printf("\n\tSelect one of the following options:\n");
        printf("\n\t1. Add a product\n");
        printf("\n\t2. View all available products\n");
        printf("\n\t3. Search for a product by name\n");
        printf("\n\t4. Exit the program\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\n\tEnter the name of the product: ");
                scanf("%s", w[i].p.name);
                printf("\n\tEnter the quantity of the product: ");
                scanf("%d", &w[i].p.quantity);
                printf("\n\tEnter the price of the product: ");
                scanf("%f", &w[i].p.price);
                printf("\n\tEnter the expiry date of the product (dd/mm/yyyy): ");
                scanf("%s", w[i].p.expiry);
                printf("\n\tEnter the location of the product: ");
                scanf("%s", w[i].location);
                i++;
                count++;
                break;
            case 2:
                if(count==0){
                    printf("\n\tNo products available in the warehouse\n");
                    break;
                }
                printf("\n\tAll products available in the warehouse are:\n");
                printf("\n\tSL.NO.\tNAME\tQUANTITY\tPRICE\tEXPIRY\tLOCATION\n");
                for(int j=0;j<count;j++){
                    printf("\n\t%d\t%s\t%d\t%.2f\t%s\t%s\n", j+1, w[j].p.name, w[j].p.quantity, w[j].p.price, w[j].p.expiry, w[j].location);
                }
                break;
            case 3:
                if(count==0){
                    printf("\n\tNo products available in the warehouse\n");
                    break;
                }
                char search_name[20];
                printf("\n\tEnter the name of the product to search for: ");
                scanf("%s", search_name);
                int found = 0;
                for(int j=0;j<count;j++){
                    if(strcmp(search_name, w[j].p.name)==0){
                        printf("\n\tProduct found:\n");
                        printf("\n\tNAME\tQUANTITY\tPRICE\tEXPIRY\tLOCATION\n");
                        printf("\n\t%s\t%d\t%.2f\t%s\t%s\n", w[j].p.name, w[j].p.quantity, w[j].p.price, w[j].p.expiry, w[j].location);
                        found = 1;
                    }
                }
                if(found==0){
                    printf("\n\tProduct not found\n");
                }
                break;
            case 4:
                printf("\n\tExiting the program.....\n");
                break;
            default:
                printf("\n\tInvalid choice entered. Try again.....\n");
        }
    }
    return 0;
}