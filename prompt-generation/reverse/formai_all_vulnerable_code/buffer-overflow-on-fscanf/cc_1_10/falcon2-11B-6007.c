//Falcon2-11B DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define PASSWORD_LEN 16
#define PWD_FILE_NAME "pwd.txt"

char* generate_password() {
    char password[PASSWORD_LEN];
    srand(time(NULL));
    
    for (int i = 0; i < PASSWORD_LEN; i++) {
        password[i] = (char)('0' + rand() % 10);
    }
    
    return password;
}

void write_password_to_file(char* password) {
    FILE* f = fopen(PWD_FILE_NAME, "w");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    fprintf(f, "%s\n", password);
    fclose(f);
}

void read_password_from_file() {
    FILE* f = fopen(PWD_FILE_NAME, "r");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    char password[PASSWORD_LEN];
    fscanf(f, "%s", password);
    
    fclose(f);
}

int main() {
    char* password = generate_password();
    write_password_to_file(password);
    read_password_from_file();
    
    printf("Password: %s\n", password);
    return 0;
}