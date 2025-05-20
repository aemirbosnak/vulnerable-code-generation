//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to remove all vowels from a string
void remove_vowels(char *str) {
    int i, j;
    char vowels[] = "aeiouAEIOU";
    for (i = 0, j = 0; str[i]; i++) {
        if (strchr(vowels, tolower(str[i])) == NULL) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i++] = str[j];
        str[j--] = temp;
    }
}

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    char *p = strtok(str, " ");
    while (p!= NULL) {
        count++;
        p = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    // Remove all vowels from the string
    remove_vowels(str);
    printf("String without vowels: %s\n", str);

    // Reverse the string
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    // Count the number of words in the string
    int word_count = count_words(str);
    printf("Number of words: %d\n", word_count);

    return 0;
}