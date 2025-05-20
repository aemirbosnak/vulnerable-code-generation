//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_PASSWORD_LENGTH 20

void * checkPasswordStrength(void *);

int main() {
    pthread_t threads[MAX_PASSWORD_LENGTH + 1];
    int rc[MAX_PASSWORD_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];
    int i;

    printf("Enter a password to check its strength (max length: %d): ", MAX_PASSWORD_LENGTH);
    scanf("%s", password);

    for(i = 1; i <= MAX_PASSWORD_LENGTH; i++) {
        rc[i] = pthread_create(&threads[i], NULL, checkPasswordStrength, (void*)password);
        if (rc[i]) { 
            printf("ERROR: return code from pthread_create() is %d\n", rc[i]);
            exit(-1);
        }
    }

    printf("\nChecking password strength for length:\n");

    for(i = 1; i <= MAX_PASSWORD_LENGTH; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n");

    return 0;
}

void * checkPasswordStrength(void * arg) {
    char* password = (char*)arg;
    int length = strlen(password);
    int i;
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int special = 0;

    if(length == (int)pthread_self()) {
        for(i = 0; i < length; i++) {
            if(isupper(password[i])) {
                uppercase = 1;
            } else if(islower(password[i])) {
                lowercase = 1;
            } else if(isdigit(password[i])) {
                numbers = 1;
            } else {
                special = 1;
            }
        }

        printf("%d: ", length);

        if(length <= 8 && uppercase && lowercase && numbers) {
            printf("Medium\n");
        } else if(length > 8 && uppercase && lowercase && numbers && special) {
            printf("Strong\n");
        } else {
            printf("Weak\n");
        }
    }

    pthread_exit(NULL);
}