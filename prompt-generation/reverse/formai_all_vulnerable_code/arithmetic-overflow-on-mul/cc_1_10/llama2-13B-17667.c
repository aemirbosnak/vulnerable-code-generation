//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/sysinfo.h>
#include <fcntl.h>
#include <termios.h>
#include <utime.h>

#define MEMORY_USAGE_COLORS \
    "0;36m" /* Default color */ \
    "1;32m" /* Red */ \
    "2;34m" /* Green */ \
    "3;31m" /* Yellow */ \
    "4;37m" /* Blue */ \
    "5;33m" /* Magenta */ \
    "6;35m" /* Cyan */ \
    "7;38m" /* White */

#define MEMORY_USAGE_LEVELS 7

struct memory_usage {
    int usage;
    char color[MEMORY_USAGE_LEVELS][10];
};

static struct memory_usage memory_usage_levels[MEMORY_USAGE_LEVELS] = {
    { 0, "0;36m" }, /* Default */
    { 1, "1;32m" }, /* Low */
    { 2, "2;34m" }, /* Medium */
    { 3, "3;31m" }, /* High */
    { 4, "4;37m" }, /* Very High */
    { 5, "5;33m" }, /* Extremely High */
    { 6, "6;35m" }, /* Critical */
    { 7, "7;38m" }, /* Overheating */
};

void print_memory_usage(void) {
    struct sysinfo si;
    int i, usage;
    char *color;

    // Get current memory usage
    sysinfo(&si);
    usage = si.totalram / (1024 * 1024);

    // Calculate usage percentage
    usage = (usage * 100) / si.totalram;

    // Print memory usage
    for (i = 0; i < MEMORY_USAGE_LEVELS; i++) {
        if (usage >= memory_usage_levels[i].usage) {
            color = memory_usage_levels[i].color;
            break;
        }
    }

    printf("Memory usage: %3d%% 📈 %s\n", usage, color);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    while (1) {
        print_memory_usage();
        sleep(1);
    }

    return 0;
}