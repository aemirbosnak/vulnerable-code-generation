//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: shape shifting
// A unique C ebook reader program in a shape-shifting style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ebook struct
typedef struct {
    char title[50];
    char author[50];
    char genre[50];
    char publisher[50];
    int pageCount;
    int readCount;
} Ebook;

// Define the reader struct
typedef struct {
    char name[50];
    int age;
    char favoriteBook[50];
    int readCount;
} Reader;

// Define the library struct
typedef struct {
    Ebook ebook[100];
    int numEbooks;
    Reader reader[100];
    int numReaders;
} Library;

// Function to add a new ebook to the library
void addEbook(Library *library, Ebook ebook) {
    library->ebook[library->numEbooks] = ebook;
    library->numEbooks++;
}

// Function to add a new reader to the library
void addReader(Library *library, Reader reader) {
    library->reader[library->numReaders] = reader;
    library->numReaders++;
}

// Function to read an ebook
void readEbook(Library *library, int ebookIndex, int readerIndex) {
    library->ebook[ebookIndex].readCount++;
    library->reader[readerIndex].readCount++;
}

// Function to search for an ebook by title
Ebook* searchEbookByTitle(Library *library, char *title) {
    for (int i = 0; i < library->numEbooks; i++) {
        if (strcmp(library->ebook[i].title, title) == 0) {
            return &library->ebook[i];
        }
    }
    return NULL;
}

// Function to search for a reader by name
Reader* searchReaderByName(Library *library, char *name) {
    for (int i = 0; i < library->numReaders; i++) {
        if (strcmp(library->reader[i].name, name) == 0) {
            return &library->reader[i];
        }
    }
    return NULL;
}

// Function to print the ebook library
void printEbookLibrary(Library *library) {
    printf("Ebook Library:\n");
    for (int i = 0; i < library->numEbooks; i++) {
        printf("%d. %s by %s (%s) - %d pages, read %d times\n", i + 1, library->ebook[i].title, library->ebook[i].author, library->ebook[i].genre, library->ebook[i].pageCount, library->ebook[i].readCount);
    }
}

// Function to print the reader library
void printReaderLibrary(Library *library) {
    printf("Reader Library:\n");
    for (int i = 0; i < library->numReaders; i++) {
        printf("%d. %s (%d) - read %d books\n", i + 1, library->reader[i].name, library->reader[i].age, library->reader[i].readCount);
    }
}

// Main function
int main() {
    // Create a new ebook library
    Library *library = malloc(sizeof(Library));
    library->numEbooks = 0;
    library->numReaders = 0;

    // Add some ebooks to the library
    addEbook(library, (Ebook){"The Great Gatsby", "F. Scott Fitzgerald", "Classic Fiction", "Scribner", 200, 0});
    addEbook(library, (Ebook){"To Kill a Mockingbird", "Harper Lee", "Classic Fiction", "HarperCollins", 200, 0});
    addEbook(library, (Ebook){"1984", "George Orwell", "Science Fiction", "Penguin", 300, 0});
    addEbook(library, (Ebook){"The Catcher in the Rye", "J.D. Salinger", "Classic Fiction", "Vintage", 200, 0});

    // Add some readers to the library
    addReader(library, (Reader){"Jane Doe", 25, "To Kill a Mockingbird", 0});
    addReader(library, (Reader){"John Doe", 30, "1984", 0});
    addReader(library, (Reader){"Jimmy Doe", 18, "The Catcher in the Rye", 0});

    // Read some ebooks
    readEbook(library, 0, 0);
    readEbook(library, 1, 1);
    readEbook(library, 2, 2);

    // Search for an ebook by title
    Ebook *ebook = searchEbookByTitle(library, "The Great Gatsby");
    printf("Found ebook: %s by %s (%s) - %d pages, read %d times\n", ebook->title, ebook->author, ebook->genre, ebook->pageCount, ebook->readCount);

    // Search for a reader by name
    Reader *reader = searchReaderByName(library, "Jane Doe");
    printf("Found reader: %s (%d) - read %d books\n", reader->name, reader->age, reader->readCount);

    // Print the ebook library
    printEbookLibrary(library);

    // Print the reader library
    printReaderLibrary(library);

    // Free the memory
    free(library);

    return 0;
}