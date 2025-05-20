//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_LOANS 50

typedef struct {
    char name[30];
    int id;
    double loanAmount;
    double interestRate;
    int term;
} Player;

Player players[MAX_PLAYERS];
int numPlayers;
int numLoans;

void readPlayers() {
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].id = i+1;
        players[i].loanAmount = 0;
        players[i].interestRate = 0;
        players[i].term = 0;
    }
}

void readLoans() {
    printf("Enter the number of loans: ");
    scanf("%d", &numLoans);

    for (int i = 0; i < numLoans; i++) {
        printf("Enter loan %d's player ID: ", i+1);
        scanf("%d", &players[i].id);
        printf("Enter loan %d's amount: ", i+1);
        scanf("%lf", &players[i].loanAmount);
        printf("Enter loan %d's interest rate: ", i+1);
        scanf("%lf", &players[i].interestRate);
        printf("Enter loan %d's term in years: ", i+1);
        scanf("%d", &players[i].term);
    }
}

void calculateMortgage() {
    for (int i = 0; i < numLoans; i++) {
        double monthlyPayment = (players[i].loanAmount * players[i].interestRate) / (1 - pow(1 + players[i].interestRate, -12 * players[i].term));
        printf("Loan %d's monthly payment is: $%.2lf\n", i+1, monthlyPayment);
    }
}

int main() {
    readPlayers();
    readLoans();
    calculateMortgage();

    return 0;
}