//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    int size;
    int modified;
} File;

void add_file(File *files, int count, char *filename) {
    files[count].filename = filename;
    files[count].size = 0;
    files[count].modified = 0;
}

void print_files(File *files, int count) {
    printf("Files:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%d bytes)\n", files[i].filename, files[i].size);
    }
}

void sync_files(File *local_files, int local_count, File *remote_files, int remote_count) {
    printf("Syncing files...\n");
    for (int i = 0; i < local_count; i++) {
        for (int j = 0; j < remote_count; j++) {
            if (strcmp(local_files[i].filename, remote_files[j].filename) == 0) {
                if (local_files[i].size!= remote_files[j].size || local_files[i].modified) {
                    printf("Updating %s...\n", local_files[i].filename);
                    local_files[i].size = remote_files[j].size;
                    local_files[i].modified = 0;
                    break;
                }
            }
        }
    }
}

int main() {
    int local_count, remote_count;
    printf("Enter number of local files: ");
    scanf("%d", &local_count);
    File local_files[local_count];
    for (int i = 0; i < local_count; i++) {
        char filename[100];
        printf("Enter filename %d: ", i+1);
        scanf("%s", filename);
        add_file(local_files, i, filename);
    }

    printf("Enter number of remote files: ");
    scanf("%d", &remote_count);
    File remote_files[remote_count];
    for (int i = 0; i < remote_count; i++) {
        char filename[100];
        printf("Enter filename %d: ", i+1);
        scanf("%s", filename);
        add_file(remote_files, i, filename);
    }

    sync_files(local_files, local_count, remote_files, remote_count);

    print_files(local_files, local_count);
    printf("\n");
    print_files(remote_files, remote_count);

    return 0;
}