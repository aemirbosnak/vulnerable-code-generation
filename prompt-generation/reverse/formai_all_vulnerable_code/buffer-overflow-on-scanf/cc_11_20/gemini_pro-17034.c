//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <signal.h>

#define MSGKEY 1234

typedef struct {
    long mtype;
    char command[10];
    int speed;
    int direction;
} msgbuf;

int main() {
    int server = msgget(MSGKEY, 0666 | IPC_CREAT);
    if (server < 0) {
        perror("msgget");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0) {
        int state = 0;
        while (state != 5) {
            msgbuf msg;
            int n = msgrcv(server, &msg, sizeof(msg) - sizeof(long), 1, 0);
            if (n < 0) {
                perror("msgrcv");
                exit(1);
            }

            switch (msg.command[0]) {
                case 'f':
                    printf("Moving forward at speed %d\n", msg.speed);
                    state = 1;
                    break;
                case 'b':
                    printf("Moving backward at speed %d\n", msg.speed);
                    state = 2;
                    break;
                case 'l':
                    printf("Turning left at speed %d\n", msg.speed);
                    state = 3;
                    break;
                case 'r':
                    printf("Turning right at speed %d\n", msg.speed);
                    state = 4;
                    break;
                case 's':
                    printf("Stopping\n");
                    state = 5;
                    break;
            }
        }

        exit(0);
    } else {
        char command[10];
        int speed;
        int direction;

        while (1) {
            printf("Enter command (f/b/l/r/s): ");
            scanf("%s", command);

            printf("Enter speed (0-100): ");
            scanf("%d", &speed);

            printf("Enter direction (0-360): ");
            scanf("%d", &direction);

            msgbuf msg;
            msg.mtype = 1;
            strcpy(msg.command, command);
            msg.speed = speed;
            msg.direction = direction;

            int n = msgsnd(server, &msg, sizeof(msg) - sizeof(long), 0);
            if (n < 0) {
                perror("msgsnd");
                exit(1);
            }

            if (command[0] == 's') {
                break;
            }
        }

        kill(pid, SIGTERM);
        waitpid(pid, NULL, 0);

        msgctl(server, IPC_RMID, NULL);
    }

    return 0;
}