//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EBOOK_FILE "example.epub"
#define CHAPTER_HEADER "Chapter %d: %s"
#define PARAGRAPH_SEP "\n\n"

typedef struct {
    char *name;
    int chapter;
    int page;
} chapter_info_t;

// Function to read an ebook file and print it line by line
void read_ebook(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Parse the ebook file to extract chapter and page information
    char line[1024];
    chapter_info_t chapter;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d: %s", &chapter.chapter, chapter.name) == 2) {
            // Print chapter header
            printf(CHAPTER_HEADER, chapter.chapter, chapter.name);
            chapter.page = 1;
        } else if (sscanf(line, "%d", &chapter.page) == 1) {
            // Print paragraph
            printf("%s\n", line);
        }
    }

    fclose(file);
}

// Function to display a menu to select a chapter and page
void display_menu() {
    int selection;
    do {
        printf("Select a chapter (1-10): ");
        scanf("%d", &selection);
        if (selection < 1 || selection > 10) {
            printf("Invalid selection. Try again.\n");
        }
        read_ebook(EBOOK_FILE);
    } while (selection != 0);
}

int main() {
    display_menu();
    return 0;
}