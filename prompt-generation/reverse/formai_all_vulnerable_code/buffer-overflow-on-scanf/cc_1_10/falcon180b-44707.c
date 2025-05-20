//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void reverse(char* str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void capitalize(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void removeVowels(char* str) {
    int len = strlen(str);
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            if (tolower(str[i]) == vowels[j]) {
                str[i] = '\0';
                break;
            }
        }
    }
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original string: %s\n", str);
    reverse(str);
    printf("Reversed string: %s\n", str);
    capitalize(str);
    printf("Capitalized string: %s\n", str);
    removeVowels(str);
    printf("String without vowels: %s\n", str);

    return 0;
}