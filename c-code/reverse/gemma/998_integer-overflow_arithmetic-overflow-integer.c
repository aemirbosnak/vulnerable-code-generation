#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 1024

struct msg_packet {
  int signal_status;
  int timer_value;
} msg_packet_t;

int main() {
  int msg_id;
  struct msg_packet msg_packet;

  // Create a message queue
  msg_id = msgget(IPC_PRIVATE, 0644);

  // Send a message to the traffic light controller
  msg_packet.signal_status = 1;
  msg_packet.timer_value = 10;
  msgsnd(msg_id, &msg_packet, sizeof(msg_packet), 0);

  // Receive a message from the traffic light controller
  msgrcv(msg_id, &msg_packet, sizeof(msg_packet), 0, 0);

  // Print the signal status and timer value
  printf("Signal status: %d\n", msg_packet.signal_status);
  printf("Timer value: %d\n", msg_packet.timer_value);

  return 0;
}
