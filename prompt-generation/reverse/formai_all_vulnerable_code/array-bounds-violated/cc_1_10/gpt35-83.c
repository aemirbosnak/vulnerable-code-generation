//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define CMD_ARGS_MAX 100
#define CMD_LENGTH_MAX 1024
#define HISTORY_MAX 100

char history[HISTORY_MAX][CMD_LENGTH_MAX];
int history_counter = 0;

void execute_command(char **args, int redirect, char *filename) {
    int pid = fork();
    if (pid == -1) {
        printf("Fork Failed\n");
        exit(1);
    } else if (pid == 0) {
        if (redirect) {
            int fd;
            if (filename == NULL) {
                printf("Redirection error: Invalid filename\n");
                exit(1);
            }
            if (access(filename, F_OK) != -1) {
                unlink(filename);
            }
            fd = creat(filename, 0644);
            if (fd == -1) {
                printf("Failed to open '%s'\n", filename);
                exit(1);
            }
            if (dup2(fd, STDOUT_FILENO) == -1) {
                printf("Error in dup2\n");
                exit(1);
            }
            close(fd);
        }
        if (execvp(args[0], args) == -1) {
            printf("Command not found\n");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) != 0) {
                printf("Command failed\n");
            }
        }
    }
}

int parse_command(char *cmd, char **args, int *flag, char **filename) {
    int i = 0, j = 0, k = 0;
    *flag = 0;
    *filename = NULL;
    while (cmd[i] != '\0') {
        if (cmd[i] == ' ') {
            if (j != 0) {
                args[k][j] = '\0';
                k++;
                j = 0;
            }
        } else if (cmd[i] == '>') {
            *flag = 1;
            i++;
            while (cmd[i] == ' ' && cmd[i] != '\0') {
                i++;
            }
            if (cmd[i] == '\0') {
                printf("Redirection error: Invalid filename\n");
                return -1;
            }
            j = 0;
            *filename = (char *) malloc(sizeof(char) * (strlen(cmd) - i + 1));
            while (cmd[i] != '\0') {
                (*filename)[j++] = cmd[i++];
            }
            (*filename)[j] = '\0';
            break;
        } else {
            args[k][j] = cmd[i];
            j++;
        }
        i++;
    }
    if (j != 0) {
        args[k][j] = '\0';
        k++;
    }
    args[k] = NULL;
    return k;
}

void execute_history_command(char **args) {
    int i;
    if (args[1] != NULL) {
        printf("Invalid Arguments\nUsage: history\n");
        return;
    }
    printf("History:\n");
    for (i = 0; i < history_counter; i++) {
        printf("  %d  %s\n", i + 1, history[i]);
    }
}

void execute_exit_command(char **args) {
    if (args[1] != NULL) {
        printf("Invalid Arguments\nUsage: exit\n");
        return;
    }
    printf("Exiting Shell...\n");
    exit(0);
}

void execute_bang_command(char **args) {
    int histnum;
    char *histcmd;
    if (args[1] == NULL) {
        printf("Invalid Arguments\nUsage: !<history_number>\n");
        return;
    }
    if (args[2] != NULL) {
        printf("Too many arguments\nUsage: !<history_number>\n");
        return;
    }
    if (args[1][0] != '!') {
        printf("Invalid Command\nUsage: !<history_number>\n");
        return;
    }
    if (args[1][1] == '\0') {
        histnum = history_counter;
    } else if (!isdigit(args[1][1])) {
        printf("Invalid Command\nUsage: !<history_number>\n");
        return;
    } else {
        histnum = atoi(&args[1][1]);
    }
    if (histnum < 1 || histnum > history_counter) {
        printf("History index out of range\n");
        return;
    }
    histcmd = history[histnum - 1];
    printf("Executing Command: %s\n", histcmd);
    execute_command(args, 0, NULL);
}

void handle_signal(int signum) {
    printf("\nShell Interrupted! Type 'exit' to exit shell.\n");
    printf("> ");
    fflush(stdout);
}

void run_shell() {
    char cmd[CMD_LENGTH_MAX];
    char *args[CMD_ARGS_MAX];
    int cmd_count = 0, flag, i, len;
    char *filename;
    signal(SIGINT, handle_signal);
    printf("*** Type 'exit' to exit shell. ***\n");
    while (1) {
        printf("> ");
        if (fgets(cmd, CMD_LENGTH_MAX, stdin)) {
            len = strlen(cmd) - 1;
            if (cmd[len] == '\n') {
                cmd[len] = '\0';
            }
            if (strcmp(cmd, "") == 0) {
                continue;
            }
            strcpy(history[history_counter], cmd);
            history_counter++;
            if (history_counter == HISTORY_MAX) {
                for (i = 0; i < HISTORY_MAX - 1; i++) {
                    strcpy(history[i], history[i + 1]);
                }
                history_counter--;
            }
            cmd_count = parse_command(cmd, args, &flag, &filename);
            if (cmd_count == -1) {
                continue;
            }
            if (strcmp(args[0], "history") == 0) {
                execute_history_command(args);
            } else if (strcmp(args[0], "exit") == 0) {
                execute_exit_command(args);
            } else if (args[0][0] == '!') {
                execute_bang_command(args);
            } else {
                execute_command(args, flag, filename);
            }
        } else {
            exit(0);
        }
    }
}

int main() {
    run_shell();
    return 0;
}