//FormAI DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;

    if(argc > 1) {
        dir = opendir(argv[1]);
        if(dir == NULL) {
            fprintf(stderr, "Error: Unable to open directory %s\n", argv[1]);
        }
    } else {
        dir = opendir("/proc");
        if(dir == NULL) {
            fprintf(stderr, "Error: Unable to open directory /proc\n");
        }
    }

    if(dir) {
        printf("%-6s %-30s %-10s\n", "PID", "Name", "Status");
        while((entry = readdir(dir)) != NULL) {
            if(entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char path[1024] = {0};
                snprintf(path, sizeof(path), "%s/%s/status", argc > 1 ? argv[1] : "/proc", entry->d_name);
                FILE *fp = fopen(path, "r");
                if(fp) {
                    char line[256];
                    char name[256];
                    int pid, status = -1;
                    while(fgets(line, sizeof(line), fp)) {
                        if(strncmp(line, "Name:", 5) == 0) {
                            sscanf(line + 6, "%s", name);
                        } else if(strncmp(line, "State:", 6) == 0) {
                            sscanf(line + 7, "%*s %d", &status);
                        } else if(strncmp(line, "Pid:", 4) == 0) {
                            sscanf(line + 5, "%d", &pid);
                        }
                    }
                    fclose(fp);
                    if(status != -1) {
                        printf("%-6d %-30s %-10s\n", pid, name, status == 0 ? "Running" : "Sleeping");
                    }
                }
            }
        }
        closedir(dir);
    }

    return 0;
}