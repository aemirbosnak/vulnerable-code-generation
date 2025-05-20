//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_LINE_LEN 128
#define MAX_PROCESS_NAME 256

int main() {

    printf("Welcome to the CRAM monitor. Press CTRL+C to exit at any time.\n");

    while(1) {

        char buffer[MAX_LINE_LEN];
        struct sysinfo s_info;
        int error = sysinfo(&s_info);

        if(error != 0) {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }

        long total_ram = s_info.totalram * s_info.mem_unit;
        long used_ram = (s_info.totalram - s_info.freeram) * s_info.mem_unit;
        long ram_percentage = used_ram * 100 / total_ram;

        printf("CRAM usage: %ld/%ld MB (%ld%%)\n", used_ram / 1024 / 1024, total_ram / 1024 / 1024, ram_percentage);

        FILE* fp;

        fp = popen("ps -eo pid,comm,%mem --sort=-%mem | head -n 6", "r");

        if(fp == NULL) {
            perror("popen");
            exit(EXIT_FAILURE);
        }

        printf("\nTop 5 high memory usage processes:\n");

        char process_name[MAX_PROCESS_NAME];
        char percent[MAX_LINE_LEN];

        while(fgets(buffer, MAX_LINE_LEN, fp) != NULL) {
            sscanf(buffer, "%*d %s %s", process_name, percent);
            printf("%s: %s\n", process_name, percent);
        }

        printf("\n");

        pclose(fp);

        sleep(10);
    }

    return 0;
}