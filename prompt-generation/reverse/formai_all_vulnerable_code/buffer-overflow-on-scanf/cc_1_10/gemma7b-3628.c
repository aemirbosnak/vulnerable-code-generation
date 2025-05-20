//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

char history[MAX_HISTORY][1024];
int history_index = 0;

void store_history(char *cmd)
{
    if (history_index >= MAX_HISTORY)
    {
        history_index = MAX_HISTORY - 1;
    }

    strcpy(history[history_index++], cmd);
}

void print_history()
{
    int i;
    for (i = 0; i < history_index; i++)
    {
        printf("%s\n", history[i]);
    }
}

int main()
{
    char cmd[1024];

    printf("$ ");

    scanf("%s", cmd);

    store_history(cmd);

    while (strcmp(cmd, "exit") != 0)
    {
        printf("Output: %s\n", cmd);

        printf("$ ");

        scanf("%s", cmd);

        store_history(cmd);
    }

    print_history();

    return 0;
}