//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main() {
    // initializing characters for password generation
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";

    // input variables
    int num_chars;
    int num_numbers;
    int num_symbols;
    char include_uppercase;
    char include_symbols;

    // randomization
    srand(time(NULL));

    // getting user input
    printf("Welcome to Secure Password Generator!\n");
    printf("How many characters would you like your password to be? (at least 8)\n");
    scanf("%d", &num_chars);
    printf("How many numbers would you like in your password? (at least 1)\n");
    scanf("%d", &num_numbers);
    printf("Would you like to include uppercase letters? (y/n)\n");
    scanf(" %c", &include_uppercase);
    printf("Would you like to include symbols? (y/n)\n");
    scanf(" %c", &include_symbols);
    printf("How many symbols would you like in your password? (0-3)\n");
    scanf("%d", &num_symbols);

    // check for valid input
    if (num_chars < 8 || num_numbers < 1 || num_symbols < 0 || num_symbols > 3 || (include_uppercase != 'y' && include_uppercase != 'n') || (include_symbols != 'y' && include_symbols != 'n')) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // generating password
    char password[num_chars+1];

    // adding random letters
    for (int i = 0; i < num_chars-num_numbers-num_symbols; i++) {
        password[i] = letters[rand() % strlen(letters)];
    }

    // adding random numbers
    for (int i = 0; i < num_numbers; i++) {
        password[num_chars-num_numbers-num_symbols+i] = numbers[rand() % strlen(numbers)];
    }

    // adding uppercase letters if requested
    if (include_uppercase == 'y') {
        for (int i = 0; i < num_chars-num_numbers-num_symbols; i++) {
            if (rand() % 2) {
                password[i] = toupper(password[i]);
            }
        }
    }

    // adding symbols if requested
    if (include_symbols == 'y') {
        for (int i = 0; i < num_symbols; i++) {
            int index = num_chars-num_symbols+i;
            password[index] = symbols[rand() % strlen(symbols)];
        }
    }

    // adding null terminator and outputting password
    password[num_chars] = '\0';
    printf("Your password is:\n%s\n", password);

    return 0;
}