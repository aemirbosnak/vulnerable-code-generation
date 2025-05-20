//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to my unique C file handling program!\n\n");

    FILE *fp;
    char filename[100];
    char ch, search[10];
    int choice, count = 0;

    while(1){
        printf("***MENU***\n");
        printf("1. Create a File\n");
        printf("2. Read a File\n");
        printf("3. Append to a File\n");
        printf("4. Search a File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: //create a file
                printf("Enter the name of the file you want to create: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");

                if(fp == NULL){
                    printf("Error creating file!\n");
                    exit(1);
                }

                printf("File created successfully!\n");
                fclose(fp);
                break;

            case 2: //read a file
                printf("Enter the name of the file you want to read: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");

                if(fp == NULL){
                    printf("Error reading file!\n");
                    exit(1);
                }

                printf("File contents:\n");
                ch = fgetc(fp);

                while(ch != EOF){
                    printf("%c", ch);
                    ch = fgetc(fp);
                }

                fclose(fp);
                break;

            case 3: //append to a file
                printf("Enter the name of the file you want to append to: ");
                scanf("%s", filename);

                fp = fopen(filename, "a");

                if(fp == NULL){
                    printf("Error appending to file!\n");
                    exit(1);
                }

                printf("Enter the text to append to the file (press Enter to stop):\n");

                while(1){
                    ch = getchar();

                    if(ch == '\n')
                        break;

                    fputc(ch, fp);
                }

                printf("Text appended successfully!\n");
                fclose(fp);
                break;

            case 4: //search a file
                printf("Enter the name of the file you want to search: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");

                if(fp == NULL){
                    printf("Error searching file!\n");
                    exit(1);
                }

                printf("Enter the text to search in the file: ");
                scanf("%s", search);

                ch = fgetc(fp);

                while(ch != EOF){
                    if(ch == search[0]){
                        fseek(fp, -1, SEEK_CUR);
                        count = 0;

                        while(ch == search[count]){
                            ch = fgetc(fp);
                            count++;
                        }

                        if(count == strlen(search)){
                            printf("'%s' found in the file!\n", search);
                            fclose(fp);
                            exit(0);
                        }

                        fseek(fp, -(count-1), SEEK_CUR);
                    }

                    ch = fgetc(fp);
                }

                printf("'%s' not found in the file!\n", search);
                fclose(fp);
                break;

            case 5: //exit
                printf("Exiting Program...\n");
                exit(0);

            default: //invalid option
                printf("Invalid option! Please select a valid option.\n");
        }
    }

    return 0;
}