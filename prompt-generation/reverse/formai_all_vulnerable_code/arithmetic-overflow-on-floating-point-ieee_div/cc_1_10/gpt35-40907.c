//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define PAGE_SIZE 4096

unsigned long long int get_sys_totalram() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram;
}

unsigned long long int get_sys_freeram() {
    struct sysinfo info;
    sysinfo(&info);
    return info.freeram;
}

unsigned long long int get_sys_usedram() {
    return get_sys_totalram() - get_sys_freeram();
}

void print_mem_usage() {
    unsigned long long int totalram = get_sys_totalram();
    unsigned long long int freeram = get_sys_freeram();
    unsigned long long int usedram = get_sys_usedram();
    double used_pct = (double)usedram / totalram * 100;
    double free_pct = (double)freeram / totalram * 100;

    printf("RAM Usage: %.2f%% used, %.2f%% free\n", used_pct, free_pct);
}

void print_mem_details() {
    unsigned long long int totalram = get_sys_totalram();
    unsigned long long int freeram = get_sys_freeram();
    unsigned long long int usedram = get_sys_usedram();
    unsigned long long int cached = freeram - (get_sys_totalram() - get_sys_freeram());
    unsigned long long int buffers = 0;

    char line[256];
    FILE* fp = fopen("/proc/meminfo", "r");
    while (fgets(line, 255, fp)) {
        if (strncmp(line, "Buffers:", 8) == 0) {
            char* p = line + 8;
            while (*p == ' ') ++p;
            buffers = atoll(p);
        }
    }
    fclose(fp);

    unsigned long long int vc = 0;
    fp = popen("vcgencmd get_mem arm && vcgencmd get_mem gpu | awk '{print $3}' | cut -d \"M\" -f 1", "r");
    while (fgets(line, 255, fp)) {
        vc += atoll(line);
    }
    pclose(fp);

    unsigned long long int used_mc = usedram - buffers - cached;

    printf("Total memory: %.2f MB\n", (double)totalram / (1024 * 1024));
    printf("Free memory: %.2f MB\n", (double)freeram / (1024 * 1024));
    printf("Used memory: %.2f MB\n", (double)usedram / (1024 * 1024));
    printf("Cached memory: %.2f MB\n", (double)cached / (1024 * 1024));
    printf("Buffers memory: %.2f MB\n", (double)buffers / (1024 * 1024));
    printf("Used memory (excluding buffers and cache): %.2f MB\n", (double)used_mc / (1024 * 1024));
    printf("Used VideoCore memory: %.2f MB\n", (double)vc / 1024);
}

unsigned long long int get_process_rss(pid_t pid) {
    char path[256];
    snprintf(path, 256, "/proc/%d/statm", pid);
    FILE* fp = fopen(path, "r");
    if (!fp) {
        return 0;
    }
    unsigned long long int pages;
    fscanf(fp, "%llu", &pages);
    fclose(fp);
    return pages * PAGE_SIZE;
}

void print_process_mem(pid_t pid) {
    char path[256];
    snprintf(path, 256, "/proc/%d/cmdline", pid);
    FILE* fp = fopen(path, "r");
    if (!fp) {
        printf("Error: Process with pid=%d not found\n", pid);
        return;
    }
    char cmdline[256] = {0};
    fgets(cmdline, 255, fp);
    fclose(fp);

    unsigned long long int rss = get_process_rss(pid);
    printf("%d (%s) RSS: %.2f MB\n", pid, cmdline, (double)rss / (1024 * 1024));
}

int main(int argc, char** argv) {
    print_mem_usage();
    print_mem_details();

    if (argc > 1) {
        pid_t pid = atoi(argv[1]);
        print_process_mem(pid);
    }

    return 0;
}