//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter your text: ");
    scanf("%[^\n]", input); // read input till new line is encountered
    
    int len = strlen(input);
    int i, j;

    // Define ASCII characters for each letter
    char ascii_art[26][9] = {
        {"  ___  "},
        {" / _ \\ "},
        {"| | | |"},
        {"| |_| |"},
        {" \\___/ "},
        {" _   _ "},
        {"| | | |"},
        {"| |_| |"},
        {"|  _  |"},
        {"|_| |_|"},
        {" _     "},
        {"| |    "},
        {"| |    "},
        {"| |    "},
        {"| |___ "},
        {"|_   _|"},
        {"  | |  "},
        {"  | |  "},
        {"  | |  "},
        {" _| |_ "},
        {"|_   _|"},
        {"  | |  "},
        {"  | |  "},
        {"  | |  "},
        {"  |_|  "},
    };

    // Convert input string to uppercase
    for(i=0; i<len; i++) {
        input[i] = toupper(input[i]);
    }

    // Generate ASCII art for each letter of the input
    for(i=0; i<5; i++) {
        for(j=0; j<len; j++) {
            int index = input[j]-'A'; // get index of letter in ascii_art array
            if(index<0 || index>25) {
                printf("   "); // print three spaces for non-alphabet characters
            }
            else {
                printf("%s ", ascii_art[index]+i*3); // print corresponding ascii art character for the letter
            }
        }
        printf("\n");
    }

    return 0;
}