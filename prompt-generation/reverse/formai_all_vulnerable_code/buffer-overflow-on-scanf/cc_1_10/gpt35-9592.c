//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int length, i, choice;
    char password[33], chars[96];

    memset(password, 0, sizeof(password)); // clear out password array
    memset(chars, 0, sizeof(chars)); // clear out chars array

    for(i=32; i<127; i++) {
        chars[i-32] = i; // fill chars with printable ascii characters
    }

    printf("Welcome to Secure Password Generator!\n");
    printf("Enter desired password length: ");
    scanf("%d", &length);

    if(length < 8 || length > 32) {
        printf("Invalid password length (must be between 8 and 32 characters)!\n");
        return -1; // exit program with error
    }

    while(1) {
        printf("Choose password complexity:\n");
        printf("1. Simple (letters only)\n");
        printf("2. Complex (letters, numbers and special characters)\n");
        scanf("%d", &choice);

        if(choice == 1 || choice == 2) {
            break; // valid choice entered
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    srand(time(NULL)); // initialize random seed

    for(i=0; i<length; i++) {
        if(choice == 1) {
            password[i] = chars[rand() % 52]; // simple password (only letters)
        }
        else {
            password[i] = chars[rand() % 94]; // complex password (letters, numbers, special chars)
        }
    }

    printf("Your ultra secure password is: %s\n", password);

    return 0; // exit program successfully
}