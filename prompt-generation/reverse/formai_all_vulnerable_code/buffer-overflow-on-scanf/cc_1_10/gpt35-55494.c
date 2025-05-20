//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void generate_password(int n);

int main()
{
    int length;
    printf("Welcome to the C Secure Password Generator!\n");
    printf("Please enter the length of your password (minimum 8): ");
    scanf("%d", &length);
    if(length < 8){
        printf("Your password is too short. The minimum password length is 8.\n");
    }
    else{
        generate_password(length);
    }
    return 0;
}

void generate_password(int n)
{
    char password[n];
    int i;
    srand(time(NULL));
    for(i = 0; i < n; i++){
        int type = rand() % 4; //0 - lower, 1 - upper, 2 - number, 3 - symbol
        switch(type){
            case 0:
                password[i] = 'a' + rand() % 26;
                break;
            case 1:
                password[i] = 'A' + rand() % 26;
                break;
            case 2:
                password[i] = '0' + rand() % 10;
                break;
            case 3:
                password[i] = '!' + rand() % 15;
                break;
        }
    }
    password[n] = '\0';
    // shuffle the password
    for(i = 0; i < n; i++){
        int j = rand() % n;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    printf("Your secure password is: %s\n", password);
    return;
}