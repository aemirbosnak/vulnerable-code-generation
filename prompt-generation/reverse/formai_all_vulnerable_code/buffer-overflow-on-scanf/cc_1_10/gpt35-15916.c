//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MIN_LEN 8 // Minimum length of password
#define MAX_LEN 20 // Maximum length of password

void printMenu();
int getRand(int min, int max);
void generatePassword();

int main(){

    printf("\nWelcome to the Secure Password Generator!\n");
    printMenu();

    return 0;
}


/**
 * Prints the menu of options for the user to choose from
 */
void printMenu(){
    printf("\nPlease choose an option from the menu:\n");
    printf("1. Generate a password\n");
    printf("2. Exit program\n");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            generatePassword();
            break;
        case 2:
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nInvalid option!\n");
            printMenu();
            break;
    }
}

/**
 * Generates a random integer between min and max (inclusive)
 * Source: https://stackoverflow.com/a/7560564/10407079
 *
 * @param min - minimum value of the generated integer
 * @param max - maximum value of the generated integer
 * @returns a random integer between min and max
 */
int getRand(int min, int max){
    static int seedSet = 0;

    if(!seedSet){
        srand(time(NULL));
        seedSet = 1;
    }

    return (rand() % (max - min + 1)) + min;
}

/**
 * Generates a secure password and prints it to the screen
 */
void generatePassword(){
    char password[MAX_LEN+1]; // Max length + 1 for null terminator
    const char* SYMBOLS = "!@#$%^&*()_+{}[]|\\:;'\"<>,./?";
    const char* DIGITS = "0123456789";
    const char* LOWERCASE_LETTERS = "abcdefghijklmnopqrstuvwxyz";
    const char* UPPERCASE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* CHAR_SETS[] = {SYMBOLS, DIGITS, LOWERCASE_LETTERS, UPPERCASE_LETTERS};
    const int NUM_CHAR_SETS = sizeof(CHAR_SETS)/sizeof(CHAR_SETS[0]);
    int charCount = 0;
    int len = getRand(MIN_LEN, MAX_LEN); // Length of password chosen randomly between MIN_LEN and MAX_LEN
    int numCharSetsUsed = 0;

    printf("\nGenerating password:\n");

    // Choose at least one character from each character set
    for(int i = 0; i < NUM_CHAR_SETS; i++){
        int charSetIndex = getRand(0, strlen(CHAR_SETS[i])-1);
        password[charCount++] = CHAR_SETS[i][charSetIndex];
        numCharSetsUsed++;
    }

    // Choose remaining character from any character set at random
    while(charCount < len){
        int charSetIndex = getRand(0, NUM_CHAR_SETS-1);
        int charIndex = getRand(0, strlen(CHAR_SETS[charSetIndex])-1);
        char newChar = CHAR_SETS[charSetIndex][charIndex];

        // Make sure new character is not already in password
        int matchFound = 0;
        for(int i = 0; i < charCount; i++){
            if(password[i] == newChar){
                matchFound = 1;
                break;
            }
        }

        if(!matchFound){
            password[charCount++] = newChar;
            numCharSetsUsed++;
        }
    }

    // Shuffle password using Fisher-Yates algorithm
    for(int i = len-1; i > 0; i--){
        int j = getRand(0, i);
        char temp = password[j];
        password[j] = password[i];
        password[i] = temp;
    }

    // Make sure password contains at least one character from each character set
    if(numCharSetsUsed < NUM_CHAR_SETS){
        generatePassword();
        return;
    }

    // Print password to screen
    printf("\nSecure password generated: ");
    for(int i = 0; i < len; i++){
        printf("%c", password[i]);
    }
    printf("\n");

    printMenu();
}