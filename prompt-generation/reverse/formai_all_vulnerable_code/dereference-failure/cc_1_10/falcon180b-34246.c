//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_BOOK_LEN 10000

typedef struct {
    char title[MAX_LINE_LEN];
    char author[MAX_LINE_LEN];
    char content[MAX_BOOK_LEN];
} Ebook;

void read_ebook(FILE *fp, Ebook *ebook) {
    char line[MAX_LINE_LEN];
    char *token;
    int line_num = 1;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (line_num == 1) {
            // Read title and author
            token = strtok(line, "\n");
            strcpy(ebook->title, token);
            token = strtok(NULL, "\n");
            strcpy(ebook->author, token);
        } else if (line_num > 1) {
            // Read content
            strcat(ebook->content, line);
            strcat(ebook->content, "\n");
        }
        line_num++;
    }
}

void print_ebook(Ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Content:\n%s", ebook->content);
}

int main() {
    FILE *fp;
    Ebook ebook;

    fp = fopen("example.ebook", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_ebook(fp, &ebook);
    fclose(fp);

    print_ebook(&ebook);

    return 0;
}