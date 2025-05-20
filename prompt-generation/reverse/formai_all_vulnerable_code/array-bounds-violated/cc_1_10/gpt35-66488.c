//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants for calculation of the Alien Language phrases */
#define BASE 10
#define MAX_LENGTH 100

/* Array containing the vocabulary of the Alien Language */
char alien_language[BASE][MAX_LENGTH] = {"zero", "one", "two", "three", "four", 
                                         "five", "six", "seven", "eight", "nine"};

/* Function to translate a given Alien Language phrase into a decimal number */
int convert_to_decimal(char *alien_phrase) {
    int length = strlen(alien_phrase); // Length of the Alien Language phrase
    int i, j, k, num, power, decimal_val, count = 0;
    char substr[MAX_LENGTH];
    
    decimal_val = 0;
    for(i = 0; i < length; i++) {
        /* Check if we have reached a delimiter or end of input */
        if(alien_phrase[i] == ' ' || i == length-1) {
            if(i == length-1) substr[count++] = alien_phrase[i]; // Special case for last word
            substr[count] = '\0'; // Null terminate the substring
            count = 0; // Reset counter for next substring
            
            /* Compare each substring with the Alien Language vocabulary */
            for(j = 0; j < BASE; j++) {
                if(strcmp(substr, alien_language[j]) == 0) {
                    /* Calculate the equivalent decimal value of the substring */
                    num = j;
                    power = 1;
                    for(k = 0; k < strlen(substr)-1; k++) power *= BASE;
                    decimal_val += num * power;
                    break;
                }
            }
        }
        else substr[count++] = alien_phrase[i]; // Build up the substring
    }
    return decimal_val;
}

/* Function to translate a given decimal number into the Alien Language */
void convert_to_alien(int decimal_val) {
    char alien_phrase[MAX_LENGTH], temp[MAX_LENGTH];
    int i = 0, j, remainder;
    while(decimal_val > 0) {
        remainder = decimal_val % BASE;
        strcpy(temp, alien_language[remainder]);
        j = strlen(temp) - 1;
        while(j >= 0) alien_phrase[i++] = temp[j--];
        alien_phrase[i++] = ' ';
        decimal_val /= BASE;
    }
    alien_phrase[i-1] = '\0'; // Null terminate the final Alien Language phrase
    /* Reverse the order of the characters in the phrase */
    int length = strlen(alien_phrase);
    char reversed[length];
    for(i = 0, j = length-1; i < length; i++, j--) reversed[i] = alien_phrase[j];
    reversed[length] = '\0';
    printf("%s\n", reversed);
}

/* Main function for running the Alien Language Translator program */
int main() {
    char alien_phrase[MAX_LENGTH];
    int decimal_val;
    printf("Enter an Alien Language phrase: ");
    fgets(alien_phrase, MAX_LENGTH, stdin);
    /* Remove newline character from input */
    if((strlen(alien_phrase) > 0) && (alien_phrase[strlen(alien_phrase)-1] == '\n')) 
        alien_phrase[strlen(alien_phrase)-1] = '\0';
    decimal_val = convert_to_decimal(alien_phrase);
    printf("Decimal Value: %d\n", decimal_val);
    printf("Alien Language Translation: ");
    convert_to_alien(decimal_val);
    return 0;
}