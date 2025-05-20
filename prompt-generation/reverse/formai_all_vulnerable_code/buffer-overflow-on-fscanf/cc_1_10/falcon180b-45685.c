//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20
#define USERNAME_LENGTH 20

struct password_t {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
};

void generate_password(char* password) {
    int length = strlen(password);
    for(int i=0; i<length; i++) {
        if(isalpha(password[i])) {
            password[i] = toupper(password[i]);
        }
    }
}

int compare_passwords(const void* a, const void* b) {
    const struct password_t* password_a = (const struct password_t*)a;
    const struct password_t* password_b = (const struct password_t*)b;

    return strcmp(password_a->username, password_b->username);
}

void sort_passwords(struct password_t passwords[]) {
    qsort(passwords, MAX_PASSWORDS, sizeof(struct password_t), compare_passwords);
}

int main() {
    FILE* file = fopen("passwords.txt", "r");
    if(file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    struct password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while(fscanf(file, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
        num_passwords++;
    }

    fclose(file);

    sort_passwords(passwords);

    printf("Sorted Passwords:\n");
    for(int i=0; i<num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}