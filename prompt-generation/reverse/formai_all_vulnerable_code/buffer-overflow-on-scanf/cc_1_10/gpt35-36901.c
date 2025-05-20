//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_TEXT 512

// define the message structure
struct message {
  long mtype; // message type
  char mtext[MAX_TEXT]; // message text
};

// thread function to receive messages
void *receive_messages(void *id) {
  int msqid = *(int *)id;
  struct message rcv_msg;
  // loop to receive messages
  while(1) {
    // receive message of any type
    if(msgrcv(msqid, &rcv_msg, MAX_TEXT, 0, 0) == -1) {
      // if error occurs, exit the loop
      break;
    }
    // print the received message
    printf("Received message (%d): %s\n", rcv_msg.mtype, rcv_msg.mtext);
  }
  // exit thread
  pthread_exit(NULL);
}

int main() {
  int msqid, key, pid;
  struct message snd_msg;
  pthread_t tid;

  // generate a unique key
  if((key = ftok(".", 'A')) == -1) {
    perror("ftok");
    exit(1);
  }

  // create a message queue
  if((msqid = msgget(key, 0666 | IPC_CREAT)) == -1) {
    perror("msgget");
    exit(1);
  }

  // create a thread to receive messages
  if(pthread_create(&tid, NULL, &receive_messages, &msqid) != 0) {
    perror("pthread_create");
    exit(1);
  }

  // loop to send messages
  while(1) {
    // get message type
    printf("Enter message type: ");
    scanf("%ld", &snd_msg.mtype);

    // if message type is 0, exit the loop
    if(snd_msg.mtype == 0) {
      break;
    }

    // get message text
    printf("Enter message: ");
    scanf("%s", snd_msg.mtext);

    // send the message
    if(msgsnd(msqid, &snd_msg, strlen(snd_msg.mtext) + 1, 0) == -1) {
      perror("msgsnd");
      exit(1);
    }
    // print the sent message
    printf("Sent message (%ld): %s\n", snd_msg.mtype, snd_msg.mtext);
  }

  // remove the message queue
  if(msgctl(msqid, IPC_RMID, NULL) == -1) {
    perror("msgctl");
    exit(1);
  }

  // wait for receive_messages thread to exit
  if(pthread_join(tid, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  // exit the process
  exit(0);
}