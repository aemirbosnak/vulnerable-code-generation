//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define CHAR_SET_LEN 79
#define PASSWORD_LEN 16

char char_set[CHAR_SET_LEN] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";

int generate_password(char *password) {
    int i;
    for (i = 0; i < PASSWORD_LEN; i++) {
        password[i] = char_set[rand() % CHAR_SET_LEN];
    }
    password[PASSWORD_LEN - 1] = '\0';
    return 0;
}

int main(int argc, char *argv[]) {
    int i;
    FILE *file;
    char filename[50];
    char password[PASSWORD_LEN + 1];
    time_t t;

    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n");
    printf("This program will generate a secure password for you.\n\n");

    printf("Please enter the name of the file to save the password to: ");
    scanf("%s", filename);

    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }

    generate_password(password);

    fprintf(file, "Your secure password is: %s\n", password);

    fclose(file);

    printf("Your secure password has been saved to the file %s.\n", filename);

    return 0;
}