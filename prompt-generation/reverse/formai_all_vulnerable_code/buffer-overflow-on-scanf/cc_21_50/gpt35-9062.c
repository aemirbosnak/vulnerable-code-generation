//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1000

int main() {
    int choice, num_files = 0;
    char filenames[MAX_FILES][20];
    char file_content[MAX_FILES][MAX_FILE_SIZE];

    do {
        printf("1. Create a new file\n");
        printf("2. Write to an existing file\n");
        printf("3. Read from a file\n");
        printf("4. Delete a file\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_files == MAX_FILES) {
                    printf("Maximum number of files reached!\n");
                    break;
                }

                printf("Enter the name of the file: ");
                scanf("%s", filenames[num_files]);

                if(strlen(filenames[num_files]) >= 20) {
                    printf("Filename too long!\n");
                    break;
                }

                printf("Enter the contents of the file: ");
                scanf(" %[^\n]", file_content[num_files]);

                printf("File successfully created!\n");
                num_files++;
                break;

            case 2:
                if(num_files == 0) {
                    printf("No files to write to!\n");
                    break;
                }

                printf("Enter the name of the file: ");
                char filename[20];
                scanf("%s", filename);

                int found = 0;
                for(int i = 0; i < num_files; i++) {
                    if(strcmp(filenames[i], filename) == 0) {
                        printf("Enter the text to write to the file: ");
                        scanf(" %[^\n]", file_content[i]);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("File not found!\n");
                }
                else {
                    printf("File successfully updated!\n");
                }
                break;

            case 3:
                if(num_files == 0) {
                    printf("No files to read from!\n");
                    break;
                }

                printf("Enter the name of the file: ");
                char fname[20];
                scanf("%s", fname);

                int is_found = 0;
                for(int i = 0; i < num_files; i++) {
                    if(strcmp(filenames[i], fname) == 0) {
                        printf("%s\n", file_content[i]);
                        is_found = 1;
                        break;
                    }
                }

                if(!is_found) {
                    printf("File not found!\n");
                }
                break;

            case 4:
                if(num_files == 0) {
                    printf("No files to delete!\n");
                    break;
                }

                printf("Enter the name of the file: ");
                char name[20];
                scanf("%s", name);

                int is_deleted = 0;
                for(int i = 0; i < num_files; i++) {
                    if(strcmp(filenames[i], name) == 0) {
                        for(int j = i; j < num_files - 1; j++) {
                            strcpy(filenames[j], filenames[j + 1]);
                            strcpy(file_content[j], file_content[j + 1]);
                        }
                        num_files--;
                        printf("File successfully deleted!\n");
                        is_deleted = 1;
                        break;
                    }
                }

                if(!is_deleted) {
                    printf("File not found!\n");
                }
                break;

            case 5:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    } while(1);

    return 0;
}