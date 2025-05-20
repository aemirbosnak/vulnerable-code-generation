#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[33];
    char key[65];
} EncryptData;

void read_data(EncryptData* data) {
    printf("Enter your name (max 32 chars):\n");
    scanf("%s", data->name);
    printf("Enter your encryption key (max 64 chars):\n");
    scanf("%s", data->key);
}

void encryption_process(EncryptData data) {
    // Simulate encryption process for simplicity
    printf("Processing data...\n");
    sleep(1);
}

int main() {
    EncryptData user_data;
    read_data(&user_data);
    encryption_process(user_data);

    // Vulnerable code section
    char attacker_input[10];
    printf("Enter the flag to access secret data (format: flag{XXX}):\n");
    if (sscanf(attacker_input, "flag{%63s}", attacker_input) == 1) {
        printf("Access granted. Secret data: %s\n", user_data.key);
    } else {
        printf("Invalid input. Access denied.\n");
    }

    return 0;
}
