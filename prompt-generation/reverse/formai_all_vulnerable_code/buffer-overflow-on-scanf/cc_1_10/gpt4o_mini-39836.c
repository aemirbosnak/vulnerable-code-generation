//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

// A Love Letter to Memory
typedef struct {
    long total;
    long free;
    long used;
    double percent_used;
} MemoryInfo;

// A song for memory usage
void serenade_memory_usage(MemoryInfo mem) {
    printf("Oh Memory, sweet and pure,\n");
    printf("Total space, a grand allure: %ld KB\n", mem.total);
    printf("Free as the dove, a respite so dear: %ld KB\n", mem.free);
    printf("Used, but not lost, oh love, we persevere: %ld KB\n", mem.used);
    printf("By your side, I feel so fine,\n");
    printf("Memory used, a tender line: %.2f%%\n", mem.percent_used);
    printf("\nOh Memory, stay with me forever,\n");
    printf("Together we'll soar, undeterred, never.\n");
}

// A dance of dreams, capturing memory
MemoryInfo get_memory_info() {
    struct sysinfo info;
    sysinfo(&info);

    MemoryInfo mem;
    mem.total = info.totalram / 1024; // Convert to KB
    mem.free = info.freeram / 1024;    // Convert to KB
    mem.used = mem.total - mem.free;
    mem.percent_used = (mem.used / (double)mem.total) * 100.0;

    return mem;
}

// A gentle rhythm to monitor, lightly beseeching
void monitor_memory_usage(int interval) {
    while (1) {
        MemoryInfo mem = get_memory_info();
        serenade_memory_usage(mem);
        
        printf("\nWaiting for your next heartbeat... %d seconds\n", interval);
        sleep(interval);
    }
}

int main() {
    int wait_time;

    printf("Welcome, beloved user, to a monitor pure,\n");
    printf("Please share the interval for the next allure (in seconds): ");
    scanf("%d", &wait_time);

    if (wait_time < 1) {
        printf("Oh no, time must pass, at least one second!\n");
        return 1;
    }

    printf("\nLet the memories flow, full of grace,\n");
    monitor_memory_usage(wait_time);

    return 0;
}