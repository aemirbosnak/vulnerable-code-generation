//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure to hold data for a specific user
struct User{
    char name[30];
    int age;
    char contactNo[15];
    int tableNo;
    float totalBill;
};

//Function to print the main menu
void printMainMenu(){
    printf("\n---------- C CAFE BILLING SYSTEM --------\n");
    printf("1. Add new user\n");
    printf("2. Calculate bill\n");
    printf("3. View user details\n");
    printf("4. Exit\n");
}

//Function to calculate the price of different menu items and return the total price
float calculateBill(){
    int option, quantity;
    float totalBill = 0.0;
    printf("\n--------- MENU ---------\n");
    printf("1. Tea - $1.0\n");
    printf("2. Coffee - $2.0\n");
    printf("3. Sandwich - $5.0\n");
    printf("4. Burger - $8.0\n");
    printf("5. Pizza - $10.0\n");
    printf("6. Exit\n");
    while(1){
        printf("Enter option number to add to cart : ");
        scanf("%d", &option);
        if(option<1 || option>5){
            if(option==6){
                return totalBill;
            }
            printf("Invalid option, please try again.\n");
            continue;
        }
        printf("Enter quantity : ");
        scanf("%d", &quantity);
        switch(option){
            case 1:
                totalBill += quantity*1.0;
                break;
            case 2:
                totalBill += quantity*2.0;
                break;
            case 3:
                totalBill += quantity*5.0;
                break;
            case 4:
                totalBill += quantity*8.0;
                break;
            case 5:
                totalBill += quantity*10.0;
                break;
            default:
                return -1;
        }   
        printf("Item added to cart.\n");
    }
}

int main(){
    int choice, tableNo;
    struct User users[10];
    while(1){
        printMainMenu();
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            
            //Adding a new user to the system
            case 1:
                printf("\n----- ADD NEW USER -----\n");
                for(int i=0; i<10; i++){
                    if(users[i].tableNo==0){
                        scanf("%s %d %s", users[i].name, &users[i].age, users[i].contactNo);
                        users[i].tableNo = i+1;
                        printf("User added successfully. Table number : %d\n", users[i].tableNo);
                        break;
                    }
                    if(i==9){
                        printf("All tables are occupied now.\n");
                    }
                }
                break;
            
            //Calculating the bill of a user
            case 2:
                printf("\n----- CALCULATE BILL -----\nEnter table number : ");
                scanf("%d", &tableNo);
                if(tableNo<=0 || tableNo>10 || users[tableNo-1].tableNo==0){
                    printf("Invalid table number.\n");
                    break;
                }
                if(users[tableNo-1].totalBill!=0.0){
                    printf("Bill already calculated for this table number.\n");
                    break;
                }
                users[tableNo-1].totalBill = calculateBill();
                printf("Total bill for table %d : $%.2f\n", tableNo, users[tableNo-1].totalBill);
                break;
            
            //Viewing details of a user
            case 3:
                printf("\n----- VIEW USER DETAILS -----\nEnter table number : ");
                scanf("%d", &tableNo);
                if(tableNo<=0 || tableNo>10 || users[tableNo-1].tableNo==0){
                    printf("Invalid table number.\n");
                    break;
                }
                printf("Details of user at table %d : \n", tableNo);
                printf("Name : %s\n", users[tableNo-1].name);
                printf("Age : %d\n", users[tableNo-1].age);
                printf("Contact Number : %s\n", users[tableNo-1].contactNo);
                if(users[tableNo-1].totalBill!=0.0){
                    printf("Total bill : $%.2f\n", users[tableNo-1].totalBill);
                }
                else{
                    printf("Bill not calculated yet.\n");
                }
                break;
            
            //Exit the program
            case 4:
                exit(0);
            
            //Invalid choice
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}