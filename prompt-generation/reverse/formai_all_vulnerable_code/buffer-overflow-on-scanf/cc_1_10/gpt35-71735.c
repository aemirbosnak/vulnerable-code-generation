//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char words[100][100];
    int row = 0, col = 0, i, j, k, length, flag;

    printf("*** Welcome to Cheerful Spell Checking Program! ***\n");
    printf("Enter a sentence (type 'exit' to stop): \n");

    // Getting input from user
    do {
        scanf("%s", words[row]);
        if (strcmp(words[row], "exit") == 0) {
            break;
        }
        row++;
    } while (1);

    // Checking each word from input
    printf("\n*** Here are the misspelled words: ***\n");
    for (i = 0; i < row; i++) {
        length = strlen(words[i]);
        flag = 1;

        // Checking if each character is a letter
        for (j = 0; j < length; j++) {
            if (!isalpha(words[i][j])) {
                flag = 0;
                break;
            }
        }

        // If word is misspelled
        if (flag == 1) {
            // Checking with a dictionary of possible correct words
            char dictionary[10][10] = {"apple", "banana", "cherry", "grape", "kiwi", "orange", "peach", "pear", "pineapple", "watermelon"};
            int found = 0;
            for (k = 0; k < 10; k++) {
                if (strcmp(words[i], dictionary[k]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                printf("- %s\n", words[i]);
            }
        }
    }

    printf("\n*** Thank you for using Cheerful Spell Checking Program! ***\n");
    
    return 0;
}