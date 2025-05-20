#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BACKUPS 5

void create_backup(const char *original_file) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char filename[256];
    snprintf(filename, sizeof(filename), "backup_%d-%02d-%02d_%02d-%02d-%02d.txt", 
             tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,
             tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

    FILE *src = fopen(original_file, "r");
    if (!src) {
        perror("Error opening original file");
        return;
    }

    FILE *dest = fopen(filename, "w");
    if (!dest) {
        perror("Error creating backup file");
        fclose(src);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src)) {
        fputs(buffer, dest);
    }

    fclose(src);
    fclose(dest);
}

void delete_oldest_backup() {
    // This function would implement logic to find and delete the oldest backup
    printf("Deleting the oldest backup...\n");
    // Placeholder for actual implementation
}

int main() {
    const char *original_file = "data.txt";
    int backup_count = 0;

    // Simulate creating backups
    for (int i = 0; i < 10; i++) {
        create_backup(original_file);
        backup_count++;
        if (backup_count > MAX_BACKUPS) {
            delete_oldest_backup();
            backup_count--;
        }
    }

    return 0;
}
