//FormAI DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char input_str[100];
    int length, i, j, k;
    char sub_str[20];
    printf("Enter a string: ");
    gets(input_str);
    length = strlen(input_str);
    printf("\nThe length of the string is %d", length);
    printf("\nEnter a substring to search for: ");
    gets(sub_str);
    int sub_length = strlen(sub_str);
    printf("\nThe length of the substring is %d", sub_length);

    // Search for the substring
    for (i = 0; i < length; i++) {
        if (input_str[i] == sub_str[0]) {
            int flag = 1;
            for (j = 0, k = i; j < sub_length; j++, k++) {
                if (input_str[k] != sub_str[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                printf("\nThe substring was found at index %d", i);
                break;
            }
        }
    }

    // Count the number of vowels
    int vowel_count = 0;
    for (i = 0; i < length; i++) {
        char ch = input_str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowel_count++;
        }
    }
    printf("\nThe number of vowels in the string is %d", vowel_count);

    // Reverse the string
    printf("\nReversed string: ");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", input_str[i]);
    }

    return 0;
}