//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum number of expenses per player
#define MAX_EXPENSES 10

// Define the maximum length of expense name
#define MAX_EXPENSE_NAME_LENGTH 20

// Define the maximum length of player name
#define MAX_PLAYER_NAME_LENGTH 15

// Structure definition for expense
typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    float amount;
} Expense;

// Structure definition for player
typedef struct {
    char name[MAX_PLAYER_NAME_LENGTH];
    Expense expenses[MAX_EXPENSES];
    int numExpenses;
    float totalExpenses;
} Player;

// Global variables
Player players[MAX_PLAYERS];
int numPlayers;
int currentPlayerIndex = 0;

// Function to display the main menu
void displayMenu() {
    printf("Expenses Tracker\n");
    printf("================\n");
    printf("1. Add player\n");
    printf("2. Add expense\n");
    printf("3. Display expenses\n");
    printf("4. Switch player\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a player
void addPlayer() {
    if(numPlayers < MAX_PLAYERS) {
        Player player;
        printf("Enter player name: ");
        scanf("%s", player.name);
        player.numExpenses = 0;
        player.totalExpenses = 0;
        players[numPlayers] = player;
        numPlayers++;
        printf("Player added successfully!\n");
    } else {
        printf("Maximum number of players reached!\n");
    }
}

// Function to add an expense
void addExpense() {
    Player *currentPlayer = &players[currentPlayerIndex];
    if(currentPlayer->numExpenses < MAX_EXPENSES) {
        Expense expense;
        printf("Enter expense name: ");
        scanf("%s", expense.name);
        printf("Enter expense amount: ");
        scanf("%f", &expense.amount);
        currentPlayer->expenses[currentPlayer->numExpenses] = expense;
        currentPlayer->numExpenses++;
        currentPlayer->totalExpenses += expense.amount;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum number of expenses for the player reached!\n");
    }
}

// Function to display the expenses of a player
void displayExpenses() {
    Player *currentPlayer = &players[currentPlayerIndex];
    printf("Expenses of %s:\n", currentPlayer->name);
    printf("%-20s%-10s\n", "Expense", "Amount");
    printf("==============================\n");
    for(int i = 0; i < currentPlayer->numExpenses; i++) {
        printf("%-20s%-10.2f\n", currentPlayer->expenses[i].name, currentPlayer->expenses[i].amount);
    }
    printf("==============================\n");
    printf("%-20s%-10.2f\n", "Total", currentPlayer->totalExpenses);
}

// Function to switch to the next player
void switchPlayer() {
    currentPlayerIndex++;
    if(currentPlayerIndex == numPlayers) {
        currentPlayerIndex = 0;
    }
}

// Main function
int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                displayExpenses();
                break;
            case 4:
                switchPlayer();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}