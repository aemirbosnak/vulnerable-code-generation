//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin); // read input string from user

    printf("Original string: %s\n", str); // print original string

    // remove leading and trailing spaces
    while (isspace(str[0])) {
        strcpy(str, str + 1);
    }
    while (isspace(str[strlen(str) - 1])) {
        str[strlen(str) - 1] = '\0';
    }

    printf("String without leading/trailing spaces: %s\n", str);

    // reverse the string
    char rev_str[MAX_LEN];
    strcpy(rev_str, str);
    int len = strlen(rev_str);
    for (int i = 0; i < len / 2; i++) {
        char temp = rev_str[i];
        rev_str[i] = rev_str[len - i - 1];
        rev_str[len - i - 1] = temp;
    }

    printf("Reversed string: %s\n", rev_str);

    // convert all characters to uppercase
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }

    printf("String in uppercase: %s\n", str);

    // convert all characters to lowercase
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }

    printf("String in lowercase: %s\n", str);

    return 0;
}