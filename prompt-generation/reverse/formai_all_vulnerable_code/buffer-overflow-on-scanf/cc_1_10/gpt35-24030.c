//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

void generate_password(char password[], int length);

int main(){
    int password_length;
    char password[MAX_LENGTH+1];

    printf("Welcome to the Random Password Generator\n");

    // Get user input on password length
    printf("How long do you want your password to be (minimum %d, maximum %d)?\n", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &password_length);

    // Check to ensure password length is within allowed range
    if(password_length < MIN_LENGTH || password_length > MAX_LENGTH){
        printf("Invalid password length. Please enter an integer between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    // Generate the password
    generate_password(password, password_length);

    // Print out the password
    printf("Your new password is: %s\n", password);

    return 0;
}

void generate_password(char password[], int length){
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+{}[],.<>?";

    // Pick a random seed based on current time
    srand(time(NULL));

    // Keep generating passwords until we get one that meets the criteria
    while(1){
        int lowercase_count = 0;
        int uppercase_count = 0;
        int number_count = 0;
        int symbol_count = 0;

        // Fill the password with random characters
        for(int i = 0; i < length; i++){
            int category = rand() % 4;

            switch(category){
                case 0:
                    password[i] = lowercase_letters[rand() % 26];
                    lowercase_count++;
                    break;
                case 1:
                    password[i] = uppercase_letters[rand() % 26];
                    uppercase_count++;
                    break;
                case 2:
                    password[i] = numbers[rand() % 10];
                    number_count++;
                    break;
                case 3:
                    password[i] = symbols[rand() % 21];
                    symbol_count++;
                    break;
            }
        }

        // Ensure we have at least one of each character category
        if(lowercase_count == 0 || uppercase_count == 0 || number_count == 0 || symbol_count == 0){
            continue;
        }

        // Ensure that no more than half of the password is made up of symbols
        if(symbol_count > length / 2){
            continue;
        }

        // Terminate the string
        password[length] = '\0';

        // We have a valid password, break out of the loop
        break;
    }
}