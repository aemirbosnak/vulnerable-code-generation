//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLOCK_SIZE 512
#define MAX_RECOVERY_FILES 100
#define RECOVERY_DIR "recovered_files"

typedef struct {
    char filename[PATH_MAX];
    off_t offset;
} RecoveryFile;

void create_recovery_directory() {
    struct stat st;
    
    if (stat(RECOVERY_DIR, &st) == -1) {
        if (mkdir(RECOVERY_DIR, 0755) == -1) {
            perror("Unable to create recovery directory");
            exit(EXIT_FAILURE);
        }
        printf("Recovery directory created: %s\n", RECOVERY_DIR);
    } else {
        printf("Recovery directory already exists: %s\n", RECOVERY_DIR);
    }
}

int recover_file(const char *disk_image, RecoveryFile *recovery_file) {
    FILE *image = fopen(disk_image, "rb");
    if (!image) {
        perror("Failed to open disk image");
        return -1;
    }

    char buffer[BLOCK_SIZE];
    fseek(image, recovery_file->offset, SEEK_SET);
    
    size_t bytes_read = fread(buffer, 1, BLOCK_SIZE, image);
    if (bytes_read < BLOCK_SIZE && ferror(image)) {
        perror("Error reading from disk image");
        fclose(image);
        return -1;
    }

    char recover_file_path[PATH_MAX];
    snprintf(recover_file_path, sizeof(recover_file_path), "%s/%s", RECOVERY_DIR, recovery_file->filename);
    
    FILE *output = fopen(recover_file_path, "wb");
    if (!output) {
        perror("Failed to create recovery file");
        fclose(image);
        return -1;
    }

    fwrite(buffer, 1, bytes_read, output);
    printf("Recovered file created: %s\n", recover_file_path);
    
    fclose(output);
    fclose(image);
    return 0;
}

void parse_recovery_table(const char *recovery_table_path, RecoveryFile *files, int *file_count) {
    FILE *table = fopen(recovery_table_path, "r");
    if (!table) {
        perror("Failed to open recovery table");
        exit(EXIT_FAILURE);
    }

    *file_count = 0;
    while (fscanf(table, "%s %ld", files[*file_count].filename, &files[*file_count].offset) != EOF) {
        (*file_count)++;
        if (*file_count >= MAX_RECOVERY_FILES) {
            break;
        }
    }
    
    fclose(table);
}

void display_recovery_files(RecoveryFile *files, int file_count) {
    printf("Recovery files to process:\n");
    for (int i = 0; i < file_count; ++i) {
        printf("File: %s, Offset: %ld\n", files[i].filename, files[i].offset);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <disk_image> <recovery_table>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *disk_image = argv[1];
    const char *recovery_table_path = argv[2];

    create_recovery_directory();

    RecoveryFile recovery_files[MAX_RECOVERY_FILES];
    int file_count;
    parse_recovery_table(recovery_table_path, recovery_files, &file_count);
    display_recovery_files(recovery_files, file_count);

    for (int i = 0; i < file_count; ++i) {
        if (recover_file(disk_image, &recovery_files[i]) != 0) {
            fprintf(stderr, "Failed to recover file: %s\n", recovery_files[i].filename);
        }
    }

    printf("Recovery process completed. Check the '%s' directory for recovered files.\n", RECOVERY_DIR);
    return EXIT_SUCCESS;
}