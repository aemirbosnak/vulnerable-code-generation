//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

typedef struct {
    char name[20];
    int size;
    int used;
} File;

File files[MAX_FILES];
int num_files = 0;

int main() {
    int choice;

    while(1) {
        printf("\nFile System Simulation\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Display all files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_files >= MAX_FILES) {
                    printf("Maximum number of files reached.\n");
                } else {
                    printf("Enter file name: ");
                    scanf("%s", files[num_files].name);
                    printf("Enter file size: ");
                    scanf("%d", &files[num_files].size);
                    files[num_files].used = 0;
                    num_files++;
                }
                break;

            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", files[num_files-1].name);
                files[num_files-1].used = 0;
                num_files--;
                break;

            case 3:
                printf("List of all files:\n");
                for(int i=0; i<num_files; i++) {
                    if(files[i].used == 0) {
                        printf("%s (%d bytes) - Deleted\n", files[i].name, files[i].size);
                    } else {
                        printf("%s (%d bytes) - In use\n", files[i].name, files[i].size);
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}