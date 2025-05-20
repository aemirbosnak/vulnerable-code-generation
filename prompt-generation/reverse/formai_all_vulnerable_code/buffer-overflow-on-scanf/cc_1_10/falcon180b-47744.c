//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_LOWER_CASE 1
#define MIN_UPPER_CASE 1
#define MIN_DIGITS 1
#define MIN_SPECIAL_CHARS 1

typedef struct {
    int id;
    char password[MAX_PASSWORD_LENGTH];
} Password;

void *check_password_strength(void *arg) {
    Password *password = (Password *) arg;
    int length = strlen(password->password);
    int lower_case = 0, upper_case = 0, digits = 0, special_chars = 0;
    
    for (int i = 0; i < length; i++) {
        if (isdigit(password->password[i])) {
            digits++;
        }
        else if (isalpha(password->password[i])) {
            if (tolower(password->password[i]) >= 'a' && tolower(password->password[i]) <= 'z') {
                lower_case++;
            }
            else if (tolower(password->password[i]) >= 'A' && tolower(password->password[i]) <= 'Z') {
                upper_case++;
            }
        }
        else if (isalnum(password->password[i]) == 0) {
            special_chars++;
        }
    }
    
    if (length >= MIN_PASSWORD_LENGTH && lower_case >= MIN_LOWER_CASE && upper_case >= MIN_UPPER_CASE && digits >= MIN_DIGITS && special_chars >= MIN_SPECIAL_CHARS) {
        printf("Password %d is strong.\n", password->id);
    }
    else {
        printf("Password %d is weak.\n", password->id);
    }
    
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    Password passwords[MAX_THREADS];
    
    int num_passwords = 0;
    
    printf("Enter the number of passwords to check: ");
    scanf("%d", &num_passwords);
    
    for (int i = 0; i < num_passwords; i++) {
        printf("Enter password %d: ", i + 1);
        scanf("%s", passwords[i].password);
        passwords[i].id = i + 1;
    }
    
    for (int i = 0; i < num_passwords; i++) {
        pthread_create(&threads[i], NULL, check_password_strength, (void *) &passwords[i]);
    }
    
    for (int i = 0; i < num_passwords; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}