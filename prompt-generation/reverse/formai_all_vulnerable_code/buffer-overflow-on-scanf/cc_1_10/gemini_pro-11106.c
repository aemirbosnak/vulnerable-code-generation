//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Player struct
typedef struct player {
    char name[20];
    int score;
} player;

// Function to calculate mortgage payment
double calculate_mortgage(double loan_amount, double interest_rate, int loan_term) {
    double monthly_interest_rate = interest_rate / 1200;
    double number_of_payments = loan_term * 12;
    double monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -number_of_payments));
    return monthly_payment;
}

// Main function
int main() {
    // Initialize players
    player players[2];
    for (int i = 0; i < 2; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Get loan information
    double loan_amount;
    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);
    double interest_rate;
    printf("Enter interest rate (in percentage): ");
    scanf("%lf", &interest_rate);
    int loan_term;
    printf("Enter loan term (in years): ");
    scanf("%d", &loan_term);

    // Calculate monthly payment
    double monthly_payment = calculate_mortgage(loan_amount, interest_rate, loan_term);

    // Start game loop
    while (1) {
        // Get player input
        for (int i = 0; i < 2; i++) {
            int guess;
            printf("%s, guess the monthly mortgage payment: ", players[i].name);
            scanf("%d", &guess);

            // Check if guess is correct
            if (guess == (int) monthly_payment) {
                players[i].score++;
                printf("%s guessed correctly! Score: %d\n", players[i].name, players[i].score);
            } else {
                printf("%s guessed incorrectly. Correct answer: %.2f\n", players[i].name, monthly_payment);
            }
        }

        // Check if game is over
        if (players[0].score >= 5 || players[1].score >= 5) {
            break;
        }
    }

    // Print winner
    if (players[0].score > players[1].score) {
        printf("%s wins!\n", players[0].name);
    } else if (players[0].score < players[1].score) {
        printf("%s wins!\n", players[1].name);
    } else {
        printf("Tie!\n");
    }

    return 0;
}