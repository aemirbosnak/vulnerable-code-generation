//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: introspective
// Embarking on a Literary Odyssey: A C Ebook Reader

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A virtual bookshelf to hold our cherished pages
typedef struct Book {
    char *title;
    int pages;
    char **contents;
} Book;

// An inquisitive reader, eager to delve into the world of words
typedef struct Reader {
    char *name;
    Book *current_book;
    int current_page;
} Reader;

// A path to unlock the reader's chosen tome
char *choose_book() {
    printf("Enter the filename of your desired book: ");
    char *filename = malloc(100);
    scanf("%s", filename);
    return filename;
}

// Parsing the chosen tome, unlocking its secrets
Book *load_book(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Alas, the chosen tome could not be found. Try again!");
        exit(1);
    }

    // Extracting the book's essence
    Book *book = malloc(sizeof(Book));
    char title[100];
    int pages;
    fscanf(file, "%s %d\n", title, &pages);
    book->title = strdup(title);
    book->pages = pages;

    // Unveiling the book's chapters
    char *contents[pages];
    for (int i = 0; i < pages; i++) {
        contents[i] = malloc(1000);
        fgets(contents[i], 1000, file);
    }
    fclose(file);

    // A storybook ready to unfold
    book->contents = contents;
    return book;
}

// Giving life to the reader, a seeker of knowledge
Reader *create_reader(char *name) {
    Reader *reader = malloc(sizeof(Reader));
    reader->name = strdup(name);
    return reader;
}

// Opening the first page of a captivating journey
void start_reading(Reader *reader, Book *book) {
    reader->current_book = book;
    reader->current_page = 1;
    printf("Welcome, %s! Let us begin your literary adventure.\n", reader->name);
    printf("Now exploring: %s\n", reader->current_book->title);
}

// Turning the pages, immersing in the written realm
int read_page(Reader *reader) {
    if (reader->current_page > reader->current_book->pages) {
        printf("Alas, you have reached the end of the book.\n");
        return 0;
    }

    printf("Page %d:\n%s", reader->current_page, reader->current_book->contents[reader->current_page - 1]);
    reader->current_page++;
    return 1;
}

// An interactive guide through the literary labyrinth
int main() {
    // Introducing the curious reader
    char name[100];
    printf("Greetings, fellow bookworm! What is your name?\n");
    scanf("%s", name);

    // A blank canvas for the reader's journey
    Reader *reader = create_reader(name);

    // Unveiling the chosen tome
    char *filename = choose_book();
    Book *book = load_book(filename);

    // Embarking on the literary quest
    start_reading(reader, book);

    // Navigating the pages, lost in the world of words
    int continue_reading = 1;
    while (continue_reading) {
        printf("Type 'n' to turn the page, or 'q' to close the book: ");
        char input;
        scanf(" %c", &input);
        switch (input) {
            case 'n':
                continue_reading = read_page(reader);
                break;
            case 'q':
                printf("Farewell, %s! May your future literary journeys be as enchanting.\n", reader->name);
                continue_reading = 0;
                break;
            default:
                printf("Invalid input. Please enter 'n' or 'q'.\n");
                break;
        }
    }

    // Releasing the book from its digital confines
    for (int i = 0; i < book->pages; i++) {
        free(book->contents[i]);
    }
    free(book->contents);
    free(book);

    // Bidding farewell to the engrossed reader
    free(reader);

    return 0;
}