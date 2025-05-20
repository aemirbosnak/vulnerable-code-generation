//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1000

typedef struct {
    char *str;
    int length;
} String;

int main() {
    String str1 = {"Hello, world!"};
    String str2 = {"C is a powerful language."};
    String str3;

    // Concatenate two strings
    str3.length = str1.length + str2.length + 1;
    str3.str = malloc(str3.length * sizeof(char));
    strcpy(str3.str, str1.str);
    strcat(str3.str, str2.str);

    // Reverse a string
    char *reversed = malloc(str3.length * sizeof(char));
    int i = str3.length - 1;
    while (i >= 0) {
        reversed[i] = str3.str[i];
        i--;
    }
    printf("Reversed string: %s\n", reversed);

    // Check if two strings are equal
    if (strcmp(str1.str, str2.str) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    // Convert string to uppercase
    char *uppercase = malloc(str3.length * sizeof(char));
    int j = 0;
    while (j < str3.length) {
        if (str3.str[j] >= 'a' && str3.str[j] <= 'z') {
            uppercase[j] = str3.str[j] - 32;
        } else {
            uppercase[j] = str3.str[j];
        }
        j++;
    }
    printf("Uppercase string: %s\n", uppercase);

    // Count number of vowels in a string
    int vowel_count = 0;
    for (int k = 0; k < str3.length; k++) {
        if (str3.str[k] == 'a' || str3.str[k] == 'e' || str3.str[k] == 'i' || str3.str[k] == 'o' || str3.str[k] == 'u') {
            vowel_count++;
        }
    }
    printf("Number of vowels: %d\n", vowel_count);

    free(str3.str);
    free(reversed);
    free(uppercase);

    return 0;
}