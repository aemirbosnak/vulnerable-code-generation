//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*function to replace all occurrences of a character in a string*/
char *replaceChar(char *str, char oldChar, char newChar) {
    int i;
    int len = strlen(str);
    /*iterate through the string*/
    for (i = 0; i < len; i++) {
        /*if a character in the string matches the oldChar, replace it with the newChar*/
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
    return str;
}

/*function to count the number of occurrences of a character in a string*/
int countChar(char *str, char ch) {
    int i;
    int count = 0;
    /*iterate through the string*/
    for (i = 0; str[i] != '\0'; i++) {
        /*if a character in the string matches the searched character, increment the count*/
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[100];
    char oldChar, newChar;
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str); /*read input including spaces*/
    printf("Enter the character you want to replace: ");
    scanf("%c", &oldChar);
    printf("Enter the new character: ");
    scanf(" %c", &newChar); /*the space before %c is to consume the newline character*/
    
    /*replace all occurrences of the oldChar with newChar in the string*/
    char *newStr = replaceChar(str, oldChar, newChar);
    printf("String after replacing '%c' with '%c': %s\n", oldChar, newChar, newStr);
    
    /*count the number of occurrences of a character*/
    printf("Enter a character: ");
    char ch;
    scanf(" %c", &ch);
    int count = countChar(str, ch);
    printf("The character '%c' appears %d times in the string.\n", ch, count);
    
    return 0;
}