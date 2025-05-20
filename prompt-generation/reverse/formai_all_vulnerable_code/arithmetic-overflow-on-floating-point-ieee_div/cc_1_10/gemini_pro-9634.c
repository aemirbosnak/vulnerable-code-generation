//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define PROFILING_PAGES 8

int main() {
    // Open the /proc/self/stat file.
    int statfd = open("/proc/self/stat", O_RDONLY);
    if (statfd == -1) {
        perror("open");
        return 1;
    }

    // Create a buffer to store the stat file contents.
    char statbuf[1024];
    if (read(statfd, statbuf, sizeof(statbuf)) == -1) {
        perror("read");
        return 1;
    }
    close(statfd);

    // Parse the stat file contents to extract the CPU time.
    long long cputime;
    sscanf(statbuf, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*d %*d %*d %*d %*d %lld", &cputime);

    // Open the /proc/self/statm file.
    int statmfd = open("/proc/self/statm", O_RDONLY);
    if (statmfd == -1) {
        perror("open");
        return 1;
    }

    // Create a buffer to store the statm file contents.
    char statmbuf[1024];
    if (read(statmfd, statmbuf, sizeof(statmbuf)) == -1) {
        perror("read");
        return 1;
    }
    close(statmfd);

    // Parse the statm file contents to extract the RSS.
    long long rss;
    sscanf(statmbuf, "%*d %lld", &rss);

    // Get the number of pages used by the current process.
    long long pages = syscall(SYS_getdents, -1, NULL, 0);
    if (pages == -1) {
        perror("getdents");
        return 1;
    }

    // Calculate the CPU usage.
    double cpuusage = (double)cputime / (double)sysconf(_SC_CLK_TCK);

    // Calculate the memory usage.
    double memusage = (double)rss / (double)pages;

    // Print the CPU and memory usage.
    printf("CPU usage: %.2f%%\n", cpuusage * 100);
    printf("Memory usage: %.2f%%\n", memusage * 100);

    return 0;
}