//FormAI DATASET v1.0 Category: Poker Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE    52
#define RANKS        "23456789TJQKA"
#define SUITS        "CDHS"

// structure to hold card information
struct card {
    char rank;     // '2'-'9', 'T', 'J', 'Q', 'K', 'A'
    char suit;     // 'C', 'D', 'H', 'S'
    int value;     // 2-14 (2-'2', 3-'3', ..., T-'10', J-'11', ..., A-'14')
};

// structure to hold player information
struct player_info {
    char name[20];
    int money;
    int current_bet;
    int fold;
    struct card hand[2];
};

// shuffle the deck of cards
void shuffle_deck(struct card *deck) {
    int i, j;
    struct card temp_card;
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp_card = deck[i];
        deck[i] = deck[j];
        deck[j] = temp_card;
    }
}

// initialize the deck with 52 playing cards
void init_deck(struct card *deck) {
    int i, j, k;
    k = 0;
    for (i = 0; i < strlen(RANKS); i++) {
        for (j = 0; j < strlen(SUITS); j++) {
            deck[k].rank = RANKS[i];
            deck[k].suit = SUITS[j];
            if (i < 8) {
                deck[k].value = i + 2;
            } else if (i == 8) {
                deck[k].value = 10;
            } else {
                deck[k].value = 10 + i - 7;
            }
            k++;
        }
    }
}

// print a card
void print_card(struct card card) {
    printf("%c%c", card.rank, card.suit);
}

// print a player's hand
void print_hand(struct player_info player) {
    printf("%s's hand: ", player.name);
    print_card(player.hand[0]);
    printf(" ");
    print_card(player.hand[1]);
    printf("\n");
}

// print the community cards
void print_community_cards(struct card *community_cards, int community_cards_size) {
    int i;
    printf("Community cards: ");
    for (i = 0; i < community_cards_size; i++) {
        print_card(community_cards[i]);
        printf(" ");
    }
    printf("\n");
}

// print all players' money and bets
void print_money_and_bets(struct player_info *players, int num_players) {
    int i;
    for (i = 0; i < num_players; i++) {
        printf("%s's money: $%d, current bet: $%d\n", players[i].name, players[i].money, players[i].current_bet);
    }
}

// get input from user and validate it
int get_int_input(char *prompt) {
    char input_str[100];
    int input;
    do {
        printf("%s", prompt);
        fgets(input_str, 100, stdin);
        input = atoi(input_str);
        if (input == 0 && input_str[0] != '0') {
            printf("Invalid input. Please enter a number.\n");
        }
    } while (input == 0 && input_str[0] != '0');
    return input;
}

// deal the cards to the players
void deal_cards(struct player_info *players, int num_players, struct card *deck) {
    int i, j;
    for (i = 0; i < num_players; i++) {
        players[i].hand[0] = deck[i*2];
        players[i].hand[1] = deck[i*2+1];
    }
}

// get the player's action (fold, check, call, raise)
int get_player_action(struct player_info player, struct player_info *players, int num_players, int current_bet) {
    int action;
    char input_str[100];
    printf("%s's turn:\n", player.name);
    do {
        printf("Your hand: ");
        print_card(player.hand[0]);
        printf(" ");
        print_card(player.hand[1]);
        printf("\n");
        printf("Current bet: $%d\n", current_bet);
        printf("Your bet: $%d\n", player.current_bet);
        printf("Your money: $%d\n", player.money);
        printf("Please choose an action:\n");
        printf("  1. Fold\n");
        printf("  2. Check\n");
        printf("  3. Call\n");
        printf("  4. Raise\n");
        printf("Enter the number of your choice: ");
        fgets(input_str, 100, stdin);
        action = atoi(input_str);
        if (action < 1 || action > 4) {
            printf("Invalid input. Please choose a number between 1 and 4.\n");
            continue;
        }
        if (action == 3 && current_bet == player.current_bet) {
            printf("You cannot call because you have already matched the current bet.\n");
            continue;
        }
        if (action == 4) {
            int raise_amount = get_int_input("Enter the amount that you want to raise: ");
            if (raise_amount > player.money) {
                printf("You do not have enough money to raise that amount.\n");
                continue;
            }
            if (raise_amount <= current_bet - player.current_bet) {
                printf("You cannot raise by a smaller amount than the current bet.\n");
                continue;
            }
            player.current_bet += raise_amount;
            player.money -= raise_amount;
            current_bet = player.current_bet;
            printf("You raised by $%d.\n", raise_amount);
        } else {
            player.current_bet = current_bet;
        }
    } while (action == 4 || (action != 1 && player.current_bet < current_bet));
    if (action == 1) {
        player.fold = 1;
    } else if (action == 2) {
        player.current_bet = current_bet;
    } else if (action == 3) {
        int call_amount = current_bet - player.current_bet;
        player.money -= call_amount;
        player.current_bet = current_bet;
    }
    return current_bet;
}

