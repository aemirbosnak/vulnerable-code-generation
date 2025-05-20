//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char *p;
    int i, j, k, length;

    printf("Enter a string: ");
    scanf("%s", input);

    length = strlen(input);

    // Remove leading and trailing whitespace
    for (i = 0; i < length; i++) {
        if (!isspace(input[i])) {
            input[i] = toupper(input[i]);
            break;
        }
    }
    for (j = length - 1; j >= 0; j--) {
        if (!isspace(input[j])) {
            input[j] = toupper(input[j]);
            break;
        }
    }

    // Reverse the string
    p = input;
    k = 0;
    while (*p) {
        output[k++] = *p++;
    }
    output[k] = '\0';
    strcpy(input, output);

    // Convert string to title case
    p = input;
    k = 0;
    while (*p) {
        if (isalpha(*p)) {
            if (k == 0) {
                output[k++] = toupper(*p);
            } else if (k > 0 &&!isalpha(output[k - 1])) {
                output[k++] = toupper(*p);
            } else {
                output[k++] = tolower(*p);
            }
        } else {
            output[k++] = *p;
        }
        p++;
    }
    output[k] = '\0';
    strcpy(input, output);

    // Remove all vowels
    p = input;
    k = 0;
    while (*p) {
        if (*p!= 'a' && *p!= 'e' && *p!= 'i' && *p!= 'o' && *p!= 'u' && *p!= 'A' && *p!= 'E' && *p!= 'I' && *p!= 'O' && *p!= 'U') {
            output[k++] = *p;
        }
        p++;
    }
    output[k] = '\0';
    strcpy(input, output);

    // Remove all non-alphabetic characters
    p = input;
    k = 0;
    while (*p) {
        if (isalpha(*p)) {
            output[k++] = *p;
        }
        p++;
    }
    output[k] = '\0';
    strcpy(input, output);

    printf("Modified string: %s\n", input);

    return 0;
}