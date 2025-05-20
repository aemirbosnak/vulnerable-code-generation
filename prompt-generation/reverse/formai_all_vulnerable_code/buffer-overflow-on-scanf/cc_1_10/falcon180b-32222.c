//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100 MB

typedef struct {
    char name[100];
    int size;
    char *content;
} File;

void backup_file(File *file) {
    FILE *backup_file = fopen("backup.txt", "a");
    fprintf(backup_file, "%s %d\n", file->name, file->size);
    fclose(backup_file);
}

int main() {
    int num_files;
    scanf("%d", &num_files);

    File *files = malloc(num_files * sizeof(File));

    for (int i = 0; i < num_files; i++) {
        scanf("%s", files[i].name);
        files[i].size = 0;
        files[i].content = malloc(MAX_FILE_SIZE);
    }

    char ch;
    int file_index = 0;

    while ((ch = getchar())!= EOF) {
        if (ch == '\n') {
            backup_file(&files[file_index]);
            file_index++;
        } else {
            files[file_index].content[files[file_index].size++] = ch;
        }
    }

    backup_file(&files[file_index]);

    for (int i = 0; i < num_files; i++) {
        free(files[i].content);
    }
    free(files);

    return 0;
}