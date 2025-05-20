//FormAI DATASET v1.0 Category: Poker Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// card structure
typedef struct Card{
    int value;
    char suit;
}Card;

// player structure
typedef struct Player{
    int chips;
    int bet;
    Card hand[2];
}Player;

// function prototypes
void shuffleDeck(Card deck[]);
void dealHands(Player players[], Card deck[]);
void printTable(Player players[]);
void getBet(Player *player);
void swapCards(Player *player, Card deck[]);
void communityCards(Player players[], Card deck[], int turn);
int determineWinner(Player players[], int numPlayers);

int main(){
    // set up game
    int numPlayers, turn, winner;
    Card deck[52];
    Player players[4];
    srand(time(NULL));
    for(int i=0; i<4; i++){
        players[i].chips = 1000;
    }
    printf("Welcome to the Brave Poker Game!\n");
    printf("Enter the number of players (up to 4): ");
    scanf("%d", &numPlayers);
    while(numPlayers < 1 || numPlayers > 4){
        printf("Invalid number of players. Enter a number between 1 and 4: ");
        scanf("%d", &numPlayers);
    }
    printf("Shuffling deck...\n");
    shuffleDeck(deck);

    // game loop
    while(1){
        printf("\nNEW ROUND\n");
        dealHands(players, deck);
        for(int i=0; i<numPlayers; i++){
            getBet(&players[i]);
        }
        for(int i=0; i<numPlayers; i++){
            swapCards(&players[i], deck);
        }
        for(turn=1; turn<=5; turn++){
            printf("\nTurn %d\n", turn);
            if(turn <= 3){
                communityCards(players, deck, turn);
            }
            printTable(players);
        }
        winner = determineWinner(players, numPlayers);
        printf("\nPlayer %d wins %d chips!\n", winner+1, players[winner].bet*numPlayers);
        for(int i=0; i<numPlayers; i++){
            players[i].chips -= players[i].bet;
            if(i != winner){
                players[winner].chips += players[i].bet;
            }
        }
        printf("\nScores:\n");
        for(int i=0; i<numPlayers; i++){
            printf("Player %d: %d chips\n", i+1, players[i].chips);
            if(players[i].chips <= 0){
                printf("Player %d is out of chips. Game over.\n", i+1);
                return 0;
            }
        }
        printf("Next round starting in 5 seconds...\n");
        sleep(5);
    }
}

// function to shuffle the deck
void shuffleDeck(Card deck[]){
    char suits[4] = {'C', 'D', 'H', 'S'};
    for(int i=0; i<52; i++){
        deck[i].value = i % 13 + 2;
        deck[i].suit = suits[i/13];
    }
    for(int i=0; i<52; i++){
        int j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to deal hands to players
void dealHands(Player players[], Card deck[]){
    for(int i=0; i<4; i++){
        players[i].bet = 0;
        players[i].hand[0] = deck[i*2];
        players[i].hand[1] = deck[i*2+1];
    }
}

// function to print the table
void printTable(Player players[]){
    printf("\n-------TABLE-------\n\n");
    for(int i=0; i<4; i++){
        printf("Player %d: ", i+1);
        for(int j=0; j<2; j++){
            printf("%d%c ", players[i].hand[j].value, players[i].hand[j].suit);
        }
        printf("\n");
    }
    printf("\n");
}

// function for a player to make a bet
void getBet(Player *player){
    printf("Player, you have %d chips. Enter your bet: ", player->chips);
    scanf("%d", &player->bet);
    while(player->bet > player->chips || player->bet < 0){
        printf("Invalid bet. Enter a value between 0 and %d: ", player->chips);
        scanf("%d", &player->bet);
    }
    player->chips -= player->bet;
}

// function to allow a player to swap cards
void swapCards(Player *player, Card deck[]){
    int newCards[3];
    printf("\nPlayer, here are your cards: ");
    for(int i=0; i<2; i++){
        printf("%d%c ", player->hand[i].value, player->hand[i].suit);
    }
    printf("\nEnter the index of up to 3 cards to swap (or 0 to keep your hand): ");
    scanf("%d %d %d", &newCards[0], &newCards[1], &newCards[2]);
    while(newCards[0] < 0 || newCards[0] > 2 || newCards[1] < 0 || newCards[1] > 2 || newCards[2] < 0 || newCards[2] > 2){
        printf("Invalid input. Enter up to 3 values between 0 and 2: ");
        scanf("%d %d %d", &newCards[0], &newCards[1], &newCards[2]);
    }
    if(newCards[0] != 0){
        player->hand[newCards[0]-1] = deck[8];
        deck[8] = player->hand[newCards[0]-1];
    }
    if(newCards[1] != 0){
        player->hand[newCards[1]-1] = deck[9];
        deck[9] = player->hand[newCards[1]-1];
    }
    if(newCards[2] != 0){
        player->hand[newCards[2]-1] = deck[10];
        deck[10] = player->hand[newCards[2]-1];
    }
}

// function to add community cards to the table
void communityCards(Player players[], Card deck[], int turn){
    Card communityCard;
    communityCard = deck[4+turn];
    printf("Community card: %d%c\n", communityCard.value, communityCard.suit);
    for(int i=0; i<4; i++){
        players[i].hand[2+turn] = communityCard;
    }
}

// function to determine the winner
int determineWinner(Player players[], int numPlayers){
    int winner = 0, maxValue = 0;
    for(int i=1; i<numPlayers; i++){
        int currentValue = 0;
        for(int j=0; j<5; j++){
            currentValue += players[i].hand[j].value;
        }
        if(currentValue > maxValue){
            maxValue = currentValue;
            winner = i;
        }
    }
    return winner;
}