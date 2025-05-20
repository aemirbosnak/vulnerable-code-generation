//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// function to check password strength
void *password_checker(void *str) {
    char *password = (char *) str;
    int len = strlen(password);
    int num_digits = 0;
    int num_symbols = 0;
    int num_lower = 0;
    int num_upper = 0;
    int i;
    
    for(i=0; i<len; i++) {
        if(isdigit(password[i])) {
            num_digits++;
        } else if(isalpha(password[i])) {
            if(islower(password[i])) {
                num_lower++;
            } else {
                num_upper++;
            }
        } else {
            num_symbols++;
        }
    }

    // password strength calculation based on number of digits, symbols, lower and upper case letters
    if(num_digits>0 && num_symbols>0 && num_lower>0 && num_upper>0 && len>=8) {
        printf("Strong Password!\n");
    } else if(len>=6) {
        printf("Moderate Password!\n");
    } else {
        printf("Weak Password!\n");
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int i;
    char passwords[3][50];
    
    printf("Enter 3 passwords to check their strength:\n");

    // get the passwords from the user
    for(i=0; i<3; i++) {
        printf("Password %d: ", i+1);
        scanf("%s", passwords[i]);
    }
    printf("\n");

    // create threads to check password strength
    for(i=0; i<3; i++) {
        pthread_create(&threads[i], NULL, password_checker, (void *) passwords[i]);
    }

    // wait for threads to complete execution
    for(i=0; i<3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}