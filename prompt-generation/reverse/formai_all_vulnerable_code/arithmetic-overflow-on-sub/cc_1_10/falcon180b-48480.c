//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MEGABYTE (1024 * 1024)

void get_memory_info(char *process_name) {
    pid_t pid = getpid();
    char path[64];
    sprintf(path, "/proc/%d/statm", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: could not open %s\n", path);
        return;
    }
    int size, resident;
    fscanf(fp, "%d %d", &size, &resident);
    fclose(fp);

    printf("Memory usage for %s:\n", process_name);
    printf("Total: %d kB\n", size * (getpagesize() / 1024));
    printf("Resident: %d kB\n", resident * (getpagesize() / 1024));
    printf("Shared: %d kB\n", (size - resident) * (getpagesize() / 1024));
}

void get_disk_info(char *device_name) {
    struct statvfs buf;
    if (statvfs(device_name, &buf) == -1) {
        printf("Error: could not get disk info for %s\n", device_name);
        return;
    }

    printf("Disk usage for %s:\n", device_name);
    printf("Total: %d MB\n", buf.f_blocks * buf.f_frsize / MEGABYTE);
    printf("Available: %d MB\n", buf.f_bavail * buf.f_frsize / MEGABYTE);
    printf("Used: %d MB\n", (buf.f_blocks - buf.f_bavail) * buf.f_frsize / MEGABYTE);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <process_name> <device_name>\n", argv[0]);
        return 1;
    }

    char *process_name = argv[1];
    char *device_name = argv[2];

    get_memory_info(process_name);
    get_disk_info(device_name);

    return 0;
}