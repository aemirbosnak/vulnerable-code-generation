//Falcon2-11B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 32

void generatePassword(char* password, int length);
void generateRandomPassword(char* password, int length);
void printPassword(char* password);
void savePassword(char* password, char* filename);
void deletePassword(char* password);

int main() {
    char password[MAX_LEN];
    char filename[MAX_LEN];
    int length = 0;

    printf("Please enter password length: ");
    scanf("%d", &length);

    printf("Please enter password filename: ");
    scanf("%s", filename);

    generatePassword(password, length);
    printPassword(password);

    savePassword(password, filename);

    printf("Please enter password to delete: ");
    scanf("%s", password);
    deletePassword(password);

    return 0;
}

void generatePassword(char* password, int length) {
    srand(time(0));

    for (int i = 0; i < length; i++) {
        password[i] = 'A' + (rand() % 26);
    }
}

void generateRandomPassword(char* password, int length) {
    for (int i = 0; i < length; i++) {
        password[i] = 'A' + (rand() % 26);
    }
}

void printPassword(char* password) {
    printf("Your password is: %s\n", password);
}

void savePassword(char* password, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    fprintf(file, "Your password is: %s\n", password);

    fclose(file);
}

void deletePassword(char* password) {
    FILE* file = fopen("password.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    fprintf(file, "Your password has been deleted.\n");

    fclose(file);
}