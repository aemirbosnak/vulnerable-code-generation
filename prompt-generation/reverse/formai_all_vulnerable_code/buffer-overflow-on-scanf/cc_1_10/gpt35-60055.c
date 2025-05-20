//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_PASSWORD_LENGTH 20

int main(){
    time_t t;
    int password_length, i, type_choice, char_choice, digit_choice;
    char password[MAX_PASSWORD_LENGTH];
    int lowercase_characters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
    int uppercase_characters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
    int digits[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    int special_characters[] = {33, 35, 36, 37, 38, 42, 43, 45, 47, 63, 64, 94, 95};

    srand((unsigned) time(&t)); // seed the random number generator

    printf("Hello there! I'm your friendly neighbourhood password generator.\n");
    printf("How long would you like your password to be? (max %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    if(password_length > MAX_PASSWORD_LENGTH) {
        printf("That's too long, please enter a length less than or equal to %d.\n", MAX_PASSWORD_LENGTH);
        printf("How long would you like your password to be? (max %d): ", MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
    }

    // set the password length
    password[password_length] = '\0';

    printf("Which type of characters would you like to include?\n");
    printf("1. Lowercase Characters\n2. Uppercase Characters\n3. Digits\n4. Special Characters\n");
    printf("Enter the choice (1-4): ");
    scanf("%d", &type_choice);

    if(type_choice < 1 || type_choice > 4) {
        printf("Invalid choice. Please enter a number between 1 and 4.\n");
        printf("Enter the choice (1-4): ");
        scanf("%d", &type_choice);
    }

    // choose characters from selected type
    for(i=0;i<password_length;i++) {
        if(type_choice == 1) {
            char_choice = rand() % 26;
            password[i] = (char) lowercase_characters[char_choice];
        }

        if(type_choice == 2) {
            char_choice = rand() % 26;
            password[i] = (char) uppercase_characters[char_choice];
        }

        if(type_choice == 3) {
            digit_choice = rand() % 10;
            password[i] = (char) digits[digit_choice];
        }

        if(type_choice == 4) {
            char_choice = rand() % 13;
            password[i] = (char) special_characters[char_choice];
        }
    }

    // shuffle password
    for(i=0;i<password_length;i++) {
        char temp = password[i];
        int random_index = rand() % password_length;
        password[i] = password[random_index];
        password[random_index] = temp;
    }

    printf("\nYour password is: %s\n", password);
    printf("Remember to keep it safe! :)\n");

    return 0;
}