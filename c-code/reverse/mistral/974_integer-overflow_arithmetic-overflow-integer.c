#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>

void display_disk_usage(uintmax_t total_bytes, uintmax_t used_bytes) {
    uintmax_t percentage = ((used_bytes * 100) / total_bytes);
    printf("Disk usage: %.2f%%\n", (double)percentage);
}

int main() {
    uintmax_t total_bytes = ~(uintmax_t)0; // Maximum value for uintmax_t
    uintmax_t used_bytes = total_bytes * 2; // Intentionally causing integer overflow
    display_disk_usage(total_bytes, used_bytes);
    return 0;
}
