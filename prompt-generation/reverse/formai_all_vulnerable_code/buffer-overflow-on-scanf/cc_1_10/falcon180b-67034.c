//Falcon-180B DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50];
    int choice, ch;
    printf("Welcome to the File Handling program!\n");
    printf("Enter the name of the file you want to work with: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(0);
    }

    printf("Enter your choice:\n");
    printf("1. Read file\n");
    printf("2. Write to file\n");
    printf("3. Append to file\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Reading file...\n");
            ch = fgetc(fp);
            while (ch!= EOF) {
                printf("%c", ch);
                ch = fgetc(fp);
            }
            printf("\n");
            break;
        case 2:
            printf("Enter the text you want to write to the file: ");
            scanf("%s", filename);
            fprintf(fp, "%s", filename);
            printf("Text written to file.\n");
            break;
        case 3:
            printf("Enter the text you want to append to the file: ");
            scanf("%s", filename);
            fprintf(fp, "%s", filename);
            printf("Text appended to file.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    fclose(fp);
    return 0;
}