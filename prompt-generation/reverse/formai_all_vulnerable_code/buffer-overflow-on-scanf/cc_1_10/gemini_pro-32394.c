//GEMINI-pro DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// Vault of Secrets
typedef struct {
    char username[32];
    char password[32];
} Vault;

// The scraps of civilization's secrets
Vault vault[MAX_PASSWORDS];

// The key to cracking the vault
char master_key[32];

// Initialize the vault with the remnants of the old world
void init_vault() {
    strcpy(vault[0].username, "Commander");
    strcpy(vault[0].password, "123456");
    strcpy(vault[1].username, "Scavenger");
    strcpy(vault[1].password, "password");
    strcpy(vault[2].username, "Doctor");
    strcpy(vault[2].password, "healme");
}

// Check if the key is the master key
int check_key(char *key) {
    return strcmp(key, master_key) == 0;
}

// Raid the vault for a specific password
char *raid_vault(char *username, char *key) {
    if (!check_key(key)) {
        return "Access Denied: Wrong Key";
    }

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(vault[i].username, username) == 0) {
            return vault[i].password;
        }
    }

    return "Password Not Found: User Not Authorized";
}

int main() {
    // Initialize the key to unlock the secrets
    strcpy(master_key, "apocalypse");

    // Initialize the vault of secrets
    init_vault();

    // The wasteland survivor seeking knowledge
    char username[32];
    char key[32];

    // Prompt the survivor for their credentials
    printf("Enter your username, Scavenger: ");
    scanf("%s", username);

    printf("Enter the master key, Raider: ");
    scanf("%s", key);

    // Raid the vault and retrieve the password
    char *password = raid_vault(username, key);

    // Display the password, if it was found
    printf("Password for %s: %s\n", username, password);

    return 0;
}