//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: excited
// Brace yourselves, folks! The ultimate C File Backup System is arriving!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These constants are the backbone of our backup system!
#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

// And now, let's define some snazzy data structures!
typedef struct File {
    char name[50];
    char contents[MAX_FILE_SIZE];
    int size;
} File;

// Time for the main event! The granddaddy of all file backup systems!
int main() {
    // Behold, the mighty army of files we're about to conquer!
    File files[MAX_FILES];

    // Let's get some user input. We're gonna make this interactive!
    int numFiles;
    printf("How many files do you want to back up, my friend? :");
    scanf("%d", &numFiles);

    // Time to get the details of our beloved files.
    for (int i = 0; i < numFiles; i++) {
        printf("Enter file %d name: ", i + 1);
        scanf("%s", files[i].name);

        printf("Enter file %d contents: ", i + 1);
        scanf("%s", files[i].contents);

        // Don't forget the size!
        files[i].size = strlen(files[i].contents);
    }

    // Hold your horses! We're about to open a backup file.
    FILE *backupFile;
    backupFile = fopen("backup.txt", "w");

    // Now, let's write our files into that backup file with style!
    for (int i = 0; i < numFiles; i++) {
        fprintf(backupFile, "%s\n%d\n%s\n", files[i].name, files[i].size, files[i].contents);
    }

    // Mission accomplished! We've backed up our files like champs.
    fclose(backupFile);

    // Time for some well-deserved celebration!
    printf("Ta-da! Your files are safely backed up! Feel the joy!\n");
    return 0;
}