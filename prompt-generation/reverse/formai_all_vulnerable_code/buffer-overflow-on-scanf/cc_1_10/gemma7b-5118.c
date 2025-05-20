//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Player {
  char name[20];
  int score;
  struct Player* next;
} Player;

void addPlayer(Player** head) {
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

void playGame(Player* head) {
  while (head) {
    printf("%s, it is your turn to guess the number: ", head->name);
    int guessNumber = atoi(stdin);

    if (guessNumber == head->score) {
      printf("Congratulations, you won!\n");
      head->score++;
    } else {
      printf("Sorry, your guess is incorrect.\n");
    }

    head = head->next;
  }
}

int main() {
  Player* head = NULL;
  addPlayer(&head);
  addPlayer(&head);

  playGame(head);

  return 0;
}