//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char password[100];
    int length = 0;

    // Prompt user for desired password length
    printf("In this post-apocalyptic world, your password is your lifeline.\n");
    printf("Enter the desired length of your password: ");
    scanf("%d", &length);

    // Generate random password
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        if (i % 3 == 0) {
            // Every third character must be a special character
            int special_index = rand() % 6;
            switch (special_index) {
                case 0:
                    password[i] = '!';
                    break;
                case 1:
                    password[i] = '@';
                    break;
                case 2:
                    password[i] = '#';
                    break;
                case 3:
                    password[i] = '$';
                    break;
                case 4:
                    password[i] = '%';
                    break;
                case 5:
                    password[i] = '^';
                    break;
            }
        } else {
            // Other characters can be uppercase letters, lowercase letters, or numbers
            int char_index = rand() % 62;
            if (char_index < 26) {
                password[i] = 'A' + char_index;
            } else if (char_index < 52) {
                password[i] = 'a' + (char_index - 26);
            } else {
                password[i] = '0' + (char_index - 52);
            }
        }
    }

    // Print generated password
    printf("\nYour password is: %s\n", password);

    return 0;
}