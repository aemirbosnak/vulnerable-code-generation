//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>

// declare global variables
int secretCode = 12345;
char password[6] = "";

// function to check if password is correct
int checkPassword(char *password) {
    int i, check = 0;
    
    // iterate through characters in password
    for (i = 0; password[i] != '\0'; i++) {
        
        // perform paranoid encryption on each character
        password[i] = (char)(((int)password[i] * 7 - 2) / 3 + 10);
    }
    
    // check if password matches secret code
    check = strcmp(password, "dvymz");
    if (check == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int attempt = 0;
    
    // get user's input for password
    printf("Enter your password: ");
    scanf("%s", password);
    
    // check if password is correct
    if (checkPassword(password)) {
        printf("Access Granted.\n");
    } else {
        attempt++;
        printf("Incorrect Password.\n");
        
        // ask for another chance if attempt < 3
        if (attempt < 3) {
            main();
        } else {
            printf("Maximum Attempts Reached.\n");
            return 0;
        }
    }
    
    // secret message for authorized users only
    printf("The code is: %d\n", secretCode);
    
    return 0;
}