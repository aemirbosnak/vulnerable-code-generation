//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

void joinGame(Player** head) {
  Player* newPlayer = (Player*)malloc(sizeof(Player));
  printf("Enter your name: ");
  scanf("%s", newPlayer->name);
  newPlayer->score = 0;
  newPlayer->next = NULL;

  if (*head == NULL) {
    *head = newPlayer;
  } else {
    (*head)->next = newPlayer;
  }
}

void startGame(Player* head) {
  int round = 1;
  while (head) {
    printf("Round %d: ", round);
    int guessNumber = rand() % 11;
    printf("Guess a number between 0 and 10: ");
    int userGuess = atoi(stdin);

    if (guessNumber == userGuess) {
      head->score++;
      printf("Congratulations! You guessed the number!\n");
    } else {
      printf("Sorry, the number was %d. Try again next round.\n", guessNumber);
    }

    round++;
    head = head->next;
  }
}

int main() {
  Player* head = NULL;
  joinGame(&head);
  joinGame(&head);
  joinGame(&head);
  joinGame(&head);

  startGame(head);

  return 0;
}