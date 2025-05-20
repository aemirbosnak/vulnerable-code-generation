//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent an ebook
struct ebook {
    char title[100];
    char author[100];
    char year[10];
    char publisher[100];
    char description[1000];
};

// Function to read an ebook from a file
struct ebook* read_ebook(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    struct ebook* ebook = malloc(sizeof(struct ebook));
    fscanf(file, "%s %s %s %s %s", ebook->title, ebook->author, ebook->year, ebook->publisher, ebook->description);
    fclose(file);

    return ebook;
}

// Function to display an ebook
void display_ebook(struct ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Year: %s\n", ebook->year);
    printf("Publisher: %s\n", ebook->publisher);
    printf("Description:\n%s\n", ebook->description);
}

// Function to search for ebooks by title
int search_ebook_by_title(struct ebook* ebooks, const char* title) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        exit(1);
    }

    struct ebook* ebook = read_ebook(argv[1]);
    if (ebook == NULL) {
        fprintf(stderr, "Error reading ebook '%s'\n", argv[1]);
        exit(1);
    }

    display_ebook(ebook);
    printf("Search ebooks by title: ");
    char title[100];
    scanf("%s", title);
    int index = search_ebook_by_title(ebook, title);
    if (index!= -1) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not found\n");
    }

    free(ebook);
    return 0;
}