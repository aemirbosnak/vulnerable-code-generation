//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Function declarations */
void textToMorse(char *text);        // Convert text to Morse code
void morseToText(char *morse);       // Convert Morse code to text

/* Main function */
int main() {
    int choice;
    char input[100];

    while(1) {
        printf("Enter input string: ");
        fgets(input, 100, stdin);

        printf("Select conversion type:\n1. Text to Morse code\n2. Morse code to text\n3. Exit\nYour choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                textToMorse(input);
                break;

            case 2:
                morseToText(input);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
                break;
        }

        /* Clear input buffer */
        while((getchar()) != '\n');
    }

    return 0;
}

/* Function to convert text to Morse code */
void textToMorse(char *text) {
    char morse[100] = "";
    int len = strlen(text);

    /* Loop through each character in the input string */
    for(int i=0; i<len; i++) {
        char c = toupper(text[i]);

        /* Convert each character to its corresponding Morse code */
        switch(c) {
            case 'A':
                strcat(morse, ".-");
                break;

            case 'B':
                strcat(morse, "-...");
                break;

            case 'C':
                strcat(morse, "-.-.");
                break;

            case 'D':
                strcat(morse, "-..");
                break;

            case 'E':
                strcat(morse, ".");
                break;

            case 'F':
                strcat(morse, "..-.");
                break;

            case 'G':
                strcat(morse, "--.");
                break;

            case 'H':
                strcat(morse, "....");
                break;

            case 'I':
                strcat(morse, "..");
                break;

            case 'J':
                strcat(morse, ".---");
                break;

            case 'K':
                strcat(morse, "-.-");
                break;

            case 'L':
                strcat(morse, ".-..");
                break;

            case 'M':
                strcat(morse, "--");
                break;

            case 'N':
                strcat(morse, "-.");
                break;

            case 'O':
                strcat(morse, "---");
                break;

            case 'P':
                strcat(morse, ".--.");
                break;

            case 'Q':
                strcat(morse, "--.-");
                break;

            case 'R':
                strcat(morse, ".-.");
                break;

            case 'S':
                strcat(morse, "...");
                break;

            case 'T':
                strcat(morse, "-");
                break;

            case 'U':
                strcat(morse, "..-");
                break;

            case 'V':
                strcat(morse, "...-");
                break;

            case 'W':
                strcat(morse, ".--");
                break;

            case 'X':
                strcat(morse, "-..-");
                break;

            case 'Y':
                strcat(morse, "-.--");
                break;

            case 'Z':
                strcat(morse, "--..");
                break;

            case ' ':
                strcat(morse, "   ");
                break;

            default:
                printf("Invalid input, try again.\n");
                return;
        }

        /* Add a space between each Morse code character */
        strcat(morse, " ");
    }

    /* Print the Morse code output */
    printf("Morse code: %s\n", morse);
}

/* Function to convert Morse code to text */
void morseToText(char *morse) {
    /* Morse code lookup table */
    const char *codes[] = {
        ".-",   //A
        "-...", //B
        "-.-.", //C
        "-..",  //D
        ".",    //E
        "..-.", //F
        "--.",  //G
        "....", //H
        "..",   //I
        ".---", //J
        "-.-",  //K
        ".-..", //L
        "--",   //M
        "-.",   //N
        "---",  //O
        ".--.", //P
        "--.-", //Q
        ".-.",  //R
        "...",  //S
        "-",    //T
        "..-",  //U
        "...-", //V
        ".--",  //W
        "-..-", //X
        "-.--", //Y
        "--.."  //Z
    };

    char output[100] = "";
    int len = strlen(morse);

    /* Loop through each character in the input string */
    for(int i=0; i<len; i++) {
        if(morse[i] == '.') {
            strcat(output, "E");
        } else if(morse[i] == '-') {
            strcat(output, "T");
        } else if(morse[i] == ' ') {
            /* Search for the Morse code character in the lookup table */
            for(int j=0; j<26; j++) {
                if(strcmp(&morse[i-2], codes[j]) == 0) {
                    /* Add the corresponding character to the output string */
                    char c = 'A' + j;
                    strcat(output, &c);
                    break;
                }
            }
        } else {
            printf("Invalid input, try again.\n");
            return;
        }
    }

    /* Print the text output */
    printf("Text: %s\n", output);
}