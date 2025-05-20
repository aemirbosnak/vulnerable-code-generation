//FormAI DATASET v1.0 Category: String manipulation ; Style: careful
#include<stdio.h>
#include<string.h>

int main(){

    char str1[20];
    char str2[20];

    printf("Enter the first string: ");
    scanf("%s",str1);
    printf("Enter the second string: ");
    scanf("%s",str2);

    int len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);

    //Concatenation of Strings
    char str3[30];
    int i,j;
    for (i = 0; i < len1; i++) {
        str3[i] = str1[i];
    }
    for (j = 0; j < len2; j++) {
        str3[i+j] = str2[j];
    }
    str3[i+j] = '\0';
    printf("\nConcatenated String: %s\n", str3);

    //Comparison of Strings
    int res = strcmp(str1, str2);
    if (res == 0) {
        printf("The two strings are equal.\n");
    }
    else {
        printf("The two strings are not equal.\n");
    }

    //Copying Strings
    char str4[20];
    strcpy(str4, str1);
    printf("Copied String: %s\n", str4);

    //Reversing a String
    char revstr[20];
    for (i = len1-1; i >= 0; i--) {
        revstr[len1-1-i] = str1[i];
    }
    revstr[len1] = '\0';
    printf("Reversed String: %s\n", revstr);

    //Finding Substring
    char substr[6];
    printf("Enter a substring to search in string 1: ");
    scanf("%s", substr);
    char *ptr = strstr(str1,substr);
    if (ptr != NULL) {
        printf("Substring found at index %d.\n",ptr-str1);
    }
    else {
        printf("Substring not found.\n");
    }

    return 0;
}