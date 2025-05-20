#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    long total_size = 1024 * 1024 * 1024; // 1 GB
    long used_space = 512 * 1024 * 1024; // 512 MB
    long free_space = total_size - used_space;

    double total_gb = total_size / (double)(1024 * 1024 * 1024);
    double used_gb = used_space / (double)(1024 * 1024 * 1024);
    double free_gb = free_space / (double)(1024 * 1024 * 1024);

    printf("Total Size: %.2f GB\n", total_gb);
    printf("Used Space: %.2f GB (%.2f%%)\n", used_gb, (used_gb / total_gb) * 100);
    printf("Free Space: %.2f GB (%.2f%%)\n", free_gb, (free_gb / total_gb) * 100);

    return 0;
}
