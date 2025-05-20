//Falcon-180B DATASET v1.0 Category: File handling ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void countWords(FILE *file) {
    char word[100];
    int count = 0;
    while(fscanf(file, "%s", word)!= EOF) {
        count++;
    }
    printf("The file contains %d words.\n", count);
}

void countLines(FILE *file) {
    char ch;
    int count = 0;
    while((ch = fgetc(file))!= EOF) {
        if(ch == '\n') {
            count++;
        }
    }
    printf("The file contains %d lines.\n", count + 1);
}

void countChars(FILE *file) {
    char ch;
    int count = 0;
    while((ch = fgetc(file))!= EOF) {
        count++;
    }
    printf("The file contains %d characters.\n", count);
}

int main() {
    FILE *file;
    char fileName[100];
    int choice;

    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if(file == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    printf("Enter your choice:\n1. Count words\n2. Count lines\n3. Count characters\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            countWords(file);
            break;
        case 2:
            countLines(file);
            break;
        case 3:
            countChars(file);
            break;
        default:
            printf("Invalid choice.\n");
    }

    fclose(file);

    return 0;
}