//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *text;
    int length;
} ebook_page_t;

typedef struct {
    ebook_page_t **pages;
    int num_pages;
    int current_page;
} ebook_t;

void load_ebook(ebook_t *ebook, const char *filename) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int page_num = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading ebook: %s\n", filename);
        exit(1);
    }

    ebook->pages = malloc(sizeof(ebook_page_t *) * 100);
    ebook->num_pages = 0;
    ebook->current_page = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        ebook_page_t *page = malloc(sizeof(ebook_page_t));
        page->text = malloc(strlen(line) + 1);
        strcpy(page->text, line);
        page->length = strlen(line);
        ebook->pages[page_num++] = page;
        ebook->num_pages++;
    }

    fclose(file);
}

void display_page(ebook_t *ebook) {
    int i = 0;
    int j = 0;

    printf("\n");
    for (i = 0; i < ebook->current_page; i++) {
        printf("\n");
    }

    for (i = ebook->current_page; i < ebook->current_page + 20 && i < ebook->num_pages; i++) {
        while (j < ebook->pages[i]->length) {
            printf("%c", ebook->pages[i]->text[j]);
            j++;
        }
        j = 0;
    }
}

void turn_page(ebook_t *ebook) {
    if (ebook->current_page < ebook->num_pages - 1) {
        ebook->current_page++;
    } else {
        ebook->current_page = 0;
    }
}

int main(int argc, char **argv) {
    ebook_t ebook;
    char *filename;

    if (argc < 2) {
        printf("Error: No ebook specified\n");
        exit(1);
    }

    filename = argv[1];
    load_ebook(&ebook, filename);

    while (1) {
        display_page(&ebook);
        getchar();
        turn_page(&ebook);
    }

    return 0;
}