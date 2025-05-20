//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define NAME_LENGTH 256

typedef struct {
    int id;             // the id of the process
    char name[NAME_LENGTH]; // the name of the process
    char state[20];    // the state of the process
} Process;

void print_header() {
    printf("    ========================\n");
    printf("     The Royal Process Viewer\n");
    printf("    ========================\n");
    printf("    ID   |   Quest Name   |   Status\n");
    printf("    ----------------------------\n");
}

void print_process(Process *p) {
    printf("    %3d   |   %-12s   |   %-10s\n", p->id, p->name, p->state);
}

int fetch_processes(Process *processes) {
    FILE *fp;
    char line[512];
    int count = 0;

    // Call the 'ps' command to gather process information
    fp = popen("ps -eo pid,comm,state --sort=pid", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return -1;
    }

    // Skip the first line (header)
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL && count < MAX_PROCESSES) {
        sscanf(line, "%d %s %s", &processes[count].id, processes[count].name, processes[count].state);
        count++;
    }

    pclose(fp);
    return count;
}

void display_processes() {
    Process processes[MAX_PROCESSES];
    int count = fetch_processes(processes);

    if (count < 0) {
        printf("Alas! Could not fetch the royal quests.\n");
        return;
    }

    print_header();
    for (int i = 0; i < count; i++) {
        print_process(&processes[i]);
    }
    printf("    ========================\n");
}

int main() {
    printf("Greeting, noble seeker! You have summoned the Royal Process Viewer.\n");
    display_processes();
    printf("May your quests be fruitful and your processes swift!\n");

    return 0;
}