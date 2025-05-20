//FormAI DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 10
#define MAX_PASSWORDS 20
#define MAX_ATTEMPTS 3

char users[MAX_USERS][20] = {"John", "Mary", "Robert", "Sarah", "David", "Emily", "Thomas", "Lucy", "Michael", "Olivia"};
char passwords[MAX_PASSWORDS][20] = {"X8#mgYd!", "fT5$Ea#", "9hL6*s@", "bK3$pR!", "7jN2&c#", "vQ4%nS!", "6dF1@g#", "tW2^xH!", "5lM9#yE", "sP7&zA!"};

void encrypt(char *pass);

int main() {
    char username[20], password[20];
    int attempts, i, j, user_index, is_valid;
    
    while(1) {
        printf("\nPlease enter your username: ");
        scanf("%s", username);
        
        // check if username exists
        is_valid = 0;
        for(i = 0; i < MAX_USERS; i++) {
            if(strcmp(users[i], username) == 0) {
                user_index = i;
                is_valid = 1;
                break;
            }
        }
        if(!is_valid) {
            printf("Invalid username!\n");
            continue;
        }
        
        // check password
        attempts = 0;
        while(attempts < MAX_ATTEMPTS) {
            printf("Please enter your password: ");
            scanf("%s", password);
            encrypt(password); // encrypt password before comparing
            
            if(strcmp(passwords[user_index], password) == 0) {
                printf("Welcome, %s!\n", username);
                break;
            } else {
                attempts++;
                printf("Incorrect password (%d/%d attempts). Please try again.\n", attempts, MAX_ATTEMPTS);
            }
        }
        if(attempts >= MAX_ATTEMPTS) {
            printf("Maximum number of attempts exceeded. Sorry, access denied.\n");
            exit(0);
        }
    }
    return 0;
}

// encryption function (algorithm confidential)
void encrypt(char *pass) {
    int i, len = strlen(pass);
    for(i = 0; i < len; i++) {
        if(isalpha(pass[i])) {
            if(islower(pass[i])) {
                pass[i] = (char)(((int)pass[i] - 97 + 13) % 26 + 97);
            } else {
                pass[i] = (char)(((int)pass[i] - 65 + 13) % 26 + 65);
            }
        } else if(isdigit(pass[i])) {
            pass[i] = (char)(((int)pass[i] - 48 + 5) % 10 + 48);
        } else {
            switch(pass[i]) {
                case '!':
                    pass[i] = '@';
                    break;
                case '@':
                    pass[i] = '#';
                    break;
                case '#':
                    pass[i] = '$';
                    break;
                case '$':
                    pass[i] = '%';
                    break;
                case '%':
                    pass[i] = '^';
                    break;
                case '^':
                    pass[i] = '&';
                    break;
                case '&':
                    pass[i] = '*';
                    break;
                case '*':
                    pass[i] = '(';
                    break;
                case '(':
                    pass[i] = ')';
                    break;
                case ')':
                    pass[i] = '-';
                    break;
                case '-':
                    pass[i] = '_';
                    break;
                case '_':
                    pass[i] = '+';
                    break;
                case '+':
                    pass[i] = '=';
                    break;
                case '=':
                    pass[i] = '`';
                    break;
                case '`':
                    pass[i] = '~';
                    break;
                case '~':
                    pass[i] = ';';
                    break;
                case ';':
                    pass[i] = ':';
                    break;
                case ':':
                    pass[i] = '"';
                    break;
                case '"':
                    pass[i] = '\'';
                    break;
                case '\'':
                    pass[i] = '\\';
                    break;
                case '\\':
                    pass[i] = '/';
                    break;
                case '/':
                    pass[i] = ',';
                    break;
                case ',':
                    pass[i] = '.';
                    break;
                case '.':
                    pass[i] = '<';
                    break;
                case '<':
                    pass[i] = '>';
                    break;
                case '>':
                    pass[i] = '?';
                    break;
                case '?':
                    pass[i] = '{';
                    break;
                case '{':
                    pass[i] = '}';
                    break;
                case '}':
                    pass[i] = '[';
                    break;
                case '[':
                    pass[i] = ']';
                    break;
                case ']':
                    pass[i] = '|';
                    break;
                case '|':
                    pass[i] = '#';
                    break;
            }
        }
    }
}