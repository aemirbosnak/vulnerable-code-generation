//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCS 10
#define PROC_LINE_LEN 256
#define PROC_NAME_LEN 32

typedef struct {
    pid_t pid;
    char name[PROC_NAME_LEN];
} process_t;

void spawn_ps(process_t procs[], int *num_procs) {
    FILE *ps_file;
    char line[PROC_LINE_LEN];
    char name[PROC_NAME_LEN];
    int i;

    ps_file = popen("ps -o pid,comm --no-headers", "r");
    if (ps_file == NULL) {
        perror("ps command failed");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, PROC_LINE_LEN, ps_file) != NULL) {
        sscanf(line, "%d %s", &procs[*num_procs].pid, name);
        strncpy(procs[*num_procs].name, name, PROC_NAME_LEN);
        (*num_procs)++;
        if (*num_procs == MAX_PROCS) break;
    }

    pclose(ps_file);
}

void print_surreal_processes(process_t procs[], int num_procs) {
    int i;
    for (i = 0; i < num_procs; i++) {
        printf("\nProcess %d - %s\n", procs[i].pid, procs[i].name);
        printf("In a dreamlike state, it dances with the memory.\n");
        printf("Colors of %s swirl and intermingle like a surrealist painting.\n", procs[i].name);
    }
}

int main() {
    process_t procs[MAX_PROCS];
    int num_procs = 0;

    spawn_ps(procs, &num_procs);
    print_surreal_processes(procs, num_procs);

    return EXIT_SUCCESS;
}