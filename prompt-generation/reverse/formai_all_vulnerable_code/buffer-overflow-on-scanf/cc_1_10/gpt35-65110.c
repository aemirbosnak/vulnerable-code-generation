//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char filename[20], ch;
    int choice, count=0;

    printf("Welcome to File Handling Program\n");
    printf("1. Create a new file\n");
    printf("2. Count number of characters in the file\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the filename to create: ");
            scanf("%s", filename);

            fp = fopen(filename, "w");

            if(fp == NULL){
                printf("Error creating file.\n");
                exit(1);
            }

            printf("File created successfully.\n");
            fclose(fp);
            break;

        case 2:
            printf("Enter the filename to open: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if(fp == NULL){
                printf("Error opening file.\n");
                exit(1);
            }

            while((ch = fgetc(fp)) != EOF){
                count++;
            }

            printf("Number of characters in the file: %d\n", count);
            fclose(fp);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}