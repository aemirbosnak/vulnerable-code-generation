//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

void generate_password(char* password, int length) {
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '<', '>', '?'};
    int num_symbols = sizeof(symbols) / sizeof(symbols[0]);
    
    srand(time(0)); // seed random number generator
    
    for (int i = 0; i < length; i++) {
        int random_char;
        int char_type = rand() % 3; // generate random number to determine character type
        
        switch (char_type) {
            case 0: // generate random lowercase letter
                random_char = 'a' + rand() % 26;
                break;
            case 1: // generate random uppercase letter
                random_char = 'A' + rand() % 26;
                break;
            case 2: // generate random symbol
                random_char = symbols[rand() % num_symbols];
                break;
        }
        
        password[i] = random_char;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;
    
    printf("=== Secure Password Generator ===\n");
    printf("Enter desired password length (%d-%d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
    
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid length entered. Password length must be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }
    
    generate_password(password, length);
    
    printf("Generated password: %s\n", password);
    
    return 0;
}