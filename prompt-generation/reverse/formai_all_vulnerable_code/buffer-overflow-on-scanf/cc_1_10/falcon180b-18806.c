//Falcon-180B DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function to split a string into words
void split_string(char* str, char** words) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }
    words[count] = NULL;
}

int main() {
    FILE* file;
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char* words[100];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int word_count = 0;

        // Split line into words
        split_string(line, words);

        // Print each word on a new line
        for (int i = 0; i < word_count; i++) {
            printf("%s\n", words[i]);
        }
    }

    // Close file
    fclose(file);

    return 0;
}