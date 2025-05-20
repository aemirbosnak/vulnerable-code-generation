//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 128

typedef struct MemInfo {
    float total_mem;
    float used_mem;
    float free_mem;
} MemInfo;

/*
 * Returns the amount of physical memory in KB
 */
float get_total_mem() {
    char buffer[BUFFER_SIZE];
    FILE* fp = fopen("/proc/meminfo", "r");

    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);

    char* total_mem_str = strtok(buffer+10, " ");
    return atof(total_mem_str);
}

/*
 * Returns the amount of used memory currently in KB
 */
float get_used_mem() {
    char buffer[BUFFER_SIZE];
    FILE* fp = fopen("/proc/meminfo", "r");

    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);

    char* used_mem_str = strtok(buffer+10, " ");
    return atof(used_mem_str);
}

/*
 * Returns the amount of free memory currently in KB
 */
float get_free_mem() {
    char buffer[BUFFER_SIZE];
    FILE* fp = fopen("/proc/meminfo", "r");

    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);

    char* free_mem_str = strtok(buffer+10, " ");
    return atof(free_mem_str);
}

/*
 * Returns a MemInfo struct containing the total, used and free
 * memory information in KB
 */
MemInfo get_mem_info() {
    MemInfo info = {
        .total_mem = get_total_mem(),
        .used_mem = get_used_mem(),
        .free_mem = get_free_mem()
    };

    return info;
}

/*
 * Prints out the current memory usage information
 */
void print_usage(MemInfo info) {
    float used_mem_pct = info.used_mem / info.total_mem * 100.0;
    float free_mem_pct = info.free_mem / info.total_mem * 100.0;

    printf("Total Memory: %.2f KB\n", info.total_mem);
    printf("Used Memory: %.2f KB (%.2f%%)\n", info.used_mem, used_mem_pct);
    printf("Free Memory: %.2f KB (%.2f%%)\n", info.free_mem, free_mem_pct);
}

int main() {
    MemInfo info;

    while (1) {
        info = get_mem_info();
        print_usage(info);
        sleep(1);
        system("clear");    // for Linux
        //system("cls");    // for Windows
    }

    return 0;
}