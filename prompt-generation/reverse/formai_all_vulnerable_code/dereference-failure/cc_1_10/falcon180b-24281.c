//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EBOOK_MAX_SIZE 100000

struct ebook {
    char title[100];
    char author[100];
    char content[EBOOK_MAX_SIZE];
};

void read_ebook(struct ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Content:\n%s\n", ebook->content);
}

void write_ebook(struct ebook *ebook) {
    FILE *file;
    file = fopen("ebook.txt", "w");
    fprintf(file, "Title: %s\n", ebook->title);
    fprintf(file, "Author: %s\n", ebook->author);
    fprintf(file, "Content:\n%s\n", ebook->content);
    fclose(file);
}

int main() {
    struct ebook ebook;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    if (size > EBOOK_MAX_SIZE) {
        printf("File too large.\n");
        return 1;
    }
    fseek(file, 0, SEEK_SET);
    fread(ebook.title, 1, 100, file);
    fread(ebook.author, 1, 100, file);
    fread(ebook.content, 1, size, file);
    fclose(file);
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Content:\n%s\n", ebook.content);
    write_ebook(&ebook);
    return 0;
}