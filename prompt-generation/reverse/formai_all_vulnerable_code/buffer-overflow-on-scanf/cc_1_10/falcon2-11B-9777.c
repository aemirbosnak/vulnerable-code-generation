//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int isSubstring(char* str1, char* str2) {
    int i, j, len1, len2;
    int isSub = 1;

    len1 = strlen(str1);
    len2 = strlen(str2);

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (str1[i] == str2[j]) {
                isSub = 1;
            } else {
                isSub = 0;
                break;
            }
        }
        if (isSub == 0) {
            break;
        }
    }

    return isSub;
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];
    int i, j, len1, len2, isSub;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (str1[i] == str2[j]) {
                isSub = 1;
            } else {
                isSub = 0;
                break;
            }
        }
        if (isSub == 0) {
            break;
        }
    }

    if (isSub == 0) {
        printf("Substring not found.\n");
    } else {
        printf("Substring found at index %d.\n", i);
    }

    return 0;
}