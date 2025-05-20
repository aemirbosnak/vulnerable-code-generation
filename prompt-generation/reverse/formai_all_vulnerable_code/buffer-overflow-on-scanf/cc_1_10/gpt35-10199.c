//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <string.h>

void toMorse(char c);
void printMorse(char *str);

const char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                           "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};

const char *letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

int main() {
    char option, message[200];
    int i, len;

    printf("Select an option:\n");
    printf("a) Convert Text to Morse Code\n");
    printf("b) Convert Morse Code to Text\n");
    scanf("%c", &option);

    if (option == 'a') {
        printf("Enter a message to be converted to Morse Code (max 200 characters):\n");
        scanf("%s", message);

        len = strlen(message);

        printf("Morse Code:\n");
        for(i = 0; i < len; i++) {
            toMorse(message[i]);
        }
        printf("\n");
    } else if (option == 'b') {
        printf("Enter the Morse Code (use comma to separate words):\n");
        scanf("%s", message);

        printf("Text:\n");
        printMorse(message);
    } else {
        printf("Invalid option selected.");
    }

    return 0;
}

void toMorse(char c) {
    int i;

    for (i = 0; i < 27; i++) {
        if(letters[i][0] == toupper(c)) {
            printf("%s ", morseCodes[i]);
            break;
        }
    }
}

void printMorse(char *str) {
    int i, j, len, found;

    len = strlen(str);

    for(i = 0; i < len; i++) {
        if(str[i] == ',') {
            printf(" ");
            continue;
        }

        found = 0;
        for(j = 0; j < 27; j++) {
            if(strcmp(morseCodes[j], &str[i]) == 0) {
                printf("%c", letters[j][0]);
                i += strlen(morseCodes[j])-1;
                found = 1;
                break;
            }
        }

        if(!found) {
            printf("Invalid Morse Code.");
            break;
        }
    }
}