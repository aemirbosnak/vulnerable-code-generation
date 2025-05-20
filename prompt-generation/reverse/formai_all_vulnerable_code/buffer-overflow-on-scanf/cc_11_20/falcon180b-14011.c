//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main() {
    char str[MAX];
    char rev[MAX];
    char upper[MAX];
    char lower[MAX];
    char *p;
    int len, i;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    // Reverse the string
    for (i = 0; i < len; i++) {
        rev[i] = str[len - 1 - i];
    }
    rev[len] = '\0';
    printf("Reversed string: %s\n", rev);

    // Convert to uppercase
    for (i = 0; i < len; i++) {
        upper[i] = toupper(str[i]);
    }
    upper[len] = '\0';
    printf("Uppercase string: %s\n", upper);

    // Convert to lowercase
    for (i = 0; i < len; i++) {
        lower[i] = tolower(str[i]);
    }
    lower[len] = '\0';
    printf("Lowercase string: %s\n", lower);

    // Remove all whitespace characters
    p = strtok(str, " ");
    while (p!= NULL) {
        printf("%s ", p);
        p = strtok(NULL, " ");
    }
    printf("\n");

    // Count the number of vowels
    int count = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);

    return 0;
}