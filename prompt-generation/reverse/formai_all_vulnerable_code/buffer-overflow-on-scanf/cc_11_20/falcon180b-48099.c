//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    int length;
    char *password;
    int i;
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *numbers = "0123456789";
    const char *special = "!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";

    // prompt user for password length
    printf("Enter password length: ");
    scanf("%d", &length);

    // allocate memory for password
    password = (char *)malloc(length + 1);

    // initialize password with random characters
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        password[i] = (char)rand() % 94 + 33;
    }
    password[length] = '\0';

    // add at least one uppercase letter, lowercase letter, number, and special character
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecial = 0;
    while (!hasUppercase ||!hasLowercase ||!hasNumber ||!hasSpecial) {
        int j = rand() % length;
        if (!hasUppercase && isupper(password[j])) {
            hasUppercase = 1;
        } else if (!hasLowercase && islower(password[j])) {
            hasLowercase = 1;
        } else if (!hasNumber && isdigit(password[j])) {
            hasNumber = 1;
        } else if (!hasSpecial && strchr(special, password[j])) {
            hasSpecial = 1;
        }
        password[j] = (char)rand() % 94 + 33;
    }

    // print password
    printf("Your secure password is: %s\n", password);

    return 0;
}