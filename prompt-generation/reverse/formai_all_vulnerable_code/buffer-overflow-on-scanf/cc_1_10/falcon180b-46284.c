//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_LEN 1000

typedef struct {
    char name[MAX_FILE_LEN];
    bool modified;
} file_t;

void read_files(file_t files[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter file name for %d: ", i + 1);
        scanf("%s", files[i].name);
        files[i].modified = false;
    }
}

void compare_files(file_t files[], int count) {
    for (int i = 0; i < count; i++) {
        if (files[i].modified) {
            printf("File %s has been modified.\n", files[i].name);
        }
    }
}

int main() {
    int count;
    printf("Enter number of files: ");
    scanf("%d", &count);

    file_t files[count];
    read_files(files, count);

    int sync_count = 0;
    while (true) {
        printf("\nEnter 1 to sync files or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        sync_count++;
        compare_files(files, count);
    }

    printf("\nTotal number of syncs: %d\n", sync_count);

    return 0;
}