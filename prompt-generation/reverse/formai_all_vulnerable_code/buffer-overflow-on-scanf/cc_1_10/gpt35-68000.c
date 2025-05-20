//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 256

void encrypt(char *msg, int key) {
  int len = strlen(msg);
  for (int i = 0; i < len; i++) {
    msg[i] ^= key; // xor each byte of message with the key
  }
}

void send_msg(char *msg, int key) {
  encrypt(msg, key);
  printf("Sent message: %s\n", msg);
}

void recv_msg(char *msg, int key) {
  printf("Received message: %s\n", msg);
  encrypt(msg, key);
}

int main() {
  int num_players, key;
  char msg[MAX_MSG_LEN];

  printf("Enter the number of players: ");
  scanf("%d", &num_players);

  printf("Enter the encryption key: ");
  scanf("%d", &key);

  for (int i = 1; i <= num_players; i++) {
    printf("\n[Player %d] Enter message: ", i);
    scanf(" %[^\n]", msg); // read message with spaces

    if (i == 1) { // send message to player 2
      send_msg(msg, key);
    } else if (i < num_players) { // relay message to next player
      recv_msg(msg, key);

      char relay_msg[MAX_MSG_LEN];
      snprintf(relay_msg, MAX_MSG_LEN, "Relaying message from player %d: %s", i, msg);
      send_msg(relay_msg, key);
    } else { // final player receives message
      recv_msg(msg, key);
    }
  }

  return 0;
}