#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    unsigned long long total_size = 1024 * 1024 * 1024; // 1 GB
    unsigned long long used_space = 512 * 1024 * 1024; // 512 MB
    unsigned long long free_space = total_size - used_space;

    int total_percent = (total_size * 100) / total_size;
    int used_percent = (used_space * 100) / total_size;
    int free_percent = (free_space * 100) / total_size;

    printf("Total Size: %llu bytes\n", total_size);
    printf("Used Space: %llu bytes (%d%%)\n", used_space, used_percent);
    printf("Free Space: %llu bytes (%d%%)\n", free_space, free_percent);

    return 0;
}
