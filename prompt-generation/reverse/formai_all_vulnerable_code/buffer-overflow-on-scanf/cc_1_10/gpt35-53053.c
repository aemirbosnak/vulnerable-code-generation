//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This function generates a random char based on ASCII range from 33 to 126 */
char gen_rand_char() {
    return (char)(rand() % 94 + 33);
}

/* This function generates a random password based on user input length and complexity */
void gen_password(int length, int complexity) {
    srand(time(NULL));  // Initialize random seed
    
    printf("Generating a secure password...\n");
    
    for (int i = 0; i < length; i++) {
        char rand_char;
        switch(complexity) {
            case 1:  // Lowercase only
                rand_char = gen_rand_char();
                while (rand_char < 'a' || rand_char > 'z') {
                    rand_char = gen_rand_char();
                }
                break;
            case 2:  // Uppercase only
                rand_char = gen_rand_char();
                while (rand_char < 'A' || rand_char > 'Z') {
                    rand_char = gen_rand_char();
                }
                break;
            case 3:  // Numbers only
                rand_char = gen_rand_char();
                while (rand_char < '0' || rand_char > '9') {
                    rand_char = gen_rand_char();
                }
                break;
            default:  // Mix of all complexity levels
                rand_char = gen_rand_char();
                break;
        }
        printf("%c", rand_char);
    }
    printf("\n");
}

int main() {
    int length, complexity;
    
    // Get user input for password length
    printf("Enter password length (min. 8): ");
    while (1) {
        scanf("%d", &length);
        if (length >= 8) {
            break;
        }
        printf("Password length must be at least 8 characters. Please try again: ");
    }
    
    // Get user input for password complexity
    printf("Enter password complexity (1-3):\n\t1. Lowercase only\n\t2. Uppercase only\n\t3. Numbers only\n\t4. Mix of all\n");
    while (1) {
        scanf("%d", &complexity);
        if (complexity >= 1 && complexity <= 4) {
            break;
        }
        printf("Invalid input. Please select a complexity level from 1 to 4: ");
    }
    
    gen_password(length, complexity);
    
    return 0;
}