//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

void displayDiskSpace(const char* path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) { 
        // Error occurred
        perror("Oops! I can't seem to find your disk!");
        return;
    }

    unsigned long totalBlocks = stat.f_blocks * stat.f_bsize;
    unsigned long availableBlocks = stat.f_bavail * stat.f_bsize;
    unsigned long usedBlocks = totalBlocks - availableBlocks;
    
    unsigned long totalMB = totalBlocks / (1024 * 1024);
    unsigned long availableMB = availableBlocks / (1024 * 1024);
    unsigned long usedMB = usedBlocks / (1024 * 1024);

    printf("\n🌍 Disk Space Stats for: %s \n", path);
    printf("🗄️  Total Space: %lu MB\n", totalMB);
    printf("💾  Used Space: %lu MB\n", usedMB);
    printf("🗑️  Available Space: %lu MB\n", availableMB);

    printf("\n🤖 That's all I could find! Let's calculate your storage fortune:\n");

    if (usedMB != 0) {
        float usagePercent = ((float)usedMB / totalMB) * 100;
        printf("📊 You are using %.2f%% of your storage.\n", usagePercent);
    } else {
        printf("🎉 You have not used a single MB yet! Are you feeling lonely? 😢 \n");
    }

    printf("\n📅 Reminder: Remember to declutter! Your disk isn’t a hoarder’s paradise!\n");
}

int main() {
    char path[256];

    printf("👋 Welcome to the Wacky Disk Space Analyzer!\n");
    printf("Enter the path you want to analyze (or type your home directory): ");
    scanf("%s", path);

    if (path[0] == '\0') {
        printf("😅 You didn't enter anything! No worries! I'll check your home directory!\n");
        snprintf(path, sizeof(path), "/home/%s", getenv("USER"));
    }

    displayDiskSpace(path);

    printf("\n💡 Tip: Regularly clean up your disk. The less clutter, the happier your files! 🎉\n");
    printf("🚀 Thank you for using the Wacky Disk Space Analyzer! 💻\n");

    return 0;
}