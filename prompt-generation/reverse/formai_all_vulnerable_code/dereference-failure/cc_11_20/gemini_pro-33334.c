//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct _task {
    pid_t pid;
    int interval;
    char *command;
} task;

int main(int argc, char *argv[]) {
    int num_tasks;
    task *tasks;
    int i, status;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num_tasks> [<interval> <command>]...\n", argv[0]);
        return EXIT_FAILURE;
    }

    num_tasks = atoi(argv[1]);
    if (num_tasks <= 0) {
        fprintf(stderr, "Invalid number of tasks: %d\n", num_tasks);
        return EXIT_FAILURE;
    }

    tasks = malloc(sizeof(task) * num_tasks);
    if (tasks == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (i = 0; i < num_tasks; i++) {
        tasks[i].pid = 0;
        tasks[i].interval = 0;
        tasks[i].command = NULL;
    }

    // parse the command line arguments

    for (i = 2; i + 1 < argc; i += 3) {
        int interval = atoi(argv[i]);
        char *command = argv[i + 1];

        if (interval <= 0) {
            fprintf(stderr, "Invalid interval: %d\n", interval);
            free(tasks);
            return EXIT_FAILURE;
        }

        tasks[i / 3].interval = interval;
        tasks[i / 3].command = strdup(command);
    }

    // start the tasks

    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].interval == 0) {
            continue;
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            free(tasks);
            return EXIT_FAILURE;
        } else if (pid == 0) {
            // child process
            char *args[] = { tasks[i].command, NULL };
            execvp(tasks[i].command, args);
            perror("execvp");
            _exit(EXIT_FAILURE);
        } else {
            // parent process
            tasks[i].pid = pid;
        }
    }

    // wait for the tasks to finish

    while (wait(&status) > 0) {
        // check the status of each task

        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].pid == WEXITSTATUS(status)) {
                // task has finished
                free(tasks[i].command);
                tasks[i].pid = 0;
            }
        }
    }

    // clean up

    free(tasks);
    return EXIT_SUCCESS;
}