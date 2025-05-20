//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include<stdio.h>

int main() {
    // Let's declare some variables
    char str[1000], c;
    int i, space = 0;
    
    // Prompt the user to enter input
    printf("Enter some C HTML code:\n");
    gets(str);
    
    // Now let's beautify the code by adding indentation
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == '<') {
            // Check if this is an opening tag
            if(str[i+1] != '/' && str[i+1] != ' ') {
                // Increase the indentation level
                space += 4;
                printf("\n");
                for(int j = 0; j < space; j++) {
                    printf(" ");
                }
                printf("%c", str[i]);
            }
            // Check if this is a closing tag
            else if(str[i+1] == '/') {
                space -= 4;
                printf("\n");
                for(int j = 0; j < space; j++) {
                    printf(" ");
                }
                printf("%c%c", str[i], str[i+1]);
            }
            // Check if this is an empty tag
            else {
                printf("\n");
                for(int j = 0; j < space; j++) {
                    printf(" ");
                }
                printf("%c", str[i]);
            }
        }
        else if(str[i] == '>') {
            printf("%c\n", str[i]);
            // Check if the next line is not end of the code
            if(str[i+1] != '\0') {
                for(int j = 0; j < space; j++) {
                    printf(" ");
                }
            }
        }
        else {
            printf("%c", str[i]);
        }
    }
    return 0;
}