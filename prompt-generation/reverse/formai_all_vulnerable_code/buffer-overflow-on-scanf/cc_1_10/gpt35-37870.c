//FormAI DATASET v1.0 Category: Data recovery tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    char file_name[50];
    FILE *fp = NULL;
    int choice, posi, size;
    char ch, backup[50];

    printf("Enter the name of the file to open: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file, please check the file name and try again.");
        return (-1);
    }

    printf("Do you want to perform data recovery? (yes=1, no=0): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Specify the position where recovery should start: ");
        scanf("%d", &posi);

        printf("Specify the amount of data to recover: ");
        scanf("%d", &size);

        fseek(fp, posi, SEEK_SET);

        for (int i = 0; i < size; i++) {
            ch = getc(fp);
            printf("%c", ch);
        }

        printf("\nRecovery completed successfully!\n\n");
    } else {
        printf("Do you want to create a backup of the file? (yes=1, no=0): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the name of the backup file: ");
            scanf("%s", backup);

            FILE *backup_fp = NULL;
            backup_fp = fopen(backup, "w");

            while ((ch = getc(fp)) != EOF)
                putc(ch, backup_fp);

            fclose(backup_fp);

            printf("Backup created successfully!\n\n");
        } else {
            printf("No problem, exiting program...\n\n");
        }
    }

    fclose(fp);
    return 0;
}