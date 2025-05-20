//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverse(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void capitalize(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void count_vowels(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }
    printf("Number of vowels in %s: %d\n", str, count);
}

void find_substring(char* str1, char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    int max_length = length1 > length2? length1 : length2;
    for (int i = 0; i <= length1 - max_length; i++) {
        int j = 0;
        while (j < max_length && str1[i + j] == str2[j]) {
            j++;
        }
        if (j == max_length) {
            printf("Found substring %s in %s\n", str2, str1);
        }
    }
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    reverse(str1);
    printf("Reversed string: %s\n", str1);

    capitalize(str1);
    printf("Capitalized string: %s\n", str1);

    count_vowels(str1);

    find_substring(str1, str2);

    return 0;
}