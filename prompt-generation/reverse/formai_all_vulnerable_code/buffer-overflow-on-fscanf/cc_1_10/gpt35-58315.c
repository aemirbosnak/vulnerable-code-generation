//FormAI DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PID_LENGTH 15
#define MAX_NAME_LENGTH 255

int is_digit(char *pid) {
    int i = 0;
    while (pid[i] != '\0') {
        if (!isdigit(pid[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void get_proc_info(char *pid) {
    char proc_path[MAX_NAME_LENGTH];
    char stat_path[MAX_NAME_LENGTH];
    char proc_name[MAX_NAME_LENGTH];
    char state;
    int ppid, pgid;

    snprintf(proc_path, MAX_NAME_LENGTH, "/proc/%s", pid);
    snprintf(stat_path, MAX_NAME_LENGTH, "/proc/%s/stat", pid);

    FILE *stat_file = fopen(stat_path, "r");
    if (stat_file == NULL) {
        printf("%s: No such process\n", pid);
        return;
    }

    fscanf(stat_file, "%s %s %c %d %d", pid, proc_name, &state, &ppid, &pgid);
    fclose(stat_file);

    printf("%s %c %d %d %s\n", pid, state, ppid, pgid, proc_name);
}

void print_processes() {
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error opening /proc directory\n");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(proc_dir))) {
        if (entry->d_type == DT_DIR && is_digit(entry->d_name)) {
            get_proc_info(entry->d_name);
        }
    }
    closedir(proc_dir);
}

int parse_args(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (!is_digit(argv[i])) {
            printf("%s is not a valid pid\n", argv[i]);
            return -1;
        }
        get_proc_info(argv[i]);
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int arg_parse = parse_args(argc, argv);
    if (arg_parse < 0) {
        return 1;
    } else if (arg_parse == 0) {
        print_processes();
    }
    return 0;
}