//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: mathematical
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[100];
    char morse[100];
    int i, j, k, n;
    char letter[26];
    
    printf("Enter a text to convert to Morse code: ");
    scanf("%s", text);
    
    // Calculate the frequency of each letter in the text
    for (i = 0; i < strlen(text); i++) {
        letter[i] = toupper(text[i]); // Convert to uppercase
        n = letter[i] - 'A'; // Get the ASCII value of the letter
        if (n < 0 || n > 25) { // Check if the letter is within the range of the alphabet
            continue;
        }
        k = 0;
        while (text[i]!= '\0') {
            if (text[i] == letter[k]) {
                k++;
            }
            i++;
        }
        letter[i] = '\0'; // Terminate the string
    }
    
    // Convert each letter to Morse code
    for (i = 0; i < strlen(letter); i++) {
        j = 0;
        k = 0;
        while (letter[i]!= '\0') {
            if (letter[i] == 'A') { // Dot
                morse[j++] = '.';
            } else if (letter[i] == 'B') { // Dash
                morse[j++] = '-';
            }
            i++;
        }
        morse[j] = '\0'; // Terminate the string
    }
    
    // Print the Morse code
    printf("Morse code for the text: %s\n", morse);
    
    return 0;
}