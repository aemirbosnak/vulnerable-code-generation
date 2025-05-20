//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Oh, how now shall our passwords be secure?\n");
    printf("It doth verily vex my soul.\n");
    
    // Setup random seed generator
    srand(time(NULL));
    
    // Define character sets for password generation
    char alphabets[] = "abcdefghijklmnopqrstuvwxyz";
    char caps[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char nums[] = "0123456789";
    char symbols[] = "!@#$%^&*";
    
    // Prompt user for password length
    int passLength;
    printf("How many characters long should the password be?\n");
    scanf("%d", &passLength);
    
    // Generate random password
    char password[passLength+1];
    for (int i = 0; i < passLength; i++) {
        int randomType = rand()%4;
        int randomChar;
        
        switch(randomType) {
            case 0:
                randomChar = rand()%26;
                password[i] = alphabets[randomChar];
                break;
            case 1:
                randomChar = rand()%26;
                password[i] = caps[randomChar];
                break;
            case 2:
                randomChar = rand()%10;
                password[i] = nums[randomChar];
                break;
            case 3:
                randomChar = rand()%8;
                password[i] = symbols[randomChar];
                break;
        }
    }
    password[passLength] = '\0';
    
    printf("Behold, thy secure password: %s\n", password);
    
    return 0;
}