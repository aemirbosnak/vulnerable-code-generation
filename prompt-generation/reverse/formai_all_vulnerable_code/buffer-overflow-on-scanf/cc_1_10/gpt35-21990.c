//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <string.h>

// Function to check whether the given string is in alien language
int isAlienLanguage(char* str, char* letterOrder)
{
    // Initialize a mapping array to store the order of each character in the alien language
    int map[26] = {0};
    int order = 0;
    int len = strlen(letterOrder);

    // Store the order of each character in the mapping array
    for (int i = 0; i < len; i++) {
        map[letterOrder[i] - 'a'] = ++order;
    }

    // Check whether the given string is in alien language
    int currOrder = map[str[0] - 'a'];
    int currLen = strlen(str);

    for (int i = 1; i < currLen; i++) {
        int nextOrder = map[str[i] - 'a'];
        if (nextOrder == 0) {
            return 0; // Invalid character
        }
        if (nextOrder < currOrder) {
            return 0; // Wrong order
        }
        currOrder = nextOrder;
    }

    // The given string is in alien language
    return 1;
}

int main()
{
    // Define the order of the alien language
    char letterOrder[26];
    strcpy(letterOrder, "fmovcnpgbhrzdqsjyuxwltaei");

    // Read the input string from the user
    char str[100];
    printf("Enter a string in alien language: ");
    scanf("%s", str);

    // Check whether the input string is in alien language
    if (isAlienLanguage(str, letterOrder)) {
        printf("\"%s\" is a valid string in alien language.\n", str);
    } else {
        printf("\"%s\" is not a valid string in alien language.\n", str);
    }

    return 0;
}