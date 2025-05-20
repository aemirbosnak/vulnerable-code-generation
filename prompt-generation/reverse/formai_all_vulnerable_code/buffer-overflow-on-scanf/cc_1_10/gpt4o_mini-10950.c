//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"

void print_divider() {
    printf("%s--------------------------------------------------%s\n", COLOR_YELLOW, COLOR_RESET);
}

void print_header() {
    printf("%s%30s Disk Space Analyzer %30s%s\n", COLOR_GREEN, "", "", COLOR_RESET);
    print_divider();
}

void display_disk_usage(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("Failed to get disk space information");
        return; // Cannot proceed
    }

    unsigned long total = stat.f_blocks * stat.f_frsize; // Total combined bytes
    unsigned long free = stat.f_bfree * stat.f_frsize; // Free bytes
    unsigned long used = total - free; // Used bytes

    printf("%sDisk Space Usage for: %s%s\n", COLOR_GREEN, path, COLOR_RESET);
    printf("%sTotal Space: %lu MB%s\n", COLOR_GREEN, total / (1024 * 1024), COLOR_RESET);
    printf("%sUsed Space: %lu MB%s\n", COLOR_RED, used / (1024 * 1024), COLOR_RESET);
    printf("%sFree Space: %lu MB%s\n", COLOR_YELLOW, free / (1024 * 1024), COLOR_RESET);
    print_divider();
}

void scan_directories(const char *path) {
    char command[256];
    snprintf(command, sizeof(command), "du -sh %s/*", path);
    printf("%sScanning directory: %s%s\n", COLOR_GREEN, path, COLOR_RESET);
    system(command);
}

void show_details_prompt() {
    char choice;
    printf("%sDo you want to see detailed directory usage? (y/n): %s", COLOR_YELLOW, COLOR_RESET);
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        printf("\n%sLaunching detailed directory size check...%s\n", COLOR_GREEN, COLOR_RESET);
    } else {
        printf("%sSkipping detailed check...%s\n", COLOR_YELLOW, COLOR_RESET);
        return;
    }
}

int main() {
    char root_path[256];

    print_header();
    printf("%sEnter the directory path to analyze (e.g., / or /home): %s", COLOR_GREEN, COLOR_RESET);
    scanf("%s", root_path);

    // Display disk usage
    display_disk_usage(root_path);
    
    // Prompt for detailed directory scan
    show_details_prompt();

    // Scan directories
    scan_directories(root_path);

    printf("%sThank you for using the Disk Space Analyzer!%s\n", COLOR_GREEN, COLOR_RESET);
    return 0;
}