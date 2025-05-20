//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define PROC_FILE "/proc/self/statm"

int main() {
    FILE *fp;
    int size;
    char buf[1024];
    int percent;
    int total = 0;
    int idle = 0;
    int i;
    int status;
    pid_t childpid;

    if ((fp = fopen(PROC_FILE, "r")) == NULL) {
        printf("Error opening file %s\n", PROC_FILE);
        exit(1);
    }

    fscanf(fp, "%*d %*s %*s %*s %*s %d", &size);
    fclose(fp);

    for (i = 0; i < size; i++) {
        buf[i] = '\0';
    }

    while (1) {
        idle = 0;
        percent = 0;
        total = 0;

        if ((childpid = fork()) == 0) {
            execlp("top", "top", "-b", "-n", "1", NULL);
            exit(0);
        } else {
            waitpid(childpid, &status, WUNTRACED);
        }

        if (WIFEXITED(status)) {
            sscanf(buf, "%*d %*s %*s %*s %d", &total);
            sscanf(buf, "%*d %*s %*s %d", &idle);
        }

        percent = ((total - idle) * 100) / total;

        printf("CPU Usage: %d%%\n", percent);

        sleep(1);
    }

    return 0;
}