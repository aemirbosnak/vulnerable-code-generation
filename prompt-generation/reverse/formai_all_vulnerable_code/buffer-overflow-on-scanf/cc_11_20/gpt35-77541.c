//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <string.h>

// Function to convert a single character to Morse code
void char_to_morse(char c, char* morse) {
    switch (c) {
        case 'A': strcpy(morse, ".-"); break;
        case 'B': strcpy(morse, "-..."); break;
        case 'C': strcpy(morse, "-.-."); break;
        case 'D': strcpy(morse, "-.."); break;
        case 'E': strcpy(morse, "."); break;
        case 'F': strcpy(morse, "..-."); break;
        case 'G': strcpy(morse, "--."); break;
        case 'H': strcpy(morse, "...."); break;
        case 'I': strcpy(morse, ".."); break;
        case 'J': strcpy(morse, ".---"); break;
        case 'K': strcpy(morse, "-.-"); break;
        case 'L': strcpy(morse, ".-.."); break;
        case 'M': strcpy(morse, "--"); break;
        case 'N': strcpy(morse, "-."); break;
        case 'O': strcpy(morse, "---"); break;
        case 'P': strcpy(morse, ".--."); break;
        case 'Q': strcpy(morse, "--.-"); break;
        case 'R': strcpy(morse, ".-."); break;
        case 'S': strcpy(morse, "..."); break;
        case 'T': strcpy(morse, "-"); break;
        case 'U': strcpy(morse, "..-"); break;
        case 'V': strcpy(morse, "...-"); break;
        case 'W': strcpy(morse, ".--"); break;
        case 'X': strcpy(morse, "-..-"); break;
        case 'Y': strcpy(morse, "-.--"); break;
        case 'Z': strcpy(morse, "--.."); break;
        case '0': strcpy(morse, "-----"); break;
        case '1': strcpy(morse, ".----"); break;
        case '2': strcpy(morse, "..---"); break;
        case '3': strcpy(morse, "...--"); break;
        case '4': strcpy(morse, "....-"); break;
        case '5': strcpy(morse, "....."); break;
        case '6': strcpy(morse, "-...."); break;
        case '7': strcpy(morse, "--..."); break;
        case '8': strcpy(morse, "---.."); break;
        case '9': strcpy(morse, "----."); break;
        default: strcpy(morse, ""); break;
    }
}

// Function to convert a string to Morse code
void string_to_morse(char* str, char* morse) {
    int n = strlen(str);
    char c_morse[7];

    morse[0] = '\0';

    for (int i = 0; i < n; i++) {
        char_to_morse(str[i], c_morse);
        strcat(morse, c_morse);

        if (i < n - 1) {
            strcat(morse, " ");
        }
    }
}

int main() {
    char str[100];
    char morse[1000];
    int choice;

    printf("Enter a string to convert to Morse code: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("\nChoose Morse code style:\n\n");
    printf("1 - Separated by spaces (e.g. .- -... -.-.)\n");
    printf("2 - Continuous (e.g. .--.-...-.-.)\n");
    printf("3 - Teleprinter style (e.g. ...-.- -...-.-.-.- -.-.-.-.-)\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            string_to_morse(str, morse);
            printf("\nMorse code: %s\n", morse);
            break;
        case 2:
            string_to_morse(str, morse);

            for (int i = 0; i < strlen(morse); i++) {
                printf("%c", morse[i]);
            }

            printf("\n");
            break;
        case 3:
            string_to_morse(str, morse);

            for (int i = 0; i < strlen(morse); i++) {
                if (morse[i] == '.') {
                    printf("•");
                } else if (morse[i] == '-') {
                    printf("-");
                } else if (morse[i] == ' ') {
                    printf(" ");
                }

                if (i < strlen(morse) - 1 && morse[i] != ' ') {
                    printf(" ");
                }
            }

            printf("\n");
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }

    return 0;
}