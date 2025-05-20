//FormAI DATASET v1.0 Category: System process viewer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define PROCESS_NAME_LENGTH 256
#define PROCESS_STAT_FILE "/proc/%d/stat"
#define PROCESS_COMM_FILE "/proc/%d/comm"
#define SEARCH_KEYWORD_LENGTH 256

typedef struct {
    int pid;
    char name[PROCESS_NAME_LENGTH];
    char state;
    int ppid;
} process_info;

int is_number(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

int read_process_stat_file(int pid, process_info *process) {
    char filename[MAX_LINE_LENGTH];
    snprintf(filename, MAX_LINE_LENGTH, PROCESS_STAT_FILE, pid);

    FILE *f = fopen(filename, "r");
    if (!f) {
        return 0;
    }

    if (fscanf(f, "%d %s %c %d", &process->pid, process->name, &process->state, &process->ppid) != 4) {
        fclose(f);
        return 0;
    }

    fclose(f);
    return 1;
}

int read_process_comm_file(int pid, process_info *process) {
    char filename[MAX_LINE_LENGTH];
    snprintf(filename, MAX_LINE_LENGTH, PROCESS_COMM_FILE, pid);

    FILE *f = fopen(filename, "r");
    if (!f) {
        return 0;
    }

    if (fgets(process->name, PROCESS_NAME_LENGTH, f) == NULL) {
        fclose(f);
        return 0;
    }

    fclose(f);
    return 1;
}

void print_process_info(process_info *process) {
    printf("%6d  %-20s  %c  %6d\n", process->pid, process->name, process->state, process->ppid);
}

void print_process_list(const char *search_keyword) {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    printf("PID     NAME                   STATE  PPID\n");

    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            int pid = atoi(entry->d_name);
            process_info process;

            if (read_process_stat_file(pid, &process) && read_process_comm_file(pid, &process)) {
                if (search_keyword == NULL || strstr(process.name, search_keyword) != NULL) {
                    print_process_info(&process);
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    char search_keyword[SEARCH_KEYWORD_LENGTH] = "";

    if (argc == 2) {
        strncpy(search_keyword, argv[1], SEARCH_KEYWORD_LENGTH);
    }

    print_process_list(search_keyword);

    return 0;
}