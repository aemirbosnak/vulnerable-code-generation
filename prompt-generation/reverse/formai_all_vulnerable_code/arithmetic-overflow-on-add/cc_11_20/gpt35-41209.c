//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, num, caps, small, specials;
    char password[50];
    int i, j;
    
    // initialize random seed
    srand(time(NULL));

    // ask for password length
    printf("Enter password length (minimum 8 characters): ");
    scanf("%d", &length);

    // validate minimum length
    if (length < 8) {
        printf("Password length should be minimum 8 characters\n");
        return 0;
    }

    // ask for number of digits, capital letters, small letters and special characters
    printf("Enter number of digits: ");
    scanf("%d", &num);

    printf("Enter number of capitals: ");
    scanf("%d", &caps);

    printf("Enter number of small letters: ");
    scanf("%d", &small);

    printf("Enter number of special characters: ");
    scanf("%d", &specials);

    // validate total number of characters
    if (num + caps + small + specials > length) {
        printf("Total number of characters should be less than or equal to password length\n");
        return 0;
    }

    // generate password
    for (i = 0; i < length; i++) {
        // generate random number between 1 and 4
        int category = rand() % 4 + 1;
        
        // generate digits
        if (category == 1 && num > 0) {
            password[i] = rand() % 10 + '0';
            num--;
        }
        // generate capitals
        else if (category == 2 && caps > 0) {
            password[i] = rand() % 26 + 'A';
            caps--;
        }
        // generate small letters
        else if (category == 3 && small > 0) {
            password[i] = rand() % 26 + 'a';
            small--;
        }
        // generate special characters
        else if (category == 4 && specials > 0) {
            password[i] = rand() % 15 + 33;
            specials--;
        }
        // if not enough of a specific category, try again
        else {
            i--;
        }
    }
    // null terminate password string
    password[length] = '\0';

    // shuffle password characters
    for (i = 0; i < length; i++) {
        j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // print password
    printf("Your secure password is: %s\n", password);

    return 0;
}