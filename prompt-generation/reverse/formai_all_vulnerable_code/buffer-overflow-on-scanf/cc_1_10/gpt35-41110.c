//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_LENGTH 100

struct msgbuf {
    long mtype;
    char mtext[MAX_MSG_LENGTH];
};

void error(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int msgid;
    key_t key;
    pid_t pid = getpid();

    if((key = ftok(".", 'a')) == -1)
        error("Couldn't generate key.");

    if((msgid = msgget(key, IPC_CREAT|0666)) == -1)
        error("Couldn't create message queue.");

    struct msgbuf rcv_msg;
    struct msgbuf snd_msg;

    memset(&rcv_msg, 0, sizeof(struct msgbuf));
    memset(&snd_msg, 0, sizeof(struct msgbuf));

    long sndtype;
    int rcv_result;

    printf("Chatbot started with PID: %d\n", pid);
    
    printf("Please enter message type to start conversation: ");
    scanf("%ld", &sndtype);
    getchar(); // to eat up the '\n'

    printf("\n");

    snd_msg.mtype = sndtype;

    while(1) {
        printf("You: ");
        fgets(snd_msg.mtext, MAX_MSG_LENGTH, stdin);

        if(msgsnd(msgid, &snd_msg, strlen(snd_msg.mtext)+1, 0) == -1)
            error("Couldn't send message");

        if(strcmp(snd_msg.mtext, "exit\n") == 0) // if user wants to exit
            break;

        rcv_result = msgrcv(msgid, &rcv_msg, MAX_MSG_LENGTH, pid, 0);
        if(rcv_result == -1)
            error("Couldn't receive message");

        printf("Bot: %s", rcv_msg.mtext);

        if(strcmp(rcv_msg.mtext, "exit\n") == 0) // if bot wants to exit
            break;
    }

    if(msgctl(msgid, IPC_RMID, 0) == -1)
        error("Couldn't delete message queue");

    printf("\nChatbot program terminated.\n");

    return 0;
}