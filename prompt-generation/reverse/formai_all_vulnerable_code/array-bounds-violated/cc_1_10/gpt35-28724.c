//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

char ascii_art[MAX_LEN][MAX_LEN] = {0}; // store the final ascii art

int main()
{
    char text[MAX_LEN];
    
    printf("Enter the text to convert into ASCII art:\n");
    fgets(text, MAX_LEN, stdin);
    
    int text_len = strlen(text);
    text[text_len-1] = '\0'; // remove the trailing newline
    
    /* Define the ASCII characters to be used for the art */
    char ascii_chars[] = {'#', '@', '%', '$', '*', '+', '-', ':', '.', '\0'};        
    
    /* Determine the number of ASCII characters */
    int num_ascii_chars = strlen(ascii_chars);
    
    /* Define the height and width of each ASCII character */
    int char_height = 5;
    int char_width = 4;
    
    /* Set up the height and width of the final ASCII art */
    int art_height = num_ascii_chars * char_height;
    int art_width = (text_len-1) * char_width;
    
    /* Initialize the ASCII art to spaces */
    for(int i=0; i<art_height; i++) {
        for(int j=0; j<art_width; j++) {
            ascii_art[i][j] = ' ';
        }
    }
    
    /* Generate the ASCII art for each character in the text */
    for(int i=0; i<text_len-1; i++) {
        /* Determine the ASCII index for the current character */
        int ascii_idx = (int)text[i] % num_ascii_chars;
        
        /* Copy the ASCII art for the current character into the final ASCII art */
        for(int j=0; j<char_height; j++) {
            for(int k=0; k<char_width; k++) {
                ascii_art[j+ascii_idx*char_height][i*char_width+k] = ascii_chars[ascii_idx];
            }
        }
    }
    
    /* Print the final ASCII art */
    for(int i=0; i<art_height; i++) {
        for(int j=0; j<art_width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}