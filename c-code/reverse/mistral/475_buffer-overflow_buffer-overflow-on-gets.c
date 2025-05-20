#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char str[100], search[50], replace[50];
    int len1, len2, i, j, k;

    printf("Enter the string: ");
    gets(str);

    printf("Enter the string to search: ");
    gets(search);

    printf("Enter the replacement string: ");
    gets(replace);

    len1 = strlen(str);
    len2 = strlen(search);

    for(i = 0; i < len1; i++) {
        if(i + len2 > len1) break;
        if(strncmp(&str[i], search, len2) == 0) {
            for(j = i + len2, k = i; j < len1; j++, k++) {
                if(k >= len1) str[k] = replace[j - i];
                else str[k] = str[j];
            }
            len1--;
            i -= len2;
        }
    }

    printf("Modified string: %s\n", str);

    return 0;
}
