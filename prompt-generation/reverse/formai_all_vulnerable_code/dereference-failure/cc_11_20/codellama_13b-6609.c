//Code Llama-13B DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
// Romeo and Juliet system administration program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 10

int main() {
    char cmd[MAX_CMD_LEN];
    char *args[MAX_ARGS];
    char *ptr;
    int status;

    while (1) {
        printf("Romeo> ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        ptr = strtok(cmd, " ");
        int i = 0;
        while (ptr != NULL) {
            args[i++] = ptr;
            ptr = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        if (strcmp(args[0], "shutdown") == 0) {
            if (args[1] == NULL) {
                printf("Usage: shutdown [now|reboot|halt]\n");
            } else if (strcmp(args[1], "now") == 0) {
                system("shutdown -P now");
            } else if (strcmp(args[1], "reboot") == 0) {
                system("shutdown -r now");
            } else if (strcmp(args[1], "halt") == 0) {
                system("shutdown -h now");
            } else {
                printf("Usage: shutdown [now|reboot|halt]\n");
            }
        } else if (strcmp(args[0], "reboot") == 0) {
            if (args[1] == NULL) {
                system("shutdown -r now");
            } else {
                printf("Usage: reboot\n");
            }
        } else if (strcmp(args[0], "halt") == 0) {
            if (args[1] == NULL) {
                system("shutdown -h now");
            } else {
                printf("Usage: halt\n");
            }
        } else if (strcmp(args[0], "kill") == 0) {
            if (args[1] == NULL || args[2] == NULL) {
                printf("Usage: kill [pid] [signal]\n");
            } else {
                kill(atoi(args[1]), atoi(args[2]));
            }
        } else {
            printf("Invalid command: %s\n", args[0]);
        }
    }

    return 0;
}