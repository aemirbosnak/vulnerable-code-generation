//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

// Function to recursively sync files and directories
void sync_files(char *src_path, char *dest_path)
{
    DIR *src_dir, *dest_dir;
    struct dirent *src_entry, *dest_entry;
    char src_file[PATH_MAX], dest_file[PATH_MAX];

    // Open source and destination directories
    src_dir = opendir(src_path);
    dest_dir = opendir(dest_path);

    // Check if directories have been opened successfully
    if (src_dir == NULL || dest_dir == NULL)
    {
        printf("Unable to open directories\n");
        return;
    }

    // Read source directory and loop through all entries
    while ((src_entry = readdir(src_dir)) != NULL)
    {
        // Ignore directories '.' and '..'
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0)
            continue;

        // Construct the source file path
        snprintf(src_file, sizeof(src_file), "%s/%s", src_path, src_entry->d_name);

        // Reset destination directory pointer to start
        rewinddir(dest_dir);

        // Loop through destination directory and search for matching file/directory
        int file_found = 0, dir_found = 0;
        while ((dest_entry = readdir(dest_dir)) != NULL)
        {
            // Ignore directories '.' and '..'
            if (strcmp(dest_entry->d_name, ".") == 0 || strcmp(dest_entry->d_name, "..") == 0)
                continue;

            // Compare source and destination file/directory names
            if (strcmp(src_entry->d_name, dest_entry->d_name) == 0)
            {
                // Construct the destination file path
                snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_path, src_entry->d_name);

                // If source entry is a directory, recursively sync it with corresponding destination directory
                if (src_entry->d_type == DT_DIR)
                {
                    sync_files(src_file, dest_file);
                    dir_found = 1;
                }
                // If source entry is a file, copy it to the destination directory
                else if (src_entry->d_type == DT_REG)
                {
                    FILE *src_fd, *dest_fd;
                    char buf[BUFSIZ];

                    // Open source and destination files for reading and writing respectively
                    src_fd = fopen(src_file, "rb");
                    dest_fd = fopen(dest_file, "wb");

                    // Check if files have been opened successfully
                    if (src_fd == NULL || dest_fd == NULL)
                    {
                        printf("Unable to open files\n");
                        return;
                    }

                    // Copy the contents of the source file to the destination file
                    size_t bytes;
                    while ((bytes = fread(buf, 1, sizeof(buf), src_fd)) > 0)
                        fwrite(buf, 1, bytes, dest_fd);

                    // Close source and destination files
                    fclose(src_fd);
                    fclose(dest_fd);
                    file_found = 1;
                }
            }
        }

        // If file/directory not found in destination, create a new one
        if (!file_found && !dir_found)
        {
            snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_path, src_entry->d_name);

            // If source entry is a directory, create a new directory in destination
            if (src_entry->d_type == DT_DIR)
            {
                mkdir(dest_file, 0755);
                sync_files(src_file, dest_file);
            }
            // If source entry is a file, copy it to the destination directory
            else if (src_entry->d_type == DT_REG)
            {
                FILE *src_fd, *dest_fd;
                char buf[BUFSIZ];

                // Open source and destination files for reading and writing respectively
                src_fd = fopen(src_file, "rb");
                dest_fd = fopen(dest_file, "wb");

                // Check if files have been opened successfully
                if (src_fd == NULL || dest_fd == NULL)
                {
                    printf("Unable to open files\n");
                    return;
                }

                // Copy the contents of the source file to the destination file
                size_t bytes;
                while ((bytes = fread(buf, 1, sizeof(buf), src_fd)) > 0)
                    fwrite(buf, 1, bytes, dest_fd);

                // Close source and destination files
                fclose(src_fd);
                fclose(dest_fd);
            }
        }
    }

    // Close directories
    closedir(src_dir);
    closedir(dest_dir);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    char *src_path = realpath(argv[1], NULL);
    char *dest_path = realpath(argv[2], NULL);

    if (src_path == NULL || dest_path == NULL)
    {
        printf("Invalid directory paths\n");
        return 1;
    }

    sync_files(src_path, dest_path);

    free(src_path);
    free(dest_path);

    printf("File synchronization complete!\n");

    return 0;
}