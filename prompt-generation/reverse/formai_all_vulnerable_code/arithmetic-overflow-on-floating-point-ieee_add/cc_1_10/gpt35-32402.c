//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    int i, j;
    long double a[200], b[200], s[200], t[200], x[200], y[200], z[200];
    char p[200][2000], q[200][2000];

    for (i = 0; i < strlen(argv[1]); ++i) {
        a[i] = argv[1][i] - 48;
    }

    i = 0;
    while (1) {
        FILE *fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("error: failed to open file /proc/stat\n");
            return -1;
        }
        fscanf(fp, "%s", p[i]);
        for (j = 0; j < 10; ++j) {
            fscanf(fp, "%Lf", &a[j+1]);
            s[i] += a[j+1];
        }
        fclose(fp);

        fp = fopen("/proc/uptime", "r");
        if (fp == NULL) {
            printf("error: failed to open file /proc/uptime\n");
            return -1;
        }
        fscanf(fp, "%Lf", &x[i]);
        fclose(fp);

        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            printf("error: failed to open file /proc/meminfo\n");
            return -1;
        }
        for (j = 0; j < 3; ++j) {
            fscanf(fp, "%s %Lf %s", q[j], &z[j], p[0]);
            if (j == 0) {
                y[i] = z[j]*1000;
            }
        }
        fclose(fp);

        b[i] = s[i] - t[i];
        if (i > 0) {
            printf("CPU Usage: %.2Lf%%\n", (b[i]/(s[i]-s[i-1]))*100);
            printf("RAM Usage: %.2Lf MB\n", (y[i]-y[i-1])/1024);
            printf("Uptime: %.0Lf seconds\n", x[i]-x[i-1]);
        }
        t[i] = s[i];
        i = (i+1) % 200;
        sleep(1);
    }

    return 0;
}