//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[20];
    printf("Please enter a word: ");
    scanf("%s", word);

    int i = 0;
    for (i = 0; word[i] != '\0'; i++) {
        if (!isalnum(word[i])) {
            printf("Error: The word contains non-alphanumeric characters.\n");
            return 1;
        }
    }

    int length = strlen(word);
    if (length < 3) {
        printf("Error: The word is too short.\n");
        return 1;
    }

    int found = 0;
    char dictionary[100][20] = {
        {"apple"},
        {"banana"},
        {"cherry"},
        {"orange"},
        {"peach"},
        {"apricot"},
        {"mango"},
        {"grapes"}
    };

    for (int j = 0; j < 10; j++) {
        if (strcmp(word, dictionary[j]) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("The word %s is found in the dictionary.\n", word);
    } else {
        printf("The word %s is not found in the dictionary.\n", word);
    }

    return 0;
}