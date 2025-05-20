//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to extract metadata from a string
void extract_metadata(char* str) {
    int len = strlen(str);
    int i = 0;

    // Extract title
    char* title = malloc(len + 1);
    while (i < len && str[i]!= '\n') {
        title[i] = toupper(str[i]);
        i++;
    }
    title[i] = '\0';

    // Extract author
    char* author = malloc(len + 1);
    i++;
    while (i < len && str[i]!= '\n') {
        author[i - 1] = toupper(str[i]);
        i++;
    }
    author[i - 1] = '\0';

    // Extract date
    char* date = malloc(len + 1);
    i++;
    while (i < len && str[i]!= '\n') {
        date[i - 2] = str[i];
        i++;
    }
    date[i - 2] = '\0';

    // Print extracted metadata
    printf("Title: %s\n", title);
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);

    // Free memory
    free(title);
    free(author);
    free(date);
}

int main() {
    char* str = "Title: The Great Gatsby\nAuthor: F. Scott Fitzgerald\nDate: 1925-04-10\n";
    extract_metadata(str);
    return 0;
}