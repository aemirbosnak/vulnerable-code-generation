//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    char reverse[MAX_LEN];
    char upper[MAX_LEN];
    char lower[MAX_LEN];
    char *p;
    int i, j;

    // Get input string from user
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    // Remove newline character from input string
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }

    // Reverse the input string
    for (i = strlen(str)-1, j = 0; i >= 0; i--, j++) {
        reverse[j] = str[i];
    }
    reverse[j] = '\0';

    // Convert input string to uppercase
    for (i = 0; str[i]!= '\0'; i++) {
        upper[i] = toupper(str[i]);
    }
    upper[i] = '\0';

    // Convert input string to lowercase
    for (i = 0; str[i]!= '\0'; i++) {
        lower[i] = tolower(str[i]);
    }
    lower[i] = '\0';

    // Print original and manipulated strings
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reverse);
    printf("Uppercase string: %s\n", upper);
    printf("Lowercase string: %s\n", lower);

    // Remove leading and trailing whitespace from input string
    p = str;
    while (isspace(*p)) {
        p++;
    }
    strcpy(str, p);
    j = strlen(str)-1;
    while (isspace(str[j])) {
        str[j] = '\0';
        j--;
    }

    // Count number of words in input string
    p = strtok(str, " ");
    i = 0;
    while (p!= NULL) {
        i++;
        p = strtok(NULL, " ");
    }

    // Print number of words in input string
    printf("Number of words: %d\n", i);

    return 0;
}