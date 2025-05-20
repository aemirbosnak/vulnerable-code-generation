//FormAI DATASET v1.0 Category: File handling ; Style: retro
#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp;
    char filename[20], ch;
    int choice;

    printf("Please choose an option:\n");
    printf("1. Create a file\n");
    printf("2. Read from a file\n");
    printf("3. Write to a file\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            printf("File created successfully!");
            fclose(fp);
            break;
        case 2:
            printf("Enter the filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if(fp == NULL) {
                printf("File does not exist.");
                exit(1);
            }
            printf("The content of the file is:\n");
            ch = fgetc(fp);
            while(ch != EOF) {
                printf("%c", ch);
                ch = fgetc(fp);
            }
            fclose(fp);
            break;
        case 3:
            printf("Enter the filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            if(fp == NULL) {
                printf("File does not exist.");
                exit(1);
            }
            printf("Enter the text to write to the file: ");
            scanf("%s", filename);
            fprintf(fp, "%s", filename);
            printf("Data written to the file successfully!");
            fclose(fp);
            break;
        default:
            printf("Invalid option.");
            break;
    }

    return 0;
}