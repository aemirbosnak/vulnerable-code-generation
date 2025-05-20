//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define HAND_SIZE 5
#define DECK_SIZE 52
#define BETTING_AMOUNT 100

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

typedef struct {
    char value[3];
    char suit[10];
} Card;

typedef struct {
    char name[30];
    int balance;
    Card hand[HAND_SIZE];
    int isFolded;
} Player;

Card deck[DECK_SIZE];
int topCardIndex = 0;

void initializeDeck() {
    int index = 0;
    for (int s = 0; s < 4; s++) {
        for (int v = 0; v < 13; v++) {
            strcpy(deck[index].value, values[v]);
            strcpy(deck[index].suit, suits[s]);
            index++;
        }
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
    topCardIndex = 0;
}

Card drawCard() {
    return deck[topCardIndex++];
}

void dealHands(Player players[], int numPlayers) {
    for (int p = 0; p < numPlayers; p++) {
        for (int c = 0; c < HAND_SIZE; c++) {
            players[p].hand[c] = drawCard();
        }
    }
}

void printCard(Card card) {
    printf("%s of %s\n", card.value, card.suit);
}

void printHand(Player player) {
    printf("%s's Hand:\n", player.name);
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(player.hand[i]);
    }
}

void printBalances(Player players[], int numPlayers) {
    printf("Player Balances:\n");
    for (int p = 0; p < numPlayers; p++) {
        printf("%s: $%d\n", players[p].name, players[p].balance);
    }
}

void bettingRound(Player players[], int numPlayers) {
    for (int p = 0; p < numPlayers; p++) {
        if (players[p].isFolded) continue;
        
        printf("%s, you have $%d. Do you want to bet $%d? (y/n): ", players[p].name, players[p].balance, BETTING_AMOUNT);
        
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'y' && players[p].balance >= BETTING_AMOUNT) {
            players[p].balance -= BETTING_AMOUNT;
            printf("%s bets $%d\n", players[p].name, BETTING_AMOUNT);
        } else {
            players[p].isFolded = 1;
            printf("%s has folded!\n", players[p].name);
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers = 0;

    printf("Welcome to the Exciting Poker Game!\n");

    // Get number of players
    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Please choose between 2 and 4 players: ");
        scanf("%d", &numPlayers);
    }

    // Get player names and initial balance
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].balance = 500; // Initial balance
        players[i].isFolded = 0;
    }

    while (1) {
        printf("\n--- New Round Starts! ---\n");
        
        // Initialize and shuffle the deck
        initializeDeck();
        shuffleDeck();
        
        // Deal hands
        dealHands(players, numPlayers);
        
        // Print hands
        for (int i = 0; i < numPlayers; i++) {
            printHand(players[i]);
        }
        
        // Betting round
        bettingRound(players, numPlayers);
        
        printBalances(players, numPlayers);
        
        // Check if a player has no balance left
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].balance <= 0) {
                printf("%s is out of the game!\n", players[i].name);
                players[i].isFolded = 1; // Mark as folded
            }
        }
        
        // Check for end of game
        int activePlayers = 0;
        for (int i = 0; i < numPlayers; i++) {
            if (!players[i].isFolded) {
                activePlayers++;
            }
        }
        if (activePlayers <= 1) {
            printf("Game over! Only one player remains!\n");
            break;
        }
        
        printf("\n--- End of Round! ---\n");
    }
    
    printf("Thanks for playing! Goodbye!\n");
    return 0;
}