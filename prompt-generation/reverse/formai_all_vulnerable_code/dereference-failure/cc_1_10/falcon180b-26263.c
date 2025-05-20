//Falcon-180B DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define DELAY 3

typedef struct command {
    char *name;
    int (*func)(void);
} Command;

void execute_command(Command *cmd) {
    printf("Executing %s...\n", cmd->name);
    cmd->func();
}

int sleep_command(void) {
    printf("Sleeping for %d seconds...\n", DELAY);
    sleep(DELAY);
    return 0;
}

int date_command(void) {
    time_t now = time(NULL);
    char *date_str = ctime(&now);
    printf("Current date and time: %s\n", date_str);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command [args]\n", argv[0]);
        return 1;
    }

    Command commands[MAX_COMMANDS] = {
        {"sleep", sleep_command},
        {"date", date_command}
    };

    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(commands[i].name, argv[1]) == 0) {
            execute_command(&commands[i]);
            return 0;
        }
    }

    printf("Unknown command: %s\n", argv[1]);
    return 1;
}