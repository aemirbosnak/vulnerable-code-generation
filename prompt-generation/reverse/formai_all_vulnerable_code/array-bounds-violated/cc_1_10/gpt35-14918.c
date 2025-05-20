//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define PATH_SIZE 32

char* getExecutablePath(const char* pid) {
    char* buffer = malloc(PATH_SIZE * sizeof(char));
    char path[BUFFER_SIZE];
    sprintf(path, "/proc/%s/exe", pid);
    ssize_t len = readlink(path, buffer, PATH_SIZE - 1);
    if(len == -1) {
        perror("readlink");
    }
    buffer[len] = '\0';
    return buffer;
}

char* getStatPath(const char* pid) {
    char* buffer = malloc(PATH_SIZE * sizeof(char));
    char path[BUFFER_SIZE];
    sprintf(path, "/proc/%s/stat", pid);
    ssize_t len = readlink(path, buffer, PATH_SIZE - 1);
    if(len == -1) {
        perror("readlink");
    }
    buffer[len] = '\0';
    return buffer;
}

char* getCommand(const char* pid) {
    char* buffer = malloc(BUFFER_SIZE * sizeof(char));
    char cmdPath[BUFFER_SIZE];
    sprintf(cmdPath, "/proc/%s/cmdline", pid);
    FILE* file = fopen(cmdPath, "r");
    if(file == NULL) {
        perror("fopen");
    } else {
        size_t len = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        for(int i = 0; i < len; i++) {
            if(buffer[i] == '\0') {
                buffer[i] = ' ';
            }
        }
    }
    fclose(file);
    return buffer;
}

int parseStatFile(const char* path, long* result) {
    char buf[BUFFER_SIZE];
    FILE* file = fopen(path, "r");
    if(file == NULL) {
        return -1;
    }
    if(fgets(buf, BUFFER_SIZE, file) != NULL) {
        char* saveptr;
        char* token = strtok_r(buf, " ", &saveptr);
        int i = 0;
        while(token != NULL && i < 23) {
            if(i == 13) {
                result[i] = atol(token);
            } else if(i == 14) {
                result[i] = atol(token);
            } else if(i == 15) {
                result[i] = atol(token);
            }
            token = strtok_r(NULL, " ", &saveptr);
            i++;
        }
        fclose(file);
        return 0;
    }
    fclose(file);
    return -1;
}



int main(void) {
    DIR* dir;
    struct dirent* ent;
    int pid;
    long result[23];
    char* processName;
    char* cmdLine;
    printf("\033[1m%8s %20s %12s %6s %6s %12s %12s %12s\033[0m\n", "PID", "EXECUTABLE PATH", "COMMAND", "STATE", "TTY", "PV", "RSS", "SHR");
    dir = opendir("/proc");
    if(dir != NULL) {
        while((ent = readdir(dir)) != NULL) {
            if(isdigit(ent->d_name[0])) {
                pid = atoi(ent->d_name);
                processName = getExecutablePath(ent->d_name);
                cmdLine = getCommand(ent->d_name);
                if(parseStatFile(getStatPath(ent->d_name), result) == 0) {
                    printf("%8d %20s %12s %6c %6ld %12ld %12ld %12ld\n", pid, processName, cmdLine, result[2], result[6], result[22], result[23], result[24]);
                    free(processName);
                    free(cmdLine);
                    continue;
                }
                printf("%8d %20s %12s  ERROR\n", pid, processName, cmdLine);
                free(processName);
                free(cmdLine);
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
        return EXIT_FAILURE;
    }
    return 0;
}