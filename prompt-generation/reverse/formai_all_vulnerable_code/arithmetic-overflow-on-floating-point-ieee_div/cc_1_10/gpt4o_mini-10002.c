//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>

void print_happy_space_info(const char *path) {
    struct statvfs stat;

    // Get filesystem statistics
    if (statvfs(path, &stat) != 0) {
        perror("Could not retrieve disk statistics");
        return;
    }

    // Calculate sizes in KB
    unsigned long total = (stat.f_blocks * stat.f_frsize) / 1024;
    unsigned long free = (stat.f_bfree * stat.f_frsize) / 1024;
    unsigned long used = total - free;

    // Calculate usage percentages
    double used_percentage = (double)used / total * 100;
    
    // Print results in a happy way
    printf("\n🎉 Happy Disk Space Analyzer! 🎉\n");
    printf("====================================\n");
    printf("📂 Path Analyzed: %s\n", path);
    printf("🌟 Total Space : %lu KB\n", total);
    printf("🌼 Used Space  : %lu KB (%.2f%%)\n", used, used_percentage);
    printf("🌱 Free Space  : %lu KB\n", free);
    printf("====================================\n");

    // Color coding based on used space
    if (used_percentage < 60) {
        printf("😊 All is well! You have plenty of space left to play around!\n");
    } else if (used_percentage < 80) {
        printf("😌 You're getting closer, but you still have some space! Clean up a bit!\n");
    } else {
        printf("😱 Oh no! You're running out of space! Time for some spring cleaning!\n");
    }
}

int main(int argc, char *argv[]) {
    // Determine the path to analyze
    const char *path = (argc > 1) ? argv[1] : "/";

    // Print a friendly welcome message
    printf("Welcome to the Disk Space Analyzer!\n");
    printf("Let's see how much space is left on your disk! 🚀\n\n");

    // Analyze and print disk space information
    print_happy_space_info(path);

    // Thank the user for using the program
    printf("\nThank you for using our Happy Disk Space Analyzer! 🎈\n");
    printf("Remember to keep your disk clean and organized!\n");

    return 0;
}