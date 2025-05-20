//FormAI DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000 // Maximum words that can be entered by the user
#define MAX_LENGTH 50 // Maximum length of each word

int main() {
    int i, j, k, nmisspelled = 0; // Variables to be used in the program
    char dict[MAX_WORDS][MAX_LENGTH], document[MAX_WORDS][MAX_LENGTH], temp[MAX_LENGTH], c;
    
    printf("Enter the words in the dictionary (type '0' to exit):\n");
    i = 0;
    while(1) {
        scanf("%s", &temp);
        if(strcmp(temp, "0") == 0) break; // Exiting the dictionary
        strcpy(dict[i++], temp); // Adding the word to dictionary
    }
    printf("\nEnter the document to be checked for spelling errors (type '0' to exit):\n");
    i = 0;
    while(1) {
        scanf("%s", &temp);
        if(strcmp(temp, "0") == 0) break; // Exiting the document
        strcpy(document[i++], temp); // Adding the word to document
    }
    for(j = 0; j < i; j++) { // Iterating through each word of the document
        for(k = 0; k < strlen(document[j]); k++) { // Iterating through each character of the word
            c = document[j][k];
            if(c >= 'A' && c <= 'Z') document[j][k] = c - ('A' - 'a'); // Converting uppercase to lowercase
            if(c < 'a' || c > 'z') { // Removing special characters
                for(int p = k; p < strlen(document[j]); p++) {
                    document[j][p] = document[j][p+1];
                }
                k--;
            }
        }
        int found = 0; // Flag for checking if word is in dictionary
        for(k = 0; k < strlen(document[j]); k++) { // Iterating through each word in dictionary
            if(strcmp(document[j], dict[k]) == 0) { // Word found in dictionary
                found = 1; 
                break;
            }
        }
        if(!found) { // Word not found in dictionary
            printf("\n%s is misspelled\n", document[j]);
            nmisspelled++;
        }
    }
    if(nmisspelled == 0) printf("\nAll words are spelled correctly.\n"); // No words misspelled
    else printf("\n%d words are misspelled.\n", nmisspelled); // Number of words misspelled
    return 0;
}