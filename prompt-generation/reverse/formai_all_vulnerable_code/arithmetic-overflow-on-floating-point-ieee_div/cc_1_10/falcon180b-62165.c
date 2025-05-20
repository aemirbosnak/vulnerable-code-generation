//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define NUM_SAMPLES 10

int main(int argc, char *argv[]) {
    struct statvfs statvfs_buf;
    int i;
    unsigned long total_ram, free_ram, used_ram;
    double ram_usage;
    time_t start_time, end_time;
    struct tm *start_tm, *end_tm;

    if (argc!= 2) {
        printf("Usage: %s <seconds>\n", argv[0]);
        return 1;
    }

    start_time = time(NULL);
    start_tm = localtime(&start_time);

    for (i = 0; i < NUM_SAMPLES; i++) {
        if (statvfs("/dev/shm", &statvfs_buf) == -1) {
            printf("Error: cannot get RAM information\n");
            return 1;
        }

        total_ram = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
        free_ram = statvfs_buf.f_bavail * statvfs_buf.f_frsize;
        used_ram = total_ram - free_ram;

        ram_usage = (double)used_ram / total_ram * 100;
        printf("%s: RAM usage %.2f%%\n", ctime(&start_time), ram_usage);

        end_time = start_time + (unsigned long)argv[1];
        end_tm = localtime(&end_time);

        while (difftime(time(NULL), end_time) > 0) {
            if (statvfs("/dev/shm", &statvfs_buf) == -1) {
                printf("Error: cannot get RAM information\n");
                return 1;
            }

            total_ram = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
            free_ram = statvfs_buf.f_bavail * statvfs_buf.f_frsize;
            used_ram = total_ram - free_ram;

            ram_usage = (double)used_ram / total_ram * 100;
            printf("%s: RAM usage %.2f%%\n", ctime(&start_time), ram_usage);

            if (difftime(time(NULL), end_time) > 1) {
                sleep(1);
            }
        }
    }

    return 0;
}