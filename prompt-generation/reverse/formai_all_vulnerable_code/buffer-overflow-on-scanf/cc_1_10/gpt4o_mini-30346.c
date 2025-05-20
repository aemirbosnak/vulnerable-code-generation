//GPT-4o-mini DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 4

typedef struct {
    char name[50];
    double principal;
    double interest_rate;
    int term_years;
    double monthly_payment;
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;
pthread_mutex_t lock;

void calculate_monthly_payment(Player *player) {
    double monthly_rate = player->interest_rate / 100 / 12;
    int term_months = player->term_years * 12;
    player->monthly_payment = (player->principal * monthly_rate) /
                              (1 - (1 / pow(1 + monthly_rate, term_months)));
}

void *input_player_data(void *arg) {
    Player *player = (Player *)arg;

    printf("Enter name for player %d: ", player_count + 1);
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline

    printf("Enter loan amount for %s (in dollars): ", player->name);
    scanf("%lf", &player->principal);
    
    printf("Enter annual interest rate for %s (as a percentage): ", player->name);
    scanf("%lf", &player->interest_rate);
    
    printf("Enter term years for %s: ", player->name);
    scanf("%d", &player->term_years);
    
    getchar(); // to consume newline left by scanf
    return NULL;
}

void *calculate_and_display_payment(void *arg) {
    Player *player = (Player *)arg;
    calculate_monthly_payment(player);
    
    pthread_mutex_lock(&lock);
    printf("\nPlayer: %s\n", player->name);
    printf("Loan Amount: $%.2f\n", player->principal);
    printf("Interest Rate: %.2f%%\n", player->interest_rate);
    printf("Term: %d years\n", player->term_years);
    printf("Monthly Payment: $%.2f\n\n", player->monthly_payment);
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    pthread_mutex_init(&lock, NULL);

    printf("Welcome to the Multiplayer Mortgage Calculator!\n");
    
    while (player_count < MAX_PLAYERS) {
        printf("\nCreating player %d...\n", player_count + 1);
        // Input player data
        pthread_create(&threads[player_count], NULL, input_player_data, &players[player_count]);
        pthread_join(threads[player_count], NULL);
        player_count++;
    }

    printf("\nCalculating monthly payments...\n");
    for (int i = 0; i < player_count; i++) {
        pthread_create(&threads[i], NULL, calculate_and_display_payment, &players[i]);
    }

    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}