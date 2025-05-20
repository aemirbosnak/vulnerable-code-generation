//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // welcome message
    printf("Welcome to the Secret Vault!\n\n");

    // open the vault file
    FILE *file = fopen("vault.txt", "r");

    // check if the vault file exists
    if (file == NULL) {
        printf("Uh oh, the vault is empty!\n");
        return 0;
    }

    // get the number of secrets in the vault
    int num_secrets;
    fscanf(file, "%d\n", &num_secrets);

    // print the number of secrets in the vault
    printf("There are %d secrets in the vault.\n\n", num_secrets);

    // iterate over the secrets in the vault
    int i;
    for (i = 0; i < num_secrets; i++) {
        // get the secret
        char secret[100];
        fgets(secret, 100, file);

        // print the secret
        printf("Secret %d: %s", i + 1, secret);
    }

    // close the vault file
    fclose(file);

    // add a secret to the vault
    printf("\nDo you have a secret to add to the vault? (y/n)\n");
    char answer;
    scanf("%c", &answer);

    if (answer == 'y') {
        // open the vault file in append mode
        FILE *file = fopen("vault.txt", "a");

        // get the new secret
        char new_secret[100];
        printf("Enter the secret:\n");
        scanf(" %[^\n]s", new_secret);

        // append the new secret to the vault file
        fprintf(file, "%s\n", new_secret);

        // close the vault file
        fclose(file);

        printf("The secret has been added to the vault!\n");
    }

    printf("\nThank you for visiting the Secret Vault!\n");

    return 0;
}