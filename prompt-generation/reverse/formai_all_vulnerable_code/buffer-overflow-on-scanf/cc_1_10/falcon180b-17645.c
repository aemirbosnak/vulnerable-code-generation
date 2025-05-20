//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define BACKUP_DIR "backup"

typedef struct {
    char *name;
    char *content;
    size_t size;
} file_t;

int main() {
    int num_files = 0;
    file_t *files = NULL;

    printf("Enter the number of files to backup:\n");
    scanf("%d", &num_files);

    files = malloc(num_files * sizeof(file_t));

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d:\n", i+1);
        char name[100];
        scanf("%s", name);
        files[i].name = strdup(name);

        printf("Enter the content of file %s:\n", name);
        char content[MAX_FILE_SIZE];
        scanf("%s", content);
        files[i].content = strdup(content);
        files[i].size = strlen(content);
    }

    mkdir(BACKUP_DIR, 0777);

    for (int i = 0; i < num_files; i++) {
        char backup_path[100];
        sprintf(backup_path, "%s/%s.bak", BACKUP_DIR, files[i].name);
        FILE *backup_file = fopen(backup_path, "w");

        if (backup_file == NULL) {
            printf("Error creating backup file %s\n", backup_path);
            exit(1);
        }

        fprintf(backup_file, "%s", files[i].content);
        fclose(backup_file);
    }

    printf("Backup completed successfully!\n");

    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
        free(files[i].content);
    }
    free(files);

    return 0;
}