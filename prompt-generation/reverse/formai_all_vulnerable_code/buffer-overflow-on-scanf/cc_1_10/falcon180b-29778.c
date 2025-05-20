//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH + 1] = {0};
    int length = 0;
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char *ptr;
    
    printf("Enter the desired length of the password: ");
    scanf("%d", &length);
    
    if (length < 1 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }
    
    printf("Enter the number of uppercase letters to include: ");
    scanf("%d", &length);
    printf("Enter the number of lowercase letters to include: ");
    scanf("%d", &length);
    printf("Enter the number of digits to include: ");
    scanf("%d", &length);
    
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 62 + 'a';
    }
    
    ptr = password;
    while (*ptr) {
        int choice = rand() % 4;
        switch (choice) {
            case 0:
                *ptr = toupper(*ptr);
                break;
            case 1:
                *ptr = tolower(*ptr);
                break;
            case 2:
                *ptr = '0' + rand() % 10;
                break;
            default:
                break;
        }
        ptr++;
    }
    
    printf("Your secure password is: %s\n", password);
    
    return 0;
}