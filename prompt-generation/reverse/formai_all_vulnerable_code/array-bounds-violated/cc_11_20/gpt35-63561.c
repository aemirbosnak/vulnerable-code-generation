//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50], str3[100];
    int i, j, k, len1, len2, len3;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = len1 + len2;

    // append str1 and str2 to str3
    for (i = 0; i < len1; i++) {
        str3[i] = str1[i];
    }
    for (j = 0; j < len2; j++) {
        str3[i+j] = str2[j];
    }
    str3[len3] = '\0';

    printf("Concatenated string is: %s\n", str3);

    // swap first and last characters of str1
    char temp = str1[0];
    str1[0] = str1[len1-1];
    str1[len1-1] = temp;

    printf("String 1 with swapped first and last characters: %s\n", str1);

    // remove all vowels from str2 and store in a new string str4
    char str4[50];
    k = 0;
    for (i = 0; i < len2; i++) {
        if (str2[i] != 'a' && str2[i] != 'e' && str2[i] != 'i' && str2[i] != 'o' && str2[i] != 'u') {
            str4[k] = str2[i];
            k++;
        }
    }
    str4[k] = '\0';

    printf("String 2 without vowels: %s\n", str4);

    // check if str1 is a palindrome
    int isPalindrome = 1;
    for (i = 0; i < len1/2; i++) {
        if (str1[i] != str1[len1-1-i]) {
            isPalindrome = 0;
            break;
        }
    }
    if(isPalindrome) {
        printf("String 1 is a palindrome!\n");
    } else {
        printf("String 1 is not a palindrome.\n");
    }

    return 0;
}