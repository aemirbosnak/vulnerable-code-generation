//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>

void displayWizardsGreeting() {
    printf("Hark! Welcome to the Grand Disk Space Analyzer of the Realm!\n");
    printf("Forsooth! Let us embark upon a journey to discover the hidden treasures\n");
    printf("and vast expanses of disk space that lie beneath.\n\n");
}

void displayUsage() {
    printf("Usage: ./disk_space_analyzer <mount_point>\n");
    printf("Example: ./disk_space_analyzer /home\n");
}

void analyzeDiskSpace(const char *mountPoint) {
    struct statvfs stat;

    if (statvfs(mountPoint, &stat) != 0) {
        fprintf(stderr, "Alas! The mystical mount point '%s' is not found!\n", mountPoint);
        return;
    }
    
    unsigned long totalSize = stat.f_blocks * stat.f_frsize;
    unsigned long freeSpace = stat.f_bfree * stat.f_frsize;
    unsigned long usedSpace = totalSize - freeSpace;

    printf("Thou hast chosen: %s\n", mountPoint);
    printf("Total Space: %lu bytes\n", totalSize);
    printf("Free Space: %lu bytes\n", freeSpace);
    printf("Used Space: %lu bytes\n", usedSpace);
    
    printf("\nThe divine percentage of usage is:\n");
    double usagePercentage = (double)usedSpace / totalSize * 100;
    printf("Disk Usage: %.2f%%\n", usagePercentage);
    
    if (usagePercentage < 70.0) {
        printf("Verily, thou art in the safe limits! Continue thy quest!\n");
    } else if (usagePercentage < 90.0) {
        printf("Beware! The disk fills quickly. Consider freeing some space!\n");
    } else {
        printf("Alas! Thy disk is nearly full! Act swiftly to save thy data!\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayUsage();
        return EXIT_FAILURE;
    }
    
    displayWizardsGreeting();
    
    const char *mountPoint = argv[1];
    analyzeDiskSpace(mountPoint);

    printf("\nMay the forces of the filesystem be with thee!\n");
    return EXIT_SUCCESS;
}