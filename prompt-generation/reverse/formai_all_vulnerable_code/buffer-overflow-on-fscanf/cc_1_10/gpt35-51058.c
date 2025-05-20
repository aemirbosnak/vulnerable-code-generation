//FormAI DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>

void printHeader() {
    printf("+----------------+----------------+----------------+---------------+\n");
    printf("|   PID        \t|   Name        \t|   Status      \t|   Memory (MB) |\n");
    printf("+----------------+----------------+----------------+---------------+\n");
}

void printProcessInfo(char *pid, char *name, char *status, char *memory) {
    printf("|   %-12s|   %-12s|   %-12s|   %-12s|\n", pid, name, status, memory);
}

void readProcessList() {
    DIR *dir;
    struct dirent *ent;

    char path[100];
    char pid[10];
    char name[50];
    char status[20];
    char memory[20];

    FILE *fp;
    while(1) {
        dir = opendir("/proc");
        if (dir != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                if (isdigit(*ent->d_name)) {
                    sprintf(path, "/proc/%s/stat", ent->d_name);
                    fp = fopen(path, "r");
                    if (fp) {
                        fscanf(fp, "%s %s %s", pid, name, status);
                        fclose(fp);

                        sprintf(path, "/proc/%s/status", ent->d_name);
                        fp = fopen(path, "r");
                        if (fp) {
                            while(fscanf(fp, "%s", memory) == 1) {
                                if(strcmp(memory, "VmSize:") == 0) {
                                    fscanf(fp, "%s", memory);
                                    sprintf(memory, "%.2f", atof(memory)/1024);
                                    break;
                                }
                            }
                            fclose(fp);
                        }

                        printProcessInfo(pid, name, status, memory);
                    }
                }
            }
            closedir(dir);
        }
        printf("-----------------------------------------------------------\n");
        sleep(1);
        system("clear");
        printHeader();
    }
}

int main() {
    srand(time(NULL));
    printf("Random System Process Viewer\n\n");
    printf("Press CTRL + C to exit.\n");
    printf("-----------------------------------------------------------\n");
    printHeader();
    readProcessList();
    return 0;
}