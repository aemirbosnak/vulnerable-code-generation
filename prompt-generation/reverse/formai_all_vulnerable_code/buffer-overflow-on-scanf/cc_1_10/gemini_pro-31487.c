//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

// A custom struct to store file information
typedef struct file_info {
    char *file_name;
    long file_size;
    time_t file_timestamp;
} file_info;

// A function to compare two file_info structs by file size
int compare_file_size(const void *a, const void *b) {
    file_info *fa = (file_info *)a;
    file_info *fb = (file_info *)b;
    return fa->file_size - fb->file_size;
}

// A function to compare two file_info structs by file timestamp
int compare_file_timestamp(const void *a, const void *b) {
    file_info *fa = (file_info *)a;
    file_info *fb = (file_info *)b;
    return fa->file_timestamp - fb->file_timestamp;
}

int main() {
    // Get the source directory from the user
    char source_dir[1024];
    printf("Enter the source directory: ");
    scanf("%s", source_dir);

    // Get the destination directory from the user
    char destination_dir[1024];
    printf("Enter the destination directory: ");
    scanf("%s", destination_dir);

    // Create a DIR object for the source directory
    DIR *source_dir_stream = opendir(source_dir);
    if (source_dir_stream == NULL) {
        perror("Error opening source directory");
        exit(1);
    }

    // Create an array to store file information
    file_info *files = NULL;
    int num_files = 0;

    // Iterate over the files in the source directory
    struct dirent *dir_entry;
    while ((dir_entry = readdir(source_dir_stream)) != NULL) {
        // Skip hidden files
        if (dir_entry->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char file_path[1024];
        sprintf(file_path, "%s/%s", source_dir, dir_entry->d_name);

        // Get the file information
        struct stat file_stat;
        if (stat(file_path, &file_stat) != 0) {
            perror("Error getting file information");
            continue;
        }

        // Allocate memory for the file information struct
        files = realloc(files, sizeof(file_info) * (num_files + 1));
        if (files == NULL) {
            perror("Error allocating memory");
            exit(1);
        }

        // Store the file information
        files[num_files].file_name = strdup(file_path);
        files[num_files].file_size = file_stat.st_size;
        files[num_files].file_timestamp = file_stat.st_mtime;

        // Increment the number of files
        num_files++;
    }

    closedir(source_dir_stream);

    // Sort the files by file size
    qsort(files, num_files, sizeof(file_info), compare_file_size);

    // Print the files by file size
    printf("Files sorted by file size:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%ld bytes)\n", files[i].file_name, files[i].file_size);
    }

    // Sort the files by file timestamp
    qsort(files, num_files, sizeof(file_info), compare_file_timestamp);

    // Print the files by file timestamp
    printf("\nFiles sorted by file timestamp:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%ld bytes, %s)\n", files[i].file_name, files[i].file_size, ctime(&files[i].file_timestamp));
    }

    // Create a DIR object for the destination directory
    DIR *destination_dir_stream = opendir(destination_dir);
    if (destination_dir_stream == NULL) {
        mkdir(destination_dir, 0777);
        destination_dir_stream = opendir(destination_dir);
        if (destination_dir_stream == NULL) {
            perror("Error opening destination directory");
            exit(1);
        }
    }

    // Iterate over the files in the source directory
    for (int i = 0; i < num_files; i++) {
        // Get the source file path
        char *source_file_path = files[i].file_name;

        // Get the destination file path
        char destination_file_path[1024];
        sprintf(destination_file_path, "%s/%s", destination_dir, files[i].file_name);

        // Open the source file
        FILE *source_file = fopen(source_file_path, "rb");
        if (source_file == NULL) {
            perror("Error opening source file");
            continue;
        }

        // Open the destination file
        FILE *destination_file = fopen(destination_file_path, "wb");
        if (destination_file == NULL) {
            fclose(source_file);
            perror("Error opening destination file");
            continue;
        }

        // Read the source file and write to the destination file
        size_t bytes_read;
        size_t bytes_written;
        do {
            bytes_read = fread(source_file, 1, 1024, source_file);
            bytes_written = fwrite(source_file, 1, bytes_read, destination_file);
        } while (bytes_read > 0);

        // Close the source file
        fclose(source_file);

        // Close the destination file
        fclose(destination_file);
    }

    closedir(destination_dir_stream);

    // Free the allocated memory
    for (int i = 0; i < num_files; i++) {
        free(files[i].file_name);
    }
    free(files);

    return 0;
}