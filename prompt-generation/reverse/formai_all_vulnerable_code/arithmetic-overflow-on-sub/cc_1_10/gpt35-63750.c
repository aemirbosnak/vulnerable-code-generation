//FormAI DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LENGTH 50 // Maximum length of each file name
#define MAX_FILES 10 // Maximum number of files

struct file {
    char name[FILENAME_LENGTH];
    int size;
    char date[20];
};

// Function to check if two files are the same
int checkFiles(struct file f1, struct file f2) {
    if (strcmp(f1.name, f2.name) == 0 && f1.size == f2.size && strcmp(f1.date, f2.date) == 0)
        return 1;
    else
        return 0;
}

// Function to copy files
void copyFile(struct file f1, struct file f2) {
    FILE *fp1, *fp2;
    char c;

    // Open the source file
    fp1 = fopen(f1.name, "r");
    if (fp1 == NULL) {
        printf("Error: %s not found!\n", f1.name);
        return;
    }

    // Open the destination file
    fp2 = fopen(f2.name, "w");
    if (fp2 == NULL) {
        printf("Error: Could not create %s!\n", f2.name);
        fclose(fp1);
        return;
    }

    // Copy file contents from source to destination
    while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp2);

    // Close files
    fclose(fp1);
    fclose(fp2);
}

int main() {
    int i, j, numFiles;
    struct file files[MAX_FILES];

    // Get number of files to synchronize
    printf("Enter number of files to synchronize (max %d): ", MAX_FILES);
    scanf("%d", &numFiles);

    // Get file details from user
    for (i = 0; i < numFiles; i++) {
        printf("\nEnter details for file %d:\n", i+1);
        printf("Name: ");
        scanf("%s", files[i].name);
        printf("Size (in bytes): ");
        scanf("%d", &files[i].size);
        printf("Date modified: ");
        scanf("%s", files[i].date);
    }

    // Check for duplicate files and prompt user to choose whether to overwrite or keep the existing file
    for (i = 0; i < numFiles-1; i++) {
        for (j = i+1; j < numFiles; j++) {
            if (checkFiles(files[i], files[j]) == 1) {
                int choice;
                printf("\n%s and %s are duplicates.\n", files[i].name, files[j].name);
                printf("Choose an option:\n");
                printf("1. Overwrite %s with %s\n", files[j].name, files[i].name);
                printf("2. Keep %s and delete %s\n", files[i].name, files[j].name);
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        copyFile(files[i], files[j]);
                        printf("%s overwritten with %s\n", files[j].name, files[i].name);
                        break;
                    case 2:
                        remove(files[j].name);
                        printf("%s deleted\n", files[j].name);
                        break;
                    default:
                        printf("Invalid choice!");
                }
            }
        }
    }

    printf("\nFile synchronization complete!\n");

    return 0;
}