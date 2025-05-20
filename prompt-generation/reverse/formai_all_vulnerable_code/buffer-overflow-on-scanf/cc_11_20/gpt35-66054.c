//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, i, j;
    char password[50];
    srand(time(0));
    
    printf("Enter the length of the password you want to generate (between 8 and 50): ");
    scanf("%d", &length);
    
    if (length < 8 || length > 50) {
        printf("Invalid length! Please enter a number between 8 and 50.\n");
        return 1;
    }
    
    printf("Your secure password is: ");
    
    for (i = 0; i < length; i++) {
        int choice = rand() % 4;
        
        switch (choice) {
            case 0:
                // Generate a lower case letter
                password[i] = 'a' + rand() % 26;
                break;
            case 1:
                // Generate an upper case letter
                password[i] = 'A' + rand() % 26;
                break;
            case 2:
                // Generate a digit
                password[i] = '0' + rand() % 10;
                break;
            case 3:
                // Generate a special character
                j = rand() % 6;
                switch (j) {
                    case 0:
                        password[i] = '!';
                        break;
                    case 1:
                        password[i] = '@';
                        break;
                    case 2:
                        password[i] = '#';
                        break;
                    case 3:
                        password[i] = '$';
                        break;
                    case 4:
                        password[i] = '%';
                        break;
                    case 5:
                        password[i] = '&';
                        break;
                }
                break;
        }
        
        printf("%c", password[i]);
    }
    
    printf("\n");
    
    return 0;
}