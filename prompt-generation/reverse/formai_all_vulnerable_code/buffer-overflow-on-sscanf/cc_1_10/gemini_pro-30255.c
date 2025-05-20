//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <signal.h>

#define PAGESIZE 4096

static volatile sig_atomic_t g_should_exit = 0;
static volatile sig_atomic_t g_pages_written = 0;

static void signal_handler(int signo)
{
    g_should_exit = 1;
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    int fd = open("/proc/meminfo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    void *map = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        return EXIT_FAILURE;
    }

    close(fd);

    int previous_ram_used = 0;
    int current_ram_used = 0;
    while (!g_should_exit) {
        sscanf(map, "MemTotal: %d kB\nMemFree: %d kB",
               &current_ram_used, &current_ram_used);

        if (current_ram_used < previous_ram_used) {
            g_pages_written++;
        }

        previous_ram_used = current_ram_used;
        sleep(1);
    }

    munmap(map, st.st_size);

    printf("Pages written: %lu\n", g_pages_written);

    return EXIT_SUCCESS;
}