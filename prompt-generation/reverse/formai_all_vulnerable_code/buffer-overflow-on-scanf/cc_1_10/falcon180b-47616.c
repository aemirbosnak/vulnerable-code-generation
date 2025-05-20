//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to read the ebook file and store it in a buffer
void read_ebook(FILE *fp, char *buffer) {
    int ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
}

// Function to display the ebook on the console
void display_ebook(char *buffer) {
    int i = 0;
    while (buffer[i]!= '\0') {
        printf("%c", buffer[i]);
        i++;
    }
}

// Function to search for a word in the ebook
int search_word(char *buffer, char *word) {
    char *ptr = strstr(buffer, word);
    if (ptr == NULL) {
        return -1;
    }
    return (ptr - buffer);
}

int main() {
    FILE *fp;
    char filename[100];
    char buffer[100000];

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the ebook file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the ebook file and store it in a buffer
    read_ebook(fp, buffer);

    // Display the ebook on the console
    printf("\nEbook:\n");
    display_ebook(buffer);

    // Search for a word in the ebook
    char word[100];
    printf("\nEnter a word to search: ");
    scanf("%s", word);
    int index = search_word(buffer, word);
    if (index == -1) {
        printf("Word not found\n");
    } else {
        printf("\nWord found at position %d\n", index);
    }

    fclose(fp);
    return 0;
}