//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char file_name[100];
    FILE *fp;
    char ch;

    printf("Enter the name of the file to read: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    printf("\n\nWhat would you like to do with the file?\n");
    printf("1. Read the file\n");
    printf("2. Shift the letters in the file\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    if (choice == 1) {
        while ((ch = fgetc(fp))!= EOF) {
            printf("%c", ch);
        }
        fclose(fp);
        exit(0);
    } else if (choice == 2) {
        int i, j;
        char temp;

        rewind(fp);
        while ((ch = fgetc(fp))!= EOF) {
            if (ch >= 'a' && ch <= 'z') {
                ch = ch + 13;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - 13;
            }
            printf("%c", ch);
        }
        fclose(fp);
        exit(0);
    } else if (choice == 3) {
        exit(0);
    } else {
        printf("Invalid choice\n");
        exit(0);
    }

    return 0;
}