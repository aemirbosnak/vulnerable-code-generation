//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include<stdio.h>
#include<string.h>

int main()
{
    char user_input[100];
    int i, j, length;
    printf("Enter a text to convert to Morse code: ");
    scanf("%[^\n]", user_input); // read user input until new line character is encountered

    length = strlen(user_input);

    char morse_code[length][10]; // morse code can be up to 4 characters long

    // loop through each character in the input and convert to corresponding Morse code
    for(i=0; i<length; i++) {
        switch(tolower(user_input[i])) { // convert all alphabets to lowercase for ease of conversion
            case 'a':
                strcpy(morse_code[i], ".-");
                break;
            case 'b':
                strcpy(morse_code[i], "-...");
                break;
            case 'c':
                strcpy(morse_code[i], "-.-.");
                break;
            case 'd':
                strcpy(morse_code[i], "-..");
                break;
            case 'e':
                strcpy(morse_code[i], ".");
                break;
            case 'f':
                strcpy(morse_code[i], "..-.");
                break;
            case 'g':
                strcpy(morse_code[i], "--.");
                break;
            case 'h':
                strcpy(morse_code[i], "....");
                break;
            case 'i':
                strcpy(morse_code[i], "..");
                break;
            case 'j':
                strcpy(morse_code[i], ".---");
                break;
            case 'k':
                strcpy(morse_code[i], "-.-");
                break;
            case 'l':
                strcpy(morse_code[i], ".-..");
                break;
            case 'm':
                strcpy(morse_code[i], "--");
                break;
            case 'n':
                strcpy(morse_code[i], "-.");
                break;
            case 'o':
                strcpy(morse_code[i], "---");
                break;
            case 'p':
                strcpy(morse_code[i], ".--.");
                break;
            case 'q':
                strcpy(morse_code[i], "--.-");
                break;
            case 'r':
                strcpy(morse_code[i], ".-.");
                break;
            case 's':
                strcpy(morse_code[i], "...");
                break;
            case 't':
                strcpy(morse_code[i], "-");
                break;
            case 'u':
                strcpy(morse_code[i], "..-");
                break;
            case 'v':
                strcpy(morse_code[i], "...-");
                break;
            case 'w':
                strcpy(morse_code[i], ".--");
                break;
            case 'x':
                strcpy(morse_code[i], "-..-");
                break;
            case 'y':
                strcpy(morse_code[i], "-.--");
                break;
            case 'z':
                strcpy(morse_code[i], "--..");
                break;
            case ' ':
                strcpy(morse_code[i], "   "); // for space between words
                break;
            default:
                printf("Invalid character entered\n"); // if the input character is not a valid alphabet or space
                return 0;
        }
    }

    // display the Morse code for the input text
    printf("\nMorse code for the entered text:\n");
    for(i=0; i<length; i++) {
        printf("%s ", morse_code[i]);
    }

    return 0;
}