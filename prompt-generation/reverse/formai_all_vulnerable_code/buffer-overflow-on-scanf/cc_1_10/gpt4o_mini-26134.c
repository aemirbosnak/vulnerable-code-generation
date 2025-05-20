//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 512
#define FILE_BUF 8192

// Cyberpunk colors
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// Function to create a timestamped backup filename
void generate_backup_filename(const char *original_path, char *backup_path) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    char time_buf[20];
    strftime(time_buf, sizeof(time_buf), "%Y%m%d_%H%M%S", tm_info);

    snprintf(backup_path, MAX_PATH, "%s_backup_%s", original_path, time_buf);
}

void log_backup_action(const char *message) {
    printf("[%s] %s" RESET "\n", YELLOW, message);
}

void backup_file(const char *file_path) {
    FILE *source_file, *dest_file;
    char backup_path[MAX_PATH];
    char buffer[FILE_BUF];
    size_t bytes;

    generate_backup_filename(file_path, backup_path);

    source_file = fopen(file_path, "rb");
    if (!source_file) {
        fprintf(stderr, RED "Error: Could not open source file %s" RESET "\n", file_path);
        return;
    }

    dest_file = fopen(backup_path, "wb");
    if (!dest_file) {
        fclose(source_file);
        fprintf(stderr, RED "Error: Could not create backup file %s" RESET "\n", backup_path);
        return;
    }

    log_backup_action("Backing up file...");
    while ((bytes = fread(buffer, 1, FILE_BUF, source_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);

    log_backup_action("Backup completed successfully.");
    printf("Backup created at: " GREEN "%s" RESET "\n", backup_path);
}

void list_directory(const char *path) {
    printf(CYAN "Listing files in directory: %s\n" RESET, path);
    system((char *)malloc(snprintf(NULL, 0, "ls %s", path) + 1));
}

void cyberpunk_ui() {
    printf(MAGENTA "================= Cyberpunk C File Backup System =================\n" RESET);
}

int main() {
    char file_path[MAX_PATH];
    char command[10];
    char dir_path[MAX_PATH];

    cyberpunk_ui();

    while (1) {
        printf(BLUE "Enter file to backup (or type 'list' to view the current directory): " RESET);
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            printf("Enter directory path: ");
            scanf("%s", dir_path);
            list_directory(dir_path);
            continue;
        }

        snprintf(file_path, MAX_PATH, "%s", command);
        backup_file(file_path);
        
        printf(BLUE "Would you like to backup another file? (yes/no): " RESET);
        char response[4];
        scanf("%s", response);
        if (strcmp(response, "no") == 0) {
            break;
        }
    }

    printf(WHITE "Exiting Cyberpunk Backup System. Stay safe in the neon shadows!\n" RESET);
    return 0;
}