//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 512
#define MAX_PROC 64

typedef struct proc_info {
    char name[256];
    int pid;
    long uptime;
    struct proc_info* next;
} proc_info_t;

proc_info_t* head = NULL;

void add_proc(char* name, int pid, long uptime) {
    proc_info_t* new_proc = malloc(sizeof(proc_info_t));
    strcpy(new_proc->name, name);
    new_proc->pid = pid;
    new_proc->uptime = uptime;
    new_proc->next = NULL;

    if (head == NULL) {
        head = new_proc;
    } else {
        proc_info_t* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_proc;
    }
}

int main() {
    while (1) {
        char buff[BUFF_SIZE];
        int pid;
        long uptime;

        printf("Enter process name: ");
        scanf("%s", buff);

        printf("Enter process pid: ");
        scanf("%d", &pid);

        printf("Enter process uptime: ");
        scanf("%ld", &uptime);

        add_proc(buff, pid, uptime);

        printf("Process added.\n");
    }
}