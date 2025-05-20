//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Hey there! Enter a word or phrase: ");
    scanf("%s", str);
    int len = strlen(str);

    // Convert to uppercase
    for(int i=0; i<len; i++) {
        str[i] = toupper(str[i]);
    }

    printf("Transformed to uppercase: %s\n", str);

    // Convert to lowercase
    for(int i=0; i<len; i++) {
        str[i] = tolower(str[i]);
    }

    printf("Transformed to lowercase: %s\n", str);

    // Reverse the string
    int start = 0;
    int end = len - 1;
    char temp;
    while(start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    printf("Reversed string: %s\n", str);

    // Check if it's a palindrome
    int is_palindrome = 1;
    for(int i=0; i<len/2; i++) {
        if(str[i] != str[len-i-1]) {
            is_palindrome = 0;
            break;
        }
    }

    if(is_palindrome) {
        printf("This is a palindrome!\n");
    } else {
        printf("This is not a palindrome :(\n");
    }

    return 0;
}