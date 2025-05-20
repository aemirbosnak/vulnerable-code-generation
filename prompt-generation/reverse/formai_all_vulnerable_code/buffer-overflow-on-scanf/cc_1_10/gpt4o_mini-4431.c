//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to replace vowels in the string with the specified character
void replace_vowels(char *str, char replacement) {
    char *vowels = "aeiouAEIOU";
    for (int i = 0; str[i]; ++i) {
        if (strchr(vowels, str[i])) {
            str[i] = replacement;
        }
    }
}

// Function to reverse the string
void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to count and display the frequency of each character in the string
void character_frequency(const char *str) {
    int freq[256] = {0}; // Array to store frequency of each ASCII character
    for (int i = 0; str[i]; ++i) {
        freq[(unsigned char)str[i]]++;
    }
    
    printf("\nCharacter Frequency:\n");
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }
}

// Function to concatenate a given string with a random string generated from the alphabet
void concatenate_random(char *str, int length) {
    const char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; ++i) {
        str[strlen(str)] = alphabet[rand() % (strlen(alphabet))];
    }
    str[strlen(str) + length] = '\0'; // Null-terminate the string
}

// Function to convert the string to uppercase
void to_uppercase(char *str) {
    for (int i = 0; str[i]; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A'; // Convert to uppercase
        }
    }
}

// Function to split a string into words and print them
void split_and_print_words(const char *str) {
    char *token;
    char *copy = strdup(str); // Duplicate the string to not modify original
    token = strtok(copy, " ");
    printf("\nWords in the string:\n");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    free(copy); // Free the duplicated string
}

int main() {
    char input[256];
    char replacement_char;

    // Input string
    printf("Enter a string (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input if it exists
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Input replacement character
    printf("Enter a character to replace vowels with: ");
    scanf(" %c", &replacement_char);

    // Manipulate the string with various functions
    printf("\nOriginal String: %s", input);
    replace_vowels(input, replacement_char);
    printf("\nAfter replacing vowels: %s", input);
    
    reverse_string(input);
    printf("\nAfter reversing the string: %s", input);

    character_frequency(input);

    concatenate_random(input, 5);
    printf("\nAfter concatenating random characters: %s\n", input);

    to_uppercase(input);
    printf("Final string in uppercase: %s\n", input);
  
    split_and_print_words(input);

    return 0;
}