//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[50], path[100], temp[100];
    int choice;
    FILE *fp;

    printf("Welcome to the System Administration Program!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Rename a file\n");
        printf("4. Copy a file\n");
        printf("5. Move a file\n");
        printf("6. Display the contents of a file\n");
        printf("7. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the path of the file you want to create: ");
                scanf("%s", path);

                fp = fopen(path, "w");

                if(fp == NULL) {
                    printf("Error creating file!");
                } else {
                    printf("File created successfully!");
                    fclose(fp);
                }

                break;
            case 2:
                printf("Enter the path of the file you want to delete: ");
                scanf("%s", path);

                if(remove(path) == 0) {
                    printf("File deleted successfully!");
                } else {
                    printf("Error deleting file!");
                }

                break;
            case 3:
                printf("Enter the path of the file you want to rename: ");
                scanf("%s", path);

                printf("Enter the new path of the file: ");
                scanf("%s", temp);

                if(rename(path, temp) == 0) {
                    printf("File renamed successfully!");
                } else {
                    printf("Error renaming file!");
                }

                break;
            case 4:
                printf("Enter the path of the file you want to copy: ");
                scanf("%s", path);

                printf("Enter the path of the destination file: ");
                scanf("%s", temp);

                fp = fopen(path, "r");

                if(fp == NULL) {
                    printf("Error opening source file!");
                    break;
                }

                FILE *dest = fopen(temp, "w");

                if(dest == NULL) {
                    printf("Error opening destination file!");
                    fclose(fp);
                    break;
                }

                int c;
                while((c = fgetc(fp)) != EOF) {
                    fputc(c, dest);
                }

                fclose(fp);
                fclose(dest);

                printf("File copied successfully!");

                break;
            case 5:
                printf("Enter the path of the file you want to move: ");
                scanf("%s", path);

                printf("Enter the path of the new location: ");
                scanf("%s", temp);

                if(rename(path, temp) == 0) {
                    printf("File moved successfully!");
                } else {
                    printf("Error moving file!");
                }

                break;
            case 6:
                printf("Enter the path of the file you want to display: ");
                scanf("%s", path);

                fp = fopen(path, "r");

                if(fp == NULL) {
                    printf("Error opening file!");
                    break;
                }

                printf("\nFile Contents:\n\n");

                int character;
                while((character = fgetc(fp)) != EOF) {
                    printf("%c", character);
                }

                printf("\n");

                fclose(fp);

                break;
            case 7:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice, please try again.");
        }
    } while(choice != 7);

    return 0;
}