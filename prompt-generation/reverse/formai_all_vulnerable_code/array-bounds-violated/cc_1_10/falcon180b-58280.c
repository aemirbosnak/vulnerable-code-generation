//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char str[MAX_LENGTH];
    int i, j, k, n;
    char *p;

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove leading and trailing whitespaces
    i = 0;
    while (isspace(str[i])) {
        i++;
    }
    n = strlen(str) - 1;
    while (isspace(str[n])) {
        n--;
    }
    str[n+1] = '\0';

    // Reverse the string
    char reverse[MAX_LENGTH];
    i = strlen(str) - 1;
    j = 0;
    while (i >= 0) {
        reverse[j++] = str[i--];
    }
    reverse[j] = '\0';

    // Convert to uppercase
    strcpy(str, reverse);
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    // Count number of words
    p = strtok(str, " ");
    n = 0;
    while (p!= NULL) {
        n++;
        p = strtok(NULL, " ");
    }

    // Print reversed string and number of words
    printf("Reversed string: %s\n", str);
    printf("Number of words: %d\n", n);

    return 0;
}