//FormAI DATASET v1.0 Category: System administration ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void print_options() {
    printf("\n[1] List files in directory\n");
    printf("[2] Create new file\n");
    printf("[3] Delete file\n");
    printf("[4] Rename file\n");
    printf("[5] Exit\n");
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char dir_path[100];
    char filename[100];
    char new_filename[100];
    int option;

    printf("Enter directory path: ");
    scanf("%s", dir_path);

    while(1) {
        print_options();
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                dir = opendir(dir_path);
                printf("\nFiles in directory:\n");

                while((ent = readdir(dir)) != NULL) {
                    printf("%s\n", ent->d_name);
                }

                closedir(dir);
                break;

            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);

                strcat(dir_path, "/");
                strcat(dir_path, filename);

                FILE *new_file;
                new_file = fopen(dir_path, "w");
                fclose(new_file);

                printf("File created successfully!\n");
                break;

            case 3:
                printf("Enter filename to delete: ");
                scanf("%s", filename);

                strcpy(dir_path, "");
                strcat(dir_path, "./");
                strcat(dir_path, filename);

                if(remove(dir_path) == 0) {
                    printf("File deleted successfully!\n");
                } else {
                    printf("File couldn't be deleted.\n");
                }
                break;

            case 4:
                printf("Enter filename to rename: ");
                scanf("%s", filename);
                printf("Enter new filename: ");
                scanf("%s", new_filename);

                strcpy(dir_path, "");
                strcat(dir_path, "./");

                strcat(dir_path, filename);
                rename(dir_path, new_filename);
                printf("File renamed successfully!\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}