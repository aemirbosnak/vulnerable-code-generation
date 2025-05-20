#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    long long total = 1024 * 1024 * 1024; // 1GB
    long long used = 512 * 1024 * 1024; // 512MB
    long long free = total - used;

    printf("Total: %lld MB\n", total / (1024 * 1024));
    printf("Used: %lld MB (%.2f%%)\n", used / (1024 * 1024), ((double)used / total) * 100);
    printf("Free: %lld MB (%.2f%%)\n", free / (1024 * 1024), ((double)free / total) * 100);

    return 0;
}
