//Falcon-180B DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define HASH_LENGTH 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];
} password_t;

void generate_hash(const char* password, char* hash) {
    int i;
    for (i = 0; i < HASH_LENGTH; i++) {
        hash[i] = password[i % strlen(password)];
    }
}

int compare_hashes(const char* hash1, const char* hash2) {
    int i;
    for (i = 0; i < HASH_LENGTH; i++) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE* file;
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char filename[MAX_PASSWORD_LENGTH];
    char input[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];
    int i, j;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while (fscanf(file, "%s", input)!= EOF) {
        if (num_passwords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            break;
        }
        generate_hash(input, hash);
        strcpy(passwords[num_passwords].password, input);
        strcpy(passwords[num_passwords].hash, hash);
        num_passwords++;
    }

    fclose(file);

    printf("Enter password: ");
    scanf("%s", input);

    for (i = 0; i < num_passwords; i++) {
        if (compare_hashes(passwords[i].hash, hash)) {
            printf("Password found.\n");
            break;
        }
    }

    if (i == num_passwords) {
        printf("Password not found.\n");
    }

    return 0;
}