//Falcon-180B DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to remove leading/trailing spaces from a string
void trim(char* str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            for (j = i; j < strlen(str); j++) {
                str[j] = str[j + 1];
            }
            str[strlen(str) - 1] = '\0';
            i--;
        }
    }
}

// Function to split a string into words
void split(char* str, char words[][MAX_WORD_LENGTH]) {
    char* token = strtok(str, ",.?!;:");
    int count = 0;
    while (token!= NULL) {
        trim(token);
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, ",.?!;:");
    }
}

// Function to reverse the order of words in a string
void reverse(char words[][MAX_WORD_LENGTH], int num_words) {
    char temp[MAX_WORD_LENGTH];
    for (int i = 0; i < num_words / 2; i++) {
        strcpy(temp, words[i]);
        strcpy(words[i], words[num_words - i - 1]);
        strcpy(words[num_words - i - 1], temp);
    }
}

// Function to capitalize the first letter of each word in a string
void capitalize(char words[][MAX_WORD_LENGTH], int num_words) {
    for (int i = 0; i < num_words; i++) {
        words[i][0] = toupper(words[i][0]);
    }
}

int main() {
    char input[MAX_WORDS][MAX_WORD_LENGTH];
    char output[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words = 0;

    printf("Enter a sentence or paragraph:\n");
    scanf("%[^\n]", input);

    split(input, input);
    num_words = strlen(input) / MAX_WORD_LENGTH;

    reverse(input, num_words);
    capitalize(input, num_words);

    printf("Reversed and capitalized:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", input[i]);
    }

    return 0;
}