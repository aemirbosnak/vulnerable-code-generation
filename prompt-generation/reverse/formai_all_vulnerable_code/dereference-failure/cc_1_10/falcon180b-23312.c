//Falcon-180B DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 20
#define MAX_COMMAND_LENGTH 50
#define MAX_ARGS 10
#define MAX_ARG_LENGTH 50
#define MAX_ENV_VARS 50
#define MAX_ENV_VAR_LENGTH 50

typedef struct {
    char *command;
    char **args;
    int num_args;
    char **env_vars;
    int num_env_vars;
} Process;

Process *process_create(char *command, int num_args, char **args, int num_env_vars, char **env_vars) {
    Process *process = malloc(sizeof(Process));
    process->command = strdup(command);
    process->args = malloc(sizeof(char *) * num_args);
    for (int i = 0; i < num_args; i++) {
        process->args[i] = strdup(args[i]);
    }
    process->num_args = num_args;
    process->env_vars = malloc(sizeof(char *) * num_env_vars);
    for (int i = 0; i < num_env_vars; i++) {
        process->env_vars[i] = strdup(env_vars[i]);
    }
    process->num_env_vars = num_env_vars;
    return process;
}

void process_destroy(Process *process) {
    free(process->command);
    for (int i = 0; i < process->num_args; i++) {
        free(process->args[i]);
    }
    free(process->args);
    for (int i = 0; i < process->num_env_vars; i++) {
        free(process->env_vars[i]);
    }
    free(process->env_vars);
    free(process);
}

int main() {
    Process *process = process_create("ls", 1, (char **) {"-l"}, 0, NULL);
    process_destroy(process);
    return 0;
}