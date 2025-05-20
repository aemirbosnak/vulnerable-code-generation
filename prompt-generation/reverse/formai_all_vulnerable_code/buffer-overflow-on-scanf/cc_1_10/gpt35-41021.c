//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
// C Image Steganography Example Program

#include <stdio.h>

int main() {

  // Declare Variables
  FILE *originalImage, *secretImage, *stegoImage;
  unsigned char originalByte, secretByte, stegoByte, mask;
  int originalSize, secretSize, stegoSize, i, j, bit, bitCount = 0;
  char originalFile[100], secretFile[100], stegoFile[100], message[100];

  // Get Filename and Message Inputs
  printf("Enter Original Image Filename: ");
  scanf("%s", originalFile);
  printf("Enter Secret Image Filename: ");
  scanf("%s", secretFile);
  printf("Enter Output Stego Image Filename: ");
  scanf("%s", stegoFile);
  printf("Enter Secret Message (Up to 100 Characters): ");
  scanf("%s", message);

  // Open Original Image to Read
  originalImage = fopen(originalFile, "rb");
  if (!originalImage) {
    printf("Error: Unable to Open Original Image\n");
    return 1;
  }

  // Open Secret Image to Read
  secretImage = fopen(secretFile, "rb");
  if (!secretImage) {
    printf("Error: Unable to Open Secret Image\n");
    fclose(originalImage);
    return 1;
  }

  // Open Stego Image to Write
  stegoImage = fopen(stegoFile, "wb");
  if (!stegoImage) {
    printf("Error: Unable to Open Stego Image\n");
    fclose(originalImage);
    fclose(secretImage);
    return 1;
  }

  // Get Sizes of Original and Secret Images
  fseek(originalImage, 0, SEEK_END);
  originalSize = ftell(originalImage);
  fseek(originalImage, 0, SEEK_SET);
  fseek(secretImage, 0, SEEK_END);
  secretSize = ftell(secretImage);
  fseek(secretImage, 0, SEEK_SET);

  // Check if Secret Image Fits into Original Image
  stegoSize = originalSize;
  if (secretSize > originalSize / 8) {
    printf("Error: Secret Image Too Large to Fit into Original Image\n");
    fclose(originalImage);
    fclose(secretImage);
    fclose(stegoImage);
    return 1;
  }

  // Write Sizes of Original and Secret Images to Stego Image
  fwrite(&originalSize, sizeof(int), 1, stegoImage);
  fwrite(&secretSize, sizeof(int), 1, stegoImage);

  // Copy Original and Secret Images to Stego Image
  for (i = 0; i < originalSize; i++) {
    originalByte = getc(originalImage);
    if (i < secretSize * 8) {
      // If Copying Secret Image, Get Next Byte
      if (bitCount % 8 == 0) {
        secretByte = getc(secretImage);
      }
      // Get Bit from Secret Byte to Copy to Stego Byte
      bit = (secretByte >> (7 - bitCount % 8)) & 1;
      bitCount ++;
      // Copy Bit to Stego Byte
      mask = 0xFE | bit;
      stegoByte = (originalByte & mask) | bit;
    } else {
      // If Not Copying Secret Image, Copy Original Byte to Stego Image
      stegoByte = originalByte;
    }
    // Write Stego Byte to Stego Image
    putc(stegoByte, stegoImage);
  }

  // Write Message to Stego Image
  for (i = 0; message[i] != '\0'; i++) {
    // Get Next Byte from Message
    secretByte = message[i];
    for (j = 0; j < 8; j++) {
      // Get Bit from Message Byte to Copy to Stego Byte
      bit = (secretByte >> (7 - j)) & 1;
      // Copy Bit to Stego Byte
      mask = 0xFE | bit;
      stegoByte = (originalByte & mask) | bit;
      // Write Stego Byte to Stego Image
      putc(stegoByte, stegoImage);
    }
  }

  // Close All Image Files
  fclose(originalImage);
  fclose(secretImage);
  fclose(stegoImage);

  // Exit Program
  printf("Steganography Complete\n");
  return 0;
}