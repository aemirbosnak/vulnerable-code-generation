//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: funny
/* Welcome to the Secure Password Generator!
 * Here, we create random passwords to keep your digital life secure... and interesting!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char password[25]; // password will be up to 25 characters
    int length, i, num, choice;

    printf("--- Welcome to the Secure Password Generator ---\n");

    printf("How long would you like your password to be? (8-25 characters) ");
    scanf("%d", &length);

    if (length < 8 || length > 25) {
        printf("Invalid input! Password length must be between 8 and 25.");
        return 0; // terminate program if invalid input given
    }

    printf("Would you like numbers in your password? (1 for Yes, 0 for No) ");
    scanf("%d", &choice);

    srand(time(NULL)); // seed random number generator with current time

    for (i = 0; i < length; i++) {

        // generate a random character
        num = rand() % (126 - 33 + 1) + 33; // ASCII characters between 33 and 126 are printable

        // if user wants numbers in password, replace some random characters with numbers
        if (choice == 1 && i % 3 == 0) {
            num = rand() % (57 - 48 + 1) + 48; // ASCII digits between 48 and 57
        }

        password[i] = (char) num;
    }

    printf("Your randomly generated password: ");

    // print out the password character by character
    for (i = 0; i < length; i++) {
        printf("%c", password[i]);
    }

    printf("\n");

    return 0;
}