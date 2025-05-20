//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
char* getFortune(int random);
void printResponse(char* sign, char* fortune);

int main() {
    char sign[20];
    int random;
    srand(time(NULL));  // seed for random number generator

    printf("Greetings traveller. What is thy sign?\n");
    scanf("%s", sign);

    // Convert sign to uppercase for comparison
    for(int i = 0; i < strlen(sign); i++) {
        sign[i] = toupper(sign[i]);
    }

    // Check if sign is valid
    if(strcmp(sign, "ARIES") != 0 && strcmp(sign, "TAURUS") != 0 &&
        strcmp(sign, "GEMINI") != 0 && strcmp(sign, "CANCER") != 0 &&
        strcmp(sign, "LEO") != 0 && strcmp(sign, "VIRGO") != 0 &&
        strcmp(sign, "LIBRA") != 0 && strcmp(sign, "SCORPIO") != 0 &&
        strcmp(sign, "SAGITTARIUS") != 0 && strcmp(sign, "CAPRICORN") != 0 &&
        strcmp(sign, "AQUARIUS") != 0 && strcmp(sign, "PISCES") != 0) {
            printf("I'm sorry, but that is not a valid sign for our fortune telling services.\n");
            return 0;
    }

    // Generate random number between 1 and 10 inclusive
    random = rand() % 10 + 1;

    // Get fortune based on random number
    char* fortune = getFortune(random);

    // Print response
    printResponse(sign, fortune);

    return 0;
}

char* getFortune(int random) {
    switch(random) {
        case 1:
            return "The stars predict riches in your future, but not without risk.";
        case 2:
            return "The portents foretell a journey, be wary of dangers on the road.";
        case 3:
            return "Your fate is intertwined with those around you, seek out allies.";
        case 4:
            return "Adversity is upon you, but it will only serve to make you stronger.";
        case 5:
            return "The omens speak of love, but beware of false affections.";
        case 6:
            return "You will face a great trial, but the rewards will be worth it.";
        case 7:
            return "The alignment of the planets bodes ill for your endeavors at this time.";
        case 8:
            return "Fortune smiles upon you, but do not be complacent in your success.";
        case 9:
            return "The arcane energies are in your favor, use them wisely.";
        case 10:
            return "Your destiny lies beyond the horizon, adventure awaits!";
        default:
            return "Error: Invalid fortune index";
    }
}

void printResponse(char* sign, char* fortune) {
    printf("Ah, I see that you are a noble %s. Let me consult the stars...\n", sign);
    printf("The stars have spoken. Your fortune is as follows: \"%s\"\n", fortune);
    printf("May your path be blessed by the divine. Farewell, traveller.\n");
}