//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    srand(time(NULL));
    int length = 0, num_count = 0, upper_count = 0, lower_count = 0, special_count = 0;
    printf("Welcome to the password generator!\n");
    while(length == 0) {
        printf("How long would you like your password to be? (min 8 characters)\n");
        scanf("%d", &length);
        if(length < 8) {
            printf("Password must be at least 8 characters long.\n");
            length = 0;
        }
    }
    while(num_count == 0 && upper_count == 0 && lower_count == 0 && special_count == 0) {
        printf("How many numbers would you like in your password?\n");
        scanf("%d", &num_count);
        printf("How many uppercase letters would you like in your password?\n");
        scanf("%d", &upper_count);
        printf("How many lowercase letters would you like in your password?\n");
        scanf("%d", &lower_count);
        printf("How many special characters would you like in your password? (e.g. !@#$%%^&*)\n");
        scanf("%d", &special_count);
        if(num_count + upper_count + lower_count + special_count < length) {
            printf("The total number of characters must be at least equal to the length of the password.\n");
            num_count = 0;
            upper_count = 0;
            lower_count = 0;
            special_count = 0;
        }
    }
    char password[length];
    int char_count = 0;
    while(char_count < length) {
        int type = rand() % 4;
        if(type == 0 && num_count > 0) {
            password[char_count] = '0' + rand() % 10;
            char_count++;
            num_count--;
        }
        else if(type == 1 && upper_count > 0) {
            password[char_count] = 'A' + rand() % 26;
            char_count++;
            upper_count--;
        }
        else if(type == 2 && lower_count > 0) {
            password[char_count] = 'a' + rand() % 26;
            char_count++;
            lower_count--;
        }
        else if(type == 3 && special_count > 0) {
            char special_chars[] = "!@#$%^&*()_+-=[]{}|<>?,./";
            password[char_count] = special_chars[rand() % strlen(special_chars)];
            char_count++;
            special_count--;
        }
    }
    printf("Your new secure password is: %s\n", password);
    return 0;
}