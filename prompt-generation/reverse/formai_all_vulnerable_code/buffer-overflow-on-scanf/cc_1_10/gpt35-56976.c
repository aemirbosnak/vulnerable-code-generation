//FormAI DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main(){
    int choice, i=0, amt, total=0;
    char expense[MAX][MAX];
    
    printf("Welcome to the Expense Tracker!\n");
    
    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter the expense name: ");
                scanf("%s", expense[i]);
                printf("Enter the amount: ");
                scanf("%d", &amt);
                total += amt;
                printf("Expense added successfully!\n");
                i++;
                break;
                
            case 2:
                printf("\nList of all expenses:\n");
                for(int j=0; j<i; j++){
                    printf("%d. %s - $%d\n", j+1, expense[j], amt);
                }
                break;
                
            case 3:
                printf("\nTotal expenses: $%d\n", total);
                break;
                
            case 4:
                printf("\nThank you for using the Expense Tracker!\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}