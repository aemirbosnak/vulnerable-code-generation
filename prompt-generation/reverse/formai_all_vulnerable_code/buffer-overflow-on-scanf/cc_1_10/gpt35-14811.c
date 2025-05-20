//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <string.h>

void convertToMorseCode(char* message){
    // Creating an array of Morse code for each character
    char* morse_codes[] = {".-", "-...", "-.-.", "-..", 
                          ".", "..-.", "--.", "....", 
                          "..", ".---", "-.-", ".-..", 
                          "--", "-.", "---", ".--.", 
                          "--.-", ".-.", "...", "-", 
                          "..-", "...-", ".--", "-..-", 
                          "-.--", "--..", ".----", "..---", 
                          "...--", "....-", ".....", "-....", 
                          "--...", "---..", "----.", "-----",
                          "/", " "}; // Adding support for forward slash and space
    
    // Creating an array of characters to compare them to their Morse code
    char characters[] = {'A', 'B', 'C', 'D', 
                         'E', 'F', 'G', 'H', 
                         'I', 'J', 'K', 'L', 
                         'M', 'N', 'O', 'P', 
                         'Q', 'R', 'S', 'T', 
                         'U', 'V', 'W', 'X', 
                         'Y', 'Z', '1', '2', 
                         '3', '4', '5', '6', 
                         '7', '8', '9', '0',
                         '/', ' '}; // Adding support for forward slash and space
    
    printf("The Morse code for your message is: \n");
    
    for(int i = 0; i < strlen(message); i++){
        // Converting the character to uppercase, to match the array of characters
        char currentChar = toupper(message[i]);
        
        // Searching for the current character in the array of characters
        for(int j = 0; j < sizeof(characters); j++){
            if(currentChar == characters[j]){
                printf("%s ", morse_codes[j]); // Printing the corresponding Morse code character
                break; // Break out of the loop once the Morse code is found
            }
        }
    }
    printf("\n");
}
 
int main(){
    char message[100];
    printf("Enter your message to be converted to Morse code (numbers and letters only):\n");
    scanf("%s", message);
    convertToMorseCode(message);
    return 0;
}