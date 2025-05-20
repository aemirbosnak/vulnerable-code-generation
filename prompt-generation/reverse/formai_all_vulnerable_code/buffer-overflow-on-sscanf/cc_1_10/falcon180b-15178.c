//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

struct word {
    char english[50];
    char alien[100];
};

int main() {
    FILE *file;
    char line[100];
    struct word words[MAX_WORDS];
    int num_words = 0;

    // Read in the dictionary file
    file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Fill in the struct with words from the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in dictionary file.\n");
            return 1;
        }
        sscanf(line, "%s %s", words[num_words].english, words[num_words].alien);
        num_words++;
    }
    fclose(file);

    // Prompt user for input
    printf("Enter a sentence to translate:\n");
    fgets(line, sizeof(line), stdin);

    // Split input into words
    char *token = strtok(line, " ");
    while (token!= NULL) {
        // Search for word in dictionary
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // Print the alien translation
                printf("%s ", words[i].alien);
                break;
            }
        }
        if (i == num_words) {
            // Word not found in dictionary, print as is
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}