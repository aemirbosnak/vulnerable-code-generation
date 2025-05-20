//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// The realm of the surreal...
#define HASH_SIZE    (SHA256_DIGEST_LENGTH)
#define BUFFER_SIZE (1024)
#define KEY_SIZE     (256)

// A cryptic lexicon of functions...
void weave_the_hash(char *key, char *data, unsigned char *digest);
void whisper_the_hash(unsigned char *digest);
int main(int argc, char **argv);

// In the labyrinthine depths of cyberspace...
void weave_the_hash(char *key, char *data, unsigned char *digest) {
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, key, strlen(key));
  SHA256_Update(&ctx, data, strlen(data));
  SHA256_Final(digest, &ctx);
}

// Reveal the whispers of the hash...
void whisper_the_hash(unsigned char *digest) {
  int i;
  for (i = 0; i < HASH_SIZE; i++) {
    printf("%02x", digest[i]);
  }
  printf("\n");
}

// The enigmatic dance of the main function...
int main(int argc, char **argv) {
  // Acquire the whispered key and enigmatic data...
  char key[KEY_SIZE];
  char data[BUFFER_SIZE];
  printf("Unveil the key, wise traveler: ");
  scanf("%s", key);
  printf("Utter the data, oh bearer of secrets: ");
  gets(data);

  // Forge the bond of the hash...
  unsigned char digest[HASH_SIZE];
  weave_the_hash(key, data, digest);

  // Echo the ethereal incantation...
  printf("Behold, the essence of your words: ");
  whisper_the_hash(digest);

  // Vanish into the cosmic void...
  return 0;
}