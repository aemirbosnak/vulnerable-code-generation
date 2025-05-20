//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function to read an ebook from a file
void readEbook(const char* filename) {
    // Open the file in read-only mode
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Read the title and content of the ebook
    char title[256];
    fscanf(file, "%s", title);

    char content[256];
    fgets(content, sizeof(content), file);

    // Close the file
    fclose(file);

    // Display the title and content of the ebook
    printf("Title: %s\n", title);
    printf("Content:\n%s\n", content);

    // Allocate memory for the ebook
    char* ebook = (char*)malloc(256 + strlen(title) + strlen(content) + 1);
    if (ebook == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Store the title and content of the ebook in the allocated memory
    strcpy(ebook, title);
    strcat(ebook, "\n");
    strcat(ebook, content);

    // Display the ebook
    printf("Ebook:\n%s\n", ebook);

    // Free the allocated memory
    free(ebook);
}

int main() {
    const char* filename = "ebook.txt";

    // Read the ebook from the file
    readEbook(filename);

    return 0;
}