//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PATH 256
#define MAX_COMMAND 512

void whisperToTheFile(const char *source, const char *destination) {
    FILE *src, *dest;
    char ch;

    src = fopen(source, "r");
    if (src == NULL) {
        fprintf(stderr, "Alas! Forbidden file: %s\n", source);
        return;
    }

    dest = fopen(destination, "w");
    if (dest == NULL) {
        fprintf(stderr, "Oh, cruel fate! Could not create: %s\n", destination);
        fclose(src);
        return;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);
    printf("A gentle breath of love has whispered your soul from %s to %s.\n", source, destination);
}

void createBackupPath(const char *filePath, char *backupPath) {
    char timeStamp[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(timeStamp, "%d-%02d-%02d_%02d-%02d-%02d",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    sprintf(backupPath, "%s_backup_%s", filePath, timeStamp);
}

void performBackup(const char *filePath) {
    char backupPath[MAX_PATH];
    createBackupPath(filePath, backupPath);
    whisperToTheFile(filePath, backupPath);
}

void callUponTheStars() {
    printf("Welcome, noble user! What file dost thou wish to save 'gainst the sands of time?\n");
}

int main() {
    char filePath[MAX_PATH];

    callUponTheStars();
    printf("Enter the path of the file you cherish: ");
    scanf("%s", filePath);

    performBackup(filePath);

    printf("Thus, your file's spirit lives on! Fare thee well, brave heart.\n");
    return 0;
}