//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 52
#define MAX_HAND_SIZE 10

typedef struct {
  char suit;
  int rank;
} Card;

typedef struct {
  Card cards[MAX_HAND_SIZE];
  int num_cards;
} Hand;

typedef struct {
  char name[20];
  Hand hand;
  int score;
} Player;

void print_card(Card card) {
  char *suits[] = {"C", "D", "H", "S"};
  char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  printf("%s%s", ranks[card.rank - 2], suits[card.suit - 'C']);
}

void print_hand(Hand hand) {
  for (int i = 0; i < hand.num_cards; i++) {
    print_card(hand.cards[i]);
    printf(" ");
  }
  printf("\n");
}

void print_player(Player player) {
  printf("%s: ", player.name);
  print_hand(player.hand);
  printf("Score: %d\n", player.score);
}

int compare_cards(Card card1, Card card2) {
  if (card1.rank == card2.rank) {
    return card1.suit - card2.suit;
  } else {
    return card1.rank - card2.rank;
  }
}

int compare_hands(Hand hand1, Hand hand2) {
  int result = 0;
  for (int i = 0; i < hand1.num_cards && i < hand2.num_cards; i++) {
    result = compare_cards(hand1.cards[i], hand2.cards[i]);
    if (result != 0) {
      break;
    }
  }
  if (result == 0) {
    result = hand1.num_cards - hand2.num_cards;
  }
  return result;
}

void play_game() {
  Player players[MAX_PLAYERS];
  int num_players;

  // Get the number of players
  printf("Enter the number of players (2-4): ");
  scanf("%d", &num_players);
  if (num_players < 2 || num_players > 4) {
    printf("Invalid number of players. Please enter a number between 2 and 4.\n");
    return;
  }

  // Get the names of the players
  for (int i = 0; i < num_players; i++) {
    printf("Enter the name of player %d: ", i + 1);
    scanf("%s", players[i].name);
  }

  // Create the deck of cards
  Card deck[MAX_CARDS];
  int num_cards = 0;
  for (int suit = 'C'; suit <= 'S'; suit++) {
    for (int rank = 2; rank <= 14; rank++) {
      deck[num_cards].suit = suit;
      deck[num_cards].rank = rank;
      num_cards++;
    }
  }

  // Shuffle the deck of cards
  for (int i = 0; i < num_cards; i++) {
    int j = rand() % num_cards;
    Card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  // Deal the cards to the players
  for (int i = 0; i < num_players; i++) {
    for (int j = 0; j < MAX_HAND_SIZE; j++) {
      players[i].hand.cards[j] = deck[num_cards - 1];
      num_cards--;
      players[i].hand.num_cards++;
    }
  }

  // Sort the hands of the players
  for (int i = 0; i < num_players; i++) {
    qsort(players[i].hand.cards, players[i].hand.num_cards, sizeof(Card), compare_cards);
  }

  // Print the hands of the players
  for (int i = 0; i < num_players; i++) {
    print_player(players[i]);
  }

  // Find the winner
  int winning_player_index = -1;
  int winning_score = -1;
  for (int i = 0; i < num_players; i++) {
    if (players[i].score > winning_score) {
      winning_player_index = i;
      winning_score = players[i].score;
    }
  }

  // Print the winner
  if (winning_player_index != -1) {
    printf("The winner is %s with a score of %d.\n", players[winning_player_index].name, winning_score);
  } else {
    printf("There is a tie.\n");
  }
}

int main() {
  srand(time(NULL));
  play_game();
  return 0;
}