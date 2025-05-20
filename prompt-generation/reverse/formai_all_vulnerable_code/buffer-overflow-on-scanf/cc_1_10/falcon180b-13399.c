//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct node {
    char filename[SIZE];
    char backupfilename[SIZE];
};

void main() {
    int n, i, j;
    char choice;
    struct node file[10];

    printf("Enter the number of files to be backed up: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the name of file %d: ", i + 1);
        scanf("%s", file[i].filename);
        strcat(file[i].backupfilename, "backup_");
        strcat(file[i].backupfilename, file[i].filename);
    }

    do {
        printf("\n1. Backup\n2. Restore\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                for (i = 0; i < n; i++) {
                    strcat(file[i].backupfilename, ".bak");
                    rename(file[i].filename, file[i].backupfilename);
                }
                printf("\nBackup completed successfully!");
                break;

            case '2':
                for (i = 0; i < n; i++) {
                    strcat(file[i].filename, ".bak");
                    rename(file[i].backupfilename, file[i].filename);
                }
                printf("\nRestore completed successfully!");
                break;

            case '3':
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice!");
        }
    } while (choice!= '3');
}