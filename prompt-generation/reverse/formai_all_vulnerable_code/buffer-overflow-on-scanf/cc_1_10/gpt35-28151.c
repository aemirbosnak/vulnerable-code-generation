//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
   
    char str1[50];
    char str2[50];
    char str3[50];

    printf("Enter the string 1:\n");
    scanf("%s", str1);
    
    printf("Enter the string 2:\n");
    scanf("%s", str2);

    strcpy(str3, str1);

    printf("\n string 1 is: %s", str1);
    printf("\n string 2 is: %s", str2);
    printf("\n string 3 is: %s (a copy of string 1)\n", str3);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("\n Length of string 1 is: %d", len1);
    printf("\n Length of string 2 is: %d\n", len2);

    // concatenate
    strcat(str1, str2);

    printf("\n String 1 after concatenation of string 1 and 2: %s\n", str1);
   
    // reverse string 2
    int n = strlen(str2);
    for (int i = 0; i < n / 2; i++) {
        char tmp = str2[i];
        str2[i] = str2[n - i - 1];
        str2[n - i - 1] = tmp;
    }

    printf("\n String 2 after reversal: %s\n", str2);

    // compare two strings
    int cmp = strcmp(str1, str3);
    if (cmp == 0) {
        printf("\n String 1 and 3 are equal\n");
    } else {
        printf("\n String 1 and 3 are not equal\n");
    }

    // modify string 1 by removing vowels
    int vowel_count = 0;
    for (int i = 0; i < strlen(str1); i++) {
        switch (str1[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel_count++;
                break;
            default:
                str1[i - vowel_count] = str1[i];
                break;
        }
    }
    str1[strlen(str1) - vowel_count] = '\0';

    printf("\n String 1 after removal of vowels: %s\n", str1);

    return 0;
}