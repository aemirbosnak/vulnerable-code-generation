//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter a string (maximum 100 characters): ");
    fgets(input, 100, stdin); //get user input, max 100 characters
    
    //ASCII art array
    char ascii_art[127][7][6] = {
        {
            " 000 ",
            "0   0",
            "0   0",
            "0   0",
            "0   0",
            " 000 "
        }, //ASCII value 48 (0)
        
        {
            " 111 ",
            "1   1",
            "1   1",
            "1   1",
            "1   1",
            " 111 "
        }, //ASCII value 49 (1)
        
        //ASCII art representations for all other characters...
        //included for brevity in this example program
        
        {
            "      ",
            "      ",
            "      ",
            "      ",
            "      ",
            "      "
        } //ASCII value 126 (~)
    };
    
    int i, j, k;
    for (i = 0; i < strlen(input); i++) {
        int ascii_val = (int)input[i];
        for (j = 0; j < 6; j++) { //6 rows in ASCII art
            for (k = 0; k < 5; k++) { //5 columns in ASCII art
                printf("%c", ascii_art[ascii_val][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}