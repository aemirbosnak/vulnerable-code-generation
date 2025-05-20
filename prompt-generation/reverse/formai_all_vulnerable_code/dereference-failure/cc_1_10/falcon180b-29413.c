//Falcon-180B DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define MAX_PROCESSES 1024

// Function to split a line into words
void split_line(char *line, char **words) {
    int count = 0;
    char *token;

    token = strtok(line, " ");
    while (token!= NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }
    words[count] = NULL;
}

// Function to execute a command and return its output
char *execute_command(char *command) {
    FILE *fp;
    char *output = NULL;
    size_t len = 0;

    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error executing command: %s\n", strerror(errno));
        return NULL;
    }

    while (fgets(output + len, MAX_LINE_SIZE - len, fp)!= NULL) {
        len += strlen(output + len);
    }

    pclose(fp);
    output[len] = '\0';

    return output;
}

// Function to list all running processes
void list_processes() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *words[MAX_PROCESSES];
    int count = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc/self/status: %s\n", strerror(errno));
        return;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        split_line(line, words);
        if (count >= MAX_PROCESSES) {
            break;
        }
        printf("%s\n", words[0]);
        count++;
    }

    fclose(fp);
}

// Function to kill a process by its PID
void kill_process(int pid) {
    char command[MAX_LINE_SIZE];

    snprintf(command, MAX_LINE_SIZE, "kill -9 %d", pid);
    execute_command(command);
}

// Main function
int main() {
    int pid;
    char input[MAX_LINE_SIZE];

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_LINE_SIZE, stdin);

        split_line(input, NULL);
        if (strcmp(input, "list") == 0) {
            list_processes();
        } else if (strcmp(input, "kill") == 0) {
            scanf("%d", &pid);
            kill_process(pid);
        } else {
            execute_command(input);
        }
    }

    return 0;
}