//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <dirent.h>

void show_uptime() {
    struct sysinfo sys_info;
    sysinfo(&sys_info);
    
    printf("\033[1;34mUptime:\033[0m %ld days, %ld hours, %ld minutes\n",
           sys_info.uptime / 86400,
           (sys_info.uptime % 86400) / 3600,
           (sys_info.uptime % 3600) / 60);
}

void list_files() {
    struct dirent *de;
    DIR *dr = opendir("."); // Current directory

    if (dr == NULL) {
        printf("\033[1;31mCould not open current directory\033[0m\n");
        return;
    }

    printf("\033[1;32mListing files in current directory:\033[0m\n");
    while ((de = readdir(dr)) != NULL) {
        printf(" - %s\n", de->d_name);
    }
    closedir(dr);
}

void check_memory() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    
    long totalVirtualMem = memInfo.totalram;
    totalVirtualMem *= memInfo.mem_unit;
    
    long virtualMemUsed = memInfo.totalram - memInfo.freeram;
    virtualMemUsed *= memInfo.mem_unit;

    printf("\033[1;36mMemory Usage:\033[0m\n");
    printf(" - Total Memory: %.2f GB\n", totalVirtualMem / (1024.0 * 1024 * 1024));
    printf(" - Used Memory: %.2f GB\n", virtualMemUsed / (1024.0 * 1024 * 1024));
}

void show_menu() {
    printf("\n\033[1;35m========================\033[0m\n");
    printf("\033[1;35m   System Admin Tool    \033[0m\n");
    printf("\033[1;35m========================\033[0m\n");
    printf("\033[1;33m1. Show System Uptime\033[0m\n");
    printf("\033[1;33m2. List Files in Current Directory\033[0m\n");
    printf("\033[1;33m3. Check Memory Usage\033[0m\n");
    printf("\033[1;33m4. Exit\033[0m\n");
    printf("\033[1;35m========================\033[0m\n");
}

int main() {
    int choice;
    
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                show_uptime();
                break;
            case 2:
                list_files();
                break;
            case 3:
                check_memory();
                break;
            case 4:
                printf("\033[1;32mExiting the System Admin Tool. Goodbye!\033[0m\n");
                exit(0);
            default:
                printf("\033[1;31mInvalid choice! Please try again.\033[0m\n");
        }
    }

    return 0;
}