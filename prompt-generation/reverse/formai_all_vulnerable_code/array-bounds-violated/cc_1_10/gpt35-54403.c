//FormAI DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#define CMD_BUFFER_LENGTH 1000

void executeCommand(char *command);
void executeAndRedirect(char *command, char *fileName, bool appendToFile);
void executePipeCommands(char *command1, char *command2);
void executeBackgroundCommands(char *command);

int main() {
    char command[CMD_BUFFER_LENGTH];
    while (1) {
        printf(">> ");
        fflush(stdout);
        fgets(command, CMD_BUFFER_LENGTH, stdin);
        command[strlen(command) - 1] = '\0';   // remove trailing '\n'
        
        // check for empty command
        if (strlen(command) == 0) {
            continue;
        }
        
        // check for exit command
        if (strcmp(command, "exit") == 0) {
            exit(0);
        }
        
        // check for pipe command
        char *pipePos = strchr(command, '|');
        if (pipePos != NULL) {
            *pipePos = '\0';
            pipePos++;
            executePipeCommands(command, pipePos);
            continue;
        }
        
        // check for background command
        if (command[strlen(command) - 1] == '&') {
            command[strlen(command) - 1] = '\0';
            executeBackgroundCommands(command);
            continue;
        }
        
        // check for output redirection
        char *outputPos = strchr(command, '>');
        if (outputPos != NULL) {
            *outputPos = '\0';
            outputPos++;
            bool append = false;
            if (outputPos[0] == '>') {
                append = true;
                outputPos++;
            }
            executeAndRedirect(command, outputPos, append);
            continue;
        }
        
        executeCommand(command);
    }
}

void executeCommand(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[] = {"/bin/sh", "-c", command, NULL};
        execv("/bin/sh", args);
        perror("execv() failed");
        exit(1);
    }
    else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
    }
    else {
        perror("fork() failed");
    }
}

void executeAndRedirect(char *command, char *fileName, bool appendToFile) {
    int outFile;
    if (appendToFile) {
        outFile = open(fileName, O_WRONLY | O_APPEND | O_CREAT, 0644);
    }
    else {
        outFile = open(fileName, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    }
    
    pid_t pid = fork();
    if (pid == 0) {
        dup2(outFile, STDOUT_FILENO);
        char *args[] = {"/bin/sh", "-c", command, NULL};
        execv("/bin/sh", args);
        perror("execv() failed");
        exit(1);
    }
    else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        close(outFile);
    }
    else {
        perror("fork() failed");
    }
}

void executePipeCommands(char *command1, char *command2) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe() failed");
        return;
    }
    
    pid_t pid1 = fork();
    if (pid1 == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        char *args[] = {"/bin/sh", "-c", command1, NULL};
        execv("/bin/sh", args);
        perror("execv() failed");
        exit(1);
    }
    else if (pid1 > 0) {
        close(pipefd[1]);
        pid_t pid2 = fork();
        if (pid2 == 0) {
            dup2(pipefd[0], STDIN_FILENO);
            char *args[] = {"/bin/sh", "-c", command2, NULL};
            execv("/bin/sh", args);
            perror("execv() failed");
            exit(1);
        }
        else if (pid2 > 0) {
            close(pipefd[0]);
            int status;
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
        }
        else {
            perror("fork() failed");
        }
    }
    else {
        perror("fork() failed");
    }
}

void executeBackgroundCommands(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        setsid();   // create a new session and become the session leader
        signal(SIGINT, SIG_IGN);    // ignore interrupt signals
        signal(SIGQUIT, SIG_IGN);   // ignore quit signals
        signal(SIGTSTP, SIG_IGN);   // ignore terminal stop signals
        char *args[] = {"/bin/sh", "-c", command, NULL};
        execv("/bin/sh", args);
        perror("execv() failed");
        exit(1);
    }
    else if (pid > 0) {
        printf("Background process started with PID %d\n", pid);
    }
    else {
        perror("fork() failed");
    }
}