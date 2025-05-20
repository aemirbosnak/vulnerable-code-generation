//Falcon-180B DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void generateError(char* message);
int isValidInput(char* input);

int main() {
    char input[100];
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Input a string\n");
        printf("2. Input a number\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a string:\n");
                scanf("%s", input);
                if(isValidInput(input)) {
                    printf("Valid input.\n");
                } else {
                    generateError("Invalid input. Please enter a valid string.");
                }
                break;
            case 2:
                printf("Enter a number:\n");
                scanf("%d", &choice);
                if(choice >= 0 && choice <= 100) {
                    printf("Valid input.\n");
                } else {
                    generateError("Invalid input. Please enter a number between 0 and 100.");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                generateError("Invalid choice. Please enter a valid choice.");
        }
    } while(choice!= 3);

    return 0;
}

void generateError(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

int isValidInput(char* input) {
    int length = strlen(input);
    if(length == 0) {
        return false;
    }
    for(int i = 0; i < length; i++) {
        if(!isalpha(input[i])) {
            return false;
        }
    }
    return true;
}