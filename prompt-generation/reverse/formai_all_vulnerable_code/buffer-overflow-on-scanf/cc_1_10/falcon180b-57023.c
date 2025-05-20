//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char *filename;
    char *content;
    int size;
} Ebook;

int main() {
    Ebook ebook;
    char filename[256];
    char *buffer = NULL;
    int filesize = 0;
    int ch;

    printf("Enter the name of the ebook file: ");
    scanf("%s", filename);

    ebook.filename = strdup(filename);
    ebook.content = NULL;
    ebook.size = 0;

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    filesize = ftell(fp);
    if (filesize > MAX_FILE_SIZE) {
        printf("Error: file is too large (max 10 MB)\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_SET);
    buffer = malloc(filesize + 1);
    if (buffer == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    filesize = fread(buffer, 1, filesize, fp);
    if (fclose(fp)!= 0) {
        printf("Error: could not close file '%s'\n", filename);
        exit(1);
    }

    ebook.content = strdup(buffer);
    ebook.size = strlen(ebook.content);

    printf("Ebook loaded successfully!\n");
    printf("Title: %s\n", ebook.filename);
    printf("Size: %d bytes\n", ebook.size);

    free(buffer);
    return 0;
}