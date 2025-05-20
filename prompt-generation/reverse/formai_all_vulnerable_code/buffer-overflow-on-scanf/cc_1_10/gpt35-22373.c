//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to calculate and display the size of a given directory
void DisplayDirectorySize(char *dir_path, int *total_size, int depth)
{
    DIR *dir = opendir(dir_path);   // Open the directory
    if (dir == NULL) {
        printf("Unable to open directory %s\n", dir_path);
        return;
    }

    struct dirent *entry;
    int subtotal_size = 0;

    while ((entry = readdir(dir)) != NULL) {   // Loop through the directory entries
        if (entry->d_type == DT_DIR) {   // Check if directory
            char path[1024];
            if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) {
                continue;
            }

            sprintf(path, "%s/%s", dir_path, entry->d_name);
            printf("%*s%s/\n", depth, "", entry->d_name);
            DisplayDirectorySize(path, &subtotal_size, depth + 4);   // Recursively check the directory
        } else {   // Entry is a file
            char file_path[1024];
            sprintf(file_path, "%s/%s", dir_path, entry->d_name);
            struct stat st;
            if (stat(file_path, &st) != 0) {
                continue;
            }

            int file_size = st.st_size;
            subtotal_size += file_size;
            printf("%*s- %s (%d bytes)\n", depth, "", entry->d_name, file_size);
        }
    }

    closedir(dir);
    *total_size += subtotal_size;
    printf("%*s -> Total directory size: %d bytes\n", depth, "", subtotal_size);   // Display directory size
}

int main()
{
    char dir_path[1024];
    printf("Enter the path of the directory you want to analyze: ");
    scanf("%s", dir_path);

    int total_size = 0;
    DisplayDirectorySize(dir_path, &total_size, 0);

    printf("Total disk space used by the directory: %d bytes\n", total_size);

    return 0;
}