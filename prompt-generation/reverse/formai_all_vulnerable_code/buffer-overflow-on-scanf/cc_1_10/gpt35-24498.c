//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10

int inventory[MAX_SIZE]; //Declare inventory array to keep track of items
char items[MAX_SIZE][20]; //Declare a 2D array to store the name of items
int top = -1; //Initialize top of stack to -1
int choice, item, quantity, i;

void push(int item){ //Function to add an item to inventory
    if(top == MAX_SIZE-1){ //Check if inventory is full
        printf("Warehouse is full! Cannot add more items.\n");
    }
    else{ //Add item to inventory and update top of stack
        top++;
        inventory[top] = item;
        printf("%s added to the warehouse inventory.\n", items[item]);
    }
}

void pop(){ //Function to remove an item from inventory
    if(top == -1){ //Check if inventory is empty
        printf("Warehouse is empty! Cannot remove any item.\n");
    }
    else{ //Remove item from inventory and update top of stack
        printf("%s removed from the warehouse inventory.\n", items[inventory[top]]);
        top--;
    }
}

void display(){ //Function to display the current inventory
    printf("Current inventory:\n");
    for(i=top; i>=0; i--){
        printf("%s\n", items[inventory[i]]);
    }
}

int main(){
    //Initialize items array with some sample items
    strcpy(items[0], "Pencil");
    strcpy(items[1], "Pen");
    strcpy(items[2], "Eraser");
    strcpy(items[3], "Sharpener");
    strcpy(items[4], "Notebook");

    while(1){ //Loop to display main menu and get user's choice
        printf("\nWarehouse Management System\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Display current inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){ //Switch case to perform user's chosen action
            case 1:
                printf("\nEnter item code (0-Pencil, 1-Pen, 2-Eraser, 3-Sharpener, 4-Notebook): ");
                scanf("%d", &item);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                for(i=0; i<quantity; i++){
                    push(item); //Add the item to inventory 'quantity' number of times
                }
                break;
            case 2:
                pop(); //Remove the top item from inventory
                break;
            case 3:
                display(); //Display the current inventory
                break;
            case 4:
                printf("\nExiting the program...\n");
                exit(0); //Exit the program
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}