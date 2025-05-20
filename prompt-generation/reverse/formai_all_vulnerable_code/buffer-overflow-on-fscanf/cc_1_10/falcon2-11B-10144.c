//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100
#define DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_PASSWORD_LENGTH];
    int index;
} Dictionary;

int check_password_strength(const char* password) {
    int i;
    Dictionary dictionary[DICTIONARY_SIZE];
    FILE* fp;

    fp = fopen("password_dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    for (i = 0; i < DICTIONARY_SIZE; i++) {
        fscanf(fp, "%s", dictionary[i].word);
        dictionary[i].index = i;
    }

    fclose(fp);

    int count = 0;
    for (i = 0; i < strlen(password); i++) {
        if (isalpha(password[i]) || isdigit(password[i])) {
            int index = -1;
            for (int j = 0; j < DICTIONARY_SIZE; j++) {
                if (strncmp(password + i, dictionary[j].word, MAX_PASSWORD_LENGTH) == 0) {
                    index = j;
                    break;
                }
            }

            if (index!= -1) {
                count++;
            }
        }
    }

    if (count == 0) {
        printf("Password is strong\n");
    } else if (count < (DICTIONARY_SIZE / 2)) {
        printf("Password is weak\n");
    } else {
        printf("Password is very weak\n");
    }

    return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';

    check_password_strength(password);

    return 0;
}