//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, digits, symbols, uppercase, lowercase, i;
    char password[129] = ""; // maximum length of password is 128 characters
    srand(time(NULL)); // seed the random number generator with the current time
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the length of your password (maximum 128): ");
    scanf("%d", &length);
    printf("Please enter the number of digits you would like in your password: ");
    scanf("%d", &digits);
    printf("Please enter the number of symbols you would like in your password: ");
    scanf("%d", &symbols);
    printf("Please enter the number of uppercase letters you would like in your password: ");
    scanf("%d", &uppercase);
    printf("Please enter the number of lowercase letters you would like in your password: ");
    scanf("%d", &lowercase);
    if (length < (digits + symbols + uppercase + lowercase)) {
        printf("Error: The length of the password must be greater than or equal to the sum of the number of digits, symbols, uppercase letters, and lowercase letters.\n");
        return 1;
    }
    // generate digits
    for (i = 0; i < digits; i++) {
        password[i] = rand() % 10 + 48; // ASCII code for digits 0-9
    }
    // generate symbols
    for (i = digits; i < digits + symbols; i++) {
        password[i] = rand() % 15 + 33; // ASCII code for symbols !-/
    }
    // generate uppercase letters
    for (i = digits + symbols; i < digits + symbols + uppercase; i++) {
        password[i] = rand() % 26 + 65; // ASCII code for uppercase letters A-Z
    }
    // generate lowercase letters
    for (i = digits + symbols + uppercase; i < length; i++) {
        password[i] = rand() % 26 + 97; // ASCII code for lowercase letters a-z
    }
    // shuffle the password characters
    for (i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    // print the password
    printf("Your secure password is: %s\n", password);
    return 0;
}