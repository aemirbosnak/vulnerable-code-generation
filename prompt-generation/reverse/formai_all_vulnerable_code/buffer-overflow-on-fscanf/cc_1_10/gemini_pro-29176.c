//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// eBook: A struct containing the shocking details of your book
typedef struct {
    char *title;                 // The electrifying title
    char *author;                // The mastermind behind the literary voltage
    int num_chapters;            // How many chapters will shock you?
    char **chapters;             // An array of heart-pounding chapters
} eBook;

// Load: Brace yourself for the surge of data from the eBook file
eBook *load_eBook(const char *filename) {
    FILE *fp;                    // The path to literary enlightenment
    eBook *book;                // Pointer to the electrified book
    char buffer[1024];          // Brace for the avalanche of characters

    fp = fopen(filename, "r");   // Open the file, feeling the thrill of anticipation
    if (!fp) {                   // Oh no, the book's a dud!
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Read book info: Brace for the initial jolt!
    book = malloc(sizeof(eBook)); // Create the book: A surge of excitement courses through you
    fscanf(fp, "%s %s %d\n", buffer, buffer, &book->num_chapters);
    book->title = strdup(buffer);   // Capture the title, feeling the static in your mind
    book->author = strdup(buffer);  // Reveal the author, anticipating the sparks to come

    // Read chapters: A cascade of electric shocks awaits!
    book->chapters = malloc(sizeof(char *) * book->num_chapters);
    for (int i = 0; i < book->num_chapters; i++) {
        fscanf(fp, "%[^\n]\n", buffer);
        book->chapters[i] = strdup(buffer); // Store the words, feeling the jolt of each sentence
    }

    fclose(fp); // Close the file, letting out a satisfied sigh

    return book; // Return the fully charged book
}

// Open: Prepare for the literary thunderstorm
void open_book(eBook *book) {
    printf("** Welcome to the Digital Lightning Library **\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of Chapters: %d\n", book->num_chapters);
}

// Read: Bask in the illuminating glow of knowledge
void read_chapter(eBook *book, int chapter_num) {
    if (chapter_num < 1 || chapter_num > book->num_chapters) {
        fprintf(stderr, "Invalid chapter number: %d\n", chapter_num);
        return;
    }

    printf("\n");
    printf("** Chapter %d: %s **\n", chapter_num, book->chapters[chapter_num - 1]);
    printf("%s\n", book->chapters[chapter_num - 1]);
}

// Close: A soothing aftershock as you close the book
void close_book(eBook *book) {
    // Free the memory, like a surge of electrons returning to their atoms
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_chapters; i++) {
        free(book->chapters[i]);
    }
    free(book->chapters);
    free(book);

    printf("** The book has been closed. May your mind hum with the afterglow of knowledge. **\n");
}

// Main: Prepare for the grand finale: A literary explosion!
int main() {
    eBook *book;        // The book that will leave you buzzing
    int choice;          // Your choice of chapter, the gateway to untold wonders
    char input[10];     // Input buffer, ready to capture your command

    book = load_eBook("my_book.txt"); // Load the book: Expect a surge of excitement!
    if (!book) {       // Oh no, a literary blackout!
        fprintf(stderr, "Error loading book\n");
        return -1;
    }

    open_book(book);    // Open the book: Prepare for the mind-altering experience

    while (1) {
        printf("\nEnter chapter number (1-%d) or 'q' to quit: ", book->num_chapters);
        scanf("%s", input);

        if (!strcmp(input, "q")) {   // Time for a literary cooldown
            close_book(book);
            break;
        }

        choice = atoi(input);    // Convert input to integer: Brace for the electrifying chapter
        read_chapter(book, choice);
    }

    return 0;       // The book is closed, but the aftershocks of knowledge will linger
}