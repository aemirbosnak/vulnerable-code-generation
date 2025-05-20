//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <string.h>

void encrypt(char *s) {
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        s[i] ^= 5;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str); // Read input with spaces

    printf("Original string: %s\n", str);
    encrypt(str);
    printf("Encrypted string: %s\n", str);
    encrypt(str); // Decrypt back
    printf("Decrypted string: %s\n", str);

    printf("Reversing string...\n");
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char tmp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = tmp;
    }
    printf("Reversed string: %s\n", str);

    printf("Counting vowels and consonants...\n");
    int vowels = 0, consonants = 0;
    for (int i = 0; i < n; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        } else if (c >= 'a' && c <= 'z') {
            consonants++;
        }
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);

    printf("Replacing characters...\n");
    char find = 'o', replace = 'u';
    for (int i = 0; i < n; i++) {
        if (str[i] == find) {
            str[i] = replace;
        }
    }
    printf("Replaced string: %s\n", str);
    return 0;
}