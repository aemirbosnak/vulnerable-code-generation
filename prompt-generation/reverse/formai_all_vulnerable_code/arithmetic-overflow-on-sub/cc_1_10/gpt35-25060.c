//FormAI DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc/"

int main(){
    DIR *proc_dir;
    struct dirent *entry;
    FILE *fp;
    char cmd_line[255] = {0};
    char buf[255] = {0};
    char path[255] = {0};
    char user[255] = {0};
    int pid, ppid, cpu_time;
    float cpu_usage;

    printf("%10s %10s %15s %20s %s\n", "PID", "PPID", "USER", "CPU_USAGE", "COMMAND");

    if ((proc_dir = opendir(PROC_PATH)) == NULL) {
        perror("opendir() error");
        return EXIT_FAILURE;
    }

    while((entry = readdir(proc_dir)) != NULL) {
        if (!isdigit(entry->d_name[0]))
            continue;
        pid = strtol(entry->d_name, NULL, 10);
        memset(cmd_line, 0, sizeof(cmd_line));
        sprintf(path, "%s%s/cmdline", PROC_PATH, entry->d_name);
        if ((fp = fopen(path, "r")) != NULL) {
            if (fgets(cmd_line, sizeof(cmd_line), fp) == NULL) {
                fclose(fp);
                continue;
            }
            fclose(fp);
        }
        memset(buf, 0, sizeof(buf));
        sprintf(path, "%s%s/stat", PROC_PATH, entry->d_name);
        if ((fp = fopen(path, "r")) != NULL) {
            fgets(buf, sizeof(buf), fp);
            fclose(fp);
            sscanf(buf, "%d %*s %*s %d", &pid, &ppid);
        }
        memset(buf, 0, sizeof(buf));
        sprintf(path, "%s%s/statm", PROC_PATH, entry->d_name);
        if ((fp = fopen(path, "r")) != NULL) {
            fgets(buf, sizeof(buf), fp);
            fclose(fp);
        }
        memset(user, 0, sizeof(user));
        sprintf(path, "%s%s/stat", PROC_PATH, entry->d_name);
        if ((fp = fopen(path, "r")) != NULL) {
            int uid;
            char pname[255];
            fgets(buf, sizeof(buf), fp);
            fclose(fp);
            sscanf(buf, "%*d (%[^)]) %*c %d", pname, &uid);
			sprintf(user, "%d", uid);
        }

        cpu_time = atoi(strtok(buf, " "));
        cpu_usage = (float) cpu_time / 10000;
        printf("%10d %10d %15s %20.2f %s", pid, ppid, user, cpu_usage, cmd_line);
    }

    closedir(proc_dir);
    return 0;
}