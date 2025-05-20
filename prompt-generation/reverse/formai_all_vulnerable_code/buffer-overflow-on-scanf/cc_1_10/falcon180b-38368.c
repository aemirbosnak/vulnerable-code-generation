//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 30
#define MAX_LOAN_AMOUNT 1000000
#define MAX_LOAN_TERM 30
#define MAX_INTEREST_RATE 10
#define MAX_MONTHLY_PAYMENT 100000
#define MAX_NUM_OF_PLAYERS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int loanAmount;
    int loanTerm;
    int interestRate;
    int monthlyPayment;
} Player;

Player players[MAX_PLAYERS];
int numOfPlayers;

void initializePlayers() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].name[0] = '\0';
        players[i].loanAmount = 0;
        players[i].loanTerm = 0;
        players[i].interestRate = 0;
        players[i].monthlyPayment = 0;
    }
    numOfPlayers = 0;
}

void addPlayer() {
    numOfPlayers++;
}

void removePlayer() {
    numOfPlayers--;
}

void displayPlayers() {
    for (int i = 0; i < numOfPlayers; i++) {
        printf("Player %d:\n", i+1);
        printf("Name: %s\n", players[i].name);
        printf("Loan Amount: $%d\n", players[i].loanAmount);
        printf("Loan Term: %d years\n", players[i].loanTerm);
        printf("Interest Rate: %.2f%%\n", players[i].interestRate/100);
        printf("Monthly Payment: $%d\n\n", players[i].monthlyPayment);
    }
}

void displayMenu() {
    printf("\n");
    printf("1. Add Player\n");
    printf("2. Remove Player\n");
    printf("3. Display Players\n");
    printf("4. Exit\n");
    printf("\n");
}

int main() {
    srand(time(NULL));
    initializePlayers();
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPlayer();
                printf("Player added.\n");
                break;
            case 2:
                removePlayer();
                printf("Player removed.\n");
                break;
            case 3:
                displayPlayers();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 4);
    return 0;
}