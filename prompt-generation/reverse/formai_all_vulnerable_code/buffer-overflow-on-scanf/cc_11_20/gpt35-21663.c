//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
struct item{
    int id;
    char name[20];
    int quantity;
};
typedef struct item Item;

int main(){
    int choice, i, j, id, add, remove;
    printf("Welcome to the Warehouse Management System!\n");

    Item items[50];
    int index = 0;

    do{
        printf("\nWhat option would you like to perform?\n");
        printf("1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. Display all items\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the ID of the item you would like to add: ");
                scanf("%d", &id);

                for(i=0; i<index; i++){
                    if(items[i].id == id){
                        printf("Item with this ID already exists. Please choose a different ID.\n");
                        break;
                    }
                }

                if(i==index){
                    items[index].id = id;
                    printf("Enter the name of the item: ");
                    scanf("%s", items[index].name);
                    printf("Enter the quantity of the item: ");
                    scanf("%d", &items[index].quantity);
                    index++;
                    printf("Item has been added.\n");
                }

                break;

            case 2:
                printf("Enter the ID of the item you would like to remove: ");
                scanf("%d", &id);

                for(i=0; i<index; i++){
                    if(items[i].id == id){
                        break;
                    }
                }

                if(i==index){
                    printf("Item with this ID doesn't exist.\n");
                }
                else{
                    for(j=i; j<index-1; j++){
                        items[j] = items[j+1];
                    }
                    index--;
                    printf("Item has been removed.\n");
                }

                break;

            case 3:
                printf("ID\tName\t\tQuantity\n");
                for(i=0; i<index; i++){
                    printf("%d\t%s\t\t%d\n", items[i].id, items[i].name, items[i].quantity);
                }
                break;

            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    }while(choice!=4);

    return 0;
}