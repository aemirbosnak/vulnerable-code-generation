//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Greetings, human. I am a curious system administrator bot.\n");
    printf("I will help you manage your files and directories.\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. List all files in a directory\n");
        printf("2. Create a new directory\n");
        printf("3. Remove a directory\n");
        printf("4. Copy a file\n");
        printf("5. Move a file\n");
        printf("6. Exit program\n");

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Please enter the path of the directory: ");
                char path[100];
                scanf("%s", path);
                char* command1 = malloc(snprintf(NULL, 0, "ls %s", path) + 1);
                sprintf(command1, "ls %s", path);
                system(command1);
                free(command1);
                break;

            case 2:
                printf("Please enter the name of the directory to create: ");
                char new_dir[100];
                scanf("%s", new_dir);
                char* command2 = malloc(snprintf(NULL, 0, "mkdir %s", new_dir) + 1);
                sprintf(command2, "mkdir %s", new_dir);
                system(command2);
                free(command2);
                break;

            case 3:
                printf("Please enter the name of the directory to remove: ");
                char old_dir[100];
                scanf("%s", old_dir);
                char* command3 = malloc(snprintf(NULL, 0, "rmdir %s", old_dir) + 1);
                sprintf(command3, "rmdir %s", old_dir);
                system(command3);
                free(command3);
                break;

            case 4:
                printf("Please enter the name of the file to copy: ");
                char old_file[100];
                scanf("%s", old_file);
                printf("Please enter the name of the new file: ");
                char new_file[100];
                scanf("%s", new_file);
                char* command4 = malloc(snprintf(NULL, 0, "cp %s %s", old_file, new_file) + 1);
                sprintf(command4, "cp %s %s", old_file, new_file);
                system(command4);
                free(command4);
                break;

            case 5:
                printf("Please enter the name of the file to move: ");
                char file_to_move[100];
                scanf("%s", file_to_move);
                printf("Please enter the path of the directory to move the file to: ");
                char new_path[100];
                scanf("%s", new_path);
                char* command5 = malloc(snprintf(NULL, 0, "mv %s %s", file_to_move, new_path) + 1);
                sprintf(command5, "mv %s %s", file_to_move, new_path);
                system(command5);
                free(command5);
                break;

            case 6:
                printf("Thank you for using my program! Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please choose a number between 1 and 6.\n");
        }
    }

    return 0;
}