//FormAI DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a curious C Word Count Tool!
// It counts the number of words in a text file, in a curious way!

int main() {
    
    char file_name[100];
    printf("Enter the name of the file you want to count the words in: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Could not open file %s", file_name);
        return 1;
    }

    char curious_characters[] = {'.', '?', '!'}; // These are the curious characters that we will use to count the words!

    int count = 0;  // This is the word count
    int inside_word = 0; // This flag indicates if we are inside a word or not
    int i;

    char c;

    while ((c = fgetc(file)) != EOF) { // Let's read the file character by character!
        for (i = 0; i < sizeof(curious_characters) / sizeof(char); i++) { // Loop through the curious characters array
            if (c == curious_characters[i]) { // We found a curious character!
                inside_word = 0; // We are no longer in a word
                count++; // Increase the word count
            }
        }

        if (c == ' ' || c == '\n' || c == '\t') { // We found a whitespace! Which means we are no longer inside a word.
            inside_word = 0;
        } else if (inside_word == 0) { // We are not inside a word, we must've just found the beginning of a new word!
            inside_word = 1;  // We are now inside a word!
        }
    }

    if (inside_word == 1) { // If we are still inside a word, then we found one more word!
        count++;
    }

    printf("The number of words in %s is %d", file_name, count); // Finally, let's output the word count!

    fclose(file); // Don't forget to close the file!
    return 0;
}