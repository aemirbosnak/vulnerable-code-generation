//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char filename[20], ch;

    printf("Welcome to the File Handling Example Program! \n");
    printf("Enter the name of file to be created: ");
    scanf("%s", filename);

    fp = fopen(filename, "w"); //opening the file with write permission

    if(fp == NULL) { //checking if fopen was successful
        printf("Failed to create the file! Exiting...\n");
        exit(1);
    }

    printf("\nEnter your text: ");

    while((ch = getchar()) != EOF) {
        putc(ch, fp);
    }

    printf("\nFile created successfully!\n");

    fclose(fp); //closing the file

    printf("\nNow opening the file for reading...\n");

    fp = fopen(filename, "r"); //opening the file with read permission

    if(fp == NULL) { //checking if fopen was successful
        printf("Failed to open the file! Exiting...\n");
        exit(1);
    }

    printf("\nContents of the file are: ");

    while((ch = getc(fp)) != EOF) {
        putchar(ch);
    }

    printf("\nDone reading the file!\n");

    fclose(fp); //closing the file

    printf("\nGoodbye from the File Handling Example Program!\n");

    return 0;
}