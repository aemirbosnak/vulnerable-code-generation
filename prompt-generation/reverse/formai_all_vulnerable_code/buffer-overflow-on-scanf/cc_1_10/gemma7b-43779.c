//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define HIST_SIZE 10

#define HIST_CMD_LEN 128

char hist[HIST_SIZE][HIST_CMD_LEN];

void hist_add(char **hist, char *cmd)
{
    int i = 0;
    for (; hist[i][0] && hist[i][0] != '\0'; i++) {}

    memcpy(hist[i], cmd, HIST_CMD_LEN);
    hist[i + 1][0] = '\0';
}

char *hist_get(char **hist, int idx)
{
    return hist[idx][0] ? hist[idx][0] : NULL;
}

void shell()
{
    char cmd[MAX_CMD_LEN];
    char *argv[MAX_CMD_LEN];
    int idx = 0;

    printf("$ ");

    // Get the command line input
    scanf("%s", cmd);

    // Parse the command line into arguments
    argv[0] = strdup(cmd);
    char *p = argv[0] + strlen(cmd) + 1;
    int i = 1;
    while (*p) {
        argv[i++] = strdup(p);
        p++;
    }

    // Add the command to the history
    hist_add(hist, cmd);

    // Execute the command
    system(cmd);

    // Free the memory allocated for the arguments
    for (i = 0; argv[i] != NULL; i++) {
        free(argv[i]);
    }
}

int main()
{
    shell();

    return 0;
}