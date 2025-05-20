//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/time.h>
#include <pthread.h>

#define INTERVAL 5 // Time interval in seconds

// Function to get current time in milliseconds
long long get_current_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// Function to get total RAM size in MB
int get_total_ram() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram / (1024 * 1024);
}

// Function to get available RAM size in MB
int get_available_ram() {
    struct sysinfo info;
    sysinfo(&info);
    return info.freeram / (1024 * 1024);
}

// Function to get used RAM size in MB
int get_used_ram() {
    int total_ram = get_total_ram();
    int available_ram = get_available_ram();
    return total_ram - available_ram;
}

// Function to print RAM usage
void print_ram_usage() {
    int total_ram = get_total_ram();
    int available_ram = get_available_ram();
    int used_ram = get_used_ram();

    printf("Total RAM: %d MB\n", total_ram);
    printf("Available RAM: %d MB\n", available_ram);
    printf("Used RAM: %d MB\n", used_ram);
}

// Function to run in a separate thread
void* run(void* arg) {
    while (1) {
        print_ram_usage();
        sleep(INTERVAL);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    // Create a new thread
    pthread_create(&thread_id, NULL, run, NULL);

    // Wait for thread to finish
    pthread_join(thread_id, NULL);

    return 0;
}