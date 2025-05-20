//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayDiskInfo(const char *path) {
    FILE *fp;
    char command[256];
    
    // Constructing command to get disk usage
    snprintf(command, sizeof(command), "df -h %s", path);
    
    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Could not open pipe for output.\n");
        return;
    }

    // Reading the output of the command
    char buffer[256];
    printf("\nO Romeo, where dost thou store thy data?\n");
    printf("Let me reveal the tales of your disk space:\n\n");
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Closing the pipe
    pclose(fp);
}

void romanticDiskAnalysis() {
    char choice[2];
    char path[256];

    printf("Enter the path to the directory (or drive) of love: ");
    scanf("%s", path);
    
    // Display the disk information
    displayDiskInfo(path);
    
    // Ask for the heart's desire to continue or exit
    printf("Wouldst thou like to seek more information? (y/n): ");
    scanf("%s", choice);
    
    if (strcmp(choice, "y") == 0) {
        romanticDiskAnalysis(); // Recursion for more inquiries
    } else {
        printf("Parting is such sweet sorrow. Farewell!\n");
    }
}

int main() {
    printf("Welcome to the Disk Space Analyzer of Verona!\n");
    printf("Forsooth, let us embark on this noble quest!\n");

    // Begin analyzing the disk space
    romanticDiskAnalysis();

    return 0;
}