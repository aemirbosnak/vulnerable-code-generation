//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    // Get input from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Check if strings are equal
    if (strcmp(str1, str2) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    // Reverse the first string
    char *p = str1;
    char *q = str1 + strlen(str1) - 1;
    while (p < q) {
        char temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
    printf("The reversed string is: %s\n", str1);

    // Convert the second string to uppercase
    strcpy(str2, toupper(str2));
    printf("The uppercase string is: %s\n", str2);

    // Count the number of vowels in the first string
    int count = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (isalpha(str1[i])) {
            if (tolower(str1[i]) == 'a' || tolower(str1[i]) == 'e' || tolower(str1[i]) == 'i' || tolower(str1[i]) == 'o' || tolower(str1[i]) == 'u') {
                count++;
            }
        }
    }
    printf("The number of vowels in the string is: %d\n", count);

    // Concatenate the two strings
    strcat(str1, " ");
    strcat(str1, str2);
    printf("The concatenated string is: %s\n", str1);

    return 0;
}