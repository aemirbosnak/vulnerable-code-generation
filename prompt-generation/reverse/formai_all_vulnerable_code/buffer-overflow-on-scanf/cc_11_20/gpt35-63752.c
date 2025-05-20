//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    
    printf("Welcome to Cafe Billing System\n");
    
    int choice, bill=0;
    char name[50], to_go[10];
    
    do{
        printf("\nMenu:\n1. Coffee\t\t50\n2. Tea\t\t\t30\n3. Sandwich\t\t80\n4. Pizza\t\t\t150\n5. Bill\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter quantity: ");
                int qty;
                scanf("%d", &qty);
                bill += (qty*50);
                printf("Added %d cups of coffee to the bill\n", qty);
                break;
            
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                bill += (qty*30);
                printf("Added %d cups of tea to the bill\n", qty);
                break;
            
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                bill += (qty*80);
                printf("Added %d sandwiches to the bill\n", qty);
                break;
                
            case 4:
                printf("Enter size (S/M/L): ");
                char size;
                scanf(" %c", &size);
                if(size=='S'){
                    bill += 150;
                    printf("Added Small pizza to the bill\n");
                }
                else if(size=='M'){
                    bill += 250;
                    printf("Added Medium pizza to the bill\n");
                }
                else if(size=='L'){
                    bill += 400;
                    printf("Added Large pizza to the bill\n");
                }
                else{
                    printf("Invalid option\n");
                }
                break;
            
            case 5:
                printf("Enter your name: ");
                scanf(" %[^\n]s", name);
                printf("Do you want the bill printed (yes/no)? ");
                scanf(" %[^\n]s", to_go);
                if(strcmp(to_go,"yes")==0){
                    printf("\nPrinting bill...\n");
                    printf("--------------------------------\n");
                    printf("Cafe Billing System\n");
                    printf("--------------------------------\n");
                    printf("Name: %s\n", name);
                    printf("Total bill: %d\n", bill);
                    printf("--------------------------------\n");
                }
                else{
                    printf("\nThank you for visiting. Have a nice day!\n");
                }
                break;
            
            default:
                printf("Invalid option\n");
                break;
        }
        
    }while(choice!=5);
    
    return 0;
}