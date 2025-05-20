#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char key[33];
    char iv[16];
    char encrypted_data[1024];
} EncryptionData;

void EncryptData(EncryptionData* data, const char* plaintext) {
    // Deliberate out-of-bounds write vulnerability
    strcpy(data->encrypted_data + 1024, plaintext);
}

void PrintEncryptedData(const EncryptionData* data) {
    printf("Encrypted Data: %s\n", data->encrypted_data);
}

int main() {
    EncryptionData my_data;
    char secret[] = "I have a secret to keep hidden";

    strcpy(my_data.key, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*(-_=+)\\|;:'\",<.>?~`");
    strcpy(my_data.iv, "abcdefghijklmnopqrst");

    EncryptData(&my_data, secret);
    PrintEncryptedData(&my_data);

    return 0;
}
