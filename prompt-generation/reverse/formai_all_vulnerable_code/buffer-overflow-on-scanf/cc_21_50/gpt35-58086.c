//FormAI DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    int i, j, len;

    printf("Please enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Reverse the string
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("The reversed string is: %s\n", str);

    // Find the palindrome substrings
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            char sub[100];
            strncpy(sub, &str[i], j - i + 1);
            sub[j - i + 1] = '\0';
            int sub_len = strlen(sub);
            char reversed[100];
            int k;
            for (k = 0; k < sub_len; k++) {
                reversed[k] = sub[sub_len - k - 1];
            }
            reversed[sub_len] = '\0';
            if (strcmp(sub, reversed) == 0) {
                printf("The substring '%s' is a palindrome.\n", sub);
            }
        }
    }

    // Count the number of vowels
    int num_of_vowels = 0;
    for (i = 0; i < len; i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            num_of_vowels++;
        }
    }
    printf("The number of vowels in the string is %d.\n", num_of_vowels);

    // Reverse each word
    int word_start_index = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i+1] == '\0') {
            for (j = word_start_index; j < i; j++) {
                temp = str[j];
                str[j] = str[i - j - 1 + word_start_index];
                str[i - j - 1 + word_start_index] = temp;
            }
            word_start_index = i + 1;
        }
    }
    printf("The string with each word reversed is: %s\n", str);
    return 0;
}