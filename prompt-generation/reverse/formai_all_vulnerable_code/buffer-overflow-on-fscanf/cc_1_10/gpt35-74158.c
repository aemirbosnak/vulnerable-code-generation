//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

// A function to check if a character is a letter or not
int is_letter(char c) {
    return isalpha(c);
}

// A function to convert a word to lower case
void to_lower_case(char* word) {
    for(int i=0; i<strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

// A function to remove leading and trailing white spaces from a string
void trim_whitespace(char* str) {
    int len = strlen(str);
    int i = 0, j = len - 1;

    while(i < len && isspace(str[i])) {
        i++;
    }
    while(j > i && isspace(str[j])) {
        j--;
    }

    str[j+1] = '\0';

    if(i > 0) {
        memmove(str, str+i, j-i+2);
    }
}

// A function to check if a word is misspelled or not
int is_misspelled(char* word) {
    // Open the dictionary file for reading
    FILE* fp = fopen("dictionary.txt", "r");

    // Check if the dictionary file opened successfully
    if(fp == NULL) {
        printf("Error: Failed to open dictionary file.\n");
        return 0;
    }

    // Convert the word to lower case
    to_lower_case(word);

    // Remove leading and trailing white spaces from the word
    trim_whitespace(word);

    // Initialize variables
    char dict_word[MAX_WORD_LENGTH];
    int word_found = 0;

    // Read words from the dictionary file one by one
    while(fscanf(fp, "%s", dict_word) != EOF) {
        // Compare the word with each word in the dictionary
        if(strcmp(word, dict_word) == 0) {
            word_found = 1;
            break;
        }
    }

    // Close the dictionary file
    fclose(fp);

    if(word_found == 1) {
        return 0; // The word is spelled correctly
    } else {
        return 1; // The word is misspelled
    }
}

// A function to print a suggested correction for a misspelled word
void print_correction(char* word) {
    // Open the dictionary file for reading
    FILE* fp = fopen("dictionary.txt", "r");

    // Check if the dictionary file opened successfully
    if(fp == NULL) {
        printf("Error: Failed to open dictionary file.\n");
        return;
    }

    // Convert the word to lower case
    to_lower_case(word);

    // Remove leading and trailing white spaces from the word
    trim_whitespace(word);

    // Initialize variables
    char dict_word[MAX_WORD_LENGTH];
    int edit_distance;
    int min_edit_distance = MAX_WORD_LENGTH;

    // Read words from the dictionary file one by one
    while(fscanf(fp, "%s", dict_word) != EOF) {
        // Calculate the edit distance between the misspelled word and the dictionary word
        edit_distance = calculate_edit_distance(word, dict_word);

        // Check if the edit distance is less than the minimum edit distance found so far
        if(edit_distance < min_edit_distance) {
            min_edit_distance = edit_distance;
        }
    }

    // Close the dictionary file
    fclose(fp);

    // Print the suggested correction for the misspelled word
    printf("Did you mean:");

    // Open the dictionary file again for reading
    fp = fopen("dictionary.txt", "r");

    // Read words from the dictionary file one by one
    while(fscanf(fp, "%s", dict_word) != EOF) {
        // Calculate the edit distance between the misspelled word and the dictionary word
        edit_distance = calculate_edit_distance(word, dict_word);

        // Check if the edit distance is equal to the minimum edit distance found
        if(edit_distance == min_edit_distance) {
            printf(" %s", dict_word);
        }
    }

    printf("?\n");

    // Close the dictionary file
    fclose(fp);
}

// A function to calculate the edit distance between two words
int calculate_edit_distance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}

// A function to find the minimum of three numbers
int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    } else if(b < c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    // Initialize variables
    char text[1000];
    char word[MAX_WORD_LENGTH];
    int i = 0, j = 0, k = 0;

    // Read input text from the user
    printf("Enter some text:\n");
    fgets(text, 1000, stdin);

    // Check each character in the input text
    while(text[i] != '\0') {
        if(is_letter(text[i])) {
            // Add the letter to the current word
            word[j++] = text[i++];
        } else {
            // Check if the current word is misspelled
            word[j] = '\0';
            if(strlen(word) > 0 && is_misspelled(word)) {
                // Print the misspelled word with a suggested correction
                printf("'%s' is misspelled.\n", word);
                print_correction(word);
            }
            j = 0;
            i++;
        }
    }

    return 0;
}