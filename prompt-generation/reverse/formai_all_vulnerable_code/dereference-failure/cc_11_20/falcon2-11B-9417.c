//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[strlen(str1) + strlen(str2) + 1];

    strcpy(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);

    printf("Original String: %s\n", str3);

    // Reverse the string
    char* revStr = str3;
    char temp;

    while ((revStr - str3) > 0) {
        temp = *revStr;
        *revStr = *revStr + 1;
        *revStr += 1;
        *revStr -= 1;
        *revStr = temp;
        revStr--;
    }

    printf("Reversed String: %s\n", revStr);

    // Find the length of the string
    int len = strlen(str3);
    printf("Length of the String: %d\n", len);

    // Convert the string to uppercase
    for (int i = 0; i < len; i++) {
        if (str3[i] >= 'a' && str3[i] <= 'z') {
            str3[i] -= 32;
        }
    }

    printf("Uppercase String: %s\n", str3);

    // Count the number of vowels in the string
    int vowelCount = 0;
    for (int i = 0; i < len; i++) {
        if (str3[i] == 'a' || str3[i] == 'e' || str3[i] == 'i' || str3[i] == 'o' || str3[i] == 'u') {
            vowelCount++;
        }
    }

    printf("Number of Vowels: %d\n", vowelCount);

    return 0;
}