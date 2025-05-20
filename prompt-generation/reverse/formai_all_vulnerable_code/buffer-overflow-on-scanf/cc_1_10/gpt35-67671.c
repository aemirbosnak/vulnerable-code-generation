//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, num, specChar, upCase, lowCase, i, j;
    char password[100];
    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the length of your desired password: ");
    scanf("%d", &length);

    printf("\nHow many numbers should be in the password? (Enter 0 to skip): ");
    scanf("%d", &num);

    printf("\nHow many special characters should be in the password? (Enter 0 to skip): ");
    scanf("%d", &specChar);

    printf("\nHow many uppercase letters should be in the password? (Enter 0 to skip): ");
    scanf("%d", &upCase);

    printf("\nHow many lowercase letters should be in the password? (Enter 0 to skip): ");
    scanf("%d", &lowCase);

    if(num + specChar + upCase + lowCase > length) {
        printf("\nOops! The sum of the requested characters is greater than the password length. Please try again.\n");
    }
    else {
        for(i = 0; i < num; i++) {
            password[i] = '0' + rand() % 10;
        }

        for(j = 0; j < specChar; j++) {
            password[i+j] = '!' + rand() % 15;
        }

        for(j = 0; j < upCase; j++) {
            password[i+specChar+j] = 'A' + rand() % 26;
        }

        for(j = 0; j < lowCase; j++) {
            password[i+specChar+upCase+j] = 'a' + rand() % 26;
        }

        for(j = i + specChar + upCase + lowCase; j < length; j++) {
            password[j] = '!' + rand() % 75;
        }

        printf("\nYour secure password is: %s\n", password);
    }
    
    printf("\nThanks for using the Secure Password Generator! Stay safe and happy!\n");

    return 0;
}