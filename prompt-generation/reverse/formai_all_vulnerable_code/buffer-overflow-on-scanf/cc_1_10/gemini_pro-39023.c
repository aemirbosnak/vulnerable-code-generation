//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char *Weekdays[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

const char *Months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

void PrintBackupTitle(time_t t) {
    struct tm *lt = localtime(&t);
    printf("*** Backup created on %s, %s %d, %d at %d:%d:%d ***\n",
        Weekdays[lt->tm_wday], Months[lt->tm_mon], lt->tm_mday, lt->tm_year + 1900,
        lt->tm_hour, lt->tm_min, lt->tm_sec);
}

void FileBackup(const char *src, const char *dest) {
    FILE *f1 = fopen(src, "rb");
    FILE *f2 = fopen(dest, "wb");
    
    if (f1 == NULL || f2 == NULL) {
        perror("Error opening files");
        exit(1);
    }

    char buff[1024];
    size_t n;

    while ((n = fread(buff, 1, sizeof(buff), f1)) > 0) {
        fwrite(buff, 1, n, f2);
    }

    fclose(f1);
    fclose(f2);

    printf("File %s backed up to %s\n", src, dest);
}

int main() {
    char filename[256];
    char backup_filename[256];
    time_t t = time(NULL);

    // Print backup title
    PrintBackupTitle(t);
    
    // Prompt user for input
    printf("Enter the name of the file to be backed up: ");
    scanf("%s", filename);
    
    // Generate backup filename
    sprintf(backup_filename, "%s.bak", filename);
    
    // Perform file backup
    FileBackup(filename, backup_filename);
    
    return 0;
}