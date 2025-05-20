//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
//Welcome to the Interstellar Interprocess Communication World!
//This program is designed to communicate between planets using IPC

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 100
#define EARTH 1
#define MARS 2
#define JUPITER 3

//Let's create an alien structure to send messages between planets
struct alien {
    long type;
    char message[MAX_SIZE];
} msg;

int main() {
    key_t key = ftok("alien_key", 'a');
    int msg_id = msgget(key, 0666 | IPC_CREAT);

    if (msg_id == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    int planet;
    printf("Greetings, space traveler! Which planet are you from?\n");
    printf("1. Earth\n2. Mars\n3. Jupiter\n");
    scanf("%d", &planet);

    printf("Welcome to the Interstellar Messaging Service!\n\n");

    if (planet == EARTH) {
        printf("You are now connected to Earth.\n");
    } else if (planet == MARS) {
        printf("You are now connected to Mars.\n");
    } else if (planet == JUPITER) {
        printf("You are now connected to Jupiter.\n");
    } else {
        printf("Invalid planet selected.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("\nEnter your message:\n");
        fgets(msg.message, MAX_SIZE, stdin);

        if (msg.message[0] == '\n')
            continue;

        msg.type = planet;
        msgsnd(msg_id, &msg, sizeof(msg), 0);

        printf("Message sent to space!\n");

        //read messages from other planets
        if (msgrcv(msg_id, &msg, sizeof(msg), planet, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Incoming transmission: ");
        printf("%s\n", msg.message);
    }

    msgctl(msg_id, IPC_RMID, NULL);

    return 0;
}