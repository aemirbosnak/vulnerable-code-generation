//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define CHAR_SET_SIZE 62

typedef struct {
    char password[MAX_LENGTH + 1];
} Password;

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char random_char(int set_size) {
    return (char)(rand() % set_size + 'a' - (set_size < 26 ? 0 : 26));
}

void generate_password(Password* password) {
    int length = random_number(MIN_LENGTH, MAX_LENGTH);
    int i;

    for (i = 0; i < length; i++) {
        password->password[i] = random_char(CHAR_SET_SIZE);
    }
    password->password[length] = '\0';
}

void print_password(const Password* password) {
    printf("Generated Password: %s\n", password->password);
}

int main() {
    Password my_password;

    srand(time(NULL));

    printf("Enter minimum length: ");
    int min_length;
    scanf("%d", &min_length);

    printf("Enter maximum length: ");
    int max_length;
    scanf("%d", &max_length);

    if (min_length > MAX_LENGTH) {
        printf("Error: Minimum length should be less than or equal to maximum length.\n");
        return 1;
    }

    generate_password(&my_password);

    print_password(&my_password);

    return 0;
}