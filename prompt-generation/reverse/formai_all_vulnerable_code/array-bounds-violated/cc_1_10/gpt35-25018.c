//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void morse_code_conversion(char *str);

int main(){
    // User input
    char str[100];
    printf("Enter a phrase to convert to Morse Code:\n");
    scanf("%[^\n]", str);
    morse_code_conversion(str); // Morse code conversion function call
    return 0;
}

void morse_code_conversion(char *str){
    // Morse code array
    char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    // Converting the string to uppercase
    for(int i=0; str[i]; i++){
        str[i] = toupper(str[i]);
    }
    
    // Printing the morse code of each character
    printf("\nMorse Code Conversion:\n");
    for(int i=0; i<strlen(str); i++){
        if(str[i] == ' '){
            printf(" / ");
        }
        else if(isalpha(str[i])){
            printf("%s ", morse[str[i] - 'A']);
        }
        else{
            printf("%c ", str[i]);
        }
    }
    printf("\n");
    
    // Puzzle code
    printf("\nYou have stumbled upon a secret code, can you solve it?\n");
    printf("Find the position of the dot in the first character's Morse code, then multiply it by 2.\n");
    printf("Add the position of the dash in the sixth character's Morse code after skipping two spaces, then subtract 1.\n");
    printf("Take the result and use it as the input of the function.\n");
    
    // Puzzle solution
    int result = (morse[str[0] - 'A'][0] - '.') * 2 + (morse[str[5] - 'A'][2] - '-') - 1;
    printf("\nWhat is the result of the puzzle? ");
    int guess;
    scanf("%d", &guess);
    if(guess == result){
        printf("\nCongratulations! You have solved the puzzle.\n");
    }
    else{
        printf("\nOops, wrong answer. Better luck next time.\n");
    }
}