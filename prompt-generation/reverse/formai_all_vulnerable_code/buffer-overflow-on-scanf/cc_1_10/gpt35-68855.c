//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXLENGTH 256

void backup(char src[], char dest[]) {
    // Generate timestamp for filename
    time_t rawtime;
    struct tm *timeinfo;
    char timestamp[MAXLENGTH];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, MAXLENGTH, "_%Y%m%d_%H%M%S", timeinfo);

    // Append timestamp to destination filename
    char backup_file[MAXLENGTH];
    strncpy(backup_file, dest, strlen(dest) - 4);
    strcat(backup_file, timestamp);
    strcat(backup_file, ".bak");

    // Copy file from source to destination with new filename
    FILE *source = fopen(src, "r");
    FILE *backup = fopen(backup_file, "w");
    if (source == NULL || backup == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, backup);
    }

    fclose(source);
    fclose(backup);

    printf("Backup successful!\n");
}

int main() {
    char source_file[MAXLENGTH];
    char dest_file[MAXLENGTH];

    printf("Enter source filename: ");
    scanf("%s", source_file);

    printf("Enter destination filename: ");
    scanf("%s", dest_file);

    backup(source_file, dest_file);

    return 0;
}