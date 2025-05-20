//FormAI DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to strip whitespace and punctuation from a given string
void strip(char* str) {
    char* p = str;
    while (*p != '\0') {
        if (isalnum(*p)) {
            *str++ = tolower(*p);
        }
        p++;
    }
    *str = '\0';
}

// function to find the minimum of two numbers
int min(int a, int b) {
    return a < b ? a : b;
}

void spellcheck(char* input, char** dictionary, int num_words) {
    strip(input);

    // initialize the distances array
    int distances[num_words + 1];
    for (int i = 0; i <= num_words; i++) {
        distances[i] = i;
    }

    // calculate the distances for each word in the dictionary
    for (int i = 0; i < num_words; i++) {
        char* dict_word = dictionary[i];
        int dict_len = strlen(dict_word);

        int prev_distance = distances[0];
        distances[0] = i + 1;

        for (int j = 0; j < dict_len; j++) {
            int add_cost = distances[j] + 1;
            int del_cost = prev_distance + 1;
            int sub_cost = prev_distance + (dict_word[j] != input[j]);
            distances[j] = prev_distance;
            prev_distance = min(min(add_cost, del_cost), sub_cost);
        }
        distances[dict_len] = prev_distance;
    }

    // find the word(s) with the minimum distance
    int min_distance = distances[0];
    for (int i = 1; i <= num_words; i++) {
        int distance = distances[i];
        if (distance < min_distance) {
            min_distance = distance;
        }
    }

    // print out any matching words with the minimum distance
    if (min_distance == 0) {
        printf("Input word is spelled correctly.\n");
        return;
    }
    printf("Did you mean:\n");
    for (int i = 0; i < num_words; i++) {
        char* dict_word = dictionary[i];
        int distance = distances[i];
        if (distance == min_distance) {
            printf("%s\n", dict_word);
        }
    }
}

int main() {
    char* dictionary[] = {
        "hello",
        "world",
        "spell",
        "checking",
        "example",
        "computer",
        "science",
        "is",
        "awesome"
    };
    int num_words = 9;

    char input[100];
    printf("Enter word to spell check: ");
    scanf("%s", input);

    spellcheck(input, dictionary, num_words);
    
    return 0;
}