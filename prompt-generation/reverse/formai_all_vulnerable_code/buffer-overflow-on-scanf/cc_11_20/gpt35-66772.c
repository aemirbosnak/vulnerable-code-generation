//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include<stdio.h>
#include<string.h>

/* This program helps in maintaining a daily expense list of a person. It stores the information about the expense 
   category, amount and date. The program calculates the total amount spent on each category and also outputs the 
   daily and monthly expense report of the person. */

int main() {
    // Declare variables
    char category[20];
    float amount;
    int day, month, year;
    int choice, i, j, flag, count = 0;
    float total = 0;
    float grocery_total = 0, fuel_total = 0, entertainment_total = 0, travel_total = 0;
    float daily_total = 0, monthly_total = 0;
    
    // Welcome message
    printf("Welcome to the Expense Tracker Program!\n\n");
    
    // Main menu
    do {
        printf("Please choose from the following options:\n");
        printf("1. Add an expense\n");
        printf("2. View daily expenses\n");
        printf("3. View monthly expenses\n");
        printf("4. View expense by category\n");
        printf("5. Exit\n\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Add an expense
                printf("\nEnter details of the expense:\n");
                printf("Category: ");
                scanf("%s", category);
                printf("Amount: ");
                scanf("%f", &amount);
                printf("Date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                
                // Calculate daily and monthly expenses
                daily_total += amount;
                monthly_total += amount;
                
                // Calculate category-wise expenses
                if(strcmp(category, "grocery") == 0) {
                    grocery_total += amount;
                }
                else if(strcmp(category, "fuel") == 0) {
                    fuel_total += amount;
                }
                else if(strcmp(category, "entertainment") == 0) {
                    entertainment_total += amount;
                }
                else if(strcmp(category, "travel") == 0) {
                    travel_total += amount;
                }
                
                printf("\nExpense added successfully!\n\n");
                count++;
                break;
            
            case 2: // View daily expenses
                printf("\nTotal expenses for today: %.2f\n\n", daily_total);
                break;
            
            case 3: // View monthly expenses
                printf("\nTotal expenses for this month: %.2f\n\n", monthly_total);
                break;
                
            case 4: // View expense by category
                printf("\nWhich category would you like to view?\n");
                printf("1. Grocery\n");
                printf("2. Fuel\n");
                printf("3. Entertainment\n");
                printf("4. Travel\n\n");
                printf("Your choice: ");
                scanf("%d", &choice);
                
                switch(choice) {
                    case 1:
                        printf("\nTotal expenses on groceries: %.2f\n\n", grocery_total);
                        break;
                    
                    case 2:
                        printf("\nTotal expenses on fuel: %.2f\n\n", fuel_total);
                        break;
                        
                    case 3:
                        printf("\nTotal expenses on entertainment: %.2f\n\n", entertainment_total);
                        break;
                        
                    case 4:
                        printf("\nTotal expenses on travel: %.2f\n\n", travel_total);
                        break;
                    
                    default:
                        printf("\nError: Invalid input\n\n");
                        break;
                }
                break;
                
            case 5: // Exit
                printf("\nThank you for using the Expense Tracker program!\n\n");
                break;
            
            default:
                printf("\nError: Invalid input\n\n");
                break;
        }
    } while(choice != 5); // Main loop ends here
    
    return 0;
}