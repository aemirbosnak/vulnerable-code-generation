//FormAI DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to Shape Shifting File Handling program!\n");
    printf("Enter a command: \n");
    
    char command[20];
    scanf("%s", command);

    while(strcmp(command, "exit") != 0) {

        if(strcmp(command, "create") == 0) {
            FILE *fp;
            char filename[20];
            printf("Enter filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "w");

            if(fp == NULL) {
                printf("Error creating file.\n");
            } else {
                printf("File created successfully.\n");
            }
            fclose(fp);

        } else if(strcmp(command, "read") == 0) {
            FILE *fp;
            char filename[20];
            printf("Enter filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if(fp == NULL) {
                printf("Error opening file.\n");
            } else {
                printf("File contents:\n");
                char c;
                while((c = getc(fp)) != EOF) {
                    putchar(c);
                }
                fclose(fp);
            }

        } else if(strcmp(command, "edit") == 0) {
            FILE *fp;
            char filename[20];
            printf("Enter filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "r+");

            if(fp == NULL) {
                printf("Error opening file.\n");
            } else {
                printf("Enter new file contents (type \"finish\" to stop):\n");
                char new_c[10];
                while(scanf("%s", new_c) != EOF && strcmp(new_c, "finish") != 0) {
                    fputs(new_c, fp);
                }

                printf("File edited successfully.\n");
                fclose(fp);
            }

        } else if(strcmp(command, "rename") == 0) {
            char old_filename[20];
            char new_filename[20];
            printf("Enter old filename: ");
            scanf("%s", old_filename);
            printf("Enter new filename: ");
            scanf("%s", new_filename);

            if(rename(old_filename, new_filename) == 0) {
                printf("File renamed successfully.\n");
            } else {
                printf("Error renaming file.\n");
            }

        } else if(strcmp(command, "delete") == 0) {
            char filename[20];
            printf("Enter filename: ");
            scanf("%s", filename);

            if(remove(filename) == 0) {
                printf("File deleted successfully.\n");
            } else {
                printf("Error deleting file.\n");
            }

        } else {
            printf("Command not recognized.\n");
        }

        printf("Enter a command: \n");
        scanf("%s", command);
    }

    printf("Program exited.\n");
    return 0;
}