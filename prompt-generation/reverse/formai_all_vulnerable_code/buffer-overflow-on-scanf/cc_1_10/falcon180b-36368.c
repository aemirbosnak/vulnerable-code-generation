//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to search for a word in a text file
int search_word(char* filename, char* word) {
    FILE* fp;
    char line[100];
    int found = 0;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read each line and check if the word is present
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strstr(line, word)!= NULL) {
            printf("Found the word '%s' in the file %s\n", word, filename);
            found = 1;
        }
    }

    // Close the file
    fclose(fp);

    if (!found) {
        printf("The word '%s' was not found in the file %s\n", word, filename);
    }

    return found;
}

int main() {
    char filename[100];
    char word[100];

    // Get the filename and word from the user
    printf("Enter the name of the file to search in: ");
    scanf("%s", filename);
    printf("Enter the word to search for: ");
    scanf("%s", word);

    // Call the search_word function
    if (search_word(filename, word)) {
        printf("Search successful!\n");
    } else {
        printf("Search failed.\n");
    }

    return 0;
}