//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

struct item{
    int id;
    char name[20];
    int quantity;
    float price;
};

void add_item(struct item [], int);
void display_items(struct item [], int);
void delete_item(struct item [], int);

int main(){
    int choice, num_items=0;
    struct item items[50];

    do{
        printf("\nWelcome to the Warehouse Management System!\n");
        printf("Enter your choice:\n");
        printf("1. Add new item\n");
        printf("2. Display all items\n");
        printf("3. Delete item\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_item(items, num_items);
                num_items++;
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                delete_item(items, num_items);
                num_items--;
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input, please try again\n");
                break;
        }
    } while(choice!=4);

    return 0;
}

void add_item(struct item items[], int num_items){
    printf("Enter item ID: ");
    scanf("%d", &items[num_items].id);

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    printf("Item added successfully!\n");
}

void display_items(struct item items[], int num_items){
    if(num_items==0){
        printf("No items in warehouse\n");
        return;
    }

    printf("Item\tID\tQuantity\tPrice\n");

    for(int i=0; i<num_items; i++){
        printf("%d\t%s\t%d\t%.2f\n", i+1, items[i].name, items[i].quantity, items[i].price);
    }
}

void delete_item(struct item items[], int num_items){
    int id, index=-1;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    for(int i=0; i<num_items; i++){
        if(items[i].id==id){
            index=i;
            break;
        }
    }

    if(index==-1){
        printf("Item with ID %d not found\n", id);
    } else{
        for(int i=index; i<num_items-1; i++){
            items[i]=items[i+1];
        }
        printf("Item with ID %d deleted successfully!\n", id);
    }
}