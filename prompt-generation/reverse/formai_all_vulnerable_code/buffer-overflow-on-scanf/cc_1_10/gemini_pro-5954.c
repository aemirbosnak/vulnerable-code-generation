//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Our mystical elixir of bytes
typedef unsigned char byte;

// The sanctuary where our secrets reside
byte* Message(size_t length) {
  byte* secret = (byte*) malloc(length);
  printf("Whisper your secret, traveler:\n");
  scanf("%s", secret);
  return secret;
}

// The forge where our unbreakable bond is forged
byte* Hash(byte* secret, size_t length) {
  // Align the stars and summon the ancient SHA-256
  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, secret, length);
  byte* digest = (byte*) malloc(SHA256_DIGEST_LENGTH);
  SHA256_Final(digest, &ctx);
  return digest;
}

// The oracle that reveals our immutable truth
void Reveal(byte* hash, size_t length) {
  printf("Behold, your immutable seal:\n");
  for (size_t i = 0; i < length; i++) {
    printf("%.2x", hash[i]);
  }
  printf("\n");
}

int main() {
  // Collect the threads of your secret
  byte* secret = Message(100);

  // Cast it into the fiery forge
  byte* hash = Hash(secret, strlen(secret));

  // Gaze upon your eternal guardian
  Reveal(hash, SHA256_DIGEST_LENGTH);

  // Release the shackles of your secret
  free(secret);
  free(hash);
  return 0;
}