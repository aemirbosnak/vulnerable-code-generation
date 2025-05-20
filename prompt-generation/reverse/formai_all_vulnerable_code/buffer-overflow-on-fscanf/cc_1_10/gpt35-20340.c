//FormAI DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char word[100], dict[100];
    int err = 0;
    FILE *fp1, *fp2;

    fp1 = fopen("dictionary.txt", "r"); // Opening dictionary file for reading
    fp2 = fopen("input.txt", "r"); // Opening input file for reading

    if (fp1 == NULL || fp2 == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    while (fscanf(fp1, "%s", dict) != EOF) { // Scanning each word from the dictionary
        rewind(fp2); // Resetting the input file to the beginning

        while (fscanf(fp2, "%s", word) != EOF) { // Scanning each word from the input file
            if (strcmp(dict, word) == 0) { // Checking for a match
                err = 0;
                break;
            }

            else if (abs((int) strlen(dict) - (int) strlen(word)) > 1){ // Checking for length difference of 1 or more
                err = 1;
                break;
            }
            else {
                err += 1; // Incrementing error count for each non-matching character
            }
        }

        if (err < 2) { // If the word has 2 or less errors, it is considered a match
            printf("%s is spelled correctly.\n", dict);
        }

        else { // If the word has more than 2 errors, it is considered a misspelling
            printf("%s is misspelled.\n", dict);
        }

        err = 0; // Resetting error count for next word in the dictionary
    }

    fclose(fp1); // Closing dictionary file
    fclose(fp2); // Closing input file
    return 0;
}