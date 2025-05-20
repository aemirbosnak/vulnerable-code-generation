//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
void encrypt(char *plaintext, char *key, char *ciphertext) {
  // Initialize variables
  int i, j;
  char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char key_alphabet[26] = {0};
  char cipher_alphabet[26] = {0};

  // Create key alphabet
  for (i = 0; i < 26; i++) {
    key_alphabet[i] = key[i % strlen(key)];
  }

  // Create cipher alphabet
  for (i = 0; i < 26; i++) {
    cipher_alphabet[i] = alphabet[i];
    for (j = 0; j < strlen(key_alphabet); j++) {
      if (alphabet[i] == key_alphabet[j]) {
        cipher_alphabet[i] = key_alphabet[(j + 1) % strlen(key_alphabet)];
        break;
      }
    }
  }

  // Encrypt plaintext
  for (i = 0; i < strlen(plaintext); i++) {
    for (j = 0; j < 26; j++) {
      if (plaintext[i] == alphabet[j]) {
        ciphertext[i] = cipher_alphabet[j];
        break;
      }
    }
  }
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
  // Initialize variables
  int i, j;
  char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char key_alphabet[26] = {0};
  char cipher_alphabet[26] = {0};

  // Create key alphabet
  for (i = 0; i < 26; i++) {
    key_alphabet[i] = key[i % strlen(key)];
  }

  // Create cipher alphabet
  for (i = 0; i < 26; i++) {
    cipher_alphabet[i] = alphabet[i];
    for (j = 0; j < strlen(key_alphabet); j++) {
      if (alphabet[i] == key_alphabet[j]) {
        cipher_alphabet[i] = key_alphabet[(j + 1) % strlen(key_alphabet)];
        break;
      }
    }
  }

  // Decrypt ciphertext
  for (i = 0; i < strlen(ciphertext); i++) {
    for (j = 0; j < 26; j++) {
      if (ciphertext[i] == cipher_alphabet[j]) {
        plaintext[i] = alphabet[j];
        break;
      }
    }
  }
}

int main() {
  char plaintext[] = "HELLO WORLD";
  char key[] = "KEY";
  char ciphertext[100] = {0};
  char decrypted_plaintext[100] = {0};

  // Encrypt plaintext
  encrypt(plaintext, key, ciphertext);
  printf("Encrypted text: %s\n", ciphertext);

  // Decrypt ciphertext
  decrypt(ciphertext, key, decrypted_plaintext);
  printf("Decrypted text: %s\n", decrypted_plaintext);

  return 0;
}