//FormAI DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_NO_OF_WORDS 1000

int compare(const void *s1, const void *s2);
int search(const char *key, const char *arr[], int len);

int main() {
    char input[MAX_WORD_LEN];
    const char *dict[] = {"apple", "banana", "cherry", "grape", "kiwi", "orange", "pineapple", "watermelon"};
    char *user_words[MAX_NO_OF_WORDS];
    int no_of_user_words = 0;

    printf("Enter words to spell-check: (type 'done' to exit)\n");

    //get user input
    while (strcmp("done", input) != 0) {
        scanf("%s", input);
        //normalize word to lowercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }
        //check if word is already in array
        if (search(input, user_words, no_of_user_words) == -1) {
            user_words[no_of_user_words++] = strdup(input);
        }
    }

    //sort user input array
    qsort(user_words, no_of_user_words, sizeof(char *), compare);

    //loop through user input array and check spelling
    printf("\nMisspelled words:\n");
    for (int i = 0; i < no_of_user_words; i++) {
        if (search(user_words[i], dict, sizeof(dict)/sizeof(const char *)) == -1) {
            printf("%s\n", user_words[i]);
        }
    }

    return 0;
}

//helper function to compare strings
int compare(const void *s1, const void *s2) {
    const char *a = *(const char **)s1;
    const char *b = *(const char **)s2;
    return strcmp(a, b);
}

//helper function to search for key in array
int search(const char *key, const char *arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (strcmp(key, arr[i]) == 0) {
            return i;
        }
    }
    return -1;
}