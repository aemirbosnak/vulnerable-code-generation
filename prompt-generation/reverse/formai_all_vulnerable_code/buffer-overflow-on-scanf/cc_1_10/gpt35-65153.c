//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate secure passwords
void generate_password(int length) {
    // define characters to be used in password
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special_characters[] = "!@#$%^&*";

    // get length of each character array
    int lowercase_length = sizeof(lowercase_letters) - 1;
    int uppercase_length = sizeof(uppercase_letters) - 1;
    int numbers_length = sizeof(numbers) - 1;
    int special_length = sizeof(special_characters) - 1;

    // initialize random seed
    srand(time(NULL));

    // loop through password length and randomly select characters
    for (int i = 0; i < length; i++) {
        int rand_num = rand() % 4;
        if (rand_num == 0) {
            printf("%c", lowercase_letters[rand() % lowercase_length]);
        }
        else if (rand_num == 1) {
            printf("%c", uppercase_letters[rand() % uppercase_length]);
        }
        else if (rand_num == 2) {
            printf("%c", numbers[rand() % numbers_length]);
        }
        else {
            printf("%c", special_characters[rand() % special_length]);
        }
    }
    printf("\n");
}

// main function to generate passwords
int main() {
    int num_passwords;
    int password_length;

    // get user input for number of passwords and length
    printf("How many passwords would you like to generate? ");
    scanf("%d", &num_passwords);
    printf("What should be the length of each password? ");
    scanf("%d", &password_length);

    // generate requested number of passwords
    printf("\nGenerating passwords...\n");
    for (int i = 0; i < num_passwords; i++) {
        generate_password(password_length);
    }

    return 0;
}