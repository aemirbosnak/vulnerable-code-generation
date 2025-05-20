//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 100

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    int allocated;
} File;

File files[MAX_FILES];

int num_files = 0;

int main() {
    char command[100];
    int i, j, choice, file_index;

    system("clear");

    printf("Welcome to the File System Simulator!\n\n");

    while(1) {
        printf("\nEnter command: ");
        scanf("%s", command);

        if(strcmp(command, "exit") == 0) {
            break;
        } else if(strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", files[num_files].name);
            printf("Enter file size: ");
            scanf("%d", &files[num_files].size);
            files[num_files].allocated = 0;
            num_files++;
            printf("\nFile created successfully!\n");
        } else if(strcmp(command, "delete") == 0) {
            printf("Enter file name: ");
            scanf("%s", command);
            for(i=0; i<num_files; i++) {
                if(strcmp(files[i].name, command) == 0) {
                    printf("\nFile deleted successfully!\n");
                    memset(&files[i], 0, sizeof(File));
                    num_files--;
                    break;
                }
            }
        } else if(strcmp(command, "allocate") == 0) {
            printf("Enter file name: ");
            scanf("%s", command);
            for(i=0; i<num_files; i++) {
                if(strcmp(files[i].name, command) == 0) {
                    printf("Enter block size: ");
                    scanf("%d", &j);
                    if(files[i].size >= files[i].allocated + j) {
                        files[i].allocated += j;
                        printf("\nBlock allocated successfully!\n");
                    } else {
                        printf("\nInsufficient space!\n");
                    }
                    break;
                }
            }
        } else if(strcmp(command, "deallocate") == 0) {
            printf("Enter file name: ");
            scanf("%s", command);
            for(i=0; i<num_files; i++) {
                if(strcmp(files[i].name, command) == 0) {
                    printf("Enter block size: ");
                    scanf("%d", &j);
                    if(files[i].allocated >= j) {
                        files[i].allocated -= j;
                        printf("\nBlock deallocated successfully!\n");
                    } else {
                        printf("\nInvalid block size!\n");
                    }
                    break;
                }
            }
        } else {
            printf("\nInvalid command!\n");
        }
    }

    return 0;
}