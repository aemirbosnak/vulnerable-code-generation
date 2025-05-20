//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct ebook {
    char title[100];
    char author[100];
    char year[10];
    char isbn[13];
    char pages[10];
    char language[10];
    char subject[50];
    char publisher[50];
    char description[1000];
};

int main() {
    struct ebook ebook;
    char buffer[100];
    FILE *file;

    ebook.title[0] = '\0';
    ebook.author[0] = '\0';
    ebook.year[0] = '\0';
    ebook.isbn[0] = '\0';
    ebook.pages[0] = '\0';
    ebook.language[0] = '\0';
    ebook.subject[0] = '\0';
    ebook.publisher[0] = '\0';
    ebook.description[0] = '\0';

    printf("Enter ebook title: ");
    scanf("%s", ebook.title);

    printf("Enter ebook author: ");
    scanf("%s", ebook.author);

    printf("Enter ebook year: ");
    scanf("%s", ebook.year);

    printf("Enter ebook isbn: ");
    scanf("%s", ebook.isbn);

    printf("Enter ebook pages: ");
    scanf("%s", ebook.pages);

    printf("Enter ebook language: ");
    scanf("%s", ebook.language);

    printf("Enter ebook subject: ");
    scanf("%s", ebook.subject);

    printf("Enter ebook publisher: ");
    scanf("%s", ebook.publisher);

    printf("Enter ebook description: ");
    fgets(buffer, 100, stdin);
    ebook.description[strlen(buffer)-1] = '\0';

    file = fopen("ebook.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(file, "Title: %s\n", ebook.title);
    fprintf(file, "Author: %s\n", ebook.author);
    fprintf(file, "Year: %s\n", ebook.year);
    fprintf(file, "ISBN: %s\n", ebook.isbn);
    fprintf(file, "Pages: %s\n", ebook.pages);
    fprintf(file, "Language: %s\n", ebook.language);
    fprintf(file, "Subject: %s\n", ebook.subject);
    fprintf(file, "Publisher: %s\n", ebook.publisher);
    fprintf(file, "Description:\n");
    fputs(ebook.description, file);
    fclose(file);

    printf("Ebook saved successfully!\n");

    return 0;
}