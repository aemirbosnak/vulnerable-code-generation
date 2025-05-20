//FormAI DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, i, j, temp;

    printf("Enter a string:\n");
    scanf("%s", str);

    len = strlen(str);

    printf("\nOriginal String: %s\n", str);

    // Reverse the string
    for(i=0, j=len-1; i<j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("\nReversed String: %s\n", str);

    // Remove all vowels
    for(i=0; i<len; i++) {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
            str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            for(j=i; j<len; j++) {
                str[j] = str[j+1];
            }
            len--;
        }
    }

    printf("\nString without vowels: %s\n", str);

    // Convert all letters to uppercase
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]>='a' && str[i]<='z') {
            str[i] = str[i] - 32;
        }
    }

    printf("\nUppercase String: %s\n", str);

    // Count number of words in string
    int count = 0;
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]==' ') {
            count++;
        }
    }

    printf("\nNumber of words in string: %d\n", count+1);

    return 0;
}