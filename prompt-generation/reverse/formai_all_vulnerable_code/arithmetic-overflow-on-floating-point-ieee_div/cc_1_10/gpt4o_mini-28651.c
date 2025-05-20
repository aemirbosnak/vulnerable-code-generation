//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

void displayPoeticMessage(const char *path, unsigned long freeSpace, unsigned long totalSpace) {
    printf("\nA Serenade for Your Disk Space:\n");
    printf("----------------------------------\n");
    printf("Oh beautiful file system, beneath our touch,\n");
    printf("You cradle our data, oh so much.\n");
    printf("In the directory of %s, we long to know,\n", path);
    
    printf("Your total embrace, a soothing glow:\n");
    printf("Total Space: %lu bytes\n", totalSpace);
    printf("Free Space: %lu bytes\n", freeSpace);
    
    float percentageFree = ((float)freeSpace / totalSpace) * 100;
    printf("In your heart, %0.2f%% is free, oh so divine,\n", percentageFree);
    
    printf("Kindly guide me, dear disk, to save or delete,\n");
    printf("To make space for new memories, so bittersweet.\n");
    
    printf("----------------------------------\n");
}

void analyzeDiskSpace(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("Failed to get disk space information");
        return;
    }

    unsigned long totalSpace = stat.f_blocks * stat.f_frsize;  // Total size in bytes
    unsigned long freeSpace = stat.f_bfree * stat.f_frsize;    // Free size in bytes

    displayPoeticMessage(path, freeSpace, totalSpace);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Beloved user, you've called upon the muse of disk space...\n");
    printf("With fervent hopes, we shall analyze the beauty within:\n");

    analyzeDiskSpace(argv[1]);

    printf("May your files find their sweet spot,\n");
    printf("And may your storage ever be full of love.\n");

    return EXIT_SUCCESS;
}