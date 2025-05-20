//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove all whitespaces from a string
void remove_whitespaces(char* str) {
    int i, j;
    for (i = j = 0; str[i]!= '\0'; i++) {
        if (!isspace(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverse_string(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to count the number of vowels in a string
int count_vowels(char* str) {
    int count = 0;
    for (int i = 0; str[i]!= '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove all whitespaces and convert to lowercase
    remove_whitespaces(str);

    // Reverse the string
    reverse_string(str);

    // Count the number of vowels
    int vowel_count = count_vowels(str);

    // Print the modified string and vowel count
    printf("Modified string: %s\n", str);
    printf("Number of vowels: %d\n", vowel_count);

    return 0;
}