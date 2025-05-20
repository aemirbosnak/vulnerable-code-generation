//FormAI DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // Maximum number of expenses

// Structure definition
struct expense{
    char name[50];
    float amount;
    char category[20];
}e[MAX];

// Global variables
int count = 0;          // Number of expenses
float total = 0;        // Total expenses

// Function prototype declaration
void addExpense();
void viewExpenses();
void searchExpense();
void removeExpense();

// Main function
int main(){
    
    int choice;
    
    printf("\n\t\t\t EXPENSE TRACKER \n");
    
    while(1){
        
        // Main menu
        printf("\n\t\t MENU \n");
        printf("1. Add Expense \n");
        printf("2. View Expenses \n");
        printf("3. Search Expense \n");
        printf("4. Remove Expense \n");
        printf("5. Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        // Menu option selection
        switch(choice){
            
            case 1: addExpense();
                    break;
            
            case 2: viewExpenses();
                    break;
            
            case 3: searchExpense();
                    break;
            
            case 4: removeExpense();
                    break;
            
            case 5: printf("\n Exiting the program. \n");
                    exit(0);
            
            default: printf("\n Invalid choice. Please try again. \n");
                     break;
        }
    }
    
    return 0;
}

// Function to add expense
void addExpense(){
    
    printf("\n Enter expense details : \n");
    printf(" Name of expense : ");
    scanf(" %[^\n]s", e[count].name);     // To read the string with spaces
    printf(" Amount spent : ");
    scanf("%f", &e[count].amount);
    printf(" Category : ");
    scanf(" %[^\n]s", e[count].category);
    
    total += e[count].amount;       // Updating total expense
    
    printf("\n Expense added successfully. \n");
    
    count++;        // Updating the count
    
    return;
}

// Function to view expenses
void viewExpenses(){
    
    if(count == 0){
        printf("\n No expense added yet. \n");
        return;
    }
    
    printf("\n %-20s %-10s %-10s\n","Expense Name", "Amount", "Category");
    
    for(int i=0;i<count;i++){
        
        printf(" %-20s %-10.2f %-10s\n",e[i].name,e[i].amount,e[i].category);      // Displaying the expense details
    }
    
    printf(" Total Expenses : %.2f \n",total);
    
    return;
}

// Function to search expense
void searchExpense(){
    
    if(count == 0){
        printf("\n No expense added yet. \n");
        return;
    }
    
    char search[50];
    int flag = 0;
    
    printf("\n Enter the name of expense to search : ");
    scanf(" %[^\n]s", search);
    
    printf("\n %-20s %-10s %-10s\n","Expense Name", "Amount", "Category");
    
    for(int i=0;i<count;i++){
        
        if(strcmp(e[i].name,search) == 0){      // If expense name found
            printf(" %-20s %-10.2f %-10s\n",e[i].name,e[i].amount,e[i].category);
            flag = 1;       // Flag to indicate expense found
            break;
        }
    }
    
    if(!flag)       // If expense not found
        printf("\n No expense found with the given name. \n");
    
    return;
}

// Function to remove expense
void removeExpense(){
    
    if(count == 0){
        printf("\n No expense added yet. \n");
        return;
    }
    
    char remove[50];
    int flag = 0;
    
    printf("\n Enter the name of expense to remove : ");
    scanf(" %[^\n]s", remove);
    
    for(int i=0;i<count;i++){
        
        if(strcmp(e[i].name,remove) == 0){     // If expense name found
            total -= e[i].amount;       // Updating total expense
            printf("\n Expense removed : \n");
            printf(" %-20s %-10.2f %-10s\n",e[i].name,e[i].amount,e[i].category);
            
            for(int j=i;j<count-1;j++){
                e[j] = e[j+1];      // Shifting the array elements
            }
            count--;        // Updating the count
            flag = 1;       // Flag to indicate expense found
            break;
        }
    }
    
    if(!flag)       // If expense not found
        printf("\n No expense found with the given name. \n");
    
    return;
}