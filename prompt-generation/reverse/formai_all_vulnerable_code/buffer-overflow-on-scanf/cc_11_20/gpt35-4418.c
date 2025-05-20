//FormAI DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char name[100], copyName[100], reversedName[100];

    printf("Enter your name: ");
    scanf("%s", name);

    // Copying the name to a new variable
    strcpy(copyName, name);

    // Reversing the name
    int i, j;
    for(i = 0, j = strlen(name) - 1; i < strlen(name); i++, j--) {
        reversedName[i] = name[j];
    }
    reversedName[i] = '\0';

    // Printing the original, copied, and reversed name
    printf("\nOriginal name: %s\n", name);
    printf("Copied name: %s\n", copyName);
    printf("Reversed name: %s\n", reversedName);

    // Checking if the name is a palindrome or not
    int palindrome = 1;
    for(i = 0; i < strlen(name); i++) {
        if(name[i] != reversedName[i]) {
            palindrome = 0;
            break;
        }
    }

    if(palindrome) {
        printf("\nThe name is a palindrome!\n");
    } else {
        printf("\nThe name is not a palindrome :(\n");
    }

    // Converting the name to uppercase
    for(i = 0; i < strlen(name); i++) {
        name[i] = toupper(name[i]);
    }

    printf("\nName in uppercase: %s\n", name);

    // Counting the number of vowels and consonants in the name
    int vowels = 0, consonants = 0;
    for(i = 0; i < strlen(name); i++) {
        if(name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U') {
            vowels++;
        } else {
            consonants++;
        }
    }

    printf("\nNumber of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}