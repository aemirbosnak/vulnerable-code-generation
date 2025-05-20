//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_LINE_LENGTH 80   /* Maximum length of a line of input */
#define MAX_COMMANDS 1000    /* Maximum number of commands that can be executed */

/* Struct to store the statistics for each process */
typedef struct _process_info {
    pid_t pid;
    char name[MAX_LINE_LENGTH];
    long unsigned int resident_memory;
    long unsigned int virtual_memory;
} ProcessInfo;

/* Main function */
int main(void) {
    char input[MAX_LINE_LENGTH];            /* The user's input */
    char *args[MAX_LINE_LENGTH/2 + 1];      /* Arguments to be passed to execvp */
    char *history[MAX_COMMANDS];            /* History of commands */
    int num_commands = 0;                   /* Number of commands entered so far */
    int do_exit = 0;                        /* Flag to indicate if we should exit */
    int i, j;                               /* Loop counter variables */
    int status;                             /* Status returned by waitpid */
    ProcessInfo processes[MAX_COMMANDS];    /* Array to store process information */
    int num_processes = 0;                  /* Number of running processes */
    time_t current_time;                    /* Current time for timestamping */

    /* Main loop */
    while (!do_exit) {
        /* Get user input */
        printf("crmon> ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';  /* Remove trailing newline character */

        /* Tokenize user input */
        i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        /* Handle empty input */
        if (args[0] == NULL) {
            continue;
        }

        /* Handle exit command */
        if (strcmp(args[0], "exit") == 0) {
            do_exit = 1;
            continue;
        }

        /* Handle history command */
        if (strcmp(args[0], "history") == 0) {
            for (j = 0; j < num_commands; j++) {
                printf("%d: %s\n", j+1, history[j]);
            }
            continue;
        }

        /* Handle crmon command */
        if (strcmp(args[0], "crmon") == 0) {
            /* Get current timestamp */
            time(&current_time);

            /* Print column headers */
            printf("%-10s %-30s %-20s %-20s\n", "PID", "NAME", "RESIDENT MEMORY", "VIRTUAL MEMORY");

            /* Print process information */
            for (j = 0; j < num_processes; j++) {
                printf("%-10d %-30s %-20lu %-20lu\n", processes[j].pid, processes[j].name,
                       processes[j].resident_memory, processes[j].virtual_memory);
            }

            /* Check if any processes have terminated */
            for (j = 0; j < num_processes; j++) {
                status = waitpid(processes[j].pid, NULL, WNOHANG);
                if (status != 0) {
                    printf("Process with PID %d has terminated.\n", processes[j].pid);
                    num_processes--;
                    processes[j] = processes[num_processes];
                    j--;
                } else {
                    /* Get the memory usage for the process */
                    char usage_command[MAX_LINE_LENGTH] = "ps -o rss=,vsz= -p ";
                    char pid_string[MAX_LINE_LENGTH];
                    sprintf(pid_string, "%d", processes[j].pid);
                    strcat(usage_command, pid_string);

                    FILE *usage_pipe = popen(usage_command, "r");
                    if (usage_pipe != NULL) {
                        fscanf(usage_pipe, "%lu %lu", &processes[j].resident_memory,
                               &processes[j].virtual_memory);
                        pclose(usage_pipe);
                    }
                }
            }

            /* Add current command to history */
            strcpy(history[num_commands % MAX_COMMANDS], input);
            num_commands++;

            continue;
        }

        /* Handle other commands */
        pid_t pid = fork();
        if (pid == 0) {
            /* Child process */
            execvp(args[0], args);

            /* If child process reaches here, something went wrong with execvp */
            printf("%s: command not found\n", args[0]);
            exit(0);
        } else if (pid > 0) {
            /* Parent process */
            /* Add child process info to array */
            processes[num_processes].pid = pid;
            strcpy(processes[num_processes].name, args[0]);
            num_processes++;

            /* Add current command to history */
            strcpy(history[num_commands % MAX_COMMANDS], input);
            num_commands++;
        } else {
            /* fork failed */
            printf("Error: fork() failed\n");
            exit(0);
        }
    }

    return 0;
}