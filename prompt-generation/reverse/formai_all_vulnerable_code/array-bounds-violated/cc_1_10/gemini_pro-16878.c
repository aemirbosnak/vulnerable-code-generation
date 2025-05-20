//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: curious
//Greetings, Earthling! Prepare for a linguistic odyssey with our Alien Language Translator.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Unveiling the alien lexicon, a cosmic Rosetta Stone of 13 characters.
char alienAlphabet[] = {'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

//Embarking on the translation journey with a terrestrial phrase.
char earthlingPhrase[101];

//Harnessing the cosmos's cryptography, the substitution cipher.
void translateToAlien(char* earthlingPhrase) {
    int phraseLength = strlen(earthlingPhrase);
    for (int i = 0; i < phraseLength; i++) {
        //We seek enlightenment in the alien alphabet.
        char earthlingCharacter = earthlingPhrase[i];
        int alphabetIndex = -1;
        for (int j = 0; j < 13; j++) {
            if (earthlingCharacter == ' ') {
                alphabetIndex = 0;
                break;
            } else if (alienAlphabet[j] == earthlingCharacter) {
                alphabetIndex = j + 1;
                break;
            }
        }
        
        //Transcending linguistic boundaries, we inscribe the alien equivalent.
        if (alphabetIndex == -1) {
            earthlingPhrase[i] = '?';
        } else {
            earthlingPhrase[i] = alienAlphabet[alphabetIndex - 1];
        }
    }
}

//A beacon of clarity, guiding us back to Earth's lexicon.
void translateToEarthling(char* alienPhrase) {
    int phraseLength = strlen(alienPhrase);
    for (int i = 0; i < phraseLength; i++) {
        //Unveiling the secrets of the alien alphabet.
        char alienCharacter = alienPhrase[i];
        int alphabetIndex = -1;
        for (int j = 0; j < 13; j++) {
            if (alienCharacter == ' ') {
                alphabetIndex = 0;
                break;
            } else if (alienAlphabet[j] == alienCharacter) {
                alphabetIndex = j + 1;
                break;
            }
        }
        
        //Illuminating the Earthling script, one character at a time.
        if (alphabetIndex == -1) {
            alienPhrase[i] = '?';
        } else {
            alienPhrase[i] = alienAlphabet[alphabetIndex - 1];
        }
    }
}

//An interstellar beacon of communication, ready to bridge linguistic chasms.
int main() {
    //Receiving Earthling transmissions...
    printf("Earthling, enlighten us with your words: ");
    fgets(earthlingPhrase, 101, stdin);
    
    //Unveiling the alien perspective...
    translateToAlien(earthlingPhrase);
    printf("Your thoughts in the tongue of the cosmos: %s\n", earthlingPhrase);
    
    //Decoding alien transmissions...
    printf("Alien whispers beckon us... Input their cryptic message: ");
    fgets(earthlingPhrase, 101, stdin);
    
    //Illuminating their celestial script...
    translateToEarthling(earthlingPhrase);
    printf("Their secrets revealed in Earthly tongue: %s\n", earthlingPhrase);
    
    return 0;
}