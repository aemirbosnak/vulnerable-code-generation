//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Configure backup settings
#define BACKUP_SOURCE "/path/to/source"
#define BACKUP_DEST "/path/to/destination"
#define BACKUP_INTERVAL 3600 // Backup every hour

// Helper function to get current timestamp
time_t get_timestamp() {
    time_t t;
    time(&t);
    return t;
}

// Main backup function
int backup(const char *source, const char *dest, time_t last_backup) {
    // Generate timestamp for this backup
    time_t current_time = get_timestamp();

    // Check if backup interval has passed
    if (current_time - last_backup < BACKUP_INTERVAL) {
        printf("No need for backup yet.\n");
        return 1;
    }

    // Open source file for reading
    FILE *source_file = fopen(source, "rb");
    if (!source_file) {
        perror("Error opening source file");
        return 2;
    }

    // Open destination file for writing
    FILE *dest_file = fopen(dest, "wb");
    if (!dest_file) {
        perror("Error opening destination file");
        fclose(source_file);
        return 3;
    }

    // Copy file contents from source to destination
    int c;
    while ((c = fgetc(source_file)) != EOF) {
        fputc(c, dest_file);
    }

    // Close both files
    fclose(source_file);
    fclose(dest_file);

    // Record the time of this backup
    FILE *log_file = fopen("backup.log", "a");
    fprintf(log_file, "Backup performed at %s\n", ctime(&current_time));
    fclose(log_file);

    return 0;
}

int main() {
    // Initialize last backup time
    time_t last_backup = 0;

    // Run continuous backup loop
    while (1) {
        // Perform the backup
        if (backup(BACKUP_SOURCE, BACKUP_DEST, last_backup) == 0) {
            last_backup = get_timestamp();
        }

        // Sleep for the backup interval
        sleep(BACKUP_INTERVAL);
    }

    return 0;
}