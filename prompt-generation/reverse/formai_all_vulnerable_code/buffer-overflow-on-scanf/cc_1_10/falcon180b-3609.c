//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define SIZE 100
#define MAX_CLIENTS 5
#define MAX_MSG_SIZE 100

int main() {
    int shmid, msqid;
    key_t key;
    char *shmaddr;
    struct msgbuf {
        long mtype;
        char mtext[MAX_MSG_SIZE];
    } msg;

    // Create shared memory segment
    key = ftok("/tmp", 'a');
    if ((shmid = shmget(key, SIZE, IPC_CREAT | 0666)) < 0) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }
    shmaddr = shmat(shmid, NULL, 0);
    if ((int)shmaddr == -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Create message queue
    key = ftok("/tmp", 'b');
    if ((msqid = msgget(key, IPC_CREAT | 0666)) < 0) {
        printf("Error creating message queue\n");
        exit(1);
    }

    // Fork child processes
    for (int i = 0; i < MAX_CLIENTS; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            printf("Error forking child process\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            break;
        }
    }

    // Child process
    if (getpid() > 0) {
        exit(0);
    }

    while (1) {
        printf("Enter message to send: ");
        scanf("%s", msg.mtext);
        msg.mtype = 1;
        if (msgsnd(msqid, &msg, MAX_MSG_SIZE, 0) < 0) {
            printf("Error sending message\n");
            exit(1);
        }
    }

    return 0;
}