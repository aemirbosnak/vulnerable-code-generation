//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length, uppercase, lowercase, numbers, symbols;
    char password[100];
    int i, random_num;

    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired length of the password: ");

    scanf("%d", &length);

    printf("Do you want uppercase letters in the password? (1 for yes, 0 for no): ");
    scanf("%d", &uppercase);

    printf("Do you want lowercase letters in the password? (1 for yes, 0 for no): ");
    scanf("%d", &lowercase);

    printf("Do you want numbers in the password? (1 for yes, 0 for no): ");
    scanf("%d", &numbers);

    printf("Do you want symbols in the password? (1 for yes, 0 for no): ");
    scanf("%d", &symbols);

    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char capital_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char num[] = "0123456789";
    char sym[] = "!@#$%^&*()_+-=<>?/.,[]{}";

    int len_letters = strlen(letters);
    int len_capital_letters = strlen(capital_letters);
    int len_num = strlen(num);
    int len_sym = strlen(sym);

    int len_password = length;

    if (uppercase == 0 && lowercase == 0 && numbers == 0 && symbols == 0) {
        printf("Error: At least one type of character must be selected.\n");
        exit(1);
    }

    for (i = 0; i < len_password; i++) {
        random_num = rand() % 4;
        if (random_num == 0 && uppercase == 1) {
            password[i] = capital_letters[rand() % len_capital_letters];
        }
        else if (random_num == 1 && lowercase == 1) {
            password[i] = letters[rand() % len_letters];
        }
        else if (random_num == 2 && numbers == 1) {
            password[i] = num[rand() % len_num];
        }
        else if (random_num == 3 && symbols == 1) {
            password[i] = sym[rand() % len_sym];
        }
        else {
            i--;
        }
    }

    password[len_password] = '\0';

    printf("Your generated password is: %s\n", password);

    return 0;
}