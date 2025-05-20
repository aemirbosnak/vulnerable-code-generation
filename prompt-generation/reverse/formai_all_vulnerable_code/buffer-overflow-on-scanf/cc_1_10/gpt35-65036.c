//FormAI DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_NUM_BACKUPS 10

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    time_t timestamp;
} Backup;

int main() {
    char filename[MAX_FILENAME_LENGTH];
    int num_backups = 0;
    Backup backups[MAX_NUM_BACKUPS];

    printf("Welcome to the C File Backup System!\n");

    while (1) {
        printf("Enter the filename to back up (or 'q' to quit): ");
        scanf("%s", filename);

        if (strcmp(filename, "q") == 0) {
            break;
        }

        // make a new backup
        Backup new_backup;
        strcpy(new_backup.name, filename);
        new_backup.timestamp = time(NULL);

        if (num_backups < MAX_NUM_BACKUPS) {
            backups[num_backups] = new_backup;
            num_backups++;
        } else {
            // shift all existing backups to the left to make space for new backup
            for (int i = 0; i < num_backups - 1; i++) {
                backups[i] = backups[i+1];
            }
            backups[num_backups - 1] = new_backup;
        }

        printf("Backup created with name '%s' and timestamp %s", new_backup.name, ctime(&new_backup.timestamp));
    }

    // print all backups
    printf("Backups:\n");
    for (int i = 0; i < num_backups; i++) {
        printf("%d. %s (%s)", i+1, backups[i].name, ctime(&backups[i].timestamp));
    }

    return 0;
}