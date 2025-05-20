//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
    int length, uppercase, lowercase, numbers, specialChars, i, randNum;
    char password[50] = "";
    srand(time(NULL));

    printf("Hello! I'm your personal password generator, but I gotta ask, how long do you want your password to be?\n");
    scanf("%d", &length);
    
    if (length < 8) {
        printf("Are you serious? That's shorter than my memory span...alright, I'll go easy on you and make it 8 characters long.\n");
        length = 8;
    } else if (length > 50) {
        printf("I'm good, but not THAT good. How about we make it 50 characters or less?\n");
        scanf("%d", &length);
    }
    
    printf("Alright, now how many uppercase letters do you want?\n");
    scanf("%d", &uppercase);
    printf("How many lowercase letters do you want?\n");
    scanf("%d", &lowercase);
    printf("How many numbers do you want?\n");
    scanf("%d", &numbers);
    printf("And lastly, how many special characters do you want (e.g. !@$%^&)?\n");
    scanf("%d", &specialChars);
    
    int totalChars = uppercase + lowercase + numbers + specialChars;
    
    if (totalChars > length) {
        printf("You're asking for too much, buddy. Let me adjust your numbers so they fit within the password length.\n");
        
        float multiplier = (float)length / (float)totalChars;
        uppercase = (int)(uppercase * multiplier);
        lowercase = (int)(lowercase * multiplier);
        numbers = (int)(numbers * multiplier);
        specialChars = (int)(specialChars * multiplier);
        
        totalChars = uppercase + lowercase + numbers + specialChars;
        
        if (totalChars < length) {
            int diff = length - totalChars;
            specialChars += diff;
        }
    }
    
    printf("Hang tight, I'm gonna generate your super secure password now...\n");
    
    for (i = 0; i < uppercase; i++) {
        randNum = rand() % 26;
        password[i] = randNum + 65;
    }
    
    for (i = uppercase; i < uppercase + lowercase; i++) {
        randNum = rand() % 26;
        password[i] = randNum + 97;
    }
    
    for (i = uppercase + lowercase; i < uppercase + lowercase + numbers; i++) {
        randNum = rand() % 10;
        password[i] = randNum + 48;
    }
    
    char* specialCharacters = "!@$%^&*()_-+={}[]|\\:;\"'<>,.?/";
    int lenSpecialChars = strlen(specialCharacters);
    
    for (i = uppercase + lowercase + numbers; i < length; i++) {
        randNum = rand() % lenSpecialChars;
        password[i] = specialCharacters[randNum];
    }
    
    for(i = 0; i < length; i++) {
        int randomIndex = rand() % length;
        char temp = password[i];
        password[i] = password[randomIndex];
        password[randomIndex] = temp;
    }
    
    printf("Your super secure password is...\n");
    printf("%s\n", password);

    return 0;
}