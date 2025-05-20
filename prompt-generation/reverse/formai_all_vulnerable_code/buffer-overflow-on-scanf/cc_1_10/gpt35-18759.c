//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
//Cyberpunk Digital Auction System

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Global Variables
int itemNumber = 0;
float bidAmount = 0;
char itemName[20];

//Functions
void addItem();
void placeBid();

//Main Function
int main(){
    printf("\n\n\033[1;36mWelcome to Cyberpunk Digital Auction System!\n\n\033[0m");
    int choice;
    printf("\033[1;31m---- Menu ----\033[0m\n");
    printf("1. Add Item\n2. Place Bid\n3. Exit\n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addItem(); break;
            case 2: placeBid(); break;
            case 3: exit(1);
            default: printf("\033[1;31mInvalid input!\033[0m\n");  
        }
    }
    
    return 0;
}

void addItem(){
    itemNumber++;
    printf("\n\n\033[1;32mItem %d\n\033[0m",itemNumber);
    printf("Enter item name: ");
    scanf("%s",itemName);
    printf("Item %d added successfully!\n",itemNumber);
}

void placeBid(){
    if(itemNumber == 0){
        printf("\n\n\033[1;31mNo items added yet!\033[0m\n");
        return;
    }
    printf("\nEnter item number to bid: ");
    int in;
    scanf("%d",&in);
    if(in<1 || in>itemNumber){
        printf("\n\n\033[1;31mInvalid item number!\033[0m\n\n");
        return;
    }
    printf("\n\n\033[1;36m%s\n\033[0m",itemName);
    printf("\nEnter bid amount: ");
    scanf("%f",&bidAmount);
    srand(time(0));
    int random = rand()%10 + 1;
    if(random>=6){
        printf("\033[1;32m\nCongratulations! Your bid for %s with amount %.2f won!\n\033[0m",itemName,bidAmount);
    }
    else{
        printf("\033[1;31m\nSorry, your bid for %s with amount %.2f did not win. Better luck next time!\n\033[0m",itemName,bidAmount);
    }
}