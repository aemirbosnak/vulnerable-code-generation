//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define BACKUP_EXT ".bak"

void showInstructions() {
    printf("Welcome to the Official File Backup System!\n");
    printf("Please follow these instructions to save your life... I mean, your files:\n");
    printf("1. Enter the number of files you want to back up (up to %d).\n", MAX_FILES);
    printf("2. For each file, input its path. We will take care of the rest!\n");
    printf("3. Sit back, relax and watch the magic happen! (Or at least wait patiently)\n");
}

void backupFile(const char* filePath) {
    char backupPath[256];
    FILE *originalFile, *backupFile;
    char ch;

    // Professional and super serious backup file naming logic
    snprintf(backupPath, sizeof(backupPath), "%s%s", filePath, BACKUP_EXT);
    
    // Open the original file
    originalFile = fopen(filePath, "r");
    if (originalFile == NULL) {
        printf("Oh no! Could not open the file: %s\n", filePath);
        return;
    }

    // Open the backup file
    backupFile = fopen(backupPath, "w");
    if (backupFile == NULL) {
        fclose(originalFile);
        printf("Yikes! Could not create backup for: %s\n", filePath);
        return;
    }

    // Let’s copy the content like a ninja making a perfect duplicate
    while ((ch = fgetc(originalFile)) != EOF) {
        fputc(ch, backupFile);
    }

    printf("Success! 🥳 The file: %s has been backed up as: %s\n", filePath, backupPath);

    // Close the files—the dramatic ending!
    fclose(originalFile);
    fclose(backupFile);
}

int main() {
    int numFiles, i;
    char filePaths[MAX_FILES][256];
    
    showInstructions();

    printf("How many files do you want to backup? ");
    scanf("%d", &numFiles);

    // Sanity check: The user must not be a wild animal!
    if (numFiles < 1 || numFiles > MAX_FILES) {
        printf("Holy Guacamole! That's not a valid number of files. Please try again.\n");
        return 1;
    }

    for (i = 0; i < numFiles; i++) {
        printf("Please, Enlighten me with the path of file #%d: ", i + 1);
        scanf("%s", filePaths[i]);
    }

    printf("Alrighty then! Time for some backup magic! 🔮\n");

    for (i = 0; i < numFiles; i++) {
        backupFile(filePaths[i]);
    }

    printf("All files have been backed up! You’re now the proud parent of duplicate files!\n");
    printf("Remember, in the world of computers, it's always good to have a safety net! ✨\n");

    return 0;
}