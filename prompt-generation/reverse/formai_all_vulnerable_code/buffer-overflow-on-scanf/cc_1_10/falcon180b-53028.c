//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char filename[100];
    char backup_filename[100];
    time_t timestamp;
} backup_file;

void backup_file_init(backup_file *b, char *filename) {
    strcpy(b->filename, filename);
    strcpy(b->backup_filename, "backup_");
    strcat(b->backup_filename, filename);
    strcat(b->backup_filename, ".bak");
    b->timestamp = time(NULL);
}

int backup_file_compare(const void *a, const void *b) {
    backup_file *file1 = (backup_file*)a;
    backup_file *file2 = (backup_file*)b;
    if (file1->timestamp > file2->timestamp) {
        return -1;
    } else if (file1->timestamp < file2->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

void backup_file_list(backup_file *b, int num_files) {
    printf("Backup Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s %s %s\n", b[i].filename, ctime(&b[i].timestamp), b[i].backup_filename);
    }
}

int main() {
    backup_file b[100];
    int num_files = 0;
    char filename[100];
    while (1) {
        printf("Enter filename to backup (or type 'list' to view backups): ");
        scanf("%s", filename);
        if (strcmp(filename, "list") == 0) {
            backup_file_list(b, num_files);
        } else {
            backup_file_init(&b[num_files], filename);
            num_files++;
        }
    }
    return 0;
}