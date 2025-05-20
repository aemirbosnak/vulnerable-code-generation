//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int len, i, j;
    int count = 0;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    len = strlen(input);

    // Remove leading and trailing spaces
    if (isspace(input[0])) {
        strcpy(output, &input[1]);
    } else {
        strcpy(output, input);
    }
    if (isspace(output[len - 1])) {
        output[len - 1] = '\0';
    }

    // Remove consecutive spaces
    j = 0;
    for (i = 0; i < len; i++) {
        if (!isspace(output[i])) {
            output[j++] = output[i];
        }
    }
    output[j] = '\0';
    len = strlen(output);

    // Reverse the string
    for (i = 0; i < len / 2; i++) {
        char temp = output[i];
        output[i] = output[len - i - 1];
        output[len - i - 1] = temp;
    }

    // Count the number of vowels
    for (i = 0; i < len; i++) {
        if (tolower(output[i]) == 'a' || tolower(output[i]) == 'e' || tolower(output[i]) == 'i' || tolower(output[i]) == 'o' || tolower(output[i]) == 'u') {
            count++;
        }
    }

    // Print the modified string and the number of vowels
    printf("Modified string: %s\n", output);
    printf("Number of vowels: %d\n", count);

    return 0;
}