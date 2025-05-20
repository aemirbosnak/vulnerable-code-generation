//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct Password {
    char username[50];
    char password[50];
    char website[50];
};

void encrypt(char *input) {
    int cipher = 5; // Choose a value for the cipher
    while(*input) {
        *input += cipher;
        input++;
    }
}

void decrypt(char *input) {
    int cipher = 5; // Choose the same value used for encryption
    while(*input) {
        *input -= cipher;
        input++;
    }
}

int main() {
    int option, count = 0, i, j;
    struct Password passwords[100];

    // Main menu
    while(1) {
        printf("\n1. Add a new password");
        printf("\n2. View all passwords");
        printf("\n3. Search for a password");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                printf("\nEnter username: ");
                scanf("%s", passwords[count].username);
                printf("Enter password: ");
                scanf("%s", passwords[count].password);
                printf("Enter website: ");
                scanf("%s", passwords[count].website);

                // Encrypt the password before saving it
                encrypt(passwords[count].password);

                printf("\nPassword added successfully!\n");

                count++;
                break;
            }
            case 2: {
                if(count == 0) {
                    printf("\nNo passwords to display.\n");
                }
                else {
                    printf("\nAll Passwords:\n");

                    // Print all passwords
                    for(i = 0; i < count; i++) {
                        printf("\n%d.", i+1);
                        printf("\nUsername: %s", passwords[i].username);

                        // Decrypt the password before displaying it
                        decrypt(passwords[i].password);

                        printf("\nPassword: %s", passwords[i].password);

                        // Encrypt the password again to keep it safe
                        encrypt(passwords[i].password);

                        printf("\nWebsite: %s\n", passwords[i].website);
                    }
                }
                break;
            }
            case 3: {
                char search[50];
                int found = 0;

                printf("\nEnter website to search for: ");
                scanf("%s", search);

                // Search for the password
                for(i = 0; i < count; i++) {
                    if(strcmp(passwords[i].website, search) == 0) {
                        printf("\nPassword found!\n");
                        printf("\nUsername: %s", passwords[i].username);

                        // Decrypt the password before displaying it
                        decrypt(passwords[i].password);

                        printf("\nPassword: %s", passwords[i].password);

                        // Encrypt the password again to keep it safe
                        encrypt(passwords[i].password);

                        printf("\nWebsite: %s\n", passwords[i].website);

                        found = 1;
                        break;
                    }
                }

                if(found == 0) {
                    printf("\nPassword not found!\n");
                }

                break;
            }
            case 4: {
                printf("\nExiting...\n");
                exit(0);
                break;
            }
            default: {
                printf("\nInvalid input. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}