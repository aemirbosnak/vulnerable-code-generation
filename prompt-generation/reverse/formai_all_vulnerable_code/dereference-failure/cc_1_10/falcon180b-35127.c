//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lines in the eBook
#define MAX_LINES 1000

// Define the maximum length of a line in the eBook
#define MAX_LINE_LENGTH 1000

// Define the structure of the eBook
typedef struct {
    char* lines[MAX_LINES]; // Array of lines in the eBook
    int num_lines; // Number of lines in the eBook
} eBook;

// Function to read the eBook from a file
eBook* read_eBook(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    eBook* ebook = malloc(sizeof(eBook));
    ebook->num_lines = 0;

    // Read each line from the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Add the line to the eBook
        ebook->lines[ebook->num_lines++] = strdup(line);
    }

    fclose(file);
    return ebook;
}

// Function to print the eBook to the console
void print_eBook(eBook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s", ebook->lines[i]);
    }
}

// Function to search for a word in the eBook
int search_eBook(eBook* ebook, char* word) {
    for (int i = 0; i < ebook->num_lines; i++) {
        char* line = ebook->lines[i];
        if (strstr(line, word)!= NULL) {
            printf("Found word '%s' on line %d\n", word, i+1);
            return 1;
        }
    }
    printf("Word '%s' not found in eBook\n", word);
    return 0;
}

int main() {
    eBook* ebook = read_eBook("example_book.txt");
    print_eBook(ebook);
    search_eBook(ebook, "excited");
    search_eBook(ebook, "programmer");
    free(ebook);
    return 0;
}