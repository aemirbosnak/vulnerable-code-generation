//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int length, type;
    char password[100];

    printf("Welcome to the Secure Password Generator\n\n");
    printf("Please choose the length of your password: ");
    scanf("%d", &length);

    printf("Please choose the type of your password:\n\n");
    printf("1. Lowercase letters only\n");
    printf("2. Uppercase letters only\n");
    printf("3. Numbers only\n");
    printf("4. Special characters only\n");
    printf("5. All of the above\n");
    scanf("%d", &type);

    switch(type) {
        case 1:
            password[0] = (char) rand() % 26 + 'a';
            for(int i=1; i<length; i++) {
                password[i] = (char) rand() % 26 + 'a';
            }
            break;
        case 2:
            password[0] = (char) rand() % 26 + 'A';
            for(int i=1; i<length; i++) {
                password[i] = (char) rand() % 26 + 'A';
            }
            break;
        case 3:
            for(int i=0; i<length; i++) {
                password[i] = (char) rand() % 10 + '0';
            }
            break;
        case 4:
            password[0] = (char) rand() % 26 + 'a';
            for(int i=1; i<length; i++) {
                password[i] = (char) rand() % 26 + 'a';
            }
            break;
        case 5:
            password[0] = (char) rand() % 26 + 'a';
            for(int i=1; i<length; i++) {
                password[i] = (char) rand() % 26 + 'a';
            }
            for(int i=length-1; i>=0; i--) {
                if(password[i] >= 'a' && password[i] <= 'z') {
                    password[i] = (char) rand() % 26 + 'A';
                }
            }
            for(int i=0; i<length; i++) {
                if(password[i] >= 'A' && password[i] <= 'Z') {
                    password[i] = (char) rand() % 10 + '0';
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
    }

    printf("\nYour password is: %s\n", password);

    return 0;
}