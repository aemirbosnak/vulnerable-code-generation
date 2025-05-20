//FormAI DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_SIZE 50

/* Define a message structure */
struct message {
    long type;
    char text[MAX_MSG_SIZE];
};

/* Function to send a message */
void sendMessage(int qid, char *msgText, int type) {
    struct message msg; 

    /* Set the type and text of a message */
    msg.type = type;
    strcpy(msg.text, msgText);

    /* Send the message */
    if (msgsnd(qid, &msg, strlen(msg.text) + 1, 0) == -1) {
        perror("msgsnd failed!");
        exit(1);
    }
}

/* Function to receive a message */
void receiveMessage(int qid, int type) {
    struct message msg; 

    /* Receive a message with the specified type */
    if (msgrcv(qid, &msg, MAX_MSG_SIZE, type, 0) == -1) {
        perror("msgrcv failed!");
        exit(1);
    }

    /* Print the received message */
    printf("Received message: %s\n", msg.text);
}

int main() {
    int qid;
    key_t key;
    int len;
    char msg[MAX_MSG_SIZE];

    /* Generate a unique key */
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok failed!");
        exit(1);
    }

    /* Create a message queue */
    if ((qid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget failed!");
        exit(1);
    }

    /* Send a message with type 1 */
    printf("Enter a message to send: ");
    fgets(msg, MAX_MSG_SIZE, stdin);
    len = strlen(msg);
    if (msg[len-1] == '\n') {
        msg[len-1] = '\0';
    }
    sendMessage(qid, msg, 1);
    printf("Sent message: %s\n", msg);

    /* Receive a message with type 2 */
    receiveMessage(qid, 2);

    /* Destroy the message queue */
    if (msgctl(qid, IPC_RMID, NULL) == -1) {
        perror("msgctl failed!");
        exit(1);
    }

    return 0;
}