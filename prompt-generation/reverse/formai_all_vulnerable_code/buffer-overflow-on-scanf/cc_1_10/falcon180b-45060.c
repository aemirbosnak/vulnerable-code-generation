//Falcon-180B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void happy_error_handling(int error_code) {
    switch(error_code) {
        case 1:
            printf("Oopsie! You've encountered an error. Please try again later.\n");
            break;
        case 2:
            printf("Uh oh! Something went wrong. Let's try that again, shall we?\n");
            break;
        case 3:
            printf("Oh dear! It looks like there's been a hiccup. Let's give it another go!\n");
            break;
        default:
            printf("Sorry, I don't know how to handle this error.\n");
            break;
    }
}

int main() {
    char input[MAX_SIZE];
    int choice, error_code = 0;

    do {
        printf("Welcome to the Happy Error Handling Program!\n");
        printf("Please choose an option:\n");
        printf("1. Enter a string\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Please enter a string:\n");
                scanf("%s", input);
                if(strlen(input) > MAX_SIZE) {
                    error_code = 1;
                }
                break;
            case 2:
                printf("Goodbye! Have a happy day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 2);

    return 0;
}