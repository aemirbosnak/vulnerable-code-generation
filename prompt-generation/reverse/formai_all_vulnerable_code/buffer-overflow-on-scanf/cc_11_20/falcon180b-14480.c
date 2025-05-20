//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    // Declare variables
    char str1[100], str2[100], str3[200];
    int len1, len2, i, j, k;

    // Get input strings from user
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    // Calculate lengths of input strings
    len1 = strlen(str1);
    len2 = strlen(str2);

    // Concatenate strings
    strcat(str1, str2);

    // Reverse string 1
    for (i = 0, j = len1 - 1; i < j; i++, j--) {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }

    // Reverse string 2
    for (i = 0, j = len2 - 1; i < j; i++, j--) {
        char temp = str2[i];
        str2[i] = str2[j];
        str2[j] = temp;
    }

    // Concatenate reversed strings
    strcat(str1, str2);

    // Convert to uppercase
    for (i = 0; i < strlen(str1); i++) {
        str1[i] = toupper(str1[i]);
    }

    // Count number of vowels
    int count = 0;
    for (i = 0; i < strlen(str1); i++) {
        if (isalpha(str1[i])) {
            str1[i] = tolower(str1[i]);
            if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u') {
                count++;
            }
        }
    }

    // Output results
    printf("Concatenated string: %s\n", str1);
    printf("Number of vowels: %d\n", count);

    return 0;
}