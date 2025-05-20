//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

int main() {
    struct sysinfo info;
    struct utsname name;

    // Fetch system information
    if (sysinfo(&info) < 0) {
        fprintf(stderr, "Error fetching system information\n");
        exit(1);
    }

    // Fetch system name information
    if (uname(&name) < 0) {
        fprintf(stderr, "Error fetching system name information\n");
        exit(1);
    }

    // Express our gratitude for the system's service
    printf("We are truly grateful for thy service, oh mighty system!\n");
    printf("Thy name art '%s', and thy node art '%s'.\n", name.sysname, name.nodename);
    printf("Thy total memory is %lu MB, and thy available memory is %lu MB.\n",
            info.totalram / 1024 / 1024, info.freeram / 1024 / 1024);
    printf("Thy CPU load is currently %.2f%%.\n", info.loads[0] / 65536.0 * 100.0);

    // Express our appreciation for specific processes
    printf("We are eternally grateful to the processes that make our system run smoothly:\n");
    printf("  PID  \tName\n");
    printf("  ----\t----\n");
    FILE *fp = fopen("/proc", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc\n");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        int pid;
        char name[16];
        sscanf(line, "%d %s", &pid, name);
        if (pid > 0) {
            printf("  %d\t%s\n", pid, name);
        }
    }
    fclose(fp);

    // Conclude with a heartfelt message of appreciation
    printf("From the bottom of our hearts, we thank thee, oh system, for thy tireless efforts.\n");
    printf("May thy memory forever be abundant, thy load be ever light, and thy processes ever faithful.\n");
    printf("Amen.\n");

    return 0;
}