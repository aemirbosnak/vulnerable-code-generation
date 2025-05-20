//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <string.h>

// function to print a character n times recursively
void print_char(char c, int n) {
    if(n > 0) {
        putchar(c);
        print_char(c, n-1);
    }
}

// function to replace characters in a string recursively
void replace_char(char* str, char from, char to) {
    if(*str == '\0') {  // base case
        return;
    }
    if(*str == from) {  // recursively replace each occurrence
        *str = to;
    }
    replace_char(str+1, from, to);
}

int main() {
    char str[50];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // print the string in reverse recursively
    printf("Reverse string: ");
    for(int i=strlen(str)-2; i>=0; i--) {  // exclude the newline character
        putchar(str[i]);
    }
    printf("\n");

    // print each character twice recursively
    printf("Double characters: ");
    for(int i=0; i<strlen(str); i++) {
        print_char(str[i], 2);
    }
    printf("\n");

    // replace characters in the string recursively
    char from, to;
    printf("Replace a character in the string: ");
    scanf("%c", &from);
    printf("Replace %c with: ", from);
    scanf(" %c", &to);  // include a space before %c to ignore whitespace
    replace_char(str, from, to);
    printf("Modified string: %s", str);

    return 0;
}