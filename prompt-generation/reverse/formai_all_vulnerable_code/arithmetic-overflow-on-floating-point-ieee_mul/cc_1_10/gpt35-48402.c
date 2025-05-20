//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: real-life
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct WarehouseInventory{
    char product_name[100];
    float product_cost_per_unit;
    int available_units;
    float total_cost;
};
struct WarehouseInventory inventory[500];
int TotalProducts;

void AddInventory(int num){
    float cost;
    int units;

    for(int i = TotalProducts; i < TotalProducts + num; i++){
        printf("\nEnter product(%d) name: ",i+1);
        scanf(" %[^\n]",inventory[i].product_name);
        printf("\nEnter product(%d) cost per unit: ",i+1);
        scanf("%f",&cost);
        printf("\nEnter number of units available for product(%d): ",i+1);
        scanf("%d",&units);

        inventory[i].product_cost_per_unit = cost;
        inventory[i].available_units = units;
        inventory[i].total_cost = cost*units;
    }
    TotalProducts += num;
}

void DisplayInventory(){
    printf("\n%-20s %-20s %-20s %-20s\n","Product Name","Cost Per Unit","Available Units","Total Cost");
    for(int i = 0; i < TotalProducts; i++){
        printf("%-20s %-20.2f %-20d %-20.2f\n",inventory[i].product_name,inventory[i].product_cost_per_unit,inventory[i].available_units,inventory[i].total_cost);
    }
}

void SearchInventory(){
    char pname[100];
    printf("\nEnter the product name: ");
    scanf(" %[^\n]",pname);
    for (int i = 0; i < TotalProducts; i++) {
        if(strcmp(inventory[i].product_name,pname)==0){
            printf("\n%-20s %-20s %-20s %-20s\n","Product Name","Cost Per Unit","Available Units","Total Cost");
            printf("%-20s %-20.2f %-20d %-20.2f\n",inventory[i].product_name,inventory[i].product_cost_per_unit,inventory[i].available_units,inventory[i].total_cost);
            return;
        }
    }
    printf("\nNo product found with the name %s\n",pname);
}

void Sale(){
    char pname[100];
    int sold_units;
    printf("\nEnter the product name: ");
    scanf(" %[^\n]",pname);
    for (int i = 0; i < TotalProducts; i++) {
        if(strcmp(inventory[i].product_name,pname)==0){
            printf("\nEnter units to be sold: ");
            scanf("%d",&sold_units);
            if(inventory[i].available_units >= sold_units){
                inventory[i].available_units -= sold_units;
                inventory[i].total_cost = inventory[i].product_cost_per_unit*inventory[i].available_units;
                printf("\nTotal cost of %d units of %s is $%.2f\n",sold_units,pname,sold_units*inventory[i].product_cost_per_unit);
                return;
            }else{
                printf("\nNot enough units available for %s\n",pname);
                return;
            }
        }
    }
    printf("\nNo product found with the name %s\n",pname);
}

int main() {
    int choice, num;
    printf("Welcome to the Warehouse Management System!\n");

    while (1) {
        printf("\nChoose:\n1. Add inventory\n2. Search inventory\n3. Display inventory\n4. Sale\n5. Quit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter number of products to be added: ");
                scanf("%d",&num);
                AddInventory(num);
                break;
            case 2:
                SearchInventory();
                break;
            case 3:
                DisplayInventory();
                break;
            case 4:
                Sale();
                break;
            case 5:
                printf("\nThank you for using the Warehouse Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}