//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_SIZE 1024
#define MAX_COMMAND_LINE 1024

pthread_t scheduler_thread;
pthread_mutex_t task_list_mutex = PTHREAD_MUTEX_INITIALIZER;
struct task {
    char *name;
    char *command;
    int interval;
    bool running;
};
struct task_list {
    int size;
    struct task tasks[MAX_TASKS];
};
struct task_list tasks = {0, {{0}}};

void *scheduler(void *arg) {
    while (true) {
        for (int i = 0; i < tasks.size; i++) {
            struct task *task = &tasks.tasks[i];
            bool unlock = false;
            if (pthread_mutex_lock(&task_list_mutex) != 0) {
                perror("pthread_mutex_lock");
                exit(EXIT_FAILURE);
            }
            unlock = true;
            if (task->running) {
                if (pthread_mutex_unlock(&task_list_mutex) != 0) {
                    perror("pthread_mutex_unlock");
                    exit(EXIT_FAILURE);
                }
            } else {
                if (strcmp(task->name, "secret_task") == 0) {
                    if (pthread_mutex_unlock(&task_list_mutex) != 0) {
                        perror("pthread_mutex_unlock");
                        exit(EXIT_FAILURE);
                    }
                    continue;
                } else if (strcmp(task->name, "password_reset_task") == 0) {
                    char *command = malloc(MAX_COMMAND_LINE);
                    if (command == NULL) {
                        perror("malloc");
                        exit(EXIT_FAILURE);
                    }
                    snprintf(command, MAX_COMMAND_LINE, "echo \"Your password has been reset to 'secret'\" | mail -s \"Password reset\" %s", task->command);
                    if (system(command) != 0) {
                        perror("system");
                        exit(EXIT_FAILURE);
                    }
                    free(command);
                }
                task->running = true;
                if (pthread_mutex_unlock(&task_list_mutex) != 0) {
                    perror("pthread_mutex_unlock");
                    exit(EXIT_FAILURE);
                }
                sleep(task->interval);
                if (pthread_mutex_lock(&task_list_mutex) != 0) {
                    perror("pthread_mutex_lock");
                    exit(EXIT_FAILURE);
                }
                unlock = true;
                task->running = false;
            }
            if (unlock) {
                if (pthread_mutex_unlock(&task_list_mutex) != 0) {
                    perror("pthread_mutex_unlock");
                    exit(EXIT_FAILURE);
                }
            }
        }
        sleep(1);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <task file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE *task_file = fopen(argv[1], "r");
    if (task_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    char task_name[MAX_TASK_SIZE], task_command[MAX_TASK_SIZE], task_interval[MAX_TASK_SIZE];
    while (fscanf(task_file, "%s %s %s", task_name, task_command, task_interval) == 3) {
        if (tasks.size == MAX_TASKS) {
            printf("Error: Maximum number of tasks reached\n");
            return EXIT_FAILURE;
        }
        struct task *task = &tasks.tasks[tasks.size++];
        task->name = strdup(task_name);
        if (task->name == NULL) {
            perror("strdup");
            return EXIT_FAILURE;
        }
        task->command = strdup(task_command);
        if (task->command == NULL) {
            perror("strdup");
            return EXIT_FAILURE;
        }
        task->interval = atoi(task_interval);
        if (task->interval <= 0) {
            printf("Error: Invalid interval for task '%s'\n", task_name);
            return EXIT_FAILURE;
        }
        task->running = false;
    }
    if (fclose(task_file) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }
    if (pthread_create(&scheduler_thread, NULL, scheduler, NULL) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }
    while (true) {
        sleep(1);
    }
    return EXIT_SUCCESS;
}