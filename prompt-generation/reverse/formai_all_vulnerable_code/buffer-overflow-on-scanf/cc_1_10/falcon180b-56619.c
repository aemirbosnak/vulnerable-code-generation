//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Ebook;

int main() {
    FILE *fp;
    Ebook ebook;
    char filename[50];
    int choice, i;

    printf("Enter the name of the ebook file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    ebook.title[0] = '\0';
    ebook.author[0] = '\0';
    ebook.content[0] = '\0';

    while (fgets(ebook.content, MAX_CONTENT_LENGTH, fp)!= NULL) {
        if (ebook.content[strcspn(ebook.content, "\n")] == '\n') {
            ebook.content[strcspn(ebook.content, "\n")] = '\0';
        }
        else {
            printf("Content too long!\n");
            exit(1);
        }
    }

    fclose(fp);

    printf("\nTitle: ");
    fgets(ebook.title, MAX_TITLE_LENGTH, stdin);
    ebook.title[strcspn(ebook.title, "\n")] = '\0';

    printf("Author: ");
    fgets(ebook.author, MAX_AUTHOR_LENGTH, stdin);
    ebook.author[strcspn(ebook.author, "\n")] = '\0';

    fp = fopen(filename, "w");
    fprintf(fp, "Title: %s\nAuthor: %s\n\n", ebook.title, ebook.author);
    fprintf(fp, "%s", ebook.content);
    fclose(fp);

    printf("\n1. Read ebook\n2. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("File not found!\n");
                exit(1);
            }
            printf("\nTitle: %s\nAuthor: %s\n", ebook.title, ebook.author);
            printf("\n%s", ebook.content);
            fclose(fp);
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    return 0;
}