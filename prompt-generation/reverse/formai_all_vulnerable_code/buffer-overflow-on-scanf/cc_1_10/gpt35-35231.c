//FormAI DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 200   // Maximum length of the input string

// The main function that does the spell check
int spell_check(char *word) {
    char dictionary[MAX_LENGTH][MAX_LENGTH];   // Dictionary to store words
    int count = 0;
    int flag = 0;
    FILE *fp;

    // Open the dictionary file in read mode
    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Error opening dictionary file!");
        exit(1);
    }

    // Read words from dictionary file and store them in the dictionary array
    while (fscanf(fp, "%s", dictionary[count]) != EOF) {
        count++;
    }

    // Close the dictionary file
    fclose(fp);

    // Convert the input string to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the input word is in the dictionary
    for (int i = 0; i < count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            flag = 1;   // Word is present in dictionary
            break;
        }
    }

    if (flag == 1) {
        printf("%s is spelled correctly\n", word);
        return 1;
    } else {
        printf("%s is not spelled correctly\n", word);
        return 0;
    }
}

int main() {
    char input[MAX_LENGTH];  // The input string

    // Get the input string from the user
    printf("Enter the string to be spell checked: ");
    scanf("%s", input);

    // Do the spell check
    spell_check(input);

    return 0;
}