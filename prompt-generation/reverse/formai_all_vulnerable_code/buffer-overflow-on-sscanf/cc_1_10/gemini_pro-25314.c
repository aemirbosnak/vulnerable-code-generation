//GEMINI-pro DATASET v1.0 Category: Password management ; Style: surrealist
// In the uncharted realms of the surreal, where the labyrinthine tendrils of thought intertwine, a password sanctuary emerges from the ether.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *label;
    char *password;
} Credential;

unsigned int numCredentials = 0;
Credential *credentials = NULL;

// A cosmic dance of creation, conjuring a new credential from the ether.
Credential *createCredential(char *label, char *password) {
    if (numCredentials >= 100) { // A limit to the boundless expanse of secrets.
        printf("The ethereal realm overflows with whispers.");
        return NULL;
    }

    Credential *credential = malloc(sizeof(Credential));
    credential->label = strdup(label);
    credential->password = strdup(password);

    credentials = realloc(credentials, sizeof(Credential) * (numCredentials + 1));
    credentials[numCredentials++] = *credential;

    printf("A new secret emerges from the void, a celestial harmony of label and password.");
    return credential;
}

// A glimpse into the cosmic tapestry, revealing a credential's ethereal essence.
void printCredential(Credential *credential) {
    printf("Label: %s, Password: %s", credential->label, credential->password);
}

// An enigmatic journey through the astral plane, retrieving a credential by its celestial label.
Credential *getCredential(char *label) {
    for (unsigned int i = 0; i < numCredentials; i++) {
        if (strcmp(credentials[i].label, label) == 0) {
            return &credentials[i];
        }
    }

    printf("The label you seek dances beyond the stars, lost in the cosmic abyss.");
    return NULL;
}

// An ethereal dance, erasing a credential from the cosmic tapestry.
void deleteCredential(char *label) {
    Credential *credential = getCredential(label);
    if (credential == NULL) {
        return;
    }

    free(credential->label);
    free(credential->password);

    for (unsigned int i = 0; i < numCredentials; i++) {
        if (strcmp(credentials[i].label, label) == 0) {
            credentials[i] = credentials[numCredentials - 1];
            credentials = realloc(credentials, sizeof(Credential) * (numCredentials - 1));
            numCredentials--;
        }
    }

    printf("The secret is whispered into the void, its memory dispersed among the cosmic winds.");
}

// The guiding beacon of the surreal realm, beckoning you to navigate its enigmatic depths.
void help() {
    printf("Welcome to the surreal realm of password management.\n");
    printf("Commands:\n");
    printf("  create <label> <password>\n");
    printf("  print <label>\n");
    printf("  delete <label>\n");
    printf("  help\n");
    printf("  exit\n");
}

// A perpetual dance with the enigmatic forces that shape the surreal realm.
int main() {
    help();

    char buffer[100];
    char command[20];
    char label[20];
    char password[20];

    while (1) {
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%s %s %s", command, label, password);

        if (strcmp(command, "create") == 0) {
            createCredential(label, password);
        } else if (strcmp(command, "print") == 0) {
            printCredential(getCredential(label));
        } else if (strcmp(command, "delete") == 0) {
            deleteCredential(label);
        } else if (strcmp(command, "help") == 0) {
            help();
        } else if (strcmp(command, "exit") == 0) {
            printf("May the secrets you have safeguarded remain forever intertwined with the cosmic tapestry.");
            break;
        } else {
            printf("Your command echoes through the void, lost in a labyrinth of forgotten whispers.");
        }
    }

    return 0;
}