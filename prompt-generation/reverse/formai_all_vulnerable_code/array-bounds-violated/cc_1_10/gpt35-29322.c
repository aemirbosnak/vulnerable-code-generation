//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

char *text_to_morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char *alphabet = "abcdefghijklmnopqrstuvwxyz";

char *paranoid_morse[] = {
    ".--.-.", ".----.", "..-.--", "--.---", ".--...", "...-..-",
    ".--..-", "-.-.--", "--.-..", "-..-.-", "-.-.-.", ".-.-..",
    "...--.", "--.--.", ".-.---", "..-.-.", "..--..", "-.-..-.",
    "..---.", "...-.-", "-..--.", "---...", "-.-..-", ".----.",
    "-.-.--.", ".--.-."
};

char input_text[MAX_INPUT_SIZE], output_morse[MAX_INPUT_SIZE * 5];

void sanitize_input(char input[]) {
    for (int i = 0; input[i]; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += ('a' - 'A');
        }
    }
}

void convert_to_morse(char input[], char output[]) {
    for (int i = 0; input[i]; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            strcat(output, text_to_morse[input[i] - 'a']);
            strcat(output, " ");
        } else if (input[i] >= '0' && input[i] <= '9') {
            strcat(output, text_to_morse[input[i] - '0' + 26]);
            strcat(output, " ");
        } else {
            switch (input[i]) {
                case ' ':
                    strcat(output, "/");
                    break;
                case '.':
                    strcat(output, ".-.-.-");
                    break;
                case ',':
                    strcat(output, "--..--");
                    break;
                case '?':
                    strcat(output, "..--..");
                    break;
                case '!':
                    strcat(output, "-.-.--");
                    break;
                default:
                    break;
            }
        }
    }
}

int main() {
    printf("Enter text to convert to paranoid Morse code: ");
    fgets(input_text, sizeof(input_text), stdin);

    sanitize_input(input_text);
    convert_to_morse(input_text, output_morse);

    printf("Paranoid Morse code: ");
    for (int i = 0; output_morse[i]; i++) {
        if (output_morse[i] == '.') {
            printf("%s ", paranoid_morse[i % 26]);
        } else if (output_morse[i] == '-') {
            printf("%s ", paranoid_morse[(i % 26) + 1]);
        } else if (output_morse[i] == ' ') {
            printf("/ ");
        }
    }
    printf("\n");

    return 0;
}