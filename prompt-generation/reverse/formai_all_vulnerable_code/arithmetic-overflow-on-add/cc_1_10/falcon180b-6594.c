//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[100], str2[100];
    int len1, len2, i, j;
    char *p;

    // take input for first string
    printf("Enter first string: ");
    gets(str1);

    // calculate length of first string
    for (i = 0; str1[i]!= '\0'; i++) {
        len1++;
    }

    // take input for second string
    printf("Enter second string: ");
    gets(str2);

    // calculate length of second string
    for (i = 0; str2[i]!= '\0'; i++) {
        len2++;
    }

    // concatenate strings
    p = (char *) malloc((len1 + len2) * sizeof(char));
    if (p == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    strcpy(p, str1);
    strcat(p, str2);

    // print concatenated string
    printf("Concatenated string: %s\n", p);

    // reverse string
    for (i = 0; i < len1 + len2 - 1; i++) {
        for (j = 0; j < len1 + len2 - 1 - i; j++) {
            if (tolower(p[j]) > tolower(p[j + 1])) {
                char temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // print reversed string
    printf("Reversed string: %s\n", p);

    // remove whitespace from string
    for (i = 0; i < len1 + len2 - 1; i++) {
        if (!isspace(p[i])) {
            strcpy(str1, p + i);
            break;
        }
    }

    // print string without whitespace
    printf("String without whitespace: %s\n", str1);

    // convert string to uppercase
    for (i = 0; str1[i]!= '\0'; i++) {
        str1[i] = toupper(str1[i]);
    }

    // print converted string
    printf("Converted string: %s\n", str1);

    return 0;
}