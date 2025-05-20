//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void);

int main(void) {
  EVP_MD_CTX *mdctx;
  const EVP_MD *md;
  char message[] = "The quick brown fox jumps over the lazy dog";
  unsigned char digest[EVP_MAX_MD_SIZE];
  unsigned int digest_len, i;

  OpenSSL_add_all_digests();

  md = EVP_get_digestbyname("sha256");
  if (!md) {
    printf("Error: no such digest");
    exit(1);
  }

  mdctx = EVP_MD_CTX_new();
  if (!mdctx) {
    handleErrors();
  }

  if (1 != EVP_DigestInit_ex(mdctx, md, NULL)) {
    handleErrors();
  }

  if (1 != EVP_DigestUpdate(mdctx, message, strlen(message))) {
    handleErrors();
  }

  if (1 != EVP_DigestFinal_ex(mdctx, digest, &digest_len)) {
    handleErrors();
  }

  EVP_MD_CTX_free(mdctx);

  printf("Digest is: ");
  for (i = 0; i < digest_len; i++) {
    printf("%02x", digest[i]);
  }
  printf("\n");

  return 0;
}

void handleErrors(void) {
  printf("Unable to complete action\n");
  exit(1);
}