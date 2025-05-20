//FormAI DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {

    char sentence[100];
    char word[20];
    
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    printf("Enter a word to search for: ");
    scanf("%s", word);

    char *result = strstr(sentence, word);
    int word_count = 0;
    while (result != NULL) {
        word_count++;
        result = strstr(result + 1, word);
    }

    printf("\nThe word '%s' appears %d times in the sentence.\n", word, word_count);

    // Convert sentence to uppercase
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            sentence[i] = sentence[i] - 32;
        }
    }

    printf("\nThe sentence in uppercase is: %s\n", sentence);

    // Count vowels and consonants in sentence
    int vowels = 0, consonants = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == 'A' || sentence[i] == 'E' ||
            sentence[i] == 'I' || sentence[i] == 'O' ||
            sentence[i] == 'U') {
            vowels++;
        } else if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
            consonants++;
        }
    }

    printf("\nThe sentence has %d vowels and %d consonants.\n", vowels, consonants);

    // Replace all occurrences of word with a new word
    char new_word[20];
    printf("\nEnter a new word to replace '%s': ", word);
    scanf("%s", new_word);

    char *ptr1, *ptr2;
    int len1 = strlen(word), len2 = strlen(new_word);
    ptr1 = sentence;
    while ((ptr2 = strstr(ptr1, word)) != NULL) {
        int len = ptr2 - ptr1;
        printf("%.*s", len, ptr1);
        printf("%s", new_word);
        ptr1 = ptr2 + len1;
    }
    printf("%s\n", ptr1);

    return 0;
}