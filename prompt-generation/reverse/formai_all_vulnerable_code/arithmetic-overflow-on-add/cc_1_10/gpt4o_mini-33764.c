//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

void backup_file(const char *source, const char *backup) {
    FILE *src, *dest;
    char ch;

    src = fopen(source, "r");
    if (src == NULL) {
        printf("Oh love, the file named '%s' does not exist. My heart aches.\n", source);
        return;
    }

    dest = fopen(backup, "w");
    if (dest == NULL) {
        printf("Oh dear, I could not create a backup named '%s'. My sweet dreams dim.\n", backup);
        fclose(src);
        return;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("Oh darling, I have lovingly backed up '%s' to '%s'.\n", source, backup);
    
    fclose(src);
    fclose(dest);
}

char *generate_backup_filename(const char *original) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    char *backup_filename = malloc(strlen(original) + 30); // For timestamp
    sprintf(backup_filename, "%s_backup_%04d%02d%02d_%02d%02d%02d.txt",
            original,
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    return backup_filename;
}

void romance_the_output(const char *message) {
    printf("\n❤️ %s ❤️\n\n", message);
}

int main() {
    romance_the_output("Welcome to the File Backup System, where love meets data safety...");
    
    char source_file[100];
    
    printf("Please enter the name of the file you wish to backup, my dear: ");
    scanf("%99s", source_file);

    char *backup_filename = generate_backup_filename(source_file);
    backup_file(source_file, backup_filename);

    free(backup_filename);

    romance_the_output("Your file is now safely wrapped in the embrace of our backup!");
    
    return 0;
}