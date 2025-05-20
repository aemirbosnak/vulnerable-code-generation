//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void printHeader() {
    printf("%-20s %-10s %-10s\n", "PROCESS NAME", "PID", "MEMORY");
}

int main() {
    DIR* dir;
    struct dirent* ent;
    char* path = "/proc/";

    if ((dir = opendir(path)) == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    printHeader();

    while ((ent = readdir(dir)) != NULL) {
        char* pid = ent->d_name;

        if (*pid >= '0' && *pid <= '9') {
            FILE* file;
            char fname[100], buf[1000];
            sprintf(fname, "%s%s/stat", path, pid);

            if ((file = fopen(fname, "r")) != NULL) {
                fgets(buf, sizeof(buf), file);
                fclose(file);

                char* nameStart = strchr(buf, '(') + 1;
                char* nameEnd = strchr(nameStart, ')');
                *nameEnd = '\0';

                char* p = nameStart;
                while (*p != '\0') {
                    if (*p == ' ') {
                        *p = '_';
                    }
                    ++p;
                }

                long unsigned int memoryUsage = 0;
                sprintf(fname, "%s%s/statm", path, pid);
                if ((file = fopen(fname, "r")) != NULL) {
                    fscanf(file, "%lu", &memoryUsage);
                    fclose(file);
                }

                printf("%-20s %-10s %-10lu\n", nameStart, pid, memoryUsage);
            }
        }
    }

    closedir(dir);
    
    return 0;
}