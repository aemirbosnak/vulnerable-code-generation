//Falcon-180B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char ch;
    int count = 0;
    int word_count = 0;

    // Prompt user to enter filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read file line by line
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            // End of line reached, count number of words
            int i = 0;
            while (i < count && isspace(filename[i])) {
                i++;
            }
            int j = i;
            while (j < count &&!isspace(filename[j])) {
                j++;
            }
            if (j > i) {
                word_count++;
            }
            count = 0;
        } else {
            // Add character to line buffer
            if (count < MAX_LINE_LENGTH) {
                filename[count++] = tolower(ch);
            }
        }
    }

    // Count last line of words
    int i = 0;
    while (i < count && isspace(filename[i])) {
        i++;
    }
    int j = i;
    while (j < count &&!isspace(filename[j])) {
        j++;
    }
    if (j > i) {
        word_count++;
    }

    // Calculate average word length
    float avg_word_length = (float) word_count / (float) count;

    // Print results
    printf("Total words: %d\n", word_count);
    printf("Average word length: %.2f\n", avg_word_length);

    // Close file
    fclose(file);

    return 0;
}