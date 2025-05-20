//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

char * morse_code[] = {".-","\010-\011\012","\010-\011.\012","\010-\012\012","\010.\012",".",\
                        ".\010-\012","\010\010\012","..\012",".\012\010-","\010-\011-\012",".-..",\
                        "\010-\012","\010-\010","\010\012","\010-\011\012","..\012",".\012","..\010-",\
                        "-.\012",".-\012\010-","\010-\010\012","...\012","-\012","..-\012",\
                        "...-\012","\010-\011-\010","\010-\011.\010-",".-\012",\
                        "\010-\011\010\010\012","-..\012","-\010-\012","+","\010-\011\010-","\010-\011-\010\012","..\010-","\010\010\010\012",".-.\012","\010.\010\012","\010-\012\010-","\010-\010\010-","\010-\011-\012\010-"};

// function to convert a single character to Morse code
void char_to_morse(char letter) {
    int index;

    // check if the character is an alphabet
    if (letter >= 'A' && letter <= 'Z') {
        index = letter - 'A';
    }
    // check if the character is a number
    else if (letter >= '0' && letter <= '9') {
        index = letter - '0' + 26;
    }
    // if the character is not a valid alphabet or number, ignore it
    else {
        return;
    }

    printf("%s ", morse_code[index]);
}

// function to convert a string to Morse code
void string_to_morse(char string[]) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        char_to_morse(string[i]);
    }
}

int main() {
    char input_string[100];

    printf("Enter a string: ");
    fgets(input_string, 100, stdin);

    // remove the newline character from the input
    input_string[strlen(input_string)-1] = '\0';

    printf("Morse code: ");
    string_to_morse(input_string);
    printf("\n");

    return 0;
}