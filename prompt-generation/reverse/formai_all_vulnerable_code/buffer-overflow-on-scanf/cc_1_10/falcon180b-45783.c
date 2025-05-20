//Falcon-180B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 20

struct Password {
    char password[PASSWORD_LENGTH];
    time_t creation_time;
};

void generate_password(char *password) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]:;?><,./-=";
    srand(time(NULL));
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[PASSWORD_LENGTH - 1] = '\0';
}

int save_password(const char *filename, const char *password) {
    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return 1;
    }
    fprintf(file, "%s\n", password);
    fclose(file);
    return 0;
}

int load_password(const char *filename, char *password) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return 1;
    }
    fscanf(file, "%s", password);
    fclose(file);
    return 0;
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    char password[PASSWORD_LENGTH];
    generate_password(password);

    int result = save_password(filename, password);
    if (result!= 0) {
        return result;
    }

    char loaded_password[PASSWORD_LENGTH];
    result = load_password(filename, loaded_password);
    if (result!= 0) {
        return result;
    }

    if (strcmp(password, loaded_password)!= 0) {
        printf("Error: Loaded password does not match generated password\n");
        return 1;
    }

    printf("Password saved successfully\n");
    return 0;
}