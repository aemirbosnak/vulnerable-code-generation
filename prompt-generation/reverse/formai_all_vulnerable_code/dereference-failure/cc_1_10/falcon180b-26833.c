//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <sender|receiver> <message>\n", argv[0]);
        return 1;
    }

    char *message = argv[2];
    int message_length = strlen(message);

    if (message_length > BUFFER_SIZE) {
        fprintf(stderr, "Message too long.\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    strncpy(buffer, message, BUFFER_SIZE);

    int sender_pid = fork();

    if (sender_pid == -1) {
        perror("fork");
        return 1;
    }

    if (sender_pid == 0) {
        if (strcmp(argv[1], "sender") == 0) {
            int receiver_pid = fork();

            if (receiver_pid == -1) {
                perror("fork");
                return 1;
            }

            if (receiver_pid == 0) {
                close(0);
                dup(1);
                dup(1);

                execlp("receiver", "receiver", argv[1], buffer, NULL);

                perror("execlp");
                return 1;
            }

            wait(NULL);
        } else {
            fprintf(stderr, "Invalid role: %s\n", argv[1]);
            return 1;
        }
    } else {
        if (strcmp(argv[1], "receiver") == 0) {
            close(1);
            dup(0);

            execlp("receiver", "receiver", argv[1], buffer, NULL);

            perror("execlp");
            return 1;
        } else {
            fprintf(stderr, "Invalid role: %s\n", argv[1]);
            return 1;
        }
    }

    return 0;
}