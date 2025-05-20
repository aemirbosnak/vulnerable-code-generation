//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8    //minimum length of the password
#define MAX_LENGTH 20   //maximum length of the password
#define SPECIAL_CHARS "!@#$%^&*()_+{}:<>?-=[]\\|/.,"
                        //list of special characters that can be included in the password

int main() {
    //Seed the random number generator
    srand(time(NULL));

    //Ask the user for the desired length of the password
    int length;
    printf("Enter the desired length of the password (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    //Make sure the password length is within the acceptable range
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Error: Password length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;   //exit the program with error code 1
    }

    //Determine the number of special characters to include in the password
    int num_special_chars = length / 4;

    //Generate the password
    char password[MAX_LENGTH + 1] = {'\0'};   //initialize password to null characters
    int i;
    for (i = 0; i < length; i++) {
        int r = rand() % 3; //randomly choose a character type: 0=lowercase, 1=uppercase, 2=digit
        if (r == 0) {   //lowercase character
            password[i] = 'a' + (rand() % 26);
        } else if (r == 1) {    //uppercase character
            password[i] = 'A' + (rand() % 26);
        } else {    //digit
            password[i] = '0' + (rand() % 10);
        }
    }

    //Insert the special characters into the password
    for (i = 0; i < num_special_chars; i++) {
        int pos = rand() % length;  //randomly choose a position in the password
        int char_pos = rand() % (sizeof(SPECIAL_CHARS) - 1);   //randomly choose a special character
        password[pos] = SPECIAL_CHARS[char_pos];
    }

    //Print the password
    printf("Your password is: %s\n", password);

    return 0;   //exit the program with success code 0
}