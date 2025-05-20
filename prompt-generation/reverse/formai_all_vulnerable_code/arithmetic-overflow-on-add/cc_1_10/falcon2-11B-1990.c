//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    char *content;
} Ebook;

void display_ebook(Ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Content:\n");
    printf("%s\n", ebook->content);
}

void read_ebook(Ebook *ebook) {
    char filename[100];
    printf("Enter the filename of the ebook: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        char *newline = (char*)malloc(sizeof(char) * (read + 1));
        strncpy(newline, line, read);
        newline[read] = '\0';

        if (strncmp(newline, "Title:", 6) == 0) {
            ebook->title = strdup(newline + 6);
        } else if (strncmp(newline, "Author:", 6) == 0) {
            ebook->author = strdup(newline + 6);
        } else if (strncmp(newline, "Content:", 6) == 0) {
            ebook->content = strdup(newline + 6);
        }

        free(line);
        line = NULL;
    }

    fclose(file);
}

int main() {
    Ebook ebook;

    read_ebook(&ebook);
    display_ebook(&ebook);

    return 0;
}