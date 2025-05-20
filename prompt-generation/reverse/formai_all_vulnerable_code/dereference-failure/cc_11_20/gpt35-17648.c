//FormAI DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

#define CBC 1

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <key> <input file> <output file>\n", argv[0]);
        return 1;
    }

    const char *key = argv[2];
    const char *input_file = argv[3];
    const char *output_file = argv[4];

    //Initialization vector, used for CBC mode
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    AES_KEY aes_key;

    //Initialize the key
    AES_set_encrypt_key(key, strlen(key)*8, &aes_key);

    FILE *fin, *fout;
    fin = fopen(input_file, "rb");
    fout = fopen(output_file, "wb");

    if (fin == NULL || fout == NULL) {
        fprintf(stderr, "Error opening input/output files!\n");
        return 1;
    }

    int bytes_read, bytes_written;
    unsigned char in_data[AES_BLOCK_SIZE], out_data[AES_BLOCK_SIZE];

    //Encrypt or decrypt data based on the first command line argument
    if (strncmp(argv[1], "encrypt", 7) == 0) {
        while (1) {
            bytes_read = fread(in_data, 1, AES_BLOCK_SIZE, fin);

            //Pad the data if it is not a multiple of the block size
            if (bytes_read < AES_BLOCK_SIZE) {
                memset(in_data + bytes_read, AES_BLOCK_SIZE - bytes_read, AES_BLOCK_SIZE - bytes_read);
            }

#if CBC
            //Encrypt the data using CBC mode
            AES_cbc_encrypt(in_data, out_data, AES_BLOCK_SIZE, &aes_key, iv, AES_ENCRYPT);
#else
            //Encrypt the data using ECB mode
            AES_ecb_encrypt(in_data, out_data, &aes_key, AES_ENCRYPT);
#endif

            bytes_written = fwrite(out_data, 1, AES_BLOCK_SIZE, fout);
            if (bytes_written != AES_BLOCK_SIZE) {
                fprintf(stderr, "Error writing encrypted data!\n");
                return 1;
            }

            if (bytes_read < AES_BLOCK_SIZE) {
                break;
            }
        }
    }
    else if (strncmp(argv[1], "decrypt", 7) == 0) {
        while (1) {
            bytes_read = fread(in_data, 1, AES_BLOCK_SIZE, fin);

            //Decrypt the data using CBC mode
#if CBC
            AES_cbc_encrypt(in_data, out_data, AES_BLOCK_SIZE, &aes_key, iv, AES_DECRYPT);
#else
            //Decrypt the data using ECB mode
            AES_ecb_encrypt(in_data, out_data, &aes_key, AES_DECRYPT);
#endif

            //Remove the padding if it exists
            if (bytes_read < AES_BLOCK_SIZE) {
                int padding = out_data[AES_BLOCK_SIZE - 1];
                if (padding > 0 && padding <= AES_BLOCK_SIZE) {
                    for (int i = AES_BLOCK_SIZE - padding; i < AES_BLOCK_SIZE; i++) {
                        if (out_data[i] != padding) {
                            fprintf(stderr, "Error removing padding!\n");
                            return 1;
                        }
                    }
                    bytes_written = fwrite(out_data, 1, AES_BLOCK_SIZE - padding, fout);
                }
                else {
                    bytes_written = fwrite(out_data, 1, AES_BLOCK_SIZE, fout);
                }
            }
            else {
                bytes_written = fwrite(out_data, 1, AES_BLOCK_SIZE, fout);
            }

            if (bytes_written != AES_BLOCK_SIZE) {
                fprintf(stderr, "Error writing decrypted data!\n");
                return 1;
            }

            if (bytes_read < AES_BLOCK_SIZE) {
                break;
            }
        }
    }
    else {
        fprintf(stderr, "Invalid command line argument!\n");
        return 1;
    }

    fclose(fin);
    fclose(fout);

    return 0;
}