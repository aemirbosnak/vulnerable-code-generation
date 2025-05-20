//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERSES 1000
#define VERSE_LEN 80
#define CHAR_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=[]{}|;:,.<>/?\\"

int main() {
    // Initialize the search pattern
    char search_pattern[VERSE_LEN];
    printf("Enter the search pattern: ");
    scanf("%[^\n]", search_pattern);
    int pattern_len = strlen(search_pattern);

    // Initialize the search result
    char search_result[MAX_VERSES][VERSE_LEN];
    int result_len = 0;

    // Open the Romeo and Juliet text file
    FILE *file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the text file line by line
    char line[VERSE_LEN];
    while (fgets(line, VERSE_LEN, file)!= NULL) {
        // Convert the line to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Search for the pattern in the line
        int index = 0;
        while (index < strlen(line)) {
            int j = 0;
            while (j < pattern_len && line[index + j] == search_pattern[j]) {
                j++;
            }
            if (j == pattern_len) {
                // Pattern found, add the line to the search result
                strcpy(search_result[result_len], line);
                result_len++;
            }
            index++;
        }
    }

    // Close the text file
    fclose(file);

    // Print the search result
    if (result_len == 0) {
        printf("Pattern not found.\n");
    } else {
        printf("Search result:\n");
        for (int i = 0; i < result_len; i++) {
            printf("%s\n", search_result[i]);
        }
    }

    return 0;
}