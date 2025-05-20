//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text_input[100];
    printf("Please enter a text input: ");
    fgets(text_input, 100, stdin); // get input from user
    
    printf("The text input you provided is: %s\n", text_input);
    
    // remove trailing newline character
    size_t len = strlen(text_input) - 1;
    if (text_input[len] == '\n') {
        text_input[len] = '\0';
    }
    
    int choice = -1;
    while (choice != 0) {
        printf("\nWhat do you want to do with the text?\n");
        printf("1. Convert to uppercase\n");
        printf("2. Convert to lowercase\n");
        printf("3. Replace vowels with '*'\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                for (int i = 0; i < strlen(text_input); i++) {
                    text_input[i] = toupper(text_input[i]);
                }
                printf("\nText in uppercase: %s\n", text_input);
                break;
            case 2:
                for (int i = 0; i < strlen(text_input); i++) {
                    text_input[i] = tolower(text_input[i]);
                }
                printf("\nText in lowercase: %s\n", text_input);
                break;
            case 3:
                for (int i = 0; i < strlen(text_input); i++) {
                    if (text_input[i] == 'a' || text_input[i] == 'e' || text_input[i] == 'i' || text_input[i] == 'o' || text_input[i] == 'u' ||
                       text_input[i] == 'A' || text_input[i] == 'E' || text_input[i] == 'I' || text_input[i] == 'O' || text_input[i] == 'U') {
                        text_input[i] = '*';
                    }
                }
                printf("\nText with vowels replaced by '*': %s\n", text_input);
                break;
            case 0:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}