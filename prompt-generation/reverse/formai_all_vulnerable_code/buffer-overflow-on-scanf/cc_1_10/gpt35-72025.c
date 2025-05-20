//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(char* filename){
    FILE *fp;
    char ch;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("\nError: Cannot open file %s\n", filename);
        return;
    }

    printf("\nPrinting content of file %s:\n", filename);
    while((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }

    fclose(fp);
}

void write_file(char* filename){
    FILE *fp;
    char content[50];

    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("\nError: Cannot create file %s\n", filename);
        return;
    }

    printf("\nEnter content(max 50 chars) to be written to file %s:\n", filename);
    scanf("%s", content);

    fprintf(fp, "%s", content);

    fclose(fp);

    printf("\nContent written successfully to file %s\n", filename);
}

int main(){
    char filename[20], option;
    int choice=0;

    printf("Enter the file name to be created/modified: ");
    scanf("%s",filename);

    while(choice!=3){
        printf("\nChoose an option:\n");
        printf("1. Read from file\n");
        printf("2. Write to file\n");
        printf("3. Exit\n");
        scanf(" %c", &option);

        switch(option){
            case '1':
                read_file(filename);
                break;
            case '2':
                write_file(filename);
                break;
            case '3':
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid option, please try again\n");
        }
    }

    return 0;
}