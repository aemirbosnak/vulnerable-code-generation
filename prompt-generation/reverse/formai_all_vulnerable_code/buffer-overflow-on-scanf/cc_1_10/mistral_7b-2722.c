//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>

#define MIN_LEN 12
#define MAX_LEN 20
#define CHAR_SET_SIZE 62
#define RANDOM_DATA_SIZE 256

char char_set[CHAR_SET_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void random_bytes(unsigned char* buffer, int length) {
    FILE* file;
    int bytes_read;

    file = fopen("/dev/urandom", "rb");
    if (!file) {
        printf("Error: Unable to open /dev/urandom.\n");
        exit(EXIT_FAILURE);
    }

    bytes_read = fread(buffer, 1, length, file);
    if (bytes_read < length) {
        printf("Error: Unable to read %d bytes from /dev/urandom.\n", length);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void shuffle_array(char* array, int length) {
    int i, j, temp;

    for (i = length - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void generate_password(char* password, int length) {
    int i;

    random_bytes(password, length);

    shuffle_array(password, length);

    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            password[i] = char_set[RAND_MAX % CHAR_SET_SIZE];
        }
        if (isalpha(password[i]) && islower(password[i])) {
            password[i] = char_set[(RAND_MAX % 26) + 'a'];
        }
        if (isalpha(password[i]) && isupper(password[i])) {
            password[i] = char_set[(RAND_MAX % 26) + 'A'];
        }
        if (!isalnum(password[i])) {
            password[i] = char_set[(RAND_MAX % CHAR_SET_SIZE)];
        }
    }
}

int main() {
    char password[MAX_LEN + 1];
    int length;

    printf("Enter the length of the password (between %d and %d): ", MIN_LEN, MAX_LEN);
    scanf("%d", &length);

    if (length < MIN_LEN || length > MAX_LEN) {
        printf("Error: Password length must be between %d and %d.\n", MIN_LEN, MAX_LEN);
        exit(EXIT_FAILURE);
    }

    generate_password(password, length);
    password[length] = '\0';

    printf("Generated password: %s\n", password);

    return EXIT_SUCCESS;
}