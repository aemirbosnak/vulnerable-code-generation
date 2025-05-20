//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

struct file_info {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
};

int main() {
    struct file_info file_info[10];

    int num_files = 0;
    printf("Enter number of files: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter file name: ");
        scanf("%s", file_info[i].file_name);

        printf("Enter backup file name: ");
        scanf("%s", file_info[i].backup_file_name);

        printf("Enter content: ");
        fgets(file_info[i].line, MAX_LINE_LENGTH, stdin);
    }

    for (int i = 0; i < num_files; i++) {
        FILE *file = fopen(file_info[i].file_name, "r");
        if (file == NULL) {
            printf("Error opening file: %s\n", file_info[i].file_name);
            continue;
        }

        FILE *backup_file = fopen(file_info[i].backup_file_name, "w");
        if (backup_file == NULL) {
            printf("Error opening backup file: %s\n", file_info[i].backup_file_name);
            fclose(file);
            continue;
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
            if (strlen(line) > 0) {
                fprintf(backup_file, "%s\n", line);
            }
        }

        fclose(file);
        fclose(backup_file);
    }

    return 0;
}