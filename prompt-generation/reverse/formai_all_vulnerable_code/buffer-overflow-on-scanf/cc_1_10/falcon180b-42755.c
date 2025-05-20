//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char line[MAX_LINE_LENGTH];
    char *word;
    int total_chars = 0;
    int num_words = 0;
    int num_lines = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", line);

    // Open file for reading
    FILE *fp = fopen(line, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", line);
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        num_lines++;
        num_words = 0;

        // Count number of words in line
        word = strtok(line, " ");
        while (word!= NULL) {
            num_words++;
            total_chars += strlen(word);
            word = strtok(NULL, " ");
        }

        // Calculate average word length for line
        if (num_words > 0) {
            float avg_word_length = (float) total_chars / num_words;
            printf("Line %d: %d words, average length %.2f\n", num_lines, num_words, avg_word_length);
        } else {
            printf("Line %d: empty\n", num_lines);
        }
    }

    // Close file
    fclose(fp);

    return 0;
}