//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void reverse_string(char* str);
void capitalize_string(char* str);
void remove_vowels(char* str);
void count_chars(char* str);

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    // Example usage
    reverse_string(str);
    capitalize_string(str);
    remove_vowels(str);
    count_chars(str);

    return 0;
}

void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void capitalize_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

void remove_vowels(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            str[i] = '\0';
        }
    }
}

void count_chars(char* str) {
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i]!= '\0') {
            count++;
        }
    }
    printf("Number of characters: %d\n", count);
}