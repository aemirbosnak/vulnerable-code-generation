//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 100000

// Function prototypes
void read_file(char *filename);
void display_menu(void);
void display_book(char *filename);
void search_book(char *filename, char *keyword);

int main(void) {
    char filename[50];
    printf("Enter the name of the ebook: ");
    scanf("%s", filename);
    read_file(filename);
    return 0;
}

void read_file(char *filename) {
    FILE *fp;
    char ch;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (count >= MAX_FILE_SIZE) {
            printf("File is too large.\n");
            fclose(fp);
            exit(0);
        }
        printf("%c", ch);
        count++;
    }

    fclose(fp);
}

void display_menu(void) {
    printf("\n");
    printf("1. Display ebook\n");
    printf("2. Search ebook\n");
    printf("3. Exit\n");
    printf("\n");
}

void display_book(char *filename) {
    FILE *fp;
    char ch;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    while ((ch = fgetc(fp))!= EOF) {
        printf("%c", ch);
    }

    fclose(fp);
}

void search_book(char *filename, char *keyword) {
    FILE *fp;
    char ch;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == *keyword) {
            printf("%c", ch);
        }
    }

    fclose(fp);
}