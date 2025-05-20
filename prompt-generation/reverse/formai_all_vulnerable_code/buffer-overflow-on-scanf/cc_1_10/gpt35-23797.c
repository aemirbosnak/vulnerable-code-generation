//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <sys/ioctl.h>
#include <sys/signal.h>
#include <termios.h>
#include <time.h>

#define MAX_PASSWORDS 10 //maximum number of passwords that can be stored
#define PASSWORD_SIZE 16 //maximum length of password
#define SALT_SIZE 10 //length of salt

char passwords[MAX_PASSWORDS][PASSWORD_SIZE + 1];
char salts[MAX_PASSWORDS][SALT_SIZE + 1];
int num_passwords = 0;

//function to get user input without echoing to terminal
void get_password(char* password) {
    printf("Enter password: ");
    struct termios old, new;
    tcgetattr(fileno(stdin), &old);
    new = old;
    new.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), TCSANOW, &new);
    scanf("%s", password);
    tcsetattr(fileno(stdin), TCSANOW, &old);
    printf("\n");
}

//function to generate a random salt
void generate_salt(char* salt) {
    const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));
    for (int i = 0; i < SALT_SIZE; i++) {
        salt[i] = charset[rand() % 62];
    }
    salt[SALT_SIZE] = '\0';
}

//function to hash a password using bcrypt algorithm
char* hash_password(const char* password, const char* salt) {
    char* result = NULL;
    char* cmd = malloc(strlen(password) + strlen(salt) + 30);
    sprintf(cmd, "echo '%s' | openssl passwd -1 -stdin -salt '%s'", password, salt);
    FILE* pipe = popen(cmd, "r");
    if (pipe == NULL) {
        printf("Error: Could not run password hashing command\n");
        return NULL;
    }
    char buffer[PASSWORD_SIZE + 1];
    size_t size = 0;
    while ((size = fread(buffer, 1, PASSWORD_SIZE, pipe)) != 0) {
        result = realloc(result, strlen(result) + size + 1);
        memcpy(result + strlen(result), buffer, size);
    }
    pclose(pipe);
    result[strlen(result) - 1] = '\0'; //remove newline character
    free(cmd);
    return result;
}

//function to add a new password
void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached (%d)\n", MAX_PASSWORDS);
        return;
    }
    char password[PASSWORD_SIZE + 1];
    get_password(password);
    char salt[SALT_SIZE + 1];
    generate_salt(salt);
    char* hashed_password = hash_password(password, salt);
    if (hashed_password == NULL) {
        return;
    }
    strcpy(passwords[num_passwords], hashed_password);
    strcpy(salts[num_passwords], salt);
    num_passwords++;
    printf("Password added successfully\n");
}

//function to validate a password
int validate_password(char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(hash_password(password, salts[i]), passwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            add_password();
        }
        else if (strcmp(input, "validate") == 0) {
            char password[PASSWORD_SIZE + 1];
            get_password(password);
            if (validate_password(password)) {
                printf("Password is valid\n");
            }
            else {
                printf("Password is invalid\n");
            }
        }
        else if (strcmp(input, "exit") == 0) {
            return 0;
        }
        else {
            printf("Error: Invalid command\n");
        }
    }
}