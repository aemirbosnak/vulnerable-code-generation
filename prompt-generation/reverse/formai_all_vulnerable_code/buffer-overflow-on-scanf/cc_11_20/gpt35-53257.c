//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int length;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    length = strlen(str1);

    // concatenate two strings without using strcpy
    for(int i=0; i<strlen(str2); i++) {
        str1[length+i] = str2[i];
    }

    printf("Concatenated string: %s\n", str1);

    // reverse the concatenated string
    char temp;
    for(int i=0; i<(length+strlen(str2))/2; i++) {
        temp = str1[i];
        str1[i] = str1[length+strlen(str2)-i-1];
        str1[length+strlen(str2)-i-1] = temp;
    }

    printf("Reversed string: %s\n", str1);

    // convert concatenated string to uppercase
    for(int i=0; i<length+strlen(str2); i++) {
        if(str1[i]>=97 && str1[i]<=122) {
            str1[i] = str1[i]-32;
        }
    }

    printf("Uppercased string: %s\n", str1);

    // remove vowels from the concatenated string
    for(int i=0; i<length+strlen(str2); i++) {
        if(str1[i]=='a' || str1[i]=='e' || str1[i]=='i' || str1[i]=='o' || str1[i]=='u' || str1[i]=='A' || str1[i]=='E' || str1[i]=='I' || str1[i]=='O' || str1[i]=='U') {
            for(int j=i; j<length+strlen(str2)-1; j++) {
                str1[j] = str1[j+1];
            }
            str1[length+strlen(str2)-1] = '\0';
            length--;
        }
    }

    printf("Final string after removing vowels: %s\n", str1);

    return 0;
}