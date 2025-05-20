//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: statistical
#include <stdio.h>
#include <string.h>

// Define Morse code symbols for all English alphabet letters, numbers and special characters
const char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.",
    "-.--.-", ".-...", "---...", "-.-.-.", "-...-", "..--.-", ".-.-.", "-....-", ".--.-."
};

// Function to convert input string to Morse code
void convertToMorse(char input[], char morseOutput[]) {
    int len = strlen(input);
    int i, j;
    // Loop through all characters in input string
    for (i = 0; i < len; i++) {
        char tmp = input[i];
        // Check if character is upper-case letter
        if (tmp >= 'A' && tmp <= 'Z') {
            j = tmp - 'A';
            strncpy(morseOutput + strlen(morseOutput), morse[j], strlen(morse[j]));
        }
        // Check if character is lower-case letter
        else if (tmp >= 'a' && tmp <= 'z') {
            j = tmp - 'a';
            strncpy(morseOutput + strlen(morseOutput), morse[j], strlen(morse[j]));
        }
        // Check if character is number
        else if (tmp >= '0' && tmp <= '9') {
            j = tmp - '0' + 26;
            strncpy(morseOutput + strlen(morseOutput), morse[j], strlen(morse[j]));
        }
        // Check if character is special character
        else if (tmp == ' ' || tmp == '\n' || tmp == '\t' || tmp == ',' || tmp == '.' || tmp == '?' || tmp == '\'' || tmp == '!' || tmp == '/' || tmp == '(' || tmp == ')' || tmp == '&' || tmp == ':' || tmp == ';' || tmp == '=' || tmp == '+' || tmp == '-' || tmp == '_' || tmp == '"' || tmp == '$' || tmp == '@') {
            j = tmp - ' ' + 36;
            strncpy(morseOutput + strlen(morseOutput), morse[j], strlen(morse[j]));
        }
        // If character is not recognized, add a question mark to Morse output
        else {
            strncpy(morseOutput + strlen(morseOutput), "?", 1);
        }
        // Add space after each Morse code symbol
        strncpy(morseOutput + strlen(morseOutput), " ", 1);
    }
}

int main() {
    char input[100], morseOutput[1000];
    printf("Enter text to convert to Morse code:\n");
    fgets(input, 100, stdin);
    convertToMorse(input, morseOutput);
    printf("Morse code output:\n%s\n", morseOutput);
    return 0;
}