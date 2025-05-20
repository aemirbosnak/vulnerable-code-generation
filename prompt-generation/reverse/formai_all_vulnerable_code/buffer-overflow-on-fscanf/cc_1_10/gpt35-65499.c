//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_SIZE 50

struct password {
    char website[MAX_SIZE];
    char username[MAX_SIZE];
    char password[MAX_SIZE];
};

struct password password_data[MAX_PASSWORDS];
int password_count = 0;

void addPassword() {
    char website[MAX_SIZE];
    char username[MAX_SIZE];
    char password[MAX_SIZE];

    printf("\nWebsite Name: ");
    scanf("%s", website);
    printf("\nUsername: ");
    scanf("%s", username);
    printf("\nPassword: ");
    scanf("%s", password);

    struct password *pwd = &(password_data[password_count++]);
    strcpy(pwd->website, website);
    strcpy(pwd->username, username);
    strcpy(pwd->password, password);
    printf("\nPassword successfully saved!\n");
}

void showPasswords() {
    if (password_count == 0) {
        printf("\nNo passwords saved yet!\n");
        return;
    }
    printf("\nWebsite\tUsername\tPassword\n");
    for (int i = 0; i < password_count; i++) {
        struct password *pwd = &(password_data[i]);
        printf("%s\t%s\t%s\n", pwd->website, pwd->username, pwd->password);
    }
}

void encrypt(char *str, int key) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + key;
    }
}

void decrypt(char *str, int key) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] - key;
    }
}

void encryptPasswords(int key) {
    for (int i = 0; i < password_count; i++) {
        struct password *pwd = &(password_data[i]);
        encrypt(pwd->website, key);
        encrypt(pwd->username, key);
        encrypt(pwd->password, key);
    }
}

void decryptPasswords(int key) {
    for (int i = 0; i < password_count; i++) {
        struct password *pwd = &(password_data[i]);
        decrypt(pwd->website, key);
        decrypt(pwd->username, key);
        decrypt(pwd->password, key);
    }
}

void savePasswordsToFile() {
    FILE *fp;
    fp = fopen("passwords.txt", "w");
    if (fp == NULL) {
        printf("\nError in opening file!\n");
        return;
    }
    fprintf(fp, "%d\n", password_count);
    for (int i = 0; i < password_count; i++) {
        struct password *pwd = &(password_data[i]);
        fprintf(fp, "%s,%s,%s\n", pwd->website, pwd->username, pwd->password);
    }
    fclose(fp);
    printf("\nPasswords successfully saved to file!\n");
}

void loadPasswordsFromFile() {
    FILE *fp;
    fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("\nError in opening file!\n");
        return;
    }
    fscanf(fp, "%d", &password_count);
    for (int i = 0; i < password_count; i++) {
        struct password *pwd = &(password_data[i]);
        fscanf(fp, "%[^,],%[^,],%[^\n]\n", pwd->website, pwd->username, pwd->password);
    }
    fclose(fp);
    printf("\nPasswords successfully loaded from file!\n");
}

int main() {
    int choice, key;
    printf("\n\n****** Password Manager ******\n\n");
    while(1) {
        printf("\n1. Add Password\n2. Show Passwords\n3. Save Passwords to File\n4. Load Passwords from File\n5. Encrypt Passwords\n6. Decrypt Passwords\n7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                showPasswords();
                break;
            case 3:
                savePasswordsToFile();
                break;
            case 4:
                loadPasswordsFromFile();
                break;
            case 5:
                printf("\nEnter encryption key: ");
                scanf("%d", &key);
                encryptPasswords(key);
                printf("\nPasswords successfully encrypted!\n");
                break;
            case 6:
                printf("\nEnter decryption key: ");
                scanf("%d", &key);
                decryptPasswords(key);
                printf("\nPasswords successfully decrypted!\n");
                break;
            case 7:
                printf("\nThank you for using Password Manager!\n\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again!\n");
        }
    }
}