//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define BUF_SIZE 100
#define RING_BUF_SIZE (BUF_SIZE * sizeof(struct ram_usage))

struct ram_usage {
    time_t timestamp;
    size_t ram_usage;
};

volatile size_t total_ram = 0;
volatile size_t free_ram = 0;
volatile size_t used_ram = 0;

struct ram_usage ring_buf[BUF_SIZE];
int head = 0, tail = 0;

void init_buffer() {
    head = 0;
    tail = 0;
    memset(ring_buf, 0, RING_BUF_SIZE);
}

void add_to_buffer(struct ram_usage data) {
    ring_buf[head] = data;
    head = (head + 1) % BUF_SIZE;
}

size_t get_average_ram_usage() {
    size_t sum = 0;
    int i;

    for (i = tail; i != head; i = (i + 1) % BUF_SIZE) {
        sum += ring_buf[i].ram_usage;
    }

    return sum / (BUF_SIZE - (head - tail));
}

void get_current_ram_usage() {
    struct sysinfo sysinfo;

    if (sysconf(_SC_PAGE_SIZE) != -1) {
        total_ram = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
    }

    if (sysconf(_SC_PAGE_SIZE) != -1 && sysconf(_SC_AVPHYS_PAGES) != -1) {
        free_ram = (sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGE_SIZE));
    }

    used_ram = total_ram - free_ram;
}

void print_ram_usage() {
    get_current_ram_usage();
    printf("\nCurrent RAM usage: %.2f%%\n", (float)used_ram / (float)total_ram * 100.0);
    printf("Average RAM usage over the last 100 samples: %.2f%%\n", (float)get_average_ram_usage() / (float)total_ram * 100.0);
}

int main() {
    init_buffer();
    get_current_ram_usage();

    while (1) {
        add_to_buffer((struct ram_usage){time(NULL), used_ram});
        print_ram_usage();
        usleep(100000); // sleep for 100ms
    }

    return 0;
}