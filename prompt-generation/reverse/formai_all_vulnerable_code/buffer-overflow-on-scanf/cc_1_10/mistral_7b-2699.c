//MISTRAL-7B DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define ALPHABET_SIZE 26

// Function to find the index of character in the alphabet
int char_index(char c) {
    return c - 'a';
}

// Function to check if a given character is vowel or consonant
int is_vowel(char c) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int i;

    for (i = 0; i < 5; i++) {
        if (c == vowels[i])
            return 1;
    }

    return 0;
}

// Function to count the number of vowels and consonants in a given string
void count_letters(char str[], int *vowels, int *consonants) {
    int i, count_vowels = 0, count_consonants = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (is_vowel(str[i])) {
            count_vowels++;
            vowels[char_index(str[i])] += count_vowels;
        } else {
            count_consonants++;
            consonants[char_index(str[i])] += count_consonants;
        }
    }
}

// Function to print the frequency of vowels and consonants in the given string
void print_frequency(char str[]) {
    int i, vowels[ALPHABET_SIZE] = {0}, consonants[ALPHABET_SIZE] = {0};

    count_letters(str, vowels, consonants);

    printf("\nFrequency of each letter in the given string:\n");

    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (is_vowel('a' + i)) {
            printf("Vowel %c : %d\n", 'a' + i, vowels[i]);
        } else {
            printf("Consonant %c : %d\n", 'a' + i, consonants[i]);
        }
    }
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    print_frequency(str);

    return 0;
}