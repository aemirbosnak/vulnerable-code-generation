//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 50
#define MAX_PRIORITY 10
#define MAX_WAIT_TIME 10

typedef struct {
    char *command;
    char **arguments;
    int priority;
    int wait_time;
} command_t;

int read_command(char *buffer, command_t *command) {
    char *token = strtok(buffer, " ");
    strcpy(command->command, token);
    command->arguments[0] = strtok(NULL, " ");
    int count = 1;
    while (count < MAX_ARGUMENTS && command->arguments[count]!= NULL) {
        command->arguments[count] = strtok(NULL, " ");
        count++;
    }
    command->priority = atoi(command->arguments[0]);
    command->wait_time = atoi(command->arguments[1]);
    return 0;
}

int execute_command(command_t *command) {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        execlp(command->command, command->command, NULL);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        fprintf(stderr, "Failed to fork()\n");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, WUNTRACED);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Command terminated by signal %d\n", WTERMSIG(status));
            return -1;
        } else {
            fprintf(stderr, "Command terminated abnormally\n");
            return -1;
        }
    }
}

int compare_priorities(const void *a, const void *b) {
    const command_t *command_a = (const command_t *)a;
    const command_t *command_b = (const command_t *)b;
    return command_a->priority - command_b->priority;
}

int main() {
    FILE *input_file;
    char buffer[MAX_COMMANDS];
    command_t commands[MAX_COMMANDS];
    int num_commands = 0;
    input_file = fopen("commands.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Failed to open commands.txt\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(buffer, MAX_COMMANDS, input_file)!= NULL) {
        read_command(buffer, &commands[num_commands]);
        num_commands++;
    }
    fclose(input_file);
    qsort(commands, num_commands, sizeof(command_t), compare_priorities);
    for (int i = 0; i < num_commands; i++) {
        execute_command(&commands[i]);
    }
    return 0;
}