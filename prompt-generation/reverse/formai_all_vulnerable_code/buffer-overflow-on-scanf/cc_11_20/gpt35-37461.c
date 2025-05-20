//FormAI DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include<stdio.h> //To use standard input/output functions
#include<stdlib.h> //To use the system() function
#include<string.h> //To use string-related functions

//Structure to store an expense
struct expense {
    char item[50];
    float amount;
};

int main() {
    struct expense expenses[100]; //Array to store 100 expenses
    int count = 0; //To keep track of number of expenses added
    float total_expense = 0; //To keep track of total expenses
    int choice = 0; //To store the user's choice
    char c; //To store user's confirmation choice
    int i; //Loop variable
    
    //Welcome the user
    printf("Welcome to Expense Tracker\n");
    
    //Menu loop
    while(choice != 4) {
        printf("\nCurrent number of expenses: %d\n", count);
        printf("Total expenses so far: %.2f\n", total_expense);
        printf("Choose an option:\n1. Add Expense\n2. View All Expenses\n3. Search Expense\n4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the item name: ");
                scanf("%s", &expenses[count].item);
                printf("Enter the amount: ");
                scanf("%f", &expenses[count].amount);
                
                total_expense += expenses[count].amount;
                count++;
                printf("Expense added successfully!\n");
                break;
                
            case 2:
                if(count == 0) {
                    printf("You have not added any expenses yet.\n");
                }
                else {
                    printf("All expenses:\n");
                    for(i = 0; i < count; i++) {
                        printf("%d) %s - %.2f\n", i+1, expenses[i].item, expenses[i].amount);
                    }
                }
                break;
                
            case 3:
                if(count == 0) {
                    printf("You have not added any expenses yet.\n");
                }
                else {
                    char search_item[50];
                    int found = 0;
                    printf("Enter the item name to search: ");
                    scanf("%s", &search_item);
                    
                    for(i = 0; i < count; i++) {
                        if(strcmp(expenses[i].item, search_item) == 0) {
                            printf("%s - %.2f\n", expenses[i].item, expenses[i].amount);
                            found = 1;
                        }
                    }
                    
                    if(found == 0) {
                        printf("No matching expenses found.\n");
                    }
                }
                break;
                
            case 4:
                printf("Are you sure you want to exit? (y/n) ");
                scanf("%s", &c);
                if(c == 'y' || c == 'Y') {
                    printf("Thank you for using Expense Tracker.\n");
                }
                else {
                    choice = 0;
                }
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        //Clear the screen
        system("clear");
    }
    
    //Exit the program
    return 0;
}