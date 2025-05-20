//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define KEY       0x4011C7 /* Here is your key */
#define BLOCKSIZE 16

void encrypt(unsigned char *plaintext, unsigned char *ciphertext) {
  unsigned int i, j, k, l;
  unsigned int state[4][4];
  unsigned char temp[4];

  for (i = 0; i < BLOCKSIZE; i += 4) {
    memcpy(state, plaintext + i, 4);

    for (j = 0; j < 10; j++) {
      for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
          state[k][l] ^= (state[(k + 1) % 4][l] + state[(k + 2) % 4][l] + state[(k + 3) % 4][l] + KEY) & 0xFF;
        }
      }

      for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
          state[k][l] ^= (state[k][(l + 1) % 4] + state[k][(l + 2) % 4] + state[k][(l + 3) % 4] + KEY) & 0xFF;
        }
      }
    }

    for (k = 0; k < 4; k++) {
      for (l = 0; l < 4; l++) {
        state[k][l] ^= (state[(k + 1) % 4][l] + state[(k + 2) % 4][l] + state[(k + 3) % 4][l] + KEY) & 0xFF;
      }
    }

    for (k = 0; k < 4; k++) {
      for (l = 0; l < 4; l++) {
        state[k][l] ^= (state[k][(l + 1) % 4] + state[k][(l + 2) % 4] + state[k][(l + 3) % 4] + KEY) & 0xFF;
      }
    }

    for (k = 0; k < 4; k++) {
      memcpy(temp, state[k], 4);
      for (l = 0; l < 4; l++) {
        state[k][l] = temp[(l + 1) % 4];
      }
    }

    for (k = 0; k < 4; k++) {
      memcpy(temp, state[k], 4);
      for (l = 0; l < 4; l++) {
        state[k][l] = temp[(l + 2) % 4];
      }
    }

    for (k = 0; k < 4; k++) {
      memcpy(temp, state[k], 4);
      for (l = 0; l < 4; l++) {
        state[k][l] = temp[(l + 3) % 4];
      }
    }

    memcpy(ciphertext + i, state, 4);
  }
}

void decrypt(unsigned char *ciphertext, unsigned char *plaintext) {
  unsigned int i, j, k, l;
  unsigned int state[4][4];
  unsigned char temp[4];

  for (i = 0; i < BLOCKSIZE; i += 4) {
    memcpy(state, ciphertext + i, 4);

    for (j = 0; j < 10; j++) {
      for (k = 0; k < 4; k++) {
        memcpy(temp, state[k], 4);
        for (l = 0; l < 4; l++) {
          state[k][l] = temp[(l + 3) % 4];
        }
      }

      for (k = 0; k < 4; k++) {
        memcpy(temp, state[k], 4);
        for (l = 0; l < 4; l++) {
          state[k][l] = temp[(l + 2) % 4];
        }
      }

      for (k = 0; k < 4; k++) {
        memcpy(temp, state[k], 4);
        for (l = 0; l < 4; l++) {
          state[k][l] = temp[(l + 1) % 4];
        }
      }

      for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
          state[k][l] ^= (state[(k + 1) % 4][l] + state[(k + 2) % 4][l] + state[(k + 3) % 4][l] + KEY) & 0xFF;
        }
      }

      for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
          state[k][l] ^= (state[k][(l + 1) % 4] + state[k][(l + 2) % 4] + state[k][(l + 3) % 4] + KEY) & 0xFF;
        }
      }
    }

    for (k = 0; k < 4; k++) {
      for (l = 0; l < 4; l++) {
        state[k][l] ^= (state[(k + 1) % 4][l] + state[(k + 2) % 4][l] + state[(k + 3) % 4][l] + KEY) & 0xFF;
      }
    }

    for (k = 0; k < 4; k++) {
      for (l = 0; l < 4; l++) {
        state[k][l] ^= (state[k][(l + 1) % 4] + state[k][(l + 2) % 4] + state[k][(l + 3) % 4] + KEY) & 0xFF;
      }
    }

    memcpy(plaintext + i, state, 4);
  }
}

int main() {
  unsigned char plaintext[] = "Hello, World!";
  unsigned char ciphertext[BLOCKSIZE];
  unsigned char decryptedtext[BLOCKSIZE];

  encrypt(plaintext, ciphertext);
  decrypt(ciphertext, decryptedtext);

  printf("Plaintext: %s\n", plaintext);
  printf("Ciphertext: %s\n", ciphertext);
  printf("Decryptedtext: %s\n", decryptedtext);

  return 0;
}