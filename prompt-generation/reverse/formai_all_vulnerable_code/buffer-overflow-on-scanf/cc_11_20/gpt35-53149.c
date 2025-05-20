//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {
    // Define variable for password length
    int pwd_length;
    // Define variables for character ranges
    int num_start = 48, num_end = 57;
    int upper_start = 65, upper_end = 90;
    int lower_start = 97, lower_end = 122;
    // Define variable for password characters
    char pwd_chars[70];
    // Define variable for generated password
    char password[20] = {'\0'};
    // Define variable for random index
    int random_index;
    // Define variable for character type
    int char_type;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Ask user for password length
    printf("How many characters do you want in your password? (between 8 and 20): ");
    scanf("%d", &pwd_length);

    // Validate user input for password length
    while (pwd_length < 8 || pwd_length > 20) {
        printf("Invalid input. Please enter a number between 8 and 20: ");
        scanf("%d", &pwd_length);
    }

    // Generate array of possible password characters
    int i = 0;
    for (int n = num_start; n <= num_end; n++) {
        pwd_chars[i] = (char) n;
        i++;
    }
    for (int u = upper_start; u <= upper_end; u++) {
        pwd_chars[i] = (char) u;
        i++;
    }
    for (int l = lower_start; l <= lower_end; l++) {
        pwd_chars[i] = (char) l;
        i++;
    }

    // Generate random password
    for (int j = 0; j < pwd_length; j++) {
        random_index = rand() % 69; // 69 is the total number of characters in the pwd_chars array
        char_type = rand() % 3; // Will generate 0, 1, or 2 for numeric, uppercase, or lowercase character
        
        // Check if randomly selected character is of the desired type
        if (char_type == 0 && isdigit(pwd_chars[random_index])) {
            password[j] = pwd_chars[random_index];
        } else if (char_type == 1 && isupper(pwd_chars[random_index])) {
            password[j] = pwd_chars[random_index];
        } else if (char_type == 2 && islower(pwd_chars[random_index])) {
            password[j] = pwd_chars[random_index];
        } else {
            // If not of the desired type, generate a new random index and character type
            j--;
        }
    }

    // Print generated password
    printf("Your generated password is: %s", password);

    return 0;
}