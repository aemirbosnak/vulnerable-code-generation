//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define maximum size for input strings
#define MAX_INPUT_SIZE 50

// Define a structure to hold transaction information
struct transaction {
    char date[MAX_INPUT_SIZE];
    char description[MAX_INPUT_SIZE];
    float amount;
};

// Declare global variables
struct transaction transactions[100];
int num_transactions = 0;

// Declare function prototypes
void add_transaction();
void view_transactions();
float calculate_total();
void configure_settings();
void print_settings();
bool validate_date(char*);
bool validate_amount(char*);

int main() {
    // Declare variables for menu input and loop control
    int choice = 0;
    bool running = true;
    
    // Display welcome message
    printf("Welcome to the Expense Tracker!\n");
    
    // Main menu loop
    while (running) {
        // Display menu options and take user input
        printf("\nWhat would you like to do?\n");
        printf("1. Add a transaction\n");
        printf("2. View all transactions\n");
        printf("3. View total expenses\n");
        printf("4. Configure settings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform selected action based on user input
        switch(choice) {
            case 1:
                add_transaction();
                break;
            case 2:
                view_transactions();
                break;
            case 3:
                printf("\nTotal expenses: $%.2f\n", calculate_total());
                break;
            case 4:
                configure_settings();
                break;
            case 5:
                running = false;
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
    
    // Display exit message
    printf("\nThank you for using the Expense Tracker!\n");
    
    return 0;
}

// Function to add a transaction to the global array of transactions
void add_transaction() {
    // Declare variables for input and loop control
    char input[MAX_INPUT_SIZE];
    bool valid_description = false;
    bool valid_amount = false;
    bool valid_date = false;
    
    // Take user input for transaction description and validate
    while (!valid_description) {
        printf("\nEnter a brief description for this transaction (e.g. gas, groceries): ");
        scanf("%s", input);
        if (strlen(input) <= MAX_INPUT_SIZE) {
            strncpy(transactions[num_transactions].description, input, MAX_INPUT_SIZE);
            valid_description = true;
        }
        else {
            printf("Description is too long. Please try again.\n");
        }
    }
    
    // Take user input for transaction amount and validate
    while (!valid_amount) {
        printf("Enter the amount for this transaction (e.g. 12.50): $");
        scanf("%s", input);
        if (validate_amount(input)) {
            transactions[num_transactions].amount = atof(input);
            valid_amount = true;
        }
        else {
            printf("Invalid amount. Please try again.\n");
        }
    }
    
    // Take user input for transaction date and validate
    while (!valid_date) {
        printf("Enter the date for this transaction (e.g. 01/31/2020): ");
        scanf("%s", input);
        if (validate_date(input)) {
            strncpy(transactions[num_transactions].date, input, MAX_INPUT_SIZE);
            valid_date = true;
        }
        else {
            printf("Invalid date format. Please use MM/DD/YYYY.\n");
        }
    }
    
    // Increment number of transactions
    num_transactions++;
    
    // Display success message and return to main menu
    printf("\nTransaction added successfully!\n");
}

// Function to view all transactions in the global array of transactions
void view_transactions() {
    // Display header for transaction table
    printf("\n%-20s %-20s %-10s\n", "Date", "Description", "Amount");
    printf("---------------------------------------------------\n");
    
    // Display each transaction in the global array of transactions
    for (int i = 0; i < num_transactions; i++) {
        printf("%-20s %-20s $%-10.2f\n", transactions[i].date, transactions[i].description, transactions[i].amount);
    }
}

// Function to calculate the total expenses from the global array of transactions
float calculate_total() {
    float total = 0;
    for (int i = 0; i < num_transactions; i++) {
        total += transactions[i].amount;
    }
    return total;
}

// Function to allow user to configure program settings
void configure_settings() {
    // Declare variables for input and loop control
    char input[MAX_INPUT_SIZE];
    bool valid_input = false;
    
    // Display settings menu
    while (!valid_input) {
        printf("\nWhat setting would you like to configure?\n");
        printf("1. Currency symbol\n");
        printf("2. Date format\n");
        printf("3. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%s", input);
        
        // Perform user-selected action based on input
        if (strcmp(input, "1") == 0) {
            printf("\nEnter the symbol for your preferred currency (e.g. $, €, £): ");
            scanf("%s", input);
            printf("Currency symbol updated to: %s\n", input);
            valid_input = true;
        }
        else if (strcmp(input, "2") == 0) {
            printf("\nEnter your preferred date format (e.g. MM/DD/YYYY): ");
            scanf("%s", input);
            printf("Date format updated to: %s\n", input);
            valid_input = true;
        }
        else if (strcmp(input, "3") == 0) {
            valid_input = true;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

// Function to display the current program settings
void print_settings() {
    printf("\nSettings:\n");
    printf("Currency symbol: $\n");
    printf("Date format: MM/DD/YYYY\n");
}

// Function to validate the format of a date string
bool validate_date(char* date) {
    if (strlen(date) != 10) {
        return false;
    }
    if (date[2] != '/' || date[5] != '/') {
        return false;
    }
    char* month = strtok(date, "/");
    char* day = strtok(NULL, "/");
    char* year = strtok(NULL, "/");
    if (atoi(month) < 1 || atoi(month) > 12) {
        return false;
    }
    if (atoi(day) < 1 || atoi(day) > 31) {
        return false;
    }
    if (atoi(year) < 1900) {
        return false;
    }
    return true;
}

// Function to validate the format of an amount string
bool validate_amount(char* amount) {
    int num_decimal_points = 0;
    for (int i = 0; i < strlen(amount); i++) {
        if (amount[i] == '.') {
            num_decimal_points++;
        }
        else if (amount[i] < '0' || amount[i] > '9') {
            return false;
        }
    }
    if (num_decimal_points != 1) {
        return false;
    }
    return true;
}