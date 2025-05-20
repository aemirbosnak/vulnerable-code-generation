//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>

/* This program creates a digital watermark using an encryption algorithm to hide a secret message within an image file. The image file is read in as a byte array and the secret message is encrypted using a key provided by the user. The encrypted message is then embedded within the least significant bit of each byte of the image file, creating a new watermarked image. The original image and the key used to encrypt the message are required to extract the message from the watermarked image. */

int main(){
  // Step 1: Read in image file
  unsigned char image[] = { 0x42, 0x4D, 0x78, 0x23, 0x10, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
                            0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00,
                            0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x23, 0x10, 0x00, 0x00, 0x13,
                            0x0B, 0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
                            0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF,
                            0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF };

  // Step 2: Encrypt secret message
  char secret_message[] = "I love puzzles";
  char key[] = "mysecretkey";
  unsigned int key_len = sizeof(key);
  unsigned int msg_len = sizeof(secret_message) - 1; // exclude null terminator
  unsigned char encrypted_msg[msg_len];
  for(int i = 0; i < msg_len; i++){
    encrypted_msg[i] = secret_message[i] ^ key[i % key_len]; // XOR encryption algorithm
  }

  // Step 3: Embed encrypted message within image file
  int image_size = sizeof(image);
  for(int i = 0; i < msg_len; i++){
    for(int j = 0; j < 8; j++){
      unsigned char bit = (encrypted_msg[i] >> j) & 1;
      image[i*8+j] = (image[i*8+j] & 0xFE) | bit; // set LSB of byte to encrypted bit
    }
  }

  // Step 4: Display watermarked image
  for(int i = 0; i < image_size; i++){
    printf("%02X ", image[i]);
    if((i+1) % 16 == 0) printf("\n");
  }

  // Step 5: Extract encrypted message from watermarked image
  char extracted_msg[msg_len];
  for(int i = 0; i < msg_len; i++){
    unsigned char byte = 0;
    for(int j = 0; j < 8; j++){
      byte |= ((image[i*8+j] & 1) << j); // extract LSB of byte
    }
    extracted_msg[i] = byte ^ key[i % key_len]; // XOR decryption algorithm
  }
  printf("\n\nThe secret message is: %s\n", extracted_msg);

  return 0;
}