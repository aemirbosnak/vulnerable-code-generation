//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include<stdio.h>
#include<string.h>

//Structure definition for storing the item information
struct item{
    char name[50];      //Name of the item
    int id;             //ID number of the item
    int quantity;       //Quantity of the item
    float price;        //Price of the item
};

int main(){
    int choice=0, num_items=0, i=0;
    struct item itemList[50];   //Array of structures to store the items
    
    //Loop to display the menu and get user input
    while(1){
        printf("\n\nWarehouse Management System\n");
        printf("\n1. Add Item\n2. Update Item\n3. Delete Item\n4. List all Items\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        //Switch case for different menu options
        switch(choice){
            case 1:     //Add Item
                printf("\nEnter the details of the item:\n");
                printf("Name: ");
                scanf("%s", itemList[num_items].name);
                printf("ID Number: ");
                scanf("%d", &itemList[num_items].id);
                printf("Quantity: ");
                scanf("%d", &itemList[num_items].quantity);
                printf("Price: ");
                scanf("%f", &itemList[num_items].price);
                num_items++;
                break;
            case 2:     //Update Item
                printf("\nEnter the ID number of the item to update: ");
                int idToUpdate;
                scanf("%d", &idToUpdate);
                for(i=0;i<num_items;i++){
                    if(itemList[i].id==idToUpdate){
                        printf("\nEnter the new details of the item:\n");
                        printf("Name: ");
                        scanf("%s", itemList[i].name);
                        printf("Quantity: ");
                        scanf("%d", &itemList[i].quantity);
                        printf("Price: ");
                        scanf("%f", &itemList[i].price);
                        break;
                    }
                }
                if(i==num_items){
                    printf("\nItem with ID number %d not found!", idToUpdate);
                }
                break;
            case 3:     //Delete Item
                printf("\nEnter the ID number of the item to delete: ");
                int idToDelete;
                scanf("%d", &idToDelete);
                i=0;
                while(i<num_items){
                    if(itemList[i].id==idToDelete){
                        break;
                    }
                    i++;
                }
                if(i==num_items){
                    printf("\nItem with ID number %d not found!", idToDelete);
                    break;
                }
                while(i<num_items-1){
                    itemList[i]=itemList[i+1];
                    i++;
                }
                num_items--;
                printf("\nItem with ID number %d deleted successfully!", idToDelete);
                break;
            case 4:     //List all Items
                if(num_items==0){
                    printf("\nNo items found in the warehouse!");
                    break;
                }
                printf("\nList of all items:\n");
                for(i=0;i<num_items;i++){
                    printf("%d. Name: %s, ID Number: %d, Quantity: %d, Price: %0.2f\n", i+1, itemList[i].name, itemList[i].id, itemList[i].quantity, itemList[i].price);
                }
                break;
            case 5:     //Exit
                printf("\nExiting Warehouse Management System... Bye!");
                return 0;
            default:    //Invalid menu option
                printf("\nInvalid choice! Please select a valid choice.");
        }
    }
}