//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <signal.h>

// Function to get process information
void getProcessInfo(int pid)
{
    struct rusage usage;
    struct utsname uname;
    char buf[1024];
    char username[1024];

    // Get process usage
    getrusage(RUSAGE_SELF, &usage);

    // Get process name
    char* s = (char*) getenv("SUDO_COMMAND");
    strcpy(buf, s);
    char* cmd = strtok(buf, " ");
    strcpy(username, cmd);

    // Get process user
    getlogin_r(username, &uname);

    // Get process id
    pid_t p = fork();
    if (p < 0) {
        perror("fork");
        exit(1);
    }
    if (p > 0) {
        waitpid(p, NULL, 0);
        return;
    }

    int status = 0;
    waitpid(p, &status, WNOHANG);

    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        printf("Process %d exited normally\n", pid);
    } else {
        printf("Process %d is running\n", pid);
    }

    printf("User: %s\n", uname.nodename);
    printf("CPU usage: %ld.%03ld seconds\n", (long) usage.ru_utime.tv_sec, (long) usage.ru_utime.tv_usec);
    printf("Max resident set size: %ld kB\n", (long) usage.ru_maxrss);
    printf("Number of threads: %ld\n", (long) usage.ru_nvcsw);
    printf("Number of blocked signals: %ld\n", (long) usage.ru_nivcsw);
    printf("Number of voluntary context switches: %ld\n", (long) usage.ru_nivcsw);
    printf("Number of involuntary context switches: %ld\n", (long) usage.ru_nivcsw);
}

int main(int argc, char* argv[])
{
    int pid;
    int status;
    char* cmd = argv[1];
    char* user = getenv("SUDO_COMMAND");
    char* cmd_user = strtok(user, " ");

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid > 0) {
        waitpid(pid, &status, 0);
        return 0;
    }

    int p = fork();
    if (p < 0) {
        perror("fork");
        exit(1);
    }
    if (p > 0) {
        waitpid(p, &status, 0);
        return 0;
    }

    if (getuid() == 0) {
        printf("This program is designed to run as a regular user.\n");
        printf("Please run the program as a regular user or use sudo.\n");
        exit(1);
    }

    if (chdir("/proc")) {
        perror("chdir");
        exit(1);
    }

    DIR* dir = opendir(".");
    if (!dir) {
        perror("opendir");
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_name[0] == '.' || entry->d_name[0] == '_') {
            continue;
        }
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, "exe") == 0 && strstr(entry->d_name, "/usr/bin/")!= NULL) {
                pid = fork();
                if (pid < 0) {
                    perror("fork");
                    exit(1);
                }
                if (pid > 0) {
                    waitpid(pid, &status, 0);
                    continue;
                }

                if (strcmp(cmd, entry->d_name) == 0) {
                    pid = fork();
                    if (pid < 0) {
                        perror("fork");
                        exit(1);
                    }
                    if (pid > 0) {
                        waitpid(pid, &status, 0);
                        continue;
                    }

                    if (getuid()!= 0) {
                        printf("Permission denied.\n");
                        exit(1);
                    }

                    if (chdir(entry->d_name)) {
                        perror("chdir");
                        exit(1);
                    }

                    getProcessInfo(getpid());
                }
            }
        }
    }

    closedir(dir);
    return 0;
}