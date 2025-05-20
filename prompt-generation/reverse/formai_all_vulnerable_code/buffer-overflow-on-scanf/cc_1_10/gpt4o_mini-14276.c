//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/statvfs.h>
#include <dirent.h>
#include <string.h>

void displayCurrentTime() {
    time_t now;
    struct tm *tm_info;
    char buffer[26];

    time(&now);
    tm_info = localtime(&now);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("😊 Current Date and Time: %s\n", buffer);
}

void checkDiskSpace() {
    struct statvfs stat;

    // Get file system statistics
    if (statvfs("/", &stat) != 0) {
        printf("😢 Unable to retrieve disk space information!\n");
        return;
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;
    
    printf("🌟 Disk Space Information:\n");
    printf("   Total space: %lu bytes\n", total);
    printf("   Used space: %lu bytes\n", used);
    printf("   Free space: %lu bytes\n", free);
    printf("💡 Keep your system healthy and tidy! \n");
}

void listFilesInDirectory(const char *path) {
    struct dirent *de;
    DIR *dr = opendir(path);

    if (dr == NULL) {
        printf("😢 Couldn't open directory: %s\n", path);
        return;
    }

    printf("📂 Files in directory '%s':\n", path);
    while ((de = readdir(dr)) != NULL) {
        if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
            printf("   - %s\n", de->d_name);
        }
    }
    closedir(dr);
    printf("🎉 Listing completed! \n");
}

void showMenu() {
    printf("🎉 Welcome to the Happy System Admin Tool! 🎉\n");
    printf("Please choose an option:\n");
    printf("1. Display current date and time\n");
    printf("2. Check disk space\n");
    printf("3. List files in a directory\n");
    printf("4. Exit\n");
    printf("💖 Enter your choice: ");
}

int main() {
    int choice;
    char dirPath[256];

    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayCurrentTime();
                break;
            case 2:
                checkDiskSpace();
                break;
            case 3:
                printf("💖 Please enter the directory path: ");
                scanf("%s", dirPath);
                listFilesInDirectory(dirPath);
                break;
            case 4:
                printf("🚪 Exiting the Happy System Admin Tool. Have a great day! 😊\n");
                return 0;
            default:
                printf("😅 Invalid choice, please try again!\n");
        }
        printf("\n");
    }

    return 0;
}