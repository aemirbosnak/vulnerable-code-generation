//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
/* Disk space analyzer program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char **argv) {
    /* Check if the user has passed a directory path */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory path>\n", argv[0]);
        return 1;
    }

    /* Get the directory path from the user */
    char *dir_path = argv[1];

    /* Open the directory */
    DIR *dir = opendir(dir_path);
    if (!dir) {
        fprintf(stderr, "Error: unable to open directory %s\n", dir_path);
        return 1;
    }

    /* Create a list to store the file names */
    char **file_names = malloc(sizeof(char *) * 100);
    int num_files = 0;

    /* Read the directory entries */
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        /* Check if the entry is a file */
        if (entry->d_type == DT_REG) {
            /* Get the file name */
            char *file_name = entry->d_name;

            /* Add the file name to the list */
            file_names[num_files++] = file_name;
        }
    }

    /* Close the directory */
    closedir(dir);

    /* Print the list of files */
    printf("Files in %s:\n", dir_path);
    for (int i = 0; i < num_files; i++) {
        printf("%s\n", file_names[i]);
    }

    /* Free the list */
    free(file_names);

    return 0;
}