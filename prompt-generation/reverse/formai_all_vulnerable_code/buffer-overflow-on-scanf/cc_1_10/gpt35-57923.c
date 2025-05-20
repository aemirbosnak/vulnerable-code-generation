//FormAI DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char website[50];
    char username[20];
    char password[20];
} Password;

void encrypt(char *str, int key) {
    int i;
    for(i=0; str[i] != '\0'; i++)
        str[i] = str[i] + key;
}
void decrypt(char *str, int key) {
    int i;
    for(i=0; str[i] != '\0'; i++)
        str[i] = str[i] - key;
}


int main() {
    Password passwords[10];
    int i, choice, key;
    char website[50];
    char username[20];
    char password[20];

    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a new password\n");
        printf("2. View an existing password\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the website name: ");
                scanf("%s", website);
                printf("Enter the username: ");
                scanf("%s", username);
                printf("Enter the password: ");
                scanf("%s", password);

                // Encrypt the password before storing it
                key = 5;
                encrypt(password, key);

                for(i=0; i<10; i++) {
                    if(strlen(passwords[i].website) == 0) {
                        strcpy(passwords[i].website, website);
                        strcpy(passwords[i].username, username);
                        strcpy(passwords[i].password, password);
                        break;
                    }
                }
                if(i == 10) {
                    printf("Password storage limit reached.");
                } else {
                    printf("Password added successfully.");
                }

                break;
            case 2:
                printf("Enter the website name: ");
                scanf("%s", website);

                for(i=0; i<10; i++) {
                    if(strcmp(passwords[i].website, website) == 0) {
                        // Decrypt the password before printing it
                        key = 5;
                        decrypt(passwords[i].password, key);

                        printf("Website name: %s\n", passwords[i].website);
                        printf("Username: %s\n", passwords[i].username);
                        printf("Password: %s\n", passwords[i].password);

                        break;
                    }
                }
                if(i == 10) {
                    printf("No password found for website '%s'.", website);
                }

                break;
            case 3:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.");
                break;
        }
    }

    return 0;
}