//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

void reverseString(char* str);
void toggleCase(char* str);
int countVowels(char* str);
void toUpperCase(char* str);
void toLowerCase(char* str);

int main() {
    char inputString[MAX_STRING_LENGTH];
    int choice;

    printf("=======================================\n");
    printf("         Retro String Manipulator      \n");
    printf("=======================================\n");
    
    printf("Enter a string (max %d characters): ", MAX_STRING_LENGTH - 1);
    fgets(inputString, MAX_STRING_LENGTH, stdin);
    
    // Remove newline character if present
    size_t len = strlen(inputString);
    if (len > 0 && inputString[len - 1] == '\n') {
        inputString[len - 1] = '\0';
    }

    do {
        printf("\nChoose an option:\n");
        printf("1. Reverse the string\n");
        printf("2. Toggle case of the string\n");
        printf("3. Count vowels in the string\n");
        printf("4. Convert to uppercase\n");
        printf("5. Convert to lowercase\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline

        switch(choice) {
            case 1:
                reverseString(inputString);
                printf("Reversed String: %s\n", inputString);
                break;
            case 2:
                toggleCase(inputString);
                printf("Toggled Case String: %s\n", inputString);
                break;
            case 3:
                printf("Number of vowels: %d\n", countVowels(inputString));
                break;
            case 4:
                toUpperCase(inputString);
                printf("Uppercase String: %s\n", inputString);
                break;
            case 5:
                toLowerCase(inputString);
                printf("Lowercase String: %s\n", inputString);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}

void reverseString(char* str) {
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void toggleCase(char* str) {
    for(int i = 0; str[i]; i++) {
        if(isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if(islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int countVowels(char* str) {
    int count = 0;
    for(int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

void toUpperCase(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}