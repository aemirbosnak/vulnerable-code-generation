//FormAI DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_LEN 50

struct msgbuf {
    long type;
    char text[MSG_LEN];
};

int main() {
    key_t key;
    int msgid;
    pid_t pid = getpid();
    struct msgbuf msg;
    
    if((key = ftok(".", 'm')) == -1) {
        perror("ftok");
        exit(1);
    }
    
    if((msgid = msgget(key, IPC_CREAT|0666)) == -1) {
        perror("msgget");
        exit(1);
    }
    
    printf("Process %d is ready to send messages\n", pid);
    printf("Enter q to quit\n");
    while(1) {
        printf("Enter recipient process ID: ");
        scanf("%ld", &msg.type);
        if(msg.type == 0) {
            printf("Invalid recipient ID\n");
            continue;
        }
        if(msg.type == pid) {
            printf("Cannot send message to self\n");
            continue;
        }
        if(msg.type == -1) {
            printf("Exiting...\n");
            break;
        }
        printf("Enter message (max %d characters): ", MSG_LEN-1);
        scanf("%s", msg.text);
        if(msgsnd(msgid, &msg, strlen(msg.text)+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
        printf("Sent message \"%s\" to process %ld\n", msg.text, msg.type);
    }
    
    if(msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    
    return 0;
}