//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    
    int length, lower, upper, digit, special;
    char password[100];

    printf("*** RETRO STYLE SECURE PASSWORD GENERATOR ***\n\n");
    printf("Please enter the desired length of your password (at least 8 characters): ");
    scanf("%d", &length);

    while(length < 8) {
        printf("Length entered is too short. Please enter a length of at least 8 characters: ");
        scanf("%d", &length);
    }

    printf("\nDo you want to include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &lower);

    printf("Do you want to include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &upper);

    printf("Do you want to include digits? (1 for yes, 0 for no): ");
    scanf("%d", &digit);

    printf("Do you want to include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &special);

    while(lower == 0 && upper == 0 && digit == 0 && special == 0) {
        printf("\nAt least one of the options must be selected.\n");
        printf("Do you want to include lowercase letters? (1 for yes, 0 for no): ");
        scanf("%d", &lower);

        printf("Do you want to include uppercase letters? (1 for yes, 0 for no): ");
        scanf("%d", &upper);

        printf("Do you want to include digits? (1 for yes, 0 for no): ");
        scanf("%d", &digit);

        printf("Do you want to include special characters? (1 for yes, 0 for no): ");
        scanf("%d", &special);
    }

    const char lc[] = "abcdefghijklmnopqrstuvwxyz";
    const char uc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char d[] = "0123456789";
    const char sc[] = "!@#$%^&*()_+~`|}{[]:;?><,./-=";
    int lc_count = 0;
    int uc_count = 0;
    int d_count = 0;
    int sc_count = 0;

    while(lc_count == 0 || uc_count == 0 || d_count == 0 || sc_count == 0) {
        lc_count = 0;
        uc_count = 0;
        d_count = 0;
        sc_count = 0;

        for(int i = 0; i < length; i++) {
            int choice = rand() % 4;

            if(choice == 0 && lower == 1) {
                password[i] = lc[rand() % 26];
                lc_count++;
            }
            else if(choice == 1 && upper == 1) {
                password[i] = uc[rand() % 26];
                uc_count++;
            }
            else if(choice == 2 && digit == 1) {
                password[i] = d[rand() % 10];
                d_count++;
            }
            else if(choice == 3 && special == 1) {
                password[i] = sc[rand() % 23];
                sc_count++;
            }
            else {
                i--;
            }
        }
    }

    printf("\nYour generated password is: %s \n\n", password);

    return 0;
}