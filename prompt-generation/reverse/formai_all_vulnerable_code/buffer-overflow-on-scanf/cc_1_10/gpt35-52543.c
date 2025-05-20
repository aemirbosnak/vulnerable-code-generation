//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[100];
    int size;
};

void display_menu() {
    printf("\n==================================");
    printf("\n         Disk Space Analyzer      ");
    printf("\n==================================");
    printf("\n1. Add file");
    printf("\n2. Delete file");
    printf("\n3. Show files");
    printf("\n4. Show disk usage");
    printf("\n5. Exit");
    printf("\n==================================\n");
}

int main() {
    int choice, total_size = 0, num_files = 0;
    struct file files[100];

    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", files[num_files].name);
                printf("Enter file size (in bytes): ");
                scanf("%d", &files[num_files].size);
                total_size += files[num_files].size;
                num_files++;
                break;
            
            case 2:
                if(num_files == 0) {
                    printf("\nNo files to delete!\n");
                    break;
                }
                printf("Enter file name to delete: ");
                char del_name[100];
                scanf("%s", del_name);
                for(int i = 0; i < num_files; i++) {
                    if(strcmp(del_name, files[i].name) == 0) {
                        total_size -= files[i].size;
                        for(int j = i; j < num_files - 1; j++) {
                            strcpy(files[j].name, files[j + 1].name);
                            files[j].size = files[j + 1].size;
                        }
                        num_files--;
                        printf("\nFile deleted successfully!\n");
                        break;
                    }
                    if(i == num_files - 1) {
                        printf("\nFile not found!\n");
                    }
                }
                break;

            case 3:
                if(num_files == 0) {
                    printf("\nNo files to display!\n");
                    break;
                }
                printf("\nFile Name\tSize (bytes)\n");
                for(int i = 0; i < num_files; i++) {
                    printf("%s\t\t%d\n", files[i].name, files[i].size);
                }
                break;

            case 4:
                printf("\nTotal disk usage: %d bytes\n", total_size);
                break;

            case 5:
                printf("\nThank you for using Disk Space Analyzer!\n");
                exit(0);
            
            default:
                printf("\nInvalid choice! Please choose again\n");
                break;
        }
    }

    return 0;
}