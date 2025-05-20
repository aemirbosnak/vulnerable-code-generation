#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BACKUPS 5

void generate_filename(char *filename, int index) {
    snprintf(filename, 256, "backup_%d", index);
}

int main() {
    char filenames[MAX_BACKUPS][256];
    time_t current_time;
    struct tm *time_info;

    // Simulate existing backups
    for (int i = 0; i < MAX_BACKUPS; i++) {
        generate_filename(filenames[i], i);
    }

    // Get current time
    time(&current_time);
    time_info = localtime(&current_time);

    // Rename files to create new backup
    for (int i = MAX_BACKUPS - 1; i > 0; i--) {
        rename(filenames[i], filenames[i - 1]);
    }
    generate_filename(filenames[0], MAX_BACKUPS);

    return 0;
}
