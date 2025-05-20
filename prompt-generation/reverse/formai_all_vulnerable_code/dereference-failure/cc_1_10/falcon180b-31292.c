//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>

#define BUF_SIZE 1024

char *get_process_name(pid_t pid) {
    char path[BUF_SIZE];
    snprintf(path, BUF_SIZE, "/proc/%d/cmdline", pid);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }

    char *name = NULL;
    size_t size = 0;

    while (getline(&name, &size, file)!= -1) {
        if (name[strcspn(name, "\n")]!= '\0') {
            fprintf(stderr, "Process name too long\n");
            free(name);
            name = NULL;
            break;
        }
        break;
    }

    fclose(file);

    return name;
}

void print_process_info(pid_t pid, int indent) {
    char *name = get_process_name(pid);
    if (name == NULL) {
        printf("%*s[unknown]\n", indent, "");
        return;
    }

    printf("%*s%s\n", indent, "", name);

    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type!= DT_DIR) {
            continue;
        }

        pid_t child_pid = atoi(entry->d_name);
        if (child_pid <= 0 || child_pid == getpid()) {
            continue;
        }

        print_process_info(child_pid, indent + 2);
    }

    closedir(dir);
}

int main() {
    print_process_info(1, 0); // Print info about init process

    return 0;
}