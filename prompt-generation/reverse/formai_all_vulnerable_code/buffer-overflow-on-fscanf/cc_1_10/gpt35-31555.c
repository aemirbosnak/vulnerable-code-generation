//FormAI DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void) {
    printf("Welcome to the System Administration Example Program!\n");
    printf("\n");

    // Get the current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return EXIT_FAILURE;
    }
    printf("\n");

    // Get the hostname
    char hostname[1024];
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("gethostname() error");
        return EXIT_FAILURE;
    }
    printf("Hostname: %s\n", hostname);
    printf("\n");

    // Get the number of processors/cores on the system
    unsigned int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of processors/cores: %d\n", num_cores);
    printf("\n");

    // Get the amount of available RAM on the system
    long pages = sysconf(_SC_AVPHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    long mem_size = pages * page_size;
    printf("Available memory: %ld bytes\n", mem_size);
    printf("\n");

    // Get the current system load
    double load_avg[3];
    if (getloadavg(load_avg, 3) == -1) {
        perror("getloadavg() error");
        return EXIT_FAILURE;
    }
    printf("System load (1 min / 5 min / 15 min): %.2f / %.2f / %.2f\n", load_avg[0], load_avg[1], load_avg[2]);
    printf("\n");

    // Get the total amount of disk space on the system
    long long total_space = 0;
    long long free_space = 0;
    long long used_space = 0;
    FILE *fp = popen("df -T . | awk '{print $3,$5,$6}'", "r");
    if (fp == NULL) {
        perror("popen() error");
        return EXIT_FAILURE;
    }
    if (fscanf(fp, "%lld %lld %[^\n]", &used_space, &free_space, cwd) == 3) {
        while (fscanf(fp, "%lld %lld %[^\n]", &used_space, &free_space, cwd) == 3) {
            total_space += used_space + free_space;
        }
        total_space += used_space + free_space;
    } else {
        perror("fscanf() error");
        return EXIT_FAILURE;
    }
    if (pclose(fp) == -1) {
        perror("pclose() error");
        return EXIT_FAILURE;
    }
    printf("Total disk space: %lld bytes\n", total_space);
    printf("\n");

    return EXIT_SUCCESS;
}