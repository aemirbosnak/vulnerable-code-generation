//FormAI DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILECOPIES 10

struct fileCopy {
    char filename[MAX_FILENAME_LENGTH];
    time_t date;
};

struct backup {
    int numCopies;
    struct fileCopy copies[MAX_FILECOPIES];
};

int main() {

    struct backup backup;
    backup.numCopies = 0;

    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    time_t currentTime;
    time(&currentTime);

    struct fileCopy fileCopy;
    strcpy(fileCopy.filename, filename);
    fileCopy.date = currentTime;

    if (backup.numCopies < MAX_FILECOPIES) {
        backup.copies[backup.numCopies] = fileCopy;
        backup.numCopies++;
    }
    else {
        for (int i = 0; i < MAX_FILECOPIES - 1; i++) {
            backup.copies[i] = backup.copies[i+1];
        }
        backup.copies[MAX_FILECOPIES - 1] = fileCopy;
    }

    printf("File backup created:\n");
    for (int i = 0; i < backup.numCopies; i++) {
        struct fileCopy currCopy = backup.copies[i];
        printf("%s backed up on %s", currCopy.filename, ctime(&currCopy.date));
    }

    return 0;
}