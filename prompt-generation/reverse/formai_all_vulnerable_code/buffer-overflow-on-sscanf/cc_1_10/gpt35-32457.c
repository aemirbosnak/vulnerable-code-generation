//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert the file size from bytes to GB
float fileSizeToGB(unsigned long long int size) {
    return (float)size / (1024 * 1024 * 1024);
}

// Function to calculate the percentage of disk space used
float percentageUsed(float used, float total) {
    return (used / total) * 100;
}

// Function to sort the directories in descending order of size
void sortDirectories(char **directories, unsigned long long int *sizes, int n) {
    int i, j;
    char *tempDir;
    unsigned long long int tempSize;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (sizes[i] < sizes[j]) {
                tempSize = sizes[i];
                sizes[i] = sizes[j];
                sizes[j] = tempSize;

                tempDir = directories[i];
                directories[i] = directories[j];
                directories[j] = tempDir;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // Check if user entered disk name
    if (argc < 2) {
        printf("Please specify the disk name.\n");
        exit(0);
    }

    char *diskName = argv[1];
    char *cmd = malloc(strlen(diskName) + 7);
    sprintf(cmd, "du -sh %s/*", diskName); // Command to get sizes of all directories in the disk
    FILE *fp = popen(cmd, "r"); // Execute command and get output
    free(cmd);

    if (fp == NULL) {
        printf("Error in opening file.\n");
        exit(0);
    }

    char **directories = malloc(100 * sizeof(char *)); // Limiting to 100 directories
    unsigned long long int *sizes = malloc(100 * sizeof(unsigned long long int)); // Array to store directory sizes
    int i = 0;
    char *dirSize = malloc(100); // String to store directory size
    char *dirName = malloc(100); // String to store directory name

    // Parse the output of 'du' command to extract directory names and sizes
    while (fgets(dirSize, 100, fp) != NULL && i < 100) {
        sscanf(dirSize, "%llu", &sizes[i]);
        fgets(dirName, 100, fp);
        int nameLen = strlen(dirName);
        if (dirName[nameLen-1] == '\n') dirName[nameLen-1] = '\0'; // Remove newline character
        directories[i] = malloc(strlen(dirName) + 1);
        strcpy(directories[i], dirName);
        i++;
    }

    pclose(fp);
    free(dirSize);
    free(dirName);

    int n = i; // Number of directories found

    sortDirectories(directories, sizes, n); // Sort the directories based on size

    printf("Disk Space Usage Statistics for '%s'\n", diskName);
    printf("==================================================\n");
    printf("Total Space: %.2f GB\n", fileSizeToGB(sizes[n-1])); // Display the total space in the disk (last element in sorted sizes array)
    printf("Used Space: %.2f GB (%.2f%%)\n", fileSizeToGB(sizes[0]), percentageUsed(fileSizeToGB(sizes[0]), fileSizeToGB(sizes[n-1])));
    printf("Free Space: %.2f GB (%.2f%%)\n", fileSizeToGB(sizes[n-1] - sizes[0]), percentageUsed(fileSizeToGB(sizes[n-1] - sizes[0]), fileSizeToGB(sizes[n-1])));

    printf("\nDirectory Sizes (sorted in descending order):\n");
    printf("==================================================\n");
    for (i = 0; i < n; i++) {
        printf("%-50s\t%.2f GB (%.2f%%)\n", directories[i], fileSizeToGB(sizes[i]), percentageUsed(fileSizeToGB(sizes[i]), fileSizeToGB(sizes[n-1])));
    }

    // Free dynamically allocated memory
    for (i = 0; i < n; i++) {
        free(directories[i]);
    }
    free(directories);
    free(sizes);

    return 0;
}