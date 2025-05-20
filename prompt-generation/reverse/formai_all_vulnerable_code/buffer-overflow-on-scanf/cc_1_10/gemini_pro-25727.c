//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Alan Turing
/*
 * Turing Password Vault
 *
 * A simple password vault that encrypts and decrypts passwords
 * using a master password.
 *
 * Based on the Turing machine model of computation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_VAULT_SIZE 100

typedef struct {
    char *name;
    char *password;
} VaultEntry;

VaultEntry vault[MAX_VAULT_SIZE];
int vaultSize = 0;

void TuringMachine(char *input, char *output, int *state, int *tapeHead) {
    while (*state != 0) {
        switch (*state) {
            case 1:
                if (*tapeHead == 0) {
                    *state = 2;
                } else {
                    *tapeHead = *tapeHead - 1;
                }
                break;
            case 2:
                if (input[*tapeHead] == '\0') {
                    *state = 3;
                } else {
                    output[*tapeHead] = input[*tapeHead];
                    *tapeHead = *tapeHead + 1;
                }
                break;
            case 3:
                if (*tapeHead == 0) {
                    *state = 4;
                } else {
                    *tapeHead = *tapeHead - 1;
                    output[*tapeHead] = '\0';
                }
                break;
            case 4:
                if (input[*tapeHead] == '\0') {
                    *state = 0;
                } else {
                    *tapeHead = *tapeHead + 1;
                }
                break;
        }
    }
}

void encryptPassword(char *password, char *masterPassword) {
    int state = 1;
    int tapeHead = 0;
    char input[MAX_PASSWORD_LENGTH + 1];
    char output[MAX_PASSWORD_LENGTH + 1];

    strcpy(input, password);
    TuringMachine(input, output, &state, &tapeHead);

    state = 1;
    tapeHead = 0;
    strcpy(password, output);
    strcpy(input, masterPassword);
    TuringMachine(input, output, &state, &tapeHead);

    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] ^ output[i];
    }
}

void decryptPassword(char *password, char *masterPassword) {
    int state = 1;
    int tapeHead = 0;
    char input[MAX_PASSWORD_LENGTH + 1];
    char output[MAX_PASSWORD_LENGTH + 1];

    strcpy(input, password);
    TuringMachine(input, output, &state, &tapeHead);

    state = 1;
    tapeHead = 0;
    strcpy(password, output);
    strcpy(input, masterPassword);
    TuringMachine(input, output, &state, &tapeHead);

    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] ^ output[i];
    }
}

void addPassword(char *name, char *password, char *masterPassword) {
    if (vaultSize >= MAX_VAULT_SIZE) {
        printf("Vault is full!\n");
        return;
    }

    encryptPassword(password, masterPassword);

    vault[vaultSize].name = malloc(strlen(name) + 1);
    strcpy(vault[vaultSize].name, name);
    vault[vaultSize].password = malloc(strlen(password) + 1);
    strcpy(vault[vaultSize].password, password);

    vaultSize++;
}

void removePassword(char *name) {
    for (int i = 0; i < vaultSize; i++) {
        if (strcmp(vault[i].name, name) == 0) {
            free(vault[i].name);
            free(vault[i].password);
            for (int j = i; j < vaultSize - 1; j++) {
                vault[j] = vault[j + 1];
            }
            vaultSize--;
            return;
        }
    }

    printf("Password not found!\n");
}

void listPasswords() {
    for (int i = 0; i < vaultSize; i++) {
        printf("%s: %s\n", vault[i].name, vault[i].password);
    }
}

int main() {
    char masterPassword[MAX_PASSWORD_LENGTH + 1];
    char command[100];

    printf("Enter master password: ");
    scanf("%s", masterPassword);

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_PASSWORD_LENGTH + 1];
            char password[MAX_PASSWORD_LENGTH + 1];

            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter password: ");
            scanf("%s", password);
            addPassword(name, password, masterPassword);
        } else if (strcmp(command, "remove") == 0) {
            char name[MAX_PASSWORD_LENGTH + 1];

            printf("Enter name: ");
            scanf("%s", name);
            removePassword(name);
        } else if (strcmp(command, "list") == 0) {
            listPasswords();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command!\n");
        }
    }

    return 0;
}