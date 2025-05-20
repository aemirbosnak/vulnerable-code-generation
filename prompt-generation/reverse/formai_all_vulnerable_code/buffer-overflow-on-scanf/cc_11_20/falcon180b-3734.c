//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char string1[MAX_SIZE];
    char string2[MAX_SIZE];
    char result[MAX_SIZE];

    printf("Enter first string: ");
    scanf("%s", string1);

    printf("Enter second string: ");
    scanf("%s", string2);

    int i, j, k = 0;

    // Concatenate string1 and string2
    for(i = 0; string1[i]!= '\0'; i++) {
        result[k++] = string1[i];
    }

    for(j = 0; string2[j]!= '\0'; j++) {
        result[k++] = string2[j];
    }

    result[k] = '\0';

    printf("Concatenated string: %s\n", result);

    // Reverse string1
    for(i = strlen(string1) - 1, j = 0; i >= 0; i--, j++) {
        result[j] = string1[i];
    }

    result[j] = '\0';

    printf("Reversed string1: %s\n", result);

    // Convert string2 to uppercase
    for(i = 0; string2[i]!= '\0'; i++) {
        result[i] = toupper(string2[i]);
    }

    result[i] = '\0';

    printf("Uppercase string2: %s\n", result);

    // Remove whitespace from string1
    int len = strlen(string1);
    char temp[len];

    for(i = 0; string1[i]!= '\0'; i++) {
        if(!isspace(string1[i])) {
            temp[k++] = string1[i];
        }
    }

    temp[k] = '\0';

    printf("String1 without whitespace: %s\n", temp);

    // Count number of vowels in string2
    int count = 0;

    for(i = 0; string2[i]!= '\0'; i++) {
        if(string2[i] == 'a' || string2[i] == 'e' || string2[i] == 'i' || string2[i] == 'o' || string2[i] == 'u') {
            count++;
        }
    }

    printf("Number of vowels in string2: %d\n", count);

    return 0;
}