//Falcon-180B DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>

// Function to count the number of words in the input string
int countWords(char *str) {
    int count = 0;
    char *word;

    word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char input[1000];

    // Loop until the user enters 'exit'
    while (1) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);

        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Count the number of words in the input string
        int numWords = countWords(input);

        // Convert the input string to all uppercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = toupper(input[i]);
        }

        // Reverse the order of the words in the input string
        char *token = strtok(input, " ");
        char reversed[1000];
        strcpy(reversed, token);

        while (token!= NULL) {
            strcat(reversed, " ");
            strcat(reversed, token);
            token = strtok(NULL, " ");
        }

        // Print the modified input string
        printf("Modified string: %s\n", reversed);
        printf("Number of words: %d\n\n", numWords);
    }

    return 0;
}