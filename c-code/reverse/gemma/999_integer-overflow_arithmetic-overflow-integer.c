#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MESSAGES 10

typedef struct Message {
  int light_id;
  int next_state;
  long timestamp;
} Message;

int main() {
  int msg_id;
  key_t key;
  Message msg;

  // Create a message queue
  msg_id = msgget(IPC_PRIVATE, 0644);
  if (msg_id == -1) {
    perror("msgget");
    exit(1);
  }

  // Listen for messages
  while (1) {
    // Wait for a message
    msg.light_id = -1;
    msg.next_state = -1;
    msg.timestamp = 0;
    if (msgrcv(msg_id, &msg, sizeof(Message), 0, 0) == -1) {
      perror("msgrcv");
      exit(1);
    }

    // Handle the message
    switch (msg.next_state) {
      case 0:
        printf("Light %d is red.\n", msg.light_id);
        break;
      case 1:
        printf("Light %d is yellow.\n", msg.light_id);
        break;
      case 2:
        printf("Light %d is green.\n", msg.light_id);
        break;
    }

    // Update the timestamp for the next state change
    msg.timestamp = time(NULL) + 2;

    // Send a message back to the controller
    msgsnd(msg_id, &msg, sizeof(Message), 0);

    // Handle potential message queue overflow
    if (msg.light_id == MAX_MESSAGES - 1) {
      printf("Message queue overflow!\n");
      exit(1);
    }
  }

  return 0;
}
