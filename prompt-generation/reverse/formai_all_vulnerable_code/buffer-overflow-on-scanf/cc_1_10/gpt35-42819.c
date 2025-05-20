//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define true 1
#define false 0

// Function Prototypes
char* generatePassword(int length, int uppercase, int lowercase, int numbers, int specialChars);
int containsOnlyNumbers(char* str);

int main(void) {
    int length, uppercase, lowercase, numbers, specialChars;
    printf("Welcome to the Cyberpunk Password Generator!\n\n");
    printf("Enter the desired length of your password (8-50): ");
    scanf("%d", &length);
    printf("\nDo you want uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &uppercase);
    printf("\nDo you want lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &lowercase);
    printf("\nDo you want numbers? (1 for yes, 0 for no): ");
    scanf("%d", &numbers);
    printf("\nDo you want special characters? (1 for yes, 0 for no): ");
    scanf("%d", &specialChars);
    char* password = generatePassword(length, uppercase, lowercase, numbers, specialChars);
    printf("\n\nYour Cyberpunk Password is: %s\n\n", password);
    free(password);
    return 0;
}

char* generatePassword(int length, int uppercase, int lowercase, int numbers, int specialChars) {
    srand(time(NULL)); // Seed the random number generator with current time
    char* password = (char*) malloc(length+1);
    int numUppercase = 0, numLowercase = 0, numNumbers = 0, numSpecialChars = 0;
    int numChars = uppercase + lowercase + numbers + specialChars;
    if (numChars == 0) {
        printf("Generate Password Failed. No character type is selected\n");
        exit(-1);
    }
    if (length < numChars) {
        printf("Generate Password Failed. Password length is shorter than the number of selected character types\n");
        exit(-1);
    }
    for (int i = 0; i < length; i++) {
        int num = rand() % 4; // Randomly select a character type from the 4 possible types
        if (num == 0 && uppercase && numUppercase < (length-numChars+1)/4) { // Check if need to add uppercase character
            password[i] = 'A' + rand()%26;
            numUppercase++;
        }
        else if (num == 1 && lowercase && numLowercase < (length-numChars+1)/4) { // Check if need to add lowercase character
            password[i] = 'a' + rand()%26;
            numLowercase++;
        }
        else if (num == 2 && numbers && numNumbers < (length-numChars+1)/4) { // Check if need to add number
            password[i] = '0' + rand()%10;
            numNumbers++;
        }
        else if (num == 3 && specialChars && numSpecialChars < (length-numChars+1)/4) { // Check if need to add special character
            password[i] = "!@#$%^&*()_+{}|:<>?~`"[rand()%20];
            numSpecialChars++;
        }
        else { // If chosen character type is not needed, try again
            i--;
        }
    }
    password[length] = '\0';
    int containOnlyNumbers = containsOnlyNumbers(password);
    if (containOnlyNumbers) { //If Password has only numbers, it's not accepted
        printf("Your generated password contains only numbers. Generating a new password...");
        free(password);
        return generatePassword(length, uppercase, lowercase, numbers, specialChars);
    }
    else {
        return password;
    }
}

int containsOnlyNumbers(char* str) {
    for (int i=0; str[i]!='\0'; i++) {
        if(isdigit(str[i]) == false) {
            return false;
        }
    }
    return true;
}