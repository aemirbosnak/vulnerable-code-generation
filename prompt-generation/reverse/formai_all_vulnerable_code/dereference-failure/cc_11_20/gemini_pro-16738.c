//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(void) {
    DIR *procdir = opendir("/proc");
    if (procdir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *procdirent;
    while ((procdirent = readdir(procdir)) != NULL) {
        if (procdirent->d_type != DT_DIR) {
            continue;
        }

        int pid = atoi(procdirent->d_name);
        if (pid <= 0) {
            continue;
        }

        char procfilepath[256];
        sprintf(procfilepath, "/proc/%d/status", pid);

        FILE *procfile = fopen(procfilepath, "r");
        if (procfile == NULL) {
            perror("fopen");
            continue;
        }

        char line[1024];
        while (fgets(line, sizeof(line), procfile) != NULL) {
            if (strcmp(line, "State:\n") == 0) {
                fgets(line, sizeof(line), procfile);
                printf("PID: %d\n", pid);
                printf("State: %s", line);
            } else if (strcmp(line, "Name:\n") == 0) {
                fgets(line, sizeof(line), procfile);
                printf("Name: %s", line);
            } else if (strcmp(line, "Uid:\n") == 0) {
                int uid;
                fscanf(procfile, "%d", &uid);
                struct passwd *pw = getpwuid(uid);
                printf("User: %s\n", pw->pw_name);
            } else if (strcmp(line, "Gid:\n") == 0) {
                int gid;
                fscanf(procfile, "%d", &gid);
                struct group *gr = getgrgid(gid);
                printf("Group: %s\n", gr->gr_name);
            } else if (strcmp(line, "Threads:\n") == 0) {
                int threads;
                fscanf(procfile, "%d", &threads);
                printf("Threads: %d\n", threads);
            } else if (strcmp(line, "StartTime:\n") == 0) {
                long long starttime;
                fscanf(procfile, "%lld", &starttime);
                time_t starttimet = starttime / 1000000;
                struct tm *starttm = localtime(&starttimet);
                printf("StartTime: %s", asctime(starttm));
            }
        }

        fclose(procfile);
        printf("\n");
    }

    closedir(procdir);
    return 0;
}