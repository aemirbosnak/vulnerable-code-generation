//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];

    // Read two strings from user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Print the length of both strings
    printf("The length of the first string '%s' is %d\n", str1, strlen(str1));
    printf("The length of the second string '%s' is %d\n", str2, strlen(str2));

    // Concatenate both strings
    strcat(str1, str2);
    printf("After concatenation, the strings become: %s\n", str1);

    // Compare both strings
    int cmp = strcmp(str1, str2);
    if(cmp == 0) {
        printf("The strings are equal\n");
    }
    else if(cmp < 0) {
        printf("The first string is smaller than the second string\n");
    }
    else {
        printf("The first string is greater than the second string\n");
    }

    // Find substring in the first string
    char substr[20];
    printf("Enter a substring to find: ");
    scanf("%s", substr);
    char *found = strstr(str1, substr);
    if(found == NULL) {
        printf("'%s' not found in the first string\n", substr);
    }
    else {
        printf("'%s' found at index %d in the first string\n", substr, found - str1);
    }

    // Replace substring in the first string with another string
    char replace[20];
    printf("Enter a substring to replace: ");
    scanf("%s", substr);
    printf("Enter the replacement string: ");
    scanf("%s", replace);
    char *replaced = strstr(str1, substr);
    if(replaced != NULL) {
        strncpy(replaced, replace, strlen(replace));
        printf("The first string after replacement is: %s\n", str1);
    }
    else {
        printf("'%s' not found in the first string\n", substr);
    }

    return 0;
}