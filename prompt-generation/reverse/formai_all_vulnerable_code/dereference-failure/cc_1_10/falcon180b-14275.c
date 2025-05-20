//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

struct rusage usage;
int main(int argc, char *argv[]) {
    int fd, ret;
    char filename[256];
    fd = open("/proc/self/stat", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }
    ret = read(fd, &filename, sizeof(filename));
    close(fd);
    if (ret == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        exit(1);
    }
    strcat(filename, "/statm");
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }
    ret = read(fd, &filename, sizeof(filename));
    close(fd);
    if (ret == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        exit(1);
    }
    strcat(filename, "/comm");
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }
    ret = read(fd, &filename, sizeof(filename));
    close(fd);
    if (ret == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        exit(1);
    }
    printf("Process name: %s\n", filename);
    getrusage(RUSAGE_SELF, &usage);
    printf("CPU usage: %ld%%\n", (long int)usage.ru_utime.tv_sec * 100);
    return 0;
}