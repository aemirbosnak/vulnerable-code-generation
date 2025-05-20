//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MSG_LENGTH 100
#define MAX_PLAYERS 10

int main() {
  char message[MAX_MSG_LENGTH];
  int playerCount;

  // prompt user to enter number of players
  printf("Enter number of players: ");
  scanf("%d", &playerCount);

  // validate number of players
  if (playerCount > MAX_PLAYERS) {
    printf("Maximum number of players allowed is %d\n", MAX_PLAYERS);
    return 1;
  }

  // create array for storing player names
  char playerNames[playerCount][MAX_MSG_LENGTH];
  for (int i = 0; i < playerCount; i++) {
    printf("Enter name for player %d: ", i);
    scanf("%s", playerNames[i]);
  }

  // display player names
  printf("Players: ");
  for (int i = 0; i < playerCount; i++) {
    printf("%s ", playerNames[i]);
  }
  printf("\n");

  // create arrays for storing last messages for each player
  char lastMessages[playerCount][MAX_MSG_LENGTH];
  for (int i = 0; i < playerCount; i++) {
    strcpy(lastMessages[i], "");
  }

  bool spamDetected = false;

  // prompt each player to enter a message
  for (int i = 0; i < playerCount; i++) {
    printf("%s, enter your message: ", playerNames[i]);
    scanf("%s", message);

    // check for spam
    for (int j = 0; j < playerCount; j++) {
      if (j != i && strcmp(lastMessages[j], message) == 0) {
        printf("SPAM DETECTED! Message from %s matches message from %s\n", playerNames[i], playerNames[j]);
        spamDetected = true;
        break;
      }
    }

    // store current message as last message for player
    strcpy(lastMessages[i], message);

    if (spamDetected) {
      break;
    }
  }

  if (!spamDetected) {
    printf("No spam detected\n");
  }

  return 0;
}