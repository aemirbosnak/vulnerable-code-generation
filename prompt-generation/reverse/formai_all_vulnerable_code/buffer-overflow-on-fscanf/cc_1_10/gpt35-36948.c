//FormAI DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_LENGTH 6
#define MAX_NAME_LENGTH 256
#define MAX_CMDLINE_LENGTH 1024
#define MAX_STAT_LENGTH 2048

struct Process {
    char pid[MAX_PID_LENGTH];
    char name[MAX_NAME_LENGTH];
    char cmdline[MAX_CMDLINE_LENGTH];
    char stat[MAX_STAT_LENGTH];
};

void printHeader() {
    printf("%-6s %-30s %-50s %s\n", "PID", "NAME", "CMDLINE", "STAT");
}

void printProcess(const struct Process* pProcess) {
    printf("%-6s %-30s %-50s %s\n", pProcess->pid, pProcess->name, pProcess->cmdline, pProcess->stat);
}

void parseCmdline(const char* cmdline, char* output) {
    const char* pStart = cmdline;
    while (*pStart != '\0') {
        while (*pStart == ' ') {
            pStart++;
        }

        const char* pEnd = pStart;
        while (*pEnd != '\0' && *pEnd != ' ') {
            pEnd++;
        }

        const size_t length = pEnd - pStart;
        if (length > 0) {
            if (output[0] != '\0') {
                strcat(output, " ");
            }
            strncat(output, pStart, length);
        }

        pStart = pEnd;
    }
}

void parseStat(const char* stat, char* output) {
    const char* pStart = stat;
    while (*pStart != '\0' && *pStart != ')') {
        pStart++;
    }
    while (*pStart != '\0' && *pStart == ')') {
        pStart++;
    }
    while (*pStart != '\0' && *pStart == ' ') {
        pStart++;
    }

    const char* pEnd = pStart;
    while (*pEnd != '\0' && !isdigit(*pEnd)) {
        pEnd++;
    }

    const size_t length = pEnd - pStart;
    if (length > 0) {
        if (output[0] != '\0') {
            strcat(output, " ");
        }
        strncat(output, pStart, length);
    }
}

void getProcess(const char* pid, struct Process* pProcess) {
    char statPath[256];
    sprintf(statPath, "/proc/%s/stat", pid);
    
    FILE* statFile = fopen(statPath, "r");
    if (statFile == NULL) {
        return;
    }

    if (fscanf(statFile, "%s", pProcess->pid) != 1) {
        fclose(statFile);
        return;
    }

    fscanf(statFile, "%s", pProcess->name);
    parseStat(pProcess->name, pProcess->name);

    char stat[MAX_STAT_LENGTH] = "";
    fgets(stat, MAX_STAT_LENGTH, statFile);
    parseStat(stat, pProcess->stat);

    fclose(statFile);

    char cmdlinePath[256];
    sprintf(cmdlinePath, "/proc/%s/cmdline", pid);

    FILE* cmdlineFile = fopen(cmdlinePath, "r");
    if (cmdlineFile == NULL) {
        return;
    }

    fgets(pProcess->cmdline, MAX_CMDLINE_LENGTH, cmdlineFile);
    parseCmdline(pProcess->cmdline, pProcess->cmdline);

    fclose(cmdlineFile);
}

void viewProcesses() {
    DIR* procDir = opendir("/proc");
    if (procDir == NULL) {
        return;
    }

    struct dirent* pDirent;
    while ((pDirent = readdir(procDir)) != NULL) {
        const char* pName = pDirent->d_name;
        if (isdigit(*pName)) {
            struct Process process = { "", "", "", "" };
            getProcess(pName, &process);
            if (strlen(process.name) > 0 && strlen(process.cmdline) > 0 && strlen(process.stat) > 0) {
                printProcess(&process);
            }
        }
    }

    closedir(procDir);
}

int main() {
    printHeader();
    viewProcesses();
    return EXIT_SUCCESS;
}