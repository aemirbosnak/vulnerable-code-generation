//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declaration */
void generate_password(int length);

int main() {

    int length;
    printf("Enter the length of password you want: ");
    scanf("%d", &length);

    /* Seed the random number generator */
    srand(time(NULL));

    /* Call the function to generate the password */
    generate_password(length);

    return 0;
}

void generate_password(int length) {

    int i, ascii_code;
    char password[length+1];

    /* Generate a random password */
    for (i = 0; i < length; i++) {
        ascii_code = rand() % 94 + 33;  /* Generating random printable ascii characters */
        password[i] = (char) ascii_code;
    }

    /* Adding Null character at the end of the password string */
    password[length] = '\0';

    /* Print the generated password */
    printf("Generated password: %s\n", password);

    /* Secure code for better password */
    printf("Secure code for better password: ");
    for (i = 0; i < length; i++) {
        ascii_code = rand() % 6 + 1;  /* Generating random numbers between 1 to 6 */

        /* Based on generated number add a character to secure the password further */
        switch (ascii_code) {
            case 1:
                printf("%c", '*');
                break;
            case 2:
                printf("%c", '#');
                break;
            case 3:
                printf("%c", '@');
                break;
            case 4:
                printf("%c", '&');
                break;
            case 5:
                printf("%c", '$');
                break;
            case 6:
                printf("%c", '?');
                break;
        }
    }
}