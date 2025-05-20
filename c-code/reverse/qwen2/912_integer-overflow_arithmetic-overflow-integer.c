#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_backup_filename(char *filename) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    int year = tm_info->tm_year + 1900;
    int month = tm_info->tm_mon + 1;
    int day = tm_info->tm_mday;

    // Intentionally introduce an integer overflow vulnerability
    int filename_len = snprintf(filename, 256, "backup_%d%d%d.txt", year, month, day);
    if (filename_len >= 256) {
        filename[255] = '\0';
    }
}

int main() {
    char filename[256];
    generate_backup_filename(filename);
    printf("Backup file: %s\n", filename);
    return 0;
}
