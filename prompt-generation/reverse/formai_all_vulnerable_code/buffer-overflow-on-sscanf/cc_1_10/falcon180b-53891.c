//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROCESS_COUNT 5

typedef struct {
    int id;
    char name[20];
    int status;
    int memory_usage;
} process;

void get_process_info(process *process_array) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = popen("ps -eo pid,comm,vsz --sort=-vsz", "r");

    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%d %s %d", &process_array[i].id, process_array[i].name, &process_array[i].memory_usage);
        process_array[i].status = 1;
        i++;
    }

    pclose(fp);
}

void display_process_info(process *process_array) {
    int i;

    for (i = 0; i < PROCESS_COUNT; i++) {
        if (process_array[i].status == 1) {
            printf("%d. %s - Memory Usage: %d KB\n", process_array[i].id, process_array[i].name, process_array[i].memory_usage);
        } else {
            printf("%d. No process found.\n", i + 1);
        }
    }
}

int main() {
    process process_array[PROCESS_COUNT];

    get_process_info(process_array);
    display_process_info(process_array);

    return 0;
}