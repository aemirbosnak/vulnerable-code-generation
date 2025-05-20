//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: multiplayer
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

void showPlayers(Player* head) {
  Player* current = head;
  while (current) {
    printf("%s (Score: %d) ", current->name, current->score);
    current = current->next;
  }
}

int main() {
  Player* head = NULL;

  printf("Welcome to the multiplayer C Log analysis game!\n");
  printf("Enter 'join' to join the game: ");
  char command[20];
  scanf("%s", command);

  if (strcmp(command, "join") == 0) {
    joinGame(&head);
  } else {
    printf("Invalid command.\n");
  }

  showPlayers(head);

  return 0;
}