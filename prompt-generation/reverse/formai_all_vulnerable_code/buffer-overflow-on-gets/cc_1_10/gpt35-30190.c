//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include<stdio.h>
#include<string.h>

// Function to convert the entered text to Morse code
void convertToMorse(char text[]) {
    int i; // Iterator
    
    // Array of Morse code for English alphabet
    char* morseCode[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
        "-.--", "--.."
    };
    
    // Array of Morse code for English numerals
    char* morseCodeNumber[] = {
        "-----", ".----", "..---", "...--", "....-", ".....", 
        "-....", "--...", "---..", "----."
    };
    
    // Array of Morse code for punctuations and special characters
    char* morseCodeSpecial[] = {
        ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", 
        "-..-.", "---...", "-.-.-.", "-....-", "-.--.", 
        "-.--.-", ".-..-.", ".--.-.", "-...-", "..--.-", 
        ".-.-.", "...-..-", ".--..-", ".-..-.", "...-.-", 
        "-...-", ".--.-.-.-", "..--.-.-", "-.-..-", "--.-.-.-"
    };
    
    printf("\nMorse Code: ");
    
    // Iterator to iterate through each character of entered text
    for(i = 0; i < strlen(text); i++) {
        
        if(text[i] == ' ') { // For space
            printf(" ");
            continue;
        }
        
        if(text[i] >= 'A' && text[i] <= 'Z') { // For uppercase letters
            printf("%s ", morseCode[text[i] - 'A']);
        }
        else if(text[i] >= 'a' && text[i] <= 'z') { // For lowercase letters
            printf("%s ", morseCode[text[i] - 'a']);
        }
        else if(text[i] >= '0' && text[i] <= '9') { // For numerals
            printf("%s ", morseCodeNumber[text[i] - '0']);
        }
        else { // For special characters and punctuations
            printf("%s ", morseCodeSpecial[text[i]]);
        }
    }
    
    printf("\n");
}

int main() {
    char text[100]; // To store the entered text
    
    printf("Enter the text: ");
    gets(text); // To get the text from user
    
    convertToMorse(text); // Function to convert the text to Morse code
    
    return 0; // Return statement
}