//FormAI DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main() {
    DIR* proc_dir = opendir("/proc");
    struct dirent* ent;

    if (proc_dir == NULL) {
        perror("Failed to open proc directory");
        return EXIT_FAILURE;
    }

    printf("     PID | CMD\n");
    printf("----------+---------------------------\n");

    while ((ent = readdir(proc_dir)) != NULL) {
        if (ent->d_type != DT_DIR) {
            continue;
        }

        char* endptr;
        long pid = strtol(ent->d_name, &endptr, 10);
        if (*endptr != '\0') {
            continue;
        }

        char cmd[256];
        snprintf(cmd, sizeof(cmd), "/proc/%ld/cmdline", pid);
        FILE* cmd_file = fopen(cmd, "r");
        if (cmd_file == NULL) {
            continue;
        }

        size_t len = 0;
        ssize_t nread = getline(&cmd, &len, cmd_file);
        fclose(cmd_file);

        if (nread <= 0) {
            continue;
        }

        printf("%8ld | %s\n", pid, cmd);
    }

    closedir(proc_dir);
    return EXIT_SUCCESS;
}