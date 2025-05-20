//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ITEM_MAX 1000
#define NAME_LEN 50

struct Item{
    char name[NAME_LEN];
    int quantity;
};

int main(){
    struct Item items[ITEM_MAX];
    int itemCount = 0;

    char selection;
    do{
        printf("\n----------------------");
        printf("\n Warehouse Management System");
        printf("\n----------------------\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View inventory\n");
        printf("4. Exit\n");
        printf("----------------------\n");
        printf("Enter your selection: ");
        scanf(" %c", &selection);

        switch(selection){
            case '1': //Add item
                if(itemCount < ITEM_MAX){
                    printf("\nEnter name of item: ");
                    scanf("%s", items[itemCount].name);

                    printf("Enter quantity: ");
                    scanf("%d", &items[itemCount].quantity);

                    printf("\nAdded %d %s.",items[itemCount].quantity, items[itemCount].name);

                    itemCount++;
                }
                else{
                    printf("\nInventory is full. Remove some items to add new ones.");
                }
                break;

            case '2': //Remove item
                if(itemCount > 0){
                    printf("\nEnter name of item to remove: ");
                    char itemName[NAME_LEN];
                    scanf("%s", itemName);

                    int itemIndex = -1;
                    for(int i=0; i<itemCount; i++){
                        if(strcmp(itemName, items[i].name) == 0){
                            itemIndex = i;
                            break;
                        }
                    }

                    if(itemIndex == -1){
                        printf("\nItem not found.");
                    }
                    else{
                        printf("\nRemoved %d %s.",items[itemIndex].quantity, items[itemIndex].name);

                        for(int i=itemIndex; i<itemCount-1; i++){
                            strcpy(items[i].name, items[i+1].name);
                            items[i].quantity = items[i+1].quantity;
                        }

                        itemCount--;
                    }
                }
                else{
                    printf("\nInventory is empty. Nothing to remove.");
                }
                break;

            case '3': //View inventory
                printf("\nItems in inventory: ");

                if(itemCount == 0){
                    printf("None");
                }
                else{
                    for(int i=0; i<itemCount; i++){
                        printf("\n%d %s", items[i].quantity, items[i].name);
                    }
                }
                break;

            case '4': //Exit
                printf("\nExiting Warehouse Management System.");
                break;

            default:
                printf("\nInvalid selection. Please try again.");
        }

    }while(selection != '4');

    return 0;
}