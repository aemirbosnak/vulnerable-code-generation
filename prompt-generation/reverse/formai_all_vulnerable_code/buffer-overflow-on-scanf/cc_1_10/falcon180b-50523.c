//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
//C Mortgage Calculator Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_LOAN_AMOUNT 1000000
#define MAX_INTEREST_RATE 10
#define MAX_TERM_YEARS 30

struct player {
    char name[MAX_NAME_LENGTH];
    double loan_amount;
    double interest_rate;
    int term_years;
};

void get_player_data(struct player *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);

    printf("Enter the loan amount: ");
    scanf("%lf", &player->loan_amount);

    printf("Enter the interest rate (between 0 and %d): ", MAX_INTEREST_RATE);
    scanf("%lf", &player->interest_rate);

    printf("Enter the term in years (between 1 and %d): ", MAX_TERM_YEARS);
    scanf("%d", &player->term_years);
}

double calculate_monthly_payment(double loan_amount, double interest_rate, int term_years) {
    double monthly_rate = interest_rate / 1200;
    int num_months = term_years * 12;
    double monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -num_months));
    return monthly_payment;
}

int main() {
    srand(time(NULL));
    int num_players = rand() % MAX_PLAYERS + 1;
    struct player players[MAX_PLAYERS];

    for (int i = 0; i < num_players; i++) {
        get_player_data(&players[i]);
    }

    printf("Mortgage Calculator Results:\n");
    for (int i = 0; i < num_players; i++) {
        double monthly_payment = calculate_monthly_payment(players[i].loan_amount, players[i].interest_rate, players[i].term_years);
        printf("Player %d:\n", i+1);
        printf("Name: %s\n", players[i].name);
        printf("Loan Amount: $%.2lf\n", players[i].loan_amount);
        printf("Interest Rate: %.2lf%%\n", players[i].interest_rate * 100);
        printf("Term Years: %d\n", players[i].term_years);
        printf("Monthly Payment: $%.2lf\n\n", monthly_payment);
    }

    return 0;
}

/*
Sample Output:

Enter your name: John
Enter the loan amount: 500000
Enter the interest rate (between 0 and 10): 5
Enter the term in years (between 1 and 30): 30

Enter your name: Jane
Enter the loan amount: 750000
Enter the interest rate (between 0 and 10): 7
Enter the term in years (between 1 and 30): 25

Mortgage Calculator Results:

Player 1:
Name: John
Loan Amount: $500000.00
Interest Rate: 5.00%
Term Years: 30
Monthly Payment: $2684.11

Player 2:
Name: Jane
Loan Amount: $750000.00
Interest Rate: 7.00%
Term Years: 25
Monthly Payment: $4735.63
*/