//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

void main() {
    char str[MAX];
    int i, j;
    char ch;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    printf("\nOriginal string: %s\n", str);

    //Converting all characters to uppercase
    for(i=0; str[i]!='\0'; i++) {
        if(isalpha(str[i])) {
            ch = toupper(str[i]);
            str[i] = ch;
        }
    }

    printf("String in uppercase: %s\n", str);

    //Reversing the string
    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }

    printf("Reversed string: %s\n", str);

    //Counting the number of vowels in the string
    int count=0;
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            count++;
        }
    }

    printf("Number of vowels in the string: %d\n", count);

    //Removing all spaces from the string
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]!=' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    printf("String without spaces: %s\n", str);
}