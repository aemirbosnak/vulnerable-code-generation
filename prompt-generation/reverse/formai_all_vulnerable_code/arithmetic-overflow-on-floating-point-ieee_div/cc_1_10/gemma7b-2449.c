//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>

#define CPU_USAGE_FILE "/proc/stat"

int main() {
    FILE *fp;
    char buff[1024];
    int user, sys, idle, total;
    long int prev_user, prev_sys, prev_idle, prev_total;
    long int usage_diff;
    int i = 0;

    prev_user = prev_sys = prev_idle = prev_total = 0;

    while (1) {
        fp = fopen(CPU_USAGE_FILE, "r");
        if (fp == NULL) {
            perror("Error opening file");
            exit(1);
        }

        fgets(buff, 1024, fp);
        fclose(fp);

        user = sys = idle = total = 0;
        for (i = 0; i < 3; i++) {
            switch (i) {
                case 0:
                    user = atoi(buff + 13);
                    break;
                case 1:
                    sys = atoi(buff + 16);
                    break;
                case 2:
                    idle = atoi(buff + 19);
                    break;
            }
        }

        total = user + sys + idle;

        usage_diff = (prev_user - user) + (prev_sys - sys) + (prev_idle - idle);

        prev_user = user;
        prev_sys = sys;
        prev_idle = idle;
        prev_total = total;

        printf("CPU Usage: %.2f%% (user: %.2f%%, sys: %.2f%%, idle: %.2f%%)\n",
               (float) total / total * 100,
               (float) user / total * 100,
               (float) sys / total * 100,
               (float) idle / total * 100);

        sleep(1);
    }

    return 0;
}