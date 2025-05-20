//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define THRESHOLD 10

int main(void) {
    
    printf("Welcome to Happy IDS!\n");

    int count = 0; // count of failed login attempts
    bool is_wrong_username = false;
    char* username = "happyuser";
    char* password = "password";

    while(true) {

        char input_username[50];
        char input_password[50];

        printf("\nEnter your username: ");
        scanf("%s", input_username);

        if(strcmp(input_username, username) != 0) {
            printf("\nIncorrect username. Try again.\n");
            is_wrong_username = true;
            continue;
        }

        printf("\nEnter your password: ");
        scanf("%s", input_password);

        if(strcmp(input_password, password) != 0) {
            printf("\nIncorrect password. Try again.\n");
            is_wrong_username = false;
            count++;
            printf("\n%d failed attempts.\n", count);
        } else {
            printf("\nWelcome back, Happy User!\n");
            count = 0;
            is_wrong_username = false;
        }

        if(count > THRESHOLD) {
            printf("\nPossible intrusion detected. Please contact your administrator.\n");
            exit(1);
        }
        
        if(is_wrong_username) {
            printf("\nFailed attempts will not be logged due to wrong username.\n");
        } else {
            printf("\nFailed attempts will be logged.\n");
        }
    }

    return 0;
}