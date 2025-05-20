//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char filename[MAX_FILE_SIZE];
    int size;
    int modified;
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void add_file(char* filename) {
    if (num_files >= MAX_FILES) {
        printf("Sorry, too many files!\n");
        return;
    }
    strcpy(files[num_files].filename, filename);
    files[num_files].size = 0;
    files[num_files].modified = 0;
    num_files++;
}

void sync_files() {
    int i, j;
    for (i = 0; i < num_files; i++) {
        if (files[i].modified) {
            printf("Syncing file %s...\n", files[i].filename);
            for (j = 0; j < num_files; j++) {
                if (j == i)
                    continue;
                if (strcmp(files[i].filename, files[j].filename) == 0) {
                    if (files[i].size > files[j].size) {
                        printf("Copying %d bytes from %s to %s...\n", files[i].size - files[j].size, files[i].filename, files[j].filename);
                        files[j].size = files[i].size;
                    } else if (files[i].size < files[j].size) {
                        printf("Copying %d bytes from %s to %s...\n", files[j].size - files[i].size, files[j].filename, files[i].filename);
                        files[i].size = files[j].size;
                    }
                }
            }
        }
    }
}

int main() {
    int choice;
    char filename[MAX_FILE_SIZE];

    while (1) {
        printf("1. Add file\n2. Sync files\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter filename: ");
            scanf("%s", filename);
            add_file(filename);
            break;
        case 2:
            sync_files();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}