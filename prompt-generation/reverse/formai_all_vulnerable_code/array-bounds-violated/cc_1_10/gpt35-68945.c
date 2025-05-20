//FormAI DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50], result[100];

    printf("Enter first string: ");
    fgets(str1, 50, stdin);
    printf("Enter second string: ");
    fgets(str2, 50, stdin);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (str1[len1-1] == '\n')
        str1[len1-1] = '\0';

    if (str2[len2-1] == '\n')
        str2[len2-1] = '\0';

    int i, j;
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }

    for (j = 0; str2[j] != '\0'; j++) {
        result[i++] = str2[j];
    }
    result[i] = '\0';

    printf("Combined string: %s\n", result);

    char sub[50];
    printf("Enter substring to search: ");
    fgets(sub, 50, stdin);

    int count = 0;
    int sublen = strlen(sub);

    for (i = 0; result[i+sublen-1] != '\0'; i++) {
        int match = 1;
        for (j = 0; j < sublen; j++) {
            if (result[i+j] != sub[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            count++;
        }
    }

    printf("Number of occurrences of substring: %d\n", count);

    return 0;
}