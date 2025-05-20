//FormAI DATASET v1.0 Category: File Backup System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

void copy_file(const char* path, const char* dest_folder)
{
    char buffer[1024];
    int source_file, dest_file;
    ssize_t read_len;

    source_file = open(path, O_RDONLY);
    if (source_file == -1)
    {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    char dest_path[MAX_PATH_LENGTH];
    snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest_folder, path);

    dest_file = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_file == -1)
    {
        printf("Error: Could not open file for writing.\n");
        close(source_file);
        return;
    }

    while ((read_len = read(source_file, buffer, sizeof(buffer))) > 0)
    {
        write(dest_file, buffer, read_len);
    }

    close(source_file);
    close(dest_file);
}

void backup_folder(const char* folder, const char* dest_folder)
{
    DIR* dir;
    struct dirent* entry;

    if ((dir = opendir(folder)) == NULL)
    {
        printf("Error: Could not open folder %s.\n", folder);
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char path[MAX_PATH_LENGTH];
        snprintf(path, MAX_PATH_LENGTH, "%s/%s", folder, entry->d_name);

        if (entry->d_type == DT_DIR)
        {
            char dest_path[MAX_PATH_LENGTH];
            snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest_folder, entry->d_name);

            mkdir(dest_path, 0755);
            backup_folder(path, dest_path);
        }
        else if (entry->d_type == DT_REG)
        {
            copy_file(path, dest_folder);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <source-folder> <destination-folder>\n", argv[0]);
        exit(1);
    }

    const char* source_folder = argv[1];
    const char* dest_folder = argv[2];

    mkdir(dest_folder, 0755);

    printf("Backing up %s to %s...\n", source_folder, dest_folder);

    clock_t start_time = clock();

    backup_folder(source_folder, dest_folder);

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Backup completed in %.2f seconds.\n", elapsed_time);

    return 0;
}