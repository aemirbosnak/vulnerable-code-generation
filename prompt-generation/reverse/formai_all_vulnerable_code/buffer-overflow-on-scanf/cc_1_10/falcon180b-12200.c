//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char filename[100];
    time_t timestamp;
} file_t;

void backup_file(char* filename) {
    char backup_filename[100];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    rename(filename, backup_filename);
}

void restore_file(char* filename) {
    char backup_filename[100];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    rename(backup_filename, filename);
}

int main() {
    file_t* file_list = NULL;
    int num_files = 0;
    char command[100];
    char filename[100];
    char backup_filename[100];
    int i;

    printf("File Backup System\n");
    printf("Enter 'backup' to backup a file\n");
    printf("Enter'restore' to restore a file\n");
    printf("Enter 'list' to list backed up files\n");
    printf("Enter 'exit' to quit\n");

    while(1) {
        scanf("%s", command);
        if(strcmp(command, "backup") == 0) {
            scanf("%s", filename);
            backup_file(filename);
            printf("File %s backed up\n", filename);
        }
        else if(strcmp(command, "restore") == 0) {
            scanf("%s", filename);
            restore_file(filename);
            printf("File %s restored\n", filename);
        }
        else if(strcmp(command, "list") == 0) {
            printf("List of backed up files:\n");
            for(i = 0; i < num_files; i++) {
                printf("%s %ld\n", file_list[i].filename, file_list[i].timestamp);
            }
        }
        else if(strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}