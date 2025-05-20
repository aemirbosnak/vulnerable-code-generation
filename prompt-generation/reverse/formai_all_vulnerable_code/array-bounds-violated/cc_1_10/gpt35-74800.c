//FormAI DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>

#define MSG_SIZE 100

/* global variables */
int msgid;
pthread_t thread1, thread2;

/* message structure */
typedef struct {
    long msg_type;
    char msg[MSG_SIZE];
} message;

/* message-receiving thread */
void* receiver(void* arg) {
    message msg;
    while (1) {
        msgrcv(msgid, &msg, MSG_SIZE, 1, 0);
        printf("Receiver: Message received - %s\n", msg.msg);
        if (strcmp(msg.msg, "exit") == 0) {
            printf("Receiver: Exiting...\n");
            pthread_exit(0);
        }
    }
}

/* message-sending thread */
void* sender(void* arg) {
    message msg;
    while (1) {
        printf("Sender: Enter Message (exit to quit) - ");
        fgets(msg.msg, MSG_SIZE, stdin);
        msg.msg[strlen(msg.msg)-1] = '\0'; // remove newline
        msg.msg_type = 1;
        msgsnd(msgid, &msg, strlen(msg.msg), 0);
        if (strcmp(msg.msg, "exit") == 0) {
            printf("Sender: Exiting...\n");
            pthread_exit(0);
        }
    }
}

int main() {
    /* create message queue */
    key_t key = ftok("ipc_example.c", 'a');
    msgid = msgget(key, 0666 | IPC_CREAT);
    
    if (msgid == -1) {
        perror("Error: msgget failed");
        exit(1);
    }
    
    /* start message-receiving thread */
    if (pthread_create(&thread1, NULL, receiver, NULL)) {
        perror("Error: pthread_create failed");
        exit(1);
    }
    
    /* start message-sending thread */
    if (pthread_create(&thread2, NULL, sender, NULL)) {
        perror("Error: pthread_create failed");
        exit(1);
    }
    
    /* wait for threads to terminate */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    /* delete message queue */
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("Error: msgctl failed");
        exit(1);
    }
    
    return 0;
}