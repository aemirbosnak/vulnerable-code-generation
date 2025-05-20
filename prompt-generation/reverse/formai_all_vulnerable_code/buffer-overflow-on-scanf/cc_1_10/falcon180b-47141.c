//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define MAX_PASS_LEN 30
#define MIN_PASS_LEN 8
#define NUM_CHARS 62

void generate_password(char *password, int length, int complexity) {
    char charset[NUM_CHARS] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int i = 0;
    password[i] = '\0';
    if(length < MIN_PASS_LEN) {
        length = MIN_PASS_LEN;
    }
    if(complexity == 0) {
        for(i = 0; i < length; i++) {
            password[i] = charset[rand() % NUM_CHARS];
        }
    }
    else if(complexity == 1) {
        for(i = 0; i < length; i++) {
            if(i % 2 == 0) {
                password[i] = charset[rand() % NUM_CHARS];
            }
            else {
                password[i] = '!';
            }
        }
    }
    else if(complexity == 2) {
        for(i = 0; i < length; i++) {
            if(i % 3 == 0) {
                password[i] = charset[rand() % NUM_CHARS];
            }
            else {
                password[i] = '!';
            }
        }
    }
    else {
        for(i = 0; i < length; i++) {
            if(i % 4 == 0) {
                password[i] = charset[rand() % NUM_CHARS];
            }
            else {
                password[i] = '!';
            }
        }
    }
}

int main() {
    char password[MAX_PASS_LEN];
    int length, complexity;
    srand(time(NULL));
    printf("Enter password length:\n");
    scanf("%d", &length);
    printf("Enter password complexity (0-3):\n");
    scanf("%d", &complexity);
    generate_password(password, length, complexity);
    printf("Generated password: %s\n", password);
    return 0;
}