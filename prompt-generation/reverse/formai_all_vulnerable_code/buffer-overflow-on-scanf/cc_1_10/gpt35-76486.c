//FormAI DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE 100
#define MAX_AUTHOR 50
#define MAX_DESCRIPTION 200

struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char description[MAX_DESCRIPTION];
    char* content;
};

int read_file(char *filename, char **content) {
    FILE *fp;
    int file_len;

    fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    file_len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    *content = (char*) malloc(file_len);
    if (!*content) {
        fprintf(stderr, "Could not allocate memory for file content\n");
        fclose(fp);
        return -1;
    }

    fread(*content, 1, file_len, fp);
    fclose(fp);

    return file_len;
}

int main() {
    struct Book library[MAX_BOOKS];
    int num_books = 0;
    char filename[MAX_TITLE];
    char *content;
    int content_size;
    int option;

    do {
        printf("Welcome to the Ebook reader!\n");
        printf("1. Add book\n");
        printf("2. Read book\n");
        printf("3. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (num_books < MAX_BOOKS) {
                    printf("Enter title: ");
                    scanf("%s", library[num_books].title);

                    printf("Enter author: ");
                    scanf("%s", library[num_books].author);

                    printf("Enter description: ");
                    scanf("%s", library[num_books].description);

                    printf("Enter filename: ");
                    scanf("%s", filename);

                    content_size = read_file(filename, &content);
                    if (content_size > 0) {
                        library[num_books].content = content;
                        num_books++;
                    } else {
                        fprintf(stderr, "Failed to add book %s\n", library[num_books].title);
                    }
                } else {
                    printf("Library is full\n");
                }

                break;
            case 2:
                if (num_books > 0) {
                    printf("Enter book number: ");
                    scanf("%d", &option);

                    if (option >= 0 && option < num_books) {
                        printf("Title: %s\n", library[option].title);
                        printf("Author: %s\n", library[option].author);
                        printf("Description: %s\n", library[option].description);
                        printf("Content: %s\n", library[option].content);
                    } else {
                        printf("Invalid book number\n");
                    }
                } else {
                    printf("Library is empty\n");
                }

                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 3);

    for (int i = 0; i < num_books; i++) {
        free(library[i].content);
    }

    return 0;
}