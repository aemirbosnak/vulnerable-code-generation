//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include<stdio.h>
#include<stdlib.h>

//declare global variables
int inventory[5][5];
int total_items=0;

//function to display menu
void menu(){
    printf("\n\n>>> WAREHOUSE MANAGEMENT SYSTEM <<<\n");
    printf("\n1. View inventory");
    printf("\n2. Add item");
    printf("\n3. Remove item");
    printf("\n4. Search inventory");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
}

//function to view inventory
void view_inventory(){
    printf("\n\n>>> INVENTORY <<<\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d  ",inventory[i][j]);
        }
        printf("\n");
    }
}

//function to add item to inventory
void add_item(){
    int row,col,num;
    printf("\nEnter row (0-4): ");
    scanf("%d",&row);
    printf("Enter col (0-4): ");
    scanf("%d",&col);
    printf("Enter number of items (max. 99): ");
    scanf("%d",&num);
    total_items+=num;
    inventory[row][col]+=num;
}

//function to remove item from inventory
void remove_item(){
    int row,col,num;
    printf("\nEnter row (0-4): ");
    scanf("%d",&row);
    printf("Enter col (0-4): ");
    scanf("%d",&col);
    printf("Enter number of items to remove (max. %d): ",inventory[row][col]);
    scanf("%d",&num);
    total_items-=num;
    inventory[row][col]-=num;
}

//function to search inventory
void search_inventory(){
    int item,flag=0;
    printf("\nEnter item number to search: ");
    scanf("%d",&item);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(inventory[i][j]==item){
                printf("\nItem found at row %d, col %d",i,j);
                flag=1;
            }
        }
    }
    if(flag==0){
        printf("\nItem not found in inventory!");
    }
}

//main function
int main(){
    int choice;
    //initialize inventory
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            inventory[i][j]=0;
        }
    }
    //display menu and get user input
    while(1){
        menu();
        scanf("%d",&choice);
        switch(choice){
            case 1: view_inventory();
                    printf("\nTotal items in inventory: %d",total_items);
                    break;
            case 2: add_item();
                    break;
            case 3: remove_item();
                    break;
            case 4: search_inventory();
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
    return 0;
}