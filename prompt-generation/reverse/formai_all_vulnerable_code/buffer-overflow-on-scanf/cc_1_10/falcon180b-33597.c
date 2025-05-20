//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char input_string[MAX_SIZE];
    char reversed_string[MAX_SIZE];
    char *substr_start, *substr_end;
    int substr_length;
    int i, j;

    printf("Enter a string: ");
    fgets(input_string, MAX_SIZE, stdin);

    printf("Original string: %s\n", input_string);

    // Reverse the string
    for (i = strlen(input_string) - 1, j = 0; i >= 0; i--, j++) {
        reversed_string[j] = input_string[i];
    }
    reversed_string[j] = '\0';

    printf("Reversed string: %s\n", reversed_string);

    // Extract a substring
    printf("Enter the starting index of the substring: ");
    scanf("%d", &i);
    printf("Enter the ending index of the substring: ");
    scanf("%d", &j);

    substr_length = j - i + 1;
    substr_start = &input_string[i];
    substr_end = &input_string[j];

    printf("Substring: %s\n", substr_start);

    // Replace a substring
    printf("Enter the substring to replace: ");
    scanf("%s", input_string);
    printf("Enter the replacement substring: ");
    scanf("%s", input_string);

    for (i = 0; input_string[i]!= '\0'; i++) {
        if (input_string[i] == *substr_start) {
            strcat(input_string, input_string + i + 1);
            break;
        }
    }

    printf("Modified string: %s\n", input_string);

    return 0;
}