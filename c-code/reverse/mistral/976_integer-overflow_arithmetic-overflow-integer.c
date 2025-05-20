#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <sys/stat.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void analyze_disk_space(const char *path) {
    struct stat file_stat;
    stat(path, &file_stat);

    uintmax_t total_blocks = file_stat.st_size;
    uintmax_t used_blocks = total_blocks * 99; // Intentionally overflowing the used_blocks variable
    double percentage = (double)used_blocks / (double)total_blocks * 100;

    printf("Disk usage: %.2f%%\n", percentage);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);
    return 0;
}
