//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <string.h>

// function to count the number of occurrences of a character in a string
int count_char(char str[], char ch) {
    int count = 0;
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    
    // removing the new line character from the input string
    if(input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0'; 
    }
    
    printf("The input string is: %s\n", input);
    
    // counting the number of vowels in the input string
    int vowels_count = 0;
    vowels_count += count_char(input, 'a');
    vowels_count += count_char(input, 'e');
    vowels_count += count_char(input, 'i');
    vowels_count += count_char(input, 'o');
    vowels_count += count_char(input, 'u');
    
    printf("Number of vowels in the input string: %d\n", vowels_count);
    
    // counting the number of consonants in the input string
    int consonants_count = 0;
    for(int i=0; i<strlen(input); i++) {
        char ch = input[i];
        if(ch >= 'a' && ch <= 'z' && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            consonants_count++;
        }
    }
    
    printf("Number of consonants in the input string: %d\n", consonants_count);
    
    // reversing the input string
    char reversed_str[strlen(input)];
    for(int i=strlen(input)-1, j=0; i>=0; i--, j++) {
        reversed_str[j] = input[i];
    }
    reversed_str[strlen(input)] = '\0';

    printf("The reversed string is: %s\n", reversed_str);
    
    return 0;
}