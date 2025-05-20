//FormAI DATASET v1.0 Category: File Backup System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME 100
#define MAX_BACKUPS 10

int main() {
    char filename[MAX_FILENAME];
    char backup_filenames[MAX_BACKUPS][MAX_FILENAME];
    int num_backups = 0;
    int choice, i;

    printf("Enter filename to backup: ");
    scanf("%s", filename);

    FILE* fp_src = fopen(filename, "r");
    if (fp_src == NULL) {
        printf("Error opening source file!\n");
        exit(1);
    }

    while (1) {
        printf("\nSelect option:\n1. Backup file\n2. Restore from backup\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_backups >= MAX_BACKUPS) {
                    printf("Cannot create more than %d backups!\n", MAX_BACKUPS);
                    break;
                }
                char backup_filename[MAX_FILENAME];
                snprintf(backup_filename, MAX_FILENAME, "%s.bak%d", filename, num_backups + 1);
                FILE* fp_dst = fopen(backup_filename, "w");
                if (fp_dst == NULL) {
                    printf("Error creating backup file!\n");
                    break;
                }

                int c;
                while ((c = fgetc(fp_src)) != EOF) {
                    fputc(c, fp_dst);
                }
                fclose(fp_dst);
                printf("Backup successful!\n");
                strcpy(backup_filenames[num_backups], backup_filename);
                num_backups++;

                break;
            case 2:
                if (num_backups == 0) {
                    printf("No backups found!\n");
                    break;
                }
                printf("Select backup to restore:\n");
                for (i = 0; i < num_backups; i++) {
                    printf("%d. %s\n", i + 1, backup_filenames[i]);
                }
                int backup_choice;
                scanf("%d", &backup_choice);
                if (backup_choice < 1 || backup_choice > num_backups) {
                    printf("Invalid backup selection!\n");
                    break;
                }

                char* chosen_backup_filename = backup_filenames[backup_choice - 1];
                FILE* fp_src_backup = fopen(chosen_backup_filename, "r");
                if (fp_src_backup == NULL) {
                    printf("Error opening backup file: %s\n", chosen_backup_filename);
                    break;
                }

                FILE* fp_dst_restore = fopen(filename, "w");
                if (fp_dst_restore == NULL) {
                    printf("Error restoring file!\n");
                    break;
                }

                int c_restore;
                while ((c_restore = fgetc(fp_src_backup)) != EOF) {
                    fputc(c_restore, fp_dst_restore);
                }
                fclose(fp_dst_restore);
                printf("File successfully restored from backup!\n");

                break;
            case 3:
                printf("Quitting...\n");
                fclose(fp_src);
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}