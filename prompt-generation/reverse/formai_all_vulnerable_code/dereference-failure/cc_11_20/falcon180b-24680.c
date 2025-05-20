//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Example 1: Reverse a string
    char str[100] = "Hello, world!";
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    printf("Reversed string: %s\n", str);

    // Example 2: Convert a string to uppercase
    char str2[100] = "Hello, world!";
    int len = strlen(str2);
    for (int i = 0; i < len; i++) {
        str2[i] = toupper(str2[i]);
    }
    printf("Uppercase string: %s\n", str2);

    // Example 3: Convert a string to lowercase
    char str3[100] = "Hello, world!";
    int len3 = strlen(str3);
    for (int i = 0; i < len3; i++) {
        str3[i] = tolower(str3[i]);
    }
    printf("Lowercase string: %s\n", str3);

    // Example 4: Count the number of vowels in a string
    char str4[100] = "Hello, world!";
    int count = 0;
    for (int i = 0; i < strlen(str4); i++) {
        if (str4[i] == 'a' || str4[i] == 'e' || str4[i] == 'i' || str4[i] == 'o' || str4[i] == 'u') {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);

    // Example 5: Remove all whitespace characters from a string
    char str5[100] = "  Hello,  world!  ";
    int len5 = strlen(str5);
    char str6[100] = "";
    for (int i = 0; i < len5; i++) {
        if (!isspace(str5[i])) {
            strcat(str6, &str5[i]);
        }
    }
    printf("String without whitespace: %s\n", str6);

    return 0;
}