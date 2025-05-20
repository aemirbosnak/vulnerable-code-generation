//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include<stdio.h>

// Structure definition for menu
struct Menu{
    char item_name[50];
    int item_cost;
};

// Function to display the menu
void display_menu(){
    system("clear");
    printf("\t\t\tWelcome to Cafe Menu\n\n");
    printf("Item no.\tItem Name\t\t\tCost\n\n");
    printf("1.\t\tEspresso\t\t\t100\n");
    printf("2.\t\tCappuccino\t\t\t120\n");
    printf("3.\t\tLatte\t\t\t\t130\n");
    printf("4.\t\tMocha\t\t\t\t140\n");
    printf("5.\t\tIced Tea\t\t\t90\n");
    printf("6.\t\tCold Coffee\t\t\t110\n");
    printf("7.\t\tHot Chocolate\t\t\t120\n");
    printf("8.\t\tFrench Fries\t\t\t70\n");
    printf("9.\t\tVeg Burger\t\t\t100\n");
    printf("10.\t\tPasta\t\t\t\t130\n");
    printf("11.\t\tPizza\t\t\t\t150\n");
    printf("12.\t\tSandwich\t\t\t80\n");
    printf("13.\t\tNachos\t\t\t\t110\n");
    printf("14.\t\tChicken Burger\t\t\t130\n");
    printf("15.\t\tCrispy Chicken\t\t\t150\n\n");
}

// Function to display the total bill and tax
void display_bill(int bill){
    system("clear");
    printf("\t\t\tCafe Bill\n\n");
    printf("Amount:\t\t\t\t%d\n", bill);
    printf("GST (18%%):\t\t\t\t%.2f\n", 0.18*bill);
    printf("Total Bill:\t\t\t\t%.2f\n", 1.18*bill);
}

int main(){
    int choice, quantity, bill=0;
    char more;
    struct Menu menu[]={
                            {"Espresso", 100},
                            {"Cappuccino", 120},
                            {"Latte", 130},
                            {"Mocha", 140},
                            {"Iced Tea", 90},
                            {"Cold Coffee", 110},
                            {"Hot Chocolate", 120},
                            {"French Fries", 70},
                            {"Veg Burger", 100},
                            {"Pasta", 130},
                            {"Pizza", 150},
                            {"Sandwich", 80},
                            {"Nachos", 110},
                            {"Chicken Burger", 130},
                            {"Crispy Chicken", 150}
                        };
    int total_items = sizeof(menu)/sizeof(menu[0]);
    
    do{
        display_menu();
        printf("Enter Item No.: ");
        scanf("%d", &choice);
        if(choice>=1 && choice<=total_items){
            printf("Enter Quantity: ");
            scanf("%d", &quantity);
            bill += menu[choice-1].item_cost * quantity;
            printf("Add more items? (y/n): ");
            scanf("\n%c", &more);
        }
        else{
            printf("\nInvalid Item no.!\n");
            printf("Add more items? (y/n): ");
            scanf("\n%c", &more);
        }
    }while(more=='y' || more=='Y');
    
    display_bill(bill);
    return 0;
}