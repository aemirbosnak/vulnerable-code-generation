//Gemma-7B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORDS 10
#define MAX_CHAR_PASS 20

typedef struct Password {
    char *name;
    char *password;
    int used;
} Password;

void generate_password(Password *passwords) {
    passwords->name = malloc(MAX_CHAR_PASS);
    passwords->password = malloc(MAX_CHAR_PASS);
    passwords->used = 0;
}

void store_password(Password *passwords) {
    FILE *fp = fopen("passwords.dat", "a");
    fprintf(fp, "%s\n%s\n", passwords->name, passwords->password);
    fclose(fp);
}

void retrieve_password(Password *passwords) {
    FILE *fp = fopen("passwords.dat", "r");
    char *name = malloc(MAX_CHAR_PASS);
    char *password = malloc(MAX_CHAR_PASS);
    fscanf(fp, "%s\n%s\n", name, password);
    passwords->name = name;
    passwords->password = password;
    fclose(fp);
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int i = 0;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        generate_password(&passwords[i]);
    }

    store_password(&passwords[0]);
    retrieve_password(&passwords[0]);

    printf("%s\n", passwords[0].name);
    printf("%s\n", passwords[0].password);

    return 0;
}