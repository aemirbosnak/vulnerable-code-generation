//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
    char alienLang[26] = ".-,-...,-.-.,-..,.,..-.,--.,....,..,.---,-.-,.-..,--,.,-.,---,.--.,--.-,.-.,...,...-,..-,..-,-..-,-.--,--.."; // Alien language string
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // English alphabet
    char message[100]; // User's message
    char translated[100]; // Translated message
    int i, j, k, m; // Loop counters
    int len; // Length of message
    
    printf("Enter message to translate in Alien language: ");
    fgets(message, 100, stdin); // Reads user input from console
    
    len = strlen(message); // Gets the length of the message
    
    // Loops through each character in the message
    for (i = 0; i < len; i++) {
        if (message[i] == ' ') { // Handles spaces as is
            translated[i] = ' ';
        }
        else {
            // Finds the corresponding alien language code for the English alphabet letter
            for (j = 0; j < 26; j++) {
                if (message[i] == alpha[j]) {
                    // Splits the comma separated alien language code and converts to English alphabet letter
                    k = 0;
                    char temp[10];
                    while (alienLang[k] != '\0') {
                        if (alienLang[k] == ',') {
                            temp[m] = '\0';
                            m = 0;
                            if (strcmp(temp, ".") == 0) {
                                translated[i] = alpha[j];
                            }
                            else if (strcmp(temp, "-") == 0) {
                                translated[i] = alpha[j];
                            }
                            memset(temp, 0, sizeof(temp));
                        }
                        else {
                            temp[m] = alienLang[k];
                            m++;
                        }
                        k++;
                    }
                    break;
                }
            }
        }
    }
    
    printf("Translated message: %s", translated); // Prints the translated message
    
    return 0; // Ends program
}