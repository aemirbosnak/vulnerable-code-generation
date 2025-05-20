//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int main() {
  BN_CTX *ctx = BN_CTX_new();
  BIGNUM *p = BN_new();
  BIGNUM *q = BN_new();
  BIGNUM *n = BN_new();
  BIGNUM *e = BN_new();
  BIGNUM *d = BN_new();
  BIGNUM *num = BN_new();
  BIGNUM *enc = BN_new();
  BIGNUM *dec = BN_new();
  RSA *rsa = RSA_new();

  // Generate prime numbers p and q
  BN_generate_prime_ex(p, 512, 0, NULL, NULL, NULL);
  BN_generate_prime_ex(q, 512, 0, NULL, NULL, NULL);

  // Calculate n = p * q
  BN_mul(n, p, q, ctx);

  // Calculate Euler's totient of n
  BIGNUM *phi_n = BN_new();
  BN_sub(p, p, BN_value_one());
  BN_sub(q, q, BN_value_one());
  BN_mul(phi_n, p, q, ctx);

  // Find a suitable e such that gcd(e, phi_n) = 1
  BN_set_word(e, 65537);
  while (BN_gcd(num, e, phi_n, ctx) != BN_value_one()) {
    BN_add_word(e, 2);
  }

  // Calculate d = e^-1 mod phi_n
  BN_mod_inverse(d, e, phi_n, ctx);

  // Assign the values to the RSA structure
  RSA_set0_key(rsa, n, e, d);

  // Generate a message to encrypt
  BN_set_word(num, 12345);

  // Encrypt the message
  RSA_public_encrypt(BN_num_bytes(num), num, enc, rsa, RSA_PKCS1_PADDING);

  // Decrypt the encrypted message
  RSA_private_decrypt(BN_num_bytes(enc), enc, dec, rsa, RSA_PKCS1_PADDING);

  // Check if the decrypted message matches the original message
  if (BN_cmp(num, dec) == 0) {
    printf("Public-key encryption and decryption successful!\n");
  } else {
    printf("Uh-oh, something went wrong during encryption or decryption!\n");
  }

  // Free the allocated memory
  BN_free(ctx);
  BN_free(p);
  BN_free(q);
  BN_free(n);
  BN_free(e);
  BN_free(d);
  BN_free(num);
  BN_free(enc);
  BN_free(dec);
  RSA_free(rsa);
  BN_free(phi_n);

  return 0;
}