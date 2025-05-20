//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Function to read the ebook file
void readEbook(FILE *ebookFile) {
    char line[MAX_STRING_LENGTH];
    while (fgets(line, MAX_STRING_LENGTH, ebookFile)!= NULL) {
        printf("%s", line);
    }
}

// Function to search for a specific word in the ebook
int searchWord(FILE *ebookFile, char *word) {
    char line[MAX_STRING_LENGTH];
    while (fgets(line, MAX_STRING_LENGTH, ebookFile)!= NULL) {
        if (strstr(line, word)!= NULL) {
            printf("Found the word '%s' in the ebook.\n", word);
            return 1;
        }
    }
    printf("The word '%s' was not found in the ebook.\n", word);
    return 0;
}

int main() {
    FILE *ebookFile;
    char ebookFileName[MAX_STRING_LENGTH];
    char wordToSearch[MAX_STRING_LENGTH];

    // Ask the user for the ebook file name
    printf("Enter the name of the ebook file: ");
    scanf("%s", ebookFileName);

    // Open the ebook file
    ebookFile = fopen(ebookFileName, "r");
    if (ebookFile == NULL) {
        printf("Error opening ebook file.\n");
        exit(1);
    }

    // Ask the user for the word to search
    printf("Enter the word to search for: ");
    scanf("%s", wordToSearch);

    // Search for the word in the ebook
    searchWord(ebookFile, wordToSearch);

    // Close the ebook file
    fclose(ebookFile);

    return 0;
}