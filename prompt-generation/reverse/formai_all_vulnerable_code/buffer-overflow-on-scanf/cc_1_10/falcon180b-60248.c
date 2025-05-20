//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000

int main() {
    int i, j, k;
    char str1[SIZE], str2[SIZE];
    char result[SIZE];

    // Taking input strings
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Checking if the strings are equal
    if(strcmp(str1, str2) == 0) {
        printf("Strings are equal.\n");
    }
    else {
        // Calculating length of the longest common substring
        int len = 0;
        int max_len = 0;
        for(i = 0; i < strlen(str1); i++) {
            for(j = 0; j < strlen(str2); j++) {
                if(str1[i] == str2[j]) {
                    if(len == 0) {
                        len = 1;
                    }
                    else {
                        len++;
                    }
                }
                else {
                    len = 0;
                }
                if(len > max_len) {
                    max_len = len;
                }
            }
        }

        // Printing the longest common substring
        i = strlen(str1) - max_len;
        j = strlen(str2) - max_len;
        for(k = 0; k < max_len; k++) {
            result[k] = str1[i + k];
        }
        result[max_len] = '\0';
        printf("Longest common substring: %s\n", result);
    }

    return 0;
}