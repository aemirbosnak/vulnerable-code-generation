//FormAI DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], new_str[100];
    int i, j, len;
 
    printf("\nEnter a string : ");
    scanf("%s", str);
 
    len = strlen(str);

    // generate new string with reverse characters
    for (i = len - 1, j = 0; i >= 0; i--, j++){
        new_str[j] = str[i];
    }

    // add prefix and suffix to new string
    strcat(new_str, "world!");
    strcat(new_str, " ");
    strcat(new_str, "Welcome to the world of C Programming! ");

    printf("\nNew String : %s\n", new_str);

    // generate string with all uppercase characters
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;

    printf("\nUppercase String : %s\n", str);

    // reverse string without using built-in functions
    int start = 0;
    int end = len-1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    printf("\nReversed String without built-in function : %s\n", str);

    // remove all vowels from string
    for(i=j=0; i<strlen(str); i++){
        if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u' && 
            str[i]!='A' && str[i]!='E' && str[i]!='I' && str[i]!='O' && str[i]!='U'){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    printf("\nString after removing vowels : %s", str);

    return 0;
}