//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_LEN 8
#define MAX_LEN 16

/* Function Prototypes */
void generate_password(int length);
int get_rand_num(int min, int max);

int main() {
    int length;
    char choice;

    /* Seed the random number generator */
    srand(time(NULL));

    /* Loop until user quits */
    while(1) {
        printf("Password Length (%d-%d): ", MIN_LEN, MAX_LEN);
        scanf("%d", &length);

        /* Check for valid length */
        if(length < MIN_LEN || length > MAX_LEN) {
            printf("Invalid Length!\n");
            continue;
        }

        /* Generate password */
        generate_password(length);

        /* Ask user if they want to quit */
        printf("\nGenerate Another Password? (Y/N): ");
        scanf(" %c", &choice);

        /* Check user's choice */
        if(toupper(choice) == 'N') {
            break;
        }
    }

    return 0;
}

/* Function Definitions */
void generate_password(int length) {
    int i, rand_num;
    char password[MAX_LEN+1];   /* to hold password */

    /* Ensure password is empty */
    memset(password, 0, sizeof(password));

    /* Generate password */
    for(i=0; i<length; i++) {
        rand_num = get_rand_num(0, 2);

        /* Generate random number */
        switch(rand_num) {
            case 0: /* lowercase letter */
                    password[i] = 'a' + get_rand_num(0, 25);
                    break;

            case 1: /* uppercase letter */
                    password[i] = 'A' + get_rand_num(0, 25);
                    break;

            case 2: /* number */
                    password[i] = '0' + get_rand_num(0, 9);
                    break;

            default: /* error */
                    printf("ERROR: Unknown rand_num %d\n", rand_num);
                    break;
        }
    }

    /* print password */
    printf("Password:\t%s\n", password);
}

int get_rand_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}