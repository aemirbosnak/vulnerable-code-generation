//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char myString[100];
    int i, j, n;
    
    printf("\nEnter a string: ");
    scanf("%[^\n]s", myString);
    getchar();
    
    printf("\nOriginal String: %s", myString);
    
    // converting string to uppercase
    printf("\nUppercase string: ");
    for(i = 0; myString[i] != '\0'; i++) {
        if(myString[i] >= 'a' && myString[i] <= 'z') {
            printf("%c", myString[i] - 32);
        }
        else {
            printf("%c", myString[i]);
        }
    }
    
    // converting string to lowercase
    printf("\nLowercase string: ");
    for(i = 0; myString[i] != '\0'; i++) {
        if(myString[i] >= 'A' && myString[i] <= 'Z') {
            printf("%c", myString[i] + 32);
        }
        else {
            printf("%c", myString[i]);
        }
    }
    
    // reversing the string
    n = strlen(myString);
    printf("\nReversed string: ");
    for(i = n-1; i >= 0; i--) {
        printf("%c", myString[i]);
    }
    
    // counting vowels, consonants and digits in the string
    int vowels = 0, consonants = 0, digits = 0;
    for(i = 0; myString[i] != '\0'; i++) {
        if((myString[i] >= 'a' && myString[i] <= 'z') || (myString[i] >= 'A' && myString[i] <= 'Z')) {
            if(myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' || myString[i] == 'o' || myString[i] == 'u' || myString[i] == 'A' || myString[i] == 'E' || myString[i] == 'I' || myString[i] == 'O' || myString[i] == 'U') {
                vowels++;
            }
            else {
                consonants++;
            }
        }
        else if(myString[i] >= '0' && myString[i] <= '9') {
            digits++;
        }
    }
    
    printf("\n\nVowels: %d", vowels);
    printf("\nConsonants: %d", consonants);
    printf("\nDigits: %d", digits);
    
    // removing all the spaces in the string
    for(i = 0; myString[i] != '\0'; i++) {
        if(myString[i] != ' ') {
            myString[j] = myString[i];
            j++;
        }
    }
    myString[j] = '\0';
    
    printf("\n\nString without spaces: %s", myString);
    
    // removing a particular character from the string
    printf("\nEnter the character to be removed from the string: ");
    char c;
    scanf("%c", &c);
    
    for(i = 0; myString[i] != '\0'; i++) {
        if(myString[i] == c) {
            for(j = i; myString[j] != '\0'; j++) {
                myString[j] = myString[j + 1];
            }
            i--;
        }
    }
    
    printf("\nString after removing %c: %s", c, myString);
    
    return 0;
}