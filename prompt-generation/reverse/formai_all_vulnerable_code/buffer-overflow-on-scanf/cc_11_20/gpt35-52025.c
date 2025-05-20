//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define NUM_CHARACTERS 94

int main(void) {
    char password[MAX_LENGTH + 1];
    int length = 0;
    int i, j;
    
    srand(time(NULL));
    
    printf("Secure Password Generator\n");
    printf("-------------------------\n");
    
    // User input for password length
    while (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Enter password length between %d and %d: ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);
    }
    
    printf("\nGenerated password: ");
    
    // Generate random password
    for (i = 0; i < length; i++) {
        char c = rand() % NUM_CHARACTERS + 32; // Random ASCII characters between 32 and 126
        
        // Ensure password contains at least one uppercase letter, lowercase letter, digit, and special character
        if (i == 0) {
            while (!isdigit(c) && !islower(c) && !isupper(c)) {
                c = rand() % NUM_CHARACTERS + 32; 
            }
        }
        
        // Ensure password does not contain consecutive identical characters
        if (i > 0 && c == password[i-1]) {
            i--;
            continue;
        }
        
        // Add character to password
        password[i] = c;
    }
    
    // Add null terminator to end of password
    password[length] = '\0';
    
    // Shuffle password characters randomly
    for (i = length - 1; i > 0; i--) {
        j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // Output generated password
    printf("%s\n", password);
    
    return 0;
}