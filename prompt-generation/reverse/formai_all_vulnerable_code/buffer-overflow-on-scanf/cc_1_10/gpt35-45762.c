//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char filename[30];
    char content[100];
    int choice;

    printf("Welcome to the File Handling example program!\n");

    while(1){
        printf("\nWhat do you want to do?\n");
        printf("1. Create a new file\n");
        printf("2. Write to an existing file\n");
        printf("3. Read from a file\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the filename to be created: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");

                if(fp == NULL){
                    printf("Error in file creation!\n");
                }
                else{
                    printf("File created successfully!\n");
                    fclose(fp);
                }
                break;

            case 2:
                printf("Enter the filename you want to write to: ");
                scanf("%s", filename);

                fp = fopen(filename, "a");

                if(fp == NULL){
                    printf("Error in opening the file!\n");
                }
                else{
                    printf("Enter the contents you want to write: ");
                    scanf("%s", content);
                    fprintf(fp, "%s", content);
                    printf("Contents written to file successfully!\n");
                    fclose(fp);
                }
                break;

            case 3:
                printf("Enter the filename you want to read from: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");

                if(fp == NULL){
                    printf("Error in opening the file!\n");
                }
                else{
                    printf("Contents of the file are:\n");

                    char c = fgetc(fp);
                    while(c != EOF){
                        putchar(c);
                        c = fgetc(fp);
                    }

                    fclose(fp);
                }
                break;

            case 4:
                printf("Thank you for using the File Handling example program!\n");
                exit(0);

            default:
                printf("Invalid choice entered! Please try again.\n");
                break;
        }
    }

    return 0;
}