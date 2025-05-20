#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

#define MSG_SIZE 1024

struct msg_packet {
  int light_id;
  int state;
  time_t timestamp;
} msg_packet_t;

int main() {
  int msg_id;
  struct msg_packet msg_packet;
  time_t current_time;
  int light_id;
  int state;

  // Create a message queue
  msg_id = msgget(IPC_PRIVATE, 0644);
  if (msg_id == -1) {
    perror("msgget");
    exit(1);
  }

  // Initialize the timer
  current_time = time(NULL);

  // Loop to handle messages
  while (1) {
    // Receive a message
    msgrcv(msg_id, &msg_packet, sizeof(msg_packet), 0, NULL);

    // Update the timer
    current_time = time(NULL);

    // Process the message
    light_id = msg_packet.light_id;
    state = msg_packet.state;

    // Update the traffic light state
    switch (light_id) {
      case 1:
        // Logic to handle state change for light 1
        break;
      case 2:
        // Logic to handle state change for light 2
        break;
      case 3:
        // Logic to handle state change for light 3
        break;
      case 4:
        // Logic to handle state change for light 4
        break;
    }

    // Send a message to update the timer
    msg_packet.timestamp = current_time;
    msgsnd(msg_id, &msg_packet, sizeof(msg_packet), 0);
  }

  return 0;
}