// determine the winner(s) of the hand
void determine_winner(struct player_info *players, int num_players, struct card *community_cards, int community_cards_size) {
    int i, j;
    struct card hand_cards[7];
    int max_score = -1;
    int winner_count = 0;
    int winner_indices[num_players];
    for (i = 0; i < num_players; i++) {
        if (players[i].fold)
            continue;
        memcpy(hand_cards, community_cards, community_cards_size*sizeof(struct card));
        memcpy(hand_cards+community_cards_size, players[i].hand, 2*sizeof(struct card));
        // sort the hand cards by value
        for (j = 0; j < 6; j++) {
            int k;
            for (k = j+1; k < 7; k++) {
                if (hand_cards[k].value < hand_cards[j].value) {
                    struct card temp_card = hand_cards[j];
                    hand_cards[j] = hand_cards[k];
                    hand_cards[k] = temp_card;
                }
            }
        }
        // check for flush
        int flush = 1;
        char flush_suit;
        for (j = 1; j < 7; j++) {
            if (hand_cards[j].suit != hand_cards[0].suit) {
                flush = 0;
                break;
            }
        }
        if (flush) {
            // royal flush
            if (hand_cards[0].value == 10 && hand_cards[1].value == 11 && hand_cards[2].value == 12 && hand_cards[3].value == 13 && hand_cards[4].value == 14) {
                players[i].money += 500;
                continue;
            }
            // straight flush
            for (j = 0; j < 3; j++) {
                if (hand_cards[j].value == hand_cards[j+1].value - 1 && hand_cards[j].value == hand_cards[j+2].value - 2 && hand_cards[j].value == hand_cards[j+3].value - 3 && hand_cards[j].value == hand_cards[j+4].value - 4) {
                    players[i].money += 100;
                    continue;
                }
            }
            players[i].money += 50;
            continue;
        }
        // check for four of a kind
        for (j = 0; j < 4; j++) {
            if (hand_cards[j].value == hand_cards[j+1].value && hand_cards[j].value == hand_cards[j+2].value && hand_cards[j].value == hand_cards[j+3].value) {
                players[i].money += 25;
                continue;
            }
        }
        // check for full house
        if ((hand_cards[0].value == hand_cards[1].value && hand_cards[2].value == hand_cards[3].value && hand_cards[3].value == hand_cards[4].value) ||
            (hand_cards[0].value == hand_cards[1].value && hand_cards[1].value == hand_cards[2].value && hand_cards[3].value == hand_cards[4].value)) {
            players[i].money += 10;
            continue;
        }
        // check for straight
        for (j = 0; j < 3; j++) {
            if (hand_cards[j].value == hand_cards[j+1].value - 1 && hand_cards[j].value == hand_cards[j+2].value - 2 && hand_cards[j].value == hand_cards[j+3].value - 3 && hand_cards[j].value == hand_cards[j+4].value - 4) {
                players[i].money += 5;
                continue;
            }
        }
        // check for three of a kind
        for (j = 0; j < 5; j++) {
            if (hand_cards[j].value == hand_cards[j+1].value && hand_cards[j].value == hand_cards[j+2].value) {
                players[i].money += 2;
                continue;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    struct card deck[DECK_SIZE];
    struct player_info players[6];
    int num_players, i, j;
    int current_bet, community_cards_size;
    struct card community_cards[5];
    char input_str[100];
    int game_over = 0;
    printf("Welcome to C Poker!\n");
    do {
        num_players = get_int_input("Enter the number of players (2-6): ");
    } while (num_players < 2 || num_players > 6);
    for (i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i+1);
        fgets(players[i].name, 20, stdin);
        players[i].name[strlen(players[i].name)-1] = '\0';
        players[i].money = 100;
        players[i].current_bet = 0;
        players[i].fold = 0;
    }
    printf("Game starts!\n");
    while (!game_over) {
        // initialize the deck
        init_deck(deck);
        // shuffle the deck
        shuffle_deck(deck);
        // deal the cards to the players
        deal_cards(players, num_players, deck);
        // reset player bets and fold status
        for (i = 0; i < num_players; i++) {
            players[i].current_bet = 0;
            players[i].fold = 0;
        }
        // set initial bet
        current_bet = 10;
        // flop
        community_cards_size = 0;
        printf("Flop:\n");
        for (i = 0; i < 3; i++) {
            community_cards[i] = deck[num_players*2+i];
            community_cards_size++;
        }
        // print the community cards
        print_community_cards(community_cards, community_cards_size);
        // get player actions
        for (i = 0; i < num_players; i++) {
            if (players[i].fold)
                continue;
            current_bet = get_player_action(players[i], players, num_players, current_bet);
            if (players[i].current_bet > current_bet) {
                current_bet = players[i].current_bet;
            }
        }
        // turn
        printf("Turn:\n");
        community_cards[community_cards_size++] = deck[num_players*2+3];
        // print the community cards
        print_community_cards(community_cards, community_cards_size);
        // get player actions
        for (i = 0; i < num_players; i++) {
            if (players[i].fold)
                continue;
            current_bet = get_player_action(players[i], players, num_players, current_bet);
            if (players[i].current_bet > current_bet) {
                current_bet = players[i].current_bet;
            }
        }
        // river
        printf("River:\n");
        community_cards[community_cards_size++] = deck[num_players*2+4];
        // print the community cards
        print_community_cards(community_cards, community_cards_size);
        // get player actions
        for (i = 0; i < num_players; i++) {
            if (players[i].fold)
                continue;
            current_bet = get_player_action(players[i], players, num_players, current_bet);
        }
        // determine the winner(s) of the hand
        determine_winner(players, num_players, community_cards, community_cards_size);
        // print everyone's money and bets
        print_money_and_bets(players, num_players);
        // check if anyone is out of money
        int num_active_players = 0;
        struct player_info *active_players;
        active_players = (struct player_info*)malloc(num_players*sizeof(struct player_info));
        for (i = 0; i < num_players; i++) {
            if (players[i].money > 0) {
                active_players[num_active_players++] = players[i];
            }
        }
        if (num_active_players < 2) {
            printf("Game over!\n");
            game_over = 1;
            break;
        }
        // ask if user wants to continue playing
        printf("\nDo you want to play another hand?\n");
        printf("Enter 'y' for yes or 'n' for no: ");
        fgets(input_str, 100, stdin);
        input_str[strlen(input_str)-1] = '\0';
        if (strcmp(input_str, "n") == 0) {
            printf("Game over!\n");
            game_over = 1;
        }
    }
    return 0;
}